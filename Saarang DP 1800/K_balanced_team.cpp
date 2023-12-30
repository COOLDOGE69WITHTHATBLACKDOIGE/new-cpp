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

int dp[5001][5001];

signed main(){
	setIO();
	int n,k;
	cin >> n >> k;

	vi a(n);

	forn(i,n){
		cin >> a[i];
	}

	sort(all(a));

	int ptr = 0;

	forrange(j,1,k+1){
		dp[0][j] = 1;
	}

	forrange(i,1,n){
		while(ptr < n-1 && (a[i] - a[ptr] > 5)){
			ptr++;
		}

		forrange(j,1,k+1){
			//do not take this guy in a team
			dp[i][j] = max(dp[i][j],dp[i-1][j]);

			//take this guy in a team

			if(ptr == 0){
				dp[i][j] = max(dp[i][j],i-ptr+1);
			}

			else{
				dp[i][j] = max(dp[i][j],dp[ptr-1][j-1] + (i-ptr+1));
			}
		}
	}

	cout << dp[n-1][k] << endl;
}