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
const int szze = 1e6+2;
vi dp1(szze,0);
vi dp2(szze,0);
int k = 1;

void solve(){
	int n;
	cin >> n;

	if(k >= n){
		int res = dp1[n] + dp2[n];
		res %= MOD;
		cout << res << endl;
	}

	else{
		forrange(i,k,n){
			dp1[i+1] += 2*dp1[i];
			dp1[i+1] += dp2[i];
			dp2[i+1] += dp1[i];
			dp2[i+1] += 4*dp2[i];

			dp1[i+1] %= MOD; dp2[i+1] %= MOD;
		}

		int res = dp2[n] + dp1[n];
		res %= MOD;
		k = n;

		cout << res << endl;
	}
}


signed main(){
	setIO();
	int t; cin >> t;
	dp1[1] = 1; dp2[1] = 1;
	while(t--){
		solve();
	}
}