#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> T;
 
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
	int n,x;
	cin >> n >> x;
	vpii dp((1<<n),{n,x}); vi a(n);
	dp[0] = {0,x};

	forn(i,n){
		cin >> a[i];
		dp[(1 << i)] = {1,x-a[i]};
	}

	forrange(mask,1,(1 << n)){
		if(__builtin_popcount(mask) == 1){
			continue;
		}

		else{
			forn(i,n){
				if((1 << i) & mask){
					int t = mask ^ (1 << i);
					if(a[i] <= dp[t].s){
						if(dp[mask].f > dp[t].f){
							dp[mask].f = dp[t].f;
							dp[mask].s = dp[t].s - a[i];
						}

						else if(dp[mask].f == dp[t].f){
							dp[mask].s = max(dp[mask].s,dp[t].s - a[i]);
						}
					}

					else{
						if(dp[mask].f > dp[t].f + 1){
							dp[mask].f = dp[t].f + 1;
							dp[mask].s = x - a[i];
						}

						else if(dp[mask].f == dp[t].f + 1){
							dp[mask].s = max(x - a[i],dp[mask].s);
						}
					}
				}
			}
		}
	}

	cout << dp[(1 << n) - 1].f << endl;
}