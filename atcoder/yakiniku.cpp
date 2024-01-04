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
const int N = 5e3 + 1;
const int LG = 13;

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int sparse_table[200][N][13];
int dp[N];
int dist[N];
int m;

int query(int a, int b, int t){
	int g = __lg(b-a+1);

	int l = a;
	int r = b;
	
	l--; r--;

	return max(sparse_table[t][l][g],sparse_table[t][r - (1 << g) + 1][g]);
}

int sum(int l, int r){
	int res = 0;

	forn(i,m){
		res += query(l,r,i);
	}

	return res;
}

void dnc(int l, int r, int optl, int optr){
	if(l > r){
		return;
	}

	int mid = (l+r)/2;
	dp[mid] = -INF;
	int opt = 1;

	forrange(j,optl,min(optr,mid)+1){
		if(dp[mid] < sum(j,mid) - dist[mid] + dist[j]){
			dp[mid] = sum(j,mid) + dist[j] - dist[mid];
			opt = j;
		}
	}

	dnc(l,mid-1,optl,opt);
	dnc(mid+1,r,opt,optr);
}

signed main(){
	setIO();
	int n;
	cin >> n >> m;

	int b[n][m];
	int d[n-1];

	forn(i,n-1){
		cin >> d[i];
	}
	dist[1] = 0;

	forrange(i,1,n){
		dist[i+1] = dist[i] + d[i-1];
	}

	forn(i,n){
		forn(j,m){
			cin >> b[i][j];
		}
	}

	forn(i,m){
		forn(j,n){
			sparse_table[i][j][0] = b[j][i];
		}
	}

	int L = __lg(n);

	forn(i,m){
		forrange(k,1,L+1){
			forn(j,n - (1 << k) + 1){
				sparse_table[i][j][k] = max(sparse_table[i][j][k-1],sparse_table[i][j + (1 << (k-1))][k-1]);
			}
		}
	}

	dnc(1,n,1,n);
	int c = 0;

	forrange(i,1,n+1){
		c = max(dp[i],c);
	}

	cout << c << endl;
}