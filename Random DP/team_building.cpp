#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
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

#define MOD 1000000009

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

bool comp(int &a, int &b){
	return a > b;
}

signed main(){
	setIO("input");
	int n,m,k;
	cin >> n >> m >> k;

	vi a(n);
	vi b(m);

	forn(i,n){
		cin >> a[i];
	}

	forn(i,m){
		cin >> b[i];
	}

	sort(all(a));
	sort(all(b));


	vector<vvi> dp(n+1,vvi(m+1,vi(k+1,0)));

	forn(i,n+1){
		forn(j,m+1){
			dp[i][j][0] = 1;
		}
	}

	forn(i,n){
		forn(j,m){
			forrange(l,1,k+1){
				dp[i+1][j][l] += dp[i][j][l];
				dp[i][j+1][l] += dp[i][j][l];

				dp[i+1][j+1][l] -= dp[i][j][l];

				if(a[i+1] > b[j+1]){
					dp[i+1][j+1][l] += dp[i][j][l-1];
				}

				dp[i+1][j+1][l] += MOD;
				dp[i+1][j+1][l] %= MOD;
			}
		}
	}

	dp[n][m][k] += MOD;
	dp[n][m][k] %= MOD;

	cout << dp[n][m][k] << endl;
}