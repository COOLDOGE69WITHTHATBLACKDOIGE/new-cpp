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
 
struct Edge{
	int st,en,power;
};
 
int n,m;
vi dist;
vvi ulta;
vb visited1;
vb visited2;
vector<Edge> E;
int neg_cycle = 0;
 
void dfs(int u, vb visited){
	visited[u] = true;
 
	for(int k : ulta[u]){
		if(!visited[k]){
			dfs(k,visited);
		}
	}
}
 
void bellman_ford(int start){
	dist[start] = 0;
 
	forn(i,n-1){
		for(Edge e : E){
			int a = e.st; int b = e.en; int w = e.power;
			dist[b] = min(dist[b],dist[a] + w);
		}
	}
	vi prev = dist;
 
	forn(i,n-1){
		for(Edge e : E){
			int a = e.st; int b = e.en; int w = e.power;
			dist[b] = min(dist[b],dist[a] + w);
		}
	}
 
	forrange(i,1,n+1){
		if(prev[i] > dist[i]){
			if(visited1[i] && visited2[i]){
				neg_cycle++;
			}
		}
	}
}
 
signed main(){
	setIO("input"); cin >> n >> m;
	dist.assign(n+1,INF); ulta.resize(n+1); visited1.assign(n+1,false); visited2.assign(n+1,false);
 
	forn(i,m){
		int a,b,c; cin >> a >> b >> c; c = -c;
		Edge k; k.st = a; k.en = b; k.power = c;
		ulta[b].pb(a);
		E.pb(k);
	}
 
	dfs(n,visited1); dfs(1,visited2);
	bellman_ford(1);
 
	if(neg_cycle){
		cout << -1 << endl;
		return 0;
	}
 
	else{
		cout << -dist[n] << endl;
	}
}