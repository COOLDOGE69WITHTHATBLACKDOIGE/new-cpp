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
const int LOG = 22;
 
void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
 
vi euler_tour;
int depth[maxN];
int lg[4*maxN];
int st[maxN];
pii sparse_table[4*maxN][LOG];
vvi graph;
 
void initialize(){
	lg[1] = 0;
 
	forrange(i,2,4*maxN){
		int j = i/2;
		lg[i] = lg[j] + 1;
	}
}
 
void dfs(int node, int parent){
	st[node] = euler_tour.size();
	euler_tour.pb(node);
	for(int k : graph[node]){
		if(k != parent){
			depth[k] = depth[node] + 1;
			dfs(k,node);
			euler_tour.pb(node);
		}
	}
}
 
int query(int left, int right){
	if(left > right){
		swap(left,right);
	}
 
	int diff = right - left + 1;
	int t1 = sparse_table[left][lg[diff]].f; int t2 = sparse_table[right-(1 << lg[diff])+1][lg[diff]].f;
 
	if(t1 < t2){
		return sparse_table[left][lg[diff]].s;
	}
 
	return sparse_table[right-(1<<lg[diff])+1][lg[diff]].s;
}
 
signed main(){
	setIO(); int n,q; cin >> n >> q; graph.resize(n);
 
	forn(i,n-1){
		int a,b; cin >> a >> b; a--,b--;
		graph[a].pb(b); graph[b].pb(a);
	}
 
	initialize();
	dfs(0,-1);
 
	forn(i,euler_tour.size()){
		sparse_table[i][0] = {depth[euler_tour[i]],euler_tour[i]};
	}

	int k = lg[euler_tour.size()];

	forrange(j,1,k+1){
		forn(i,euler_tour.size() - (1 << j) + 1){
			if(sparse_table[i][j-1].f < sparse_table[i + (1<<j-1)][j-1].f){
				sparse_table[i][j] = sparse_table[i][j-1];
			}

			else{
				sparse_table[i][j] = sparse_table[i +(1<<j-1)][j-1];
			}
		}
	}
 
	while(q--){
		int a,b; cin >> a >> b; a--,b--;
 
		int lca = query(st[a],st[b]);
 
		cout << depth[a] + depth[b] - depth[lca] - depth[lca] << endl;
	}
}