#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
// #define _GLIBCXX_DEBUG 1
// #define _GLIBCXX_DEBUG_PEDANTIC 1
// #pragma GCC optimize("trapv")

// #define dbg(TXTMSG) cerr << "\n" << TXTMSG
// #define dbgv(VARN) cerr << "\n" << #VARN << " = "<< VARN << ", line: " << __LINE__ << "\n"

#define ll long long
#define ld long double
#define forn(i,j) for(ll i = 0; i < j; i++)
#define forrange(i,j,k) for(int i = j; i < k; ++i)
#define rof(i,j) rof(int i = j; i >= 0; --i)
#define pii pair<int,int>
#define vll vector<ll>
#define vi vector<int>
#define vvll vector<vll>
#define vvi vector<vi>
#define vb vector<bool>
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define eb emplace_back
#define qi queue<int>
#define qpii queue<pii>

const ll MOD = (ll)1e9+7;

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int32_t main(){
	int n, l;
	cin >> n >> l;

	vi x(n+1);
	vi t(n+1);

	x[0] = 0;
	t[0] = 0;

	forrange(i,1,n+1){
		cin >> x[i];
	}

	forrange(i,1,n+1){
		cin >> t[i];
	}

	ll dp1[n+1][n+1][n+1];
	ll dp2[n+1][n+1][n+2];

	forn(i,n+1){
		forn(j,n+1){
			forn(k,n+2){
				dp1[i][j][k] = MOD;
				dp2[i][j][k] = MOD;
			}
		}
	}

	//1 -- joi kun ends at left
	//2 -- joi kun ends at right

	dp1[0][0][0] = 0;
	dp2[0][0][0] = 0;

	int it = 0;
	forn(j,n+1){
		forn(k,n+2){
			dp1[n][j][k + (l - x[n] <= t[n])] = min(dp1[n][j][k + (l - x[n] <= t[n])], dp1[it][j][k] + (l - x[n]));

			dp1[n][j][k + (l - x[n] + x[j] <= t[n])] = min(dp1[n][j][k + (l - x[n] + x[j] <= t[n])], dp2[it][j][k] + l - x[n] + x[j]);
		}
	}

	for(int i = n; i > 0; --i){
		forn(j,n){
			forn(k,n+2){
				dp1[i-1][j][k + (dp1[i][j][k] + x[i] - x[i-1] <= t[i-1])] = min(dp1[i-1][j][k + (dp1[i][j][k] + x[i] - x[i-1] <= t[i-1])], dp1[i][j][k] + x[i] - x[i-1]);
				dp1[i-1][j][k + (dp2[i][j][k] + l - x[i-1] + x[j] <= t[n])] = min(dp1[i-1][j][k + (dp2[i][j][k] + l - x[i-1] + x[j] <= t[n])], dp2[i][j][k] + l - x[i-1] + x[j]);

				dp2[i][j+1][k + (dp2[i][j][k] + x[j+1] - x[j] <= t[j+1])] = min(dp2[i][j+1][k + (dp2[i][j][k] + x[j+1] - x[j] <= t[j+1])], dp2[i][j][k] + x[j+1] - x[j]);
				dp2[i][j+1][k + (dp1[i][j][k] + (l - x[i]) + x[j+1] <= t[j+1])] = min(dp2[i][j+1][k + (dp1[i][j][k] + (l - x[i]) + x[j+1] <= t[j+1])], dp1[i][j][k] + (l - x[i]) + x[j+1]);			
			}
		}
	}

	ll ans = 0;

	forn(i,n+1){
		forn(j,n+1){
			forn(k,n+1){
				if((dp1[i][j][k] != MOD) || (dp2[i][j][k] != MOD)){
					ans = max(ans,k);
				}
			}
		}
	}

	cout << ans << endl;
}