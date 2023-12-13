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

#define MOD 1000000007

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

signed main(){
	int n;
	cin >> n;

	vi val(n);

	forn(i,n){
		cin >> value[i];
	}

	int m;
	cin >> m;

	vi b(m);

	forn(i,m){
		cin >> b[i];
	}

	vvi dp(n+1,vi((1 << m),MOD));

	dp[0][0] = 0;

	forrange(i,1,n+1){
		forn(j,(1<<m)){
			forn(k,m){
				if(j & (1 << k)){
					int t = j ^ (1 << k);
					int res;

					if(i == 0 || i == n-1){
						res = 0;
					}

					else{
						if(b[k] < value[i-1] && b[k] < value[i+1]){
							res = 1;
						}

						else if(b[k] > value[i-1] && b[k] > value[i+1]){
							res = 1;
						}
					}

					dp[i][j] = min(dp[i][j],dp[i-1][t] + res);
					dp[i][j] = min(dp[i-1][j],dp[i][j]);
				}
			}
		}
	}

	cout << dp[n-1][(1 << m)-1] << endl;
}