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

int dp[3001][3001];
int psum[3001];

void dnc(int i, int l, int r, int optl, int optr){
	if(l > r){
		return;
	}

	int mid = (l+r)/2;
	dp[i][mid] = INF;
	int opt = 1;

	forrange(j,optl,min(mid,optr)+1){
		int sum = psum[mid] - psum[j];
		sum *= sum;

		if(sum + dp[i-1][j] < dp[i][mid]){
			dp[i][mid] = sum + dp[i-1][j];
			opt = j;
		}
	}

	dnc(i,l,mid-1,optl,opt);
	dnc(i,mid+1,r,opt,optr);
}

signed main(){
	setIO();
	int n,k; cin >> n >> k;

	vi a(n);

	forn(i,n){
		cin >> a[i];

		psum[i+1] = psum[i] + a[i];
	}

	dp[0][0] = 0;

	forrange(i,1,n+1){
		dp[0][i] = INF;
	}

	forrange(i,1,k+1){
		dnc(i,1,n,0,n-1);
	}

	cout << dp[k][n] << endl;
}