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
	setIO();
	int n,k;
	cin >> n >> k;

	vi stable;

	forn(i,k){
		int a; cin >> a; stable.pb(a);
	}

	stable.pb(0);
	stable.pb(n+1);

	sort(all(stable));

	vvi dp(k+2,vi(k+2,MOD));

	forn(i,k+2){
		dp[i][i] = 0;
	}

	forrange(len,1,k+2){
		forn(l,k+2-len){
			int r = l + len;

			if(r == l+1){
				dp[l][r] = (r - l - 1);
			}

			else{
				forrange(j,l,r+1){
					dp[l][r] = min(dp[l][r], dp[l][j] + dp[j][r] + stable[r] - stable[l] - 1);
				}
			}
		}
	}

	cout << dp[0][k+1] << endl;
}