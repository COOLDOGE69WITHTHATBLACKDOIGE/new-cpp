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
#define qi queue<int>

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

signed main(){
	setIO(); int n,m; cin >> n >> m; graph.resize(n);

	vi in_degree(n,0);
	vi dist(n,-INF);
	vi p(n);
	dist[0] = 1;

	forn(i,m){
		int a,b; cin >> a >> b; a--,b--;
		graph[a].pb(b);
		in_degree[b]++;
	}

	qi q;

	forn(i,n){
		if(in_degree[i] == 0){
			q.push(i);
		}
	}

	while(!q.empty()){
		int node = q.front(); q.pop();

		for(int x : graph[node]){
			in_degree[x]--;

			if(dist[x] < dist[node] + 1){
				dist[x] = dist[node] + 1;
				p[x] = node;
			}

			if(in_degree[x] == 0){
				q.push(x);
			}
		}
	}

	if(dist[n-1] < 0){
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}

	cout << dist[n-1] << endl;
	vi backtrack;
	int j = n-1;
	backtrack.pb(j);
	while(j != 0){
		j = p[j];
		backtrack.pb(j);
	}
	reverse(all(backtrack));

	for(int k : backtrack){
		cout << k+1 << " ";
	}
}