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
const int INF = 1e17+1;

signed main(){
	setIO();
	string s1,s2;
	cin >> s1 >> s2;

	int n = s1.size(), m = s2.size();
	vvi dp(n+1,vi(m+1,INF));
	dp[0][0] = 0;

	forrange(i,1,m+1){
		dp[0][i] = min(dp[0][i],dp[0][i-1] + 1);
	}

	forrange(i,1,n+1){
		dp[i][0] = min(dp[i][0],dp[i-1][0] + 1);
	}

	forrange(i,1,n+1){
		forrange(j,1,m+1){
			dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
			dp[i][j] = min(dp[i][j],dp[i-1][j]+1);
			dp[i][j] = min(dp[i][j],dp[i-1][j-1]+(s1[i-1] != s2[j-1]));
		}
	}

	cout << dp[n][m] << endl;
}