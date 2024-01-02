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
const int N = 2e4 + 1;

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int dist[N];
int cst[N];
int psum[N];

int dp[N][3];

void dnc(int i, int l, int r, int optl, int optr){
	if(l > r){
		return;
	}

	int mid = (l+r)/2;

	int opt = 1;
	dp[mid][i] = INF;

	forrange(j,optl,min(mid,optr)+1){
		int ct = cst[mid] - cst[j] - ((psum[mid] - psum[j])*dist[j]);

		if(dp[mid][i] > dp[j-1][i-1] + ct){
			dp[mid][i] = dp[j-1][i-1] + ct;
			opt = j;
		}
	}

	dnc(i,l,mid-1,optl,opt);
	dnc(i,mid+1,r,opt,optr);
}

signed main(){
	setIO();
	int n;
	cin >> n;
	int k = 2;
	vi d(n); vi a(n);

	for(int i = n-1; i > -1; --i){
		cin >> a[i] >> d[i];
	}

	forrange(i,1,n+1){
		dist[i] = dist[i-1] + d[i-1];
		psum[i] = psum[i-1] + a[i-1];

		cst[i] = cst[i-1] + (dist[i]*a[i-1]);
	}

	forrange(i,1,n+1){
		dp[i][0] = cst[i];
	}

	forrange(i,1,k+1){
		dnc(i,1,n,1,n);
	}

	cout << dp[n][k] << endl;
}