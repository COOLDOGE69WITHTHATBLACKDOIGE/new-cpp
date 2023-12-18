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
const int LOG = 30;

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

vi visited;
vvi graph;

struct NODE{
	int cycle_size; int parent; int cycle_dist;
	bool is_tree; bool is_cycle; int conn_comp; int cycle_ind;
};

NODE nd[maxN];
int t = 0;

void dfs(int u){
	stack<int> st;
	stack<int> q;
	visited[u] = true; nd[u].is_tree = true; nd[u].is_cycle = false; nd[u].conn_comp = t; q.push(u);
	int cyc = 0;
	st.push(u);

	while(!st.empty()){
		int k = st.top(); st.pop();

		for(int x : graph[k]){
			if(visited[x] == 2){
				if(nd[x].conn_comp != nd[k].conn_comp){
					while(!q.empty()){
						int jk = q.top(); q.pop();
						nd[jk].conn_comp = nd[x].conn_comp; nd[jk].cycle_size = nd[x].cycle_size;
						nd[jk].parent = x;
						nd[jk].cycle_dist = nd[graph[jk][0]].cycle_dist + 1;
					}

					return;
				}

				else{
					while(!q.empty()){
						int jk = q.top(); q.pop();
						if(nd[jk].is_cycle){
							nd[jk].cycle_dist = 0; nd[jk].parent = jk; nd[jk].cycle_size = cyc;
						}

						else{
							nd[jk].cycle_dist = nd[graph[jk][0]].cycle_dist + 1; nd[jk].parent = nd[graph[jk][0]].parent;
							nd[jk].cycle_size = cyc;
						}
					}

					return;
				}
			}

			else if(visited[x]){
				if(nd[x].conn_comp != nd[k].conn_comp){
					while(!q.empty()){
						int nodes = q.top(); q.pop();
						nd[nodes].conn_comp = nd[x].conn_comp;
						nd[nodes].cycle_size = nd[x].cycle_size;
						nd[nodes].cycle_dist = nd[graph[nodes][0]].cycle_dist + 1;
						nd[nodes].parent = nd[x].parent;
					}

					return;
				}

				cyc++;
				visited[x]++;
				nd[x].is_cycle = true; nd[x].is_tree = false;
				nd[x].cycle_ind = cyc;
				st.push(x);
			}

			else if(!visited[x]){
				visited[x]++;
				nd[x].is_tree = true; nd[x].is_cycle = false; nd[x].conn_comp = t;
				st.push(x); q.push(x);
			}
		}
	}
}


signed main(){
	setIO("input"); int n,q; cin >> n >> q; graph.resize(n+1); visited.assign(n+1,0);
	forrange(i,1,n+1){
		int b; cin >> b; graph[i].pb(b);
	}

	forrange(i,1,n+1){
		if(!visited[i]){
			dfs(i);
		}

		if(nd[i].conn_comp == t){
			t++;
		}
	}

	forrange(i,1,n+1){
		cout << nd[i].cycle_dist + nd[i].cycle_size << " ";
	}
}