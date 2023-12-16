#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> T;
 
#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#pragma GCC optimize("trapv")

#define dbg(TXTMSG) cerr << "\n" << TXTMSG
#define dbgv(VARN) cerr << "\n" << #VARN << " = "<< VARN << ", line: " << __LINE__ << "\n"

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

struct BFS{
	int node, parent;
	char back;
};

int m,n;
vi dist;
vb visited;
vector<char> backtrack;
vi gg;
queue<BFS> q;
string grid;

void pushr(int nodes){
	BFS a;
	if(nodes % m != 0){
		a.node = nodes - 1; a.back = 'L'; a.parent = nodes;
		q.push(a);
	}

	if(nodes % m != m-1){
		a.node = nodes + 1; a.back = 'R'; a.parent = nodes;
		q.push(a);
	}

	a.node = nodes - m; a.back = 'U'; a.parent = nodes;
	q.push(a);

	a.node = nodes + m; a.back = 'D'; a.parent = nodes;
	q.push(a);
}

void bfs(int u){
	dist[u] = 0;
	gg[u] = -1;
	backtrack[u] = 'X';
	pushr(u);

	while(!q.empty()){
		BFS c = q.front();
		q.pop();

		if((c.node < 0) || (c.node >= m*n) || visited[c.node] || (grid[c.node] == '#')){
			continue;
		}

		else{
			visited[c.node] = true;
			dist[c.node] = dist[c.parent] + 1;
			backtrack[c.node] = c.back;
			gg[c.node] = c.parent;
			pushr(c.node);	
		}
	}
}

signed main(){
	setIO(); cin >> n >> m;

	cin >> grid;
	visited.assign(m*n,false);
	dist.resize(m*n);
	backtrack.resize(m*n);
	gg.resize(m*n);

	forrange(i,1,n){
		string s;
		cin >> s;
		grid = grid + s;
	}
	int start;
	int end;

	forn(i,m*n){
		if(grid[i] == 'A'){
			start = i;
		}

		if(grid[i] == 'B'){
			end = i;
		}
	}

	bfs(start);

	if(!visited[end]){
		cout << "NO" << endl;
		return 0;
	}

	vector<char> going_back;
	int k = end;
	while(k != start){
		going_back.pb(backtrack[k]);
		k = gg[k];
	}
	
	cout << "YES" << endl;
	cout << dist[end] << endl;

	int t = going_back.size();
	t--;
	for(int i = t; i >= 0; --i){
		cout << going_back[i];
	}
}