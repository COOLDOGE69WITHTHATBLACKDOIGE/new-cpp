#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#pragma GCC optimize("trapv")

#define dbg(TXTMSG) cerr << "\n" << TXTMSG
#define dbgv(VARN) cerr << "\n" << #VARN << " = "<< VARN << ", line: " << __LINE__ << "\n"

#define ll long long
#define ld long double
#define int long long
#define forn(i,j) for(ll i = 0; i < j; i++)
#define forrange(i,j,k) for(int i = j; i < k; ++i)
#define rof(i,j) rof(int i = j; i >= 0; --i)
#define pii pair<int,int>
#define vll vector<ll>
#define vi vector<int>
#define vvll vector<vll>
#define vvi vector<vi>
#define vb vector<bool>
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define eb emplace_back
#define qi queue<int>
#define qpii queue<pii>

#define MOD 1000000007

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

struct Edge{
	int x,y,cost,flow;
};

bool comp(Edge &a, Edge &b){
	return a.flow > b.flow;
}

vector<vector<pii>> graph;

vi dijsktra(int u, vi dist, vb visited){
	priority_queue<pii> q;

	q.push({0LL,u});

	while(!q.empty()){
		pii x = q.top();
		q.pop();

		if(visited[x.s]){
			continue;
		}

		else{
			visited[x.s] = true;
			for(pii j : graph[x.s]){
				if(-x.f + j.s < dist[j.f]){
					dist[j.f] = -x.f + j.s;
					q.push({-dist[j.f],j.f});
				}
			}
		}
	}

	return dist;
}

signed main(){
	setIO("pump");
	int n,m;
	cin >> n >> m;

	graph.resize(n);
	vector<Edge> e(m);

	forn(i,m){
		Edge k;
		cin >> k.x >> k.y >> k.cost >> k.flow;
		k.x--;
		k.y--;

		e[i] = k;
	}

	sort(all(e),comp);
	int ans = 0;
	int prev = 100000000;

	vi dist(n,100000000);
	vb visited(n,false);

	forn(i,m){
		
		dist[0] = 0;

		graph[e[i].x].pb({e[i].y, e[i].cost});

		graph[e[i].y].pb({e[i].x, e[i].cost});

		vi b = dijsktra(0,dist,visited);

		//if the min distance has not decreased, it means there is no use of taking this edge as a min edge

		if(b[n-1] == prev){
			continue;
		}

		//if the min distance has decreased, we can try to see whether the ratio has increased or not (if it has decreased, it means it has the new min edge in between)

		else{
			int k = (1'000'000)*(e[i].flow);
			int h = k;
			h /= b[n-1];

			ans = max(ans,h);
			prev = b[n-1];
		}
	}

	cout << ans << endl;
}