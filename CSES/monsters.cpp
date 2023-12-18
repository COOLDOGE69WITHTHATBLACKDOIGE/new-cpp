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

struct AB{
	int node; int parent; char back;
};

int n,m;
string grid;
vb visited;
vector<char> backtrack;
queue<AB> q;
vi sources;
vi dist;
vi bacc;

void pushr(int gh){
	AB c;

	if(gh % m != 0){
		c.node = gh - 1; 
		c.parent = gh; 
		c.back = 'L';
		q.push(c);
	}

	if(gh % m != m-1){
		c.node = gh + 1; 
		c.parent = gh; 
		c.back = 'R';
		q.push(c);
	}

	if(gh/m > 0){
		c.node = gh - m; 
		c.parent = gh; 
		c.back = 'U';
		q.push(c);
	}

	if(gh/m < n-1){
		c.node = gh + m; 
		c.parent = gh; 
		c.back = 'D';
		q.push(c);
	}
}

void multisource_bfs(){
	for(int k : sources){
		visited[k] = true;
		dist[k] = 0;
		pushr(k);
	}

	while(!q.empty()){
		AB c = q.front(); int nodes = c.node; int parents = c.parent; q.pop();

		if(visited[nodes] || grid[nodes] == '#'){
			continue;
		}

		else{
			visited[nodes] = true; dist[nodes] = dist[parents] + 1; backtrack[nodes] = 'M';
			pushr(nodes);
		}
	}
}

bool check(int nodes){
	return ((nodes % m == 0) || (nodes % m == m-1) || (nodes/m == 0) || (nodes/m == n-1));
}

int boundary = -1;

void monsters(int  u){
	visited[u] = true;
	dist[u] = 0;
	pushr(u);

	while(!q.empty()){
		AB c = q.front();
		int nodes = c.node; int parents = c.parent; q.pop();

		if(visited[nodes] || grid[nodes] == '#' || dist[nodes] <= dist[parents] + 1){
			continue;
		}

		else{
			visited[nodes] = true; dist[nodes] = dist[parents] + 1; backtrack[nodes] = c.back;
			bacc[nodes] = parents;
			pushr(nodes);
			if(check(nodes)){
				boundary = nodes;
				return;
			}
		}
	}
}

signed main(){
	setIO(); cin >> n >> m;
	cin >> grid;
	forrange(i,1,n){
		string st; cin >> st; grid = grid + st;
	}

	visited.assign(m*n,false); dist.resize(m*n); backtrack.resize(m*n); bacc.resize(m*n);

	int start;
	forn(i,m*n){
		if(grid[i] == 'M'){
			sources.pb(i);
		}

		if(grid[i] == 'A'){
			start = i;
		}
	}

	if(check(start)){
		cout << "YES" << endl;
		cout << 0 << endl;
		return 0;
	}
	dist.assign(m*n,MOD);
	multisource_bfs();

	visited.assign(m*n,false);
	monsters(start);

	if(boundary == -1){
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
	cout << dist[boundary] << endl;

	vector<char> track;
	while(boundary != start){
		track.pb(backtrack[boundary]);
		boundary = bacc[boundary];
	}

	for(int i = track.size() - 1; i >= 0; --i){
		cout << track[i];
	}
}