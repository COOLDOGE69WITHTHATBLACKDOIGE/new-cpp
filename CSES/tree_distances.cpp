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

pii dp[maxN];
vvi graph;
int dp2[maxN];

void dfs(int node, int parent){
	for(int k : graph[node]){
		if(k != parent){
			dfs(k,node);

			if(dp[k].f + 1 > dp[node].f){
				int prev = dp[node].f;
				dp[node].f = dp[k].f + 1;
				dp[node].s = max(dp[node].s,prev);
			}

			else{
				dp[node].s = max(dp[node].s,dp[k].f + 1);
			}
		}
	}
}

void dfs2(int node, int parent){
	for(int k : graph[node]){
		if(k != parent){
			if(dp[k].f + 1 != dp[node].f){
				dp2[k] = max(dp2[k],dp[node].f + 1);
			}

			else{
				dp2[k] = max(dp2[k],dp[node].s + 1);
			}

			dp2[k] = max(dp2[k],dp2[node]+1);

			dfs2(k,node);
		}
	}
}

signed main(){
	setIO(); int n; cin >> n;
	graph.resize(n);

	forn(i,n-1){
		int a,b; cin >> a >> b; a--,b--;
		graph[a].pb(b); graph[b].pb(a);
	}

	dfs(0,-1);
	dp2[0] = 0;
	dfs2(0,-1);

	forn(node,n){
		cout << max(dp[node].f,dp2[node]) << " ";
	}
}