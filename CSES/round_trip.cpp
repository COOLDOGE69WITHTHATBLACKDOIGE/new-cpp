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
 
void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
 
vvi graph;
vb visited;
vi parent;
pii ab = {0,0};
 
void dfs(int u){
	visited[u] = true;
 
	for(int k : graph[u]){
		if(k != parent[u]){
			if(visited[k]){
				ab = {k,u};
				return;
			}
 
			else{
				parent[k] = u; dfs(k);
			}
		}
	}
}
 
signed main(){
	setIO(); int n,m; cin >> n >> m;
	graph.resize(n+1); visited.assign(n+1,false); parent.resize(n+1);
 
	forn(i,m){
		int a,b; cin >> a >> b; graph[a].pb(b); graph[b].pb(a);
	}
	forrange(i,1,n+1){
		if(!visited[i] && (ab.f == 0) && (ab.s == 0)){
			parent[i] = 0;
			dfs(i);
		}
	}
 
	if(ab.f == 0 && ab.s == 0){
		cout << "IMPOSSIBLE" << endl;
		return 0; 
	}
 
	int start = ab.f; int end = ab.s;
	vi a;
	while(start != end && start != 0){
		a.pb(start); start = parent[start];
	}
	a.pb(end);
 
	cout << a.size()+1 << endl;
 
	for(int k : a){
		cout << k << " ";
	}
 
	cout << ab.f;
}