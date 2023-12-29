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

int dp[5001][3];  //the increasing sequence from 0
int dp1[5001][3]; //the increasing sequence from n-1

//combine them both to get the answer :)

signed main(){
	setIO();
	int n; cin >> n;
	vi a(n);

	forn(i,n){
		cin >> a[i];
	}

	if(a[0] == 1){
		dp[0][1] = 1;
		dp[0][2] = 0;
	}

	else{
		dp[0][1] = 0;
		dp[0][2] = 1;
	}

	forrange(i,1,n){
		if(a[i] == 1){
			dp[i][1] = dp[i-1][1] + 1;
			dp[i][2] = dp[i-1][2];
		}

		else{
			dp[i][2] = max(dp[i-1][2] + 1, dp[i-1][1] + 1);
			dp[i][1] = dp[i-1][1];
		}
	}

	if(a[n-1] == 1){
		dp1[n-1][1] = 1;
		dp1[n-1][2] = 0;
	}

	else{
		dp1[n-1][1] = 0;
		dp1[n-1][2] = 1;
	}

	for(int j = n-2; j > -1; --j){
		if(a[j] == 1){
			dp1[j][1] = max(dp1[j+1][2] + 1, dp1[j+1][1] + 1);
			dp1[j][2] = dp1[j+1][2];
		}

		else{
			dp1[j][1] = dp1[j+1][1];
			dp1[j][2] = dp1[j+1][2] + 1;
		}
	}
	int ans = 0;
	forn(i,n){
		if(i == n-1){
			ans = max(ans,dp[n-1][1]); ans = max(ans,dp[n-1][2]);
		}

		else{
			ans = max(ans,dp[i][2] + dp1[i+1][1]);
		}
	}

	cout << ans << endl;
}