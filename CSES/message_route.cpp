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
vi dist;
vi backtrack;
vb visited;

void bfs(int u){
	queue<pii> q;
	dist[u] = 1;
	backtrack[u] = -1;
	for(int i : graph[u]){
		q.push({i,u});
	}

	while(!q.empty()){
		int node = q.front().f; int parent = q.front().s;
		q.pop();

		if(visited[node]){
			continue;
		}

		else{
			visited[node] = true; 
			dist[node] = dist[parent] + 1; 
			backtrack[node] = parent;
			for(int k : graph[node]){
				q.push({k,node});
			}
		}
	}
}

signed main(){
	setIO(); int n,m;
	cin >> n >> m;
	graph.resize(n+1); visited.assign(n+1,false); dist.resize(n+1); backtrack.resize(n+1);

	forn(i,m){
		int a,b; cin >> a >> b;
		graph[a].pb(b); graph[b].pb(a);
	}

	bfs(1);

	if(!visited[n]){
		cout << "IMPOSSIBLE" << endl;
	}

	else{
		cout << dist[n] << endl;

		vi a;
		int k = n;
		while(k != 1){
			a.pb(k);
			k = backtrack[k];
		}

		cout << 1 << " ";

		for(int cd = a.size() - 1; cd >= 0; --cd){
			cout << a[cd] << " ";
		}
	}
}