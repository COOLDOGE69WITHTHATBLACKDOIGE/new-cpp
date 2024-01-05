#include<bits/stdc++.h>
using namespace std;
 
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// template <class T>
// using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
// #define _GLIBCXX_DEBUG 1
// #define _GLIBCXX_DEBUG_PEDANTIC 1
// #pragma GCC optimize("trapv")
 
// #define dbg(TXTMSG) cerr << "\n" << TXTMSG
// #define dbgv(VARN) cerr << "\n" << #VARN << " = "<< VARN << ", line: " << __LINE__ << "\n"
 
#define int long long
#define forn(i,j) for(int i = 0; i < j; i++)
#define forrange(i,j,k) for(int i = j; i < k; ++i)
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define vvi vector<vi>
#define vvpii vector<vector<pii>>
#define vb vector<bool>
#define pb push_back
#define f first
#define s second
 
const int MOD = 1e9 + 7;
const int INF = 1e17 + 1;
const int maxN = 2e5 + 1;
 
void setIO(string name = ""){
	ios_base::sync_with_stdio(0); cin.tie(0);
	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin); freopen((name + ".out").c_str(), "w", stdout);
	}
}
 
int up_be[maxN];
int down_be[maxN];
int dp[maxN];
int p[maxN];
int depth[maxN];
vvi graph;
vb visited;
 
void dfs(int node, int parent, int deep){
	visited[node] = true;
	depth[node] = deep;
 
	for(int k : graph[node]){
		if(k != parent){
			if(visited[k]){
				if(depth[k] > depth[node]){
					continue;
				}
 
				else{
					down_be[k]++;
					up_be[node]++;
				}
			}
 
			else{
				p[k] = node;
				dfs(k,node,deep+1);
 
				dp[node] += dp[k];
			}
		}
	}
 
	dp[node] += up_be[node] - down_be[node];
}
 
signed main(){
	setIO();
	int n,m; cin >> n >> m;
 
	graph.resize(n); visited.assign(n,false);
 
	forn(i,m){
		int a,b;
		cin >> a >> b;
		a--,b--;
 
		graph[a].pb(b); graph[b].pb(a);
	}
 
	forn(i,n){
		if(!visited[i]){
			dfs(i,-1,0);
			p[0] = -1;
		}
	}
 
	int res = 0;
	vi ans;
 
	forn(i,n){
		if(dp[i] == 0 && (p[i] != -1)){
			res++;
			ans.pb(i);
		}
	}
 
	cout << res << endl;
 
	for(int k : ans){
		cout << k+1 << " " << p[k] + 1 << endl;
	}
}