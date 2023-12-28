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
 
int n,k;
int subtree[maxN];
bool processed[maxN];
vvi graph;
int res = 0;
vi freq(maxN,0);
 
void dfs(int node,int parent){
	subtree[node] = 1;
 
	for(int tu : graph[node]){
		if(tu != parent && !processed[tu]){
			dfs(tu,node);
			subtree[node] += subtree[tu];
		}
	}
}
 
int find_centroid(int sz, int node, int parent){
	for(int ju : graph[node]){
		if(ju != parent && !processed[ju] && (subtree[ju] > sz)){
			return find_centroid(sz,ju,node);
		}
	}
 
	processed[node] = true;
	return node;
}
 
void cnt_res(int node, int parent, bool t, int depth){
	if(depth > k){
		return;
	}

	if(t){
		freq[depth]++;
	}

	else{
		res += freq[k-depth];
	}
 
	for(int yu : graph[node]){
		if(yu != parent && !processed[yu]){
			cnt_res(yu,node,t,depth+1);
		}
	}
}
 
void centroid_decomp(int node){
	dfs(node,-1);
	int ty = subtree[node]/2;
	int centroid = find_centroid(ty,node,-1);

	freq[0] = 1;

	for(int yu : graph[centroid]){
		if(!processed[yu]){
			cnt_res(yu,centroid,false,1);
			cnt_res(yu,centroid,true,1);
		}
	}

	forn(i,n+1){
		if(freq[i] == 0){
			break;
		}

		freq[i] = 0;
	}
 
	for(int yu : graph[centroid]){
		if(!processed[yu]){
			centroid_decomp(yu);
		}
	}
}
 
signed main(){
	setIO();
	cin >> n >> k;
	graph.resize(n);
 
	forn(i,n-1){
		int a,b; cin >> a >> b;
		a--,b--;
		graph[a].pb(b);
		graph[b].pb(a);
	}

	centroid_decomp(0);
 
	cout << res << endl;
}