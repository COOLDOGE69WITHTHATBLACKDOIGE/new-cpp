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
const int LOG = 20;

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int st[maxN];
vi euler_tour;
int height[maxN];
int lg[maxN];
vvi graph;
pii sparse_table[maxN][LOG];

void initialize(){
	lg[1] = 0;

	forrange(i,2,2*maxN){
		int j = i/2;
		lg[i] = lg[j] + 1;
	}
}

void dfs(int node, int parent){
	st[node] = euler_tour.size();
	euler_tour.pb(node);
	for(int k : graph[node]){
		if(k != parent){
			height[k] = height[node] + 1;
			dfs(k,node);
			euler_tour.pb(node);
		}
	}
}

pii process(pii &a, pii &b){
	if(a.f < b.f){
		return a;
	}

	return b;
}

int lca(int left, int right){
	int l = left; int r = right;
	if(l > r){
		swap(l,r);
	}

	int diff = lg[r-l+1];

	pii cg = process(sparse_table[l][diff],sparse_table[r-(1 << diff)+1][diff]);

	return cg.s;
}

signed main(){
	setIO("input"); int n,q; cin >> n >> q; graph.resize(n);

	forn(i,n-1){
		int a,b; cin >> a >> b; a--,b--;
		graph[a].pb(b); graph[b].pb(a);
	}
	
	initialize();
	// dfs(0,-1);

	forn(i,euler_tour.size()){
		sparse_table[i][0] = {height[euler_tour[i]],euler_tour[i]};
	}

	int k = lg[euler_tour.size()];

	forrange(j,1,k){
		forn(i,euler_tour.size()){
			sparse_table[i][j] = process(sparse_table[i][j-1],sparse_table[i + (1 << j-1)][j-1]);
		}
	}

	// while(q--){
	// 	int a,b; cin >> a >> b; a--,b--;

	// 	cout << lca(st[a],st[b]) + 1 << endl;
	// }
}