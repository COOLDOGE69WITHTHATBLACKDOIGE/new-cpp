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

int freq[maxN];
int bit[maxN];
int ka;
int kb;
int ans = 0;

void update(int idx, int val){
	while(idx < maxN){
		bit[idx] += val;
		idx += idx&-idx;
	}
}

int query(int idx){
	if(idx < 0){
		return 0;
	}

	int res = 1;

	while(idx > 0){
		res += bit[idx];
		idx -= idx&-idx;
	}

	return res;
}

int subtree[maxN];
bool processed[maxN];
vvi graph;

void dfs(int node, int parent){
	subtree[node] = 1;

	for(int k : graph[node]){
		if(k != parent && !processed[k]){
			dfs(k,node);
			subtree[node] += subtree[k];
		}
	}
}

int find_centroid(int node, int parent, int sz){
	for(int k : graph[node]){
		if(k != parent && !processed[k] && subtree[k] > sz){
			return find_centroid(k,node,sz);
		}
	}

	processed[node] = true;
	return node;
}

void cnt(int node, int parent, bool t, int depth){
	if(depth > ka){
		return;
	}

	if(t){
		freq[depth]++;
		update(depth,1);
	}

	else{
		ans += query(ka-depth) - query(kb - depth - 1);
	}

	for(int k : graph[node]){
		if(k != parent && !processed[k]){
			cnt(k,node,t,depth+1);
		}
	}
}

void centroid_decomp(int node){
	dfs(node,-1);
	int sz = subtree[node]/2;
	int centroid = find_centroid(node,-1,sz);

	for(int ku : graph[centroid]){
		cnt(ku,centroid,false,1);
		cnt(ku,centroid,true,1);
	}

	forrange(i,1,maxN){
		if(freq[i] == 0){
			break;
		}

		update(i,-freq[i]);
		freq[i] = 0;
	}

	for(int x : graph[centroid]){
		if(!processed[x]){
			centroid_decomp(x);
		}
	}
}

signed main(){
	setIO();
	int n;
	cin >> n >> kb >> ka; graph.resize(n);

	forn(i,n-1){
		int a,b; cin >> a >> b; a--,b--;
		graph[a].pb(b);
		graph[b].pb(a);
	}

	centroid_decomp(0);

	cout << ans << endl;
}