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
int et[maxN];
int bit[maxN+2];
int p[maxN][LOG];
int timer = 0;
vvi graph;

void update(int idx, int val){
	while(idx < maxN + 2){
		bit[idx] += val;
		idx += idx&-idx;
	}
}

int query(int idx){
	int res = 0;
	while(idx > 0){
		res += bit[idx];
		idx -= idx&-idx;
	}

	return res;
}

void dfs(int node, int parent){
	st[node] = ++timer;

	for(int k : graph[node]){
		if(k != parent){
			p[k][0] = node;
			dfs(k,node);
		}
	}

	et[node] = timer;
}

bool ancestor(int a, int b){
	return (st[a] < st[b] && et[a] >= et[b]);
}

int lca(int a, int b){
	if(ancestor(a,b)){
		return a;
	}

	else if(ancestor(b,a)){
		return b;
	}

	for(int i = LOG; i >= 0; --i){
		if(!ancestor(p[a][i],b)){
			a = p[a][i];
		}
	}	

	return p[a][0];
}

signed main(){
	setIO();
	int n,q;
	cin >> n >> q; graph.resize(n);

	vi value(n);

	forn(i,n){
		cin >> value[i];
	}

	forn(i,n-1){
		int a,b; cin >> a >> b;
		a--,b--;
		graph[a].pb(b); graph[b].pb(a);
	}

	dfs(0,-1);
	p[0][0] = 0;

	forrange(j,1,LOG){
		forrange(i,1,n){
			p[i][j] = p[p[i][j-1]][j-1];
		}
	}

	forn(i,n){
		update(st[i],value[i]);
		update(et[i] + 1,-value[i]);
	}

	while(q--){
		int type;
		cin >> type;

		if(type == 1){
			int node,x; cin >> node >> x;
			node--;

			update(st[node],-value[node]);
			update(et[node]+1,value[node]);

			value[node] = x;

			update(st[node],value[node]);
			update(et[node]+1,-value[node]);
		}

		else{
			int node; cin >> node; node--;

			cout << query(st[node]) << endl;
		}
	}
}