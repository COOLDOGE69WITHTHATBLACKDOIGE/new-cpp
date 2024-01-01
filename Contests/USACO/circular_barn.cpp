#include<bits/stdc++.h>
using namespace std;
 
// #define _GLIBCXX_DEBUG 1
// #define _GLIBCXX_DEBUG_PEDANTIC 1
// #pragma GCC optimize("trapv")

// #define dbg(TXTMSG) cerr << "\n" << TXTMSG
// #define dbgv(VARN) cerr << "\n" << #VARN << " = "<< VARN << ", line: " << __LINE__ << "\n"

#define ld long double
#define int long long
#define forn(i,j) for(int i = 0; i < j; i++)
#define forrange(i,j,k) for(int i = j; i < k; ++i)
#define rof(i,j) rof(int i = j; i >= 0; --i)
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define vvi vector<vi>
#define vvpii vector<vector<pii>>
#define vb vector<bool>
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define eb emplace_back
#define qi queue<int>
#define qpii queue<pii>
#define pqpii priority_queue<pii>
#define pqi priority_queue<int>

const int MOD = 1e9 + 7;
const int INF = 1e17 + 1;
const int maxN = 2e5 + 1;

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int dp[1001][1001][8];
int cst[1001][1001];
int n,k;

void dnc(int i, int l, int r, int optl, int optr, int st){
	if(l > r){
		return;
	}

	int mid = (l+r)/2;
	int opt;
	dp[st][mid][i] = INF;

	forrange(j,optl,min(mid,optr)+1){
		int idx1 = st + j - 1;
		int idx2 = st + mid - 1;

		if(idx1 > n){
			idx1 -= n;
		}

		if(idx2 > n){
			idx2 -= n;
		}

		if(j > 0){
			if(dp[st][mid][i] > dp[st][j-1][i-1] + cst[idx1][idx2]){
				dp[st][mid][i] = dp[st][j-1][i-1] + cst[idx1][idx2];
				opt = j;
			}
		}

		else{
			if(dp[st][mid][i] > cst[idx1][idx2]){
				dp[st][mid][i] = cst[idx1][idx2];
				opt = j;
			}
		}
	}

	dnc(i,l,mid-1,optl,opt,st);
	dnc(i,mid+1,r,opt,optr,st);
}

signed main(){
	setIO("cbarn");
	cin >> n >> k;

	vi r(n);

	forn(i,n){
		cin >> r[i];
	}

	forn(i,n){
		int i1 = i+1;

		cst[i1][i1] = 0;

		int c = i1+1;

		if(c > n){
			c -= n;
		}

		while(c != i1){
			int sum;
			if(c < i1){
				sum = (n-i1+c)*r[c-1];
			}

			else{
				sum = (c-i1)*r[c-1];
			}

			if(c == 1){
				cst[i1][c] = cst[i1][n] + sum;
			}

			else{
				cst[i1][c] = cst[i1][c-1] + sum;
			}

			c++;

			if(c > n){
				c -= n;
			}
		}
	}

	forrange(i,1,n+1){
		forrange(c,2,n+1){
			int idx = i + c - 1;

			if(idx > n){
				idx -= n;
			}

			dp[i][c][1] = cst[i][idx];
		}
	}

	if(k > 1){
		forrange(i,2,k+1){
			forrange(st,1,n+1){
				dnc(i,1,n,1,n,st);
			}
		}
	}

	int res = INF;

	forrange(st,1,n+1){
		res = min(res,dp[st][n][k]);
	}

	cout << res << endl;
}