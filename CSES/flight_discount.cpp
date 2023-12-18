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

struct edge{
	int start,end,power;
};

int n;
vvpii graph;
vvpii ulta;
vi visited;

vi djisktra(int u){
	vi dist(n+1,INF);

	pqpii pq;
	pq.push({0,u});

	while(!pq.empty()){
		pii b = pq.top(); pq.pop();
		int node = b.s; int d = -b.f;

		if(visited[node]){
			continue;
		}

		else{
			visited[node] = true; dist[node] = d;

			for(pii j : graph[node]){
				pq.push({-d-j.s,j.f});
			}
		}
	}

	return dist;
}

vi djisktra2(int u){
	vi dist(n+1,INF);

	pqpii pq;
	pq.push({0,u});

	while(!pq.empty()){
		pii b = pq.top(); pq.pop();
		int node = b.s; int d = -b.f;

		if(visited[node]){
			continue;
		}

		else{
			visited[node] = true; dist[node] = d;

			for(pii j : ulta[node]){
				pq.push({-d-j.s,j.f});
			}
		}
	}

	return dist;
}

signed main(){
	setIO(); int m; cin >> n >> m;

	vector<edge> E;
	graph.resize(n+1); visited.assign(n+1,false); ulta.resize(n+1);
	forn(i,m){
		int a,b,c; cin >> a >> b >> c;
		graph[a].pb({b,c});
		ulta[b].pb({a,c});

		edge h; h.start = a; h.end = b; h.power = c;
		E.pb(h);
	}

	vi dist1 = djisktra(1);
	visited.assign(n+1,false);
	vi dist2 = djisktra2(n);

	int mn = INF;

	for(edge K : E){
		int t = K.power; t /= 2;
		mn = min(mn,dist1[K.start] + dist2[K.end] + t);
	}

	cout << mn << endl;
}