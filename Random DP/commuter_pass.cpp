#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
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

#define MOD 1000000007

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

vi du;
vi dv;
vi ds;

vector<vector<pii>> graph;
vb visited;


vi djikstra1(int u, int size){
	vi dist(size);
	visited.assign(size,false);
	dist[u] = 0;
	pqpii pq;

	pq.push({0,u});

	while(!pq.empty()){
		pii x = pq.top();
		pq.pop();

		if(!visited[x.s]){
			dist[x.s] = -x.f;
			visited[x.s] = true;

			for(pii y: graph[x.s]){
				int node = y.f;
				int cost = y.s;

				pq.push({x.f - cost, node});
			}
		}
	}

	return dist;
}

int djikstra2(int u, int size, int end,int end2){
	visited.assign(size,false);
	pqpii pq;
	vi dpu(size);
    vi dpv(size);
 
    int ans = du[end2];
 
	pq.push({0,u});
 
	forn(i,size){
		dpu[i] = du[i];
		dpv[i] = dv[i];
	}
 
	while(!pq.empty()){
		pii x = pq.top();
		pq.pop();
 
		if(!visited[x.s]){
			visited[x.s] = true;
 
			for(pii j : graph[x.s]){
				int node = j.f;
				int cost = j.s;
				if(-x.f + cost == ds[node]){
					if(min(du[node],dpu[x.s]) + min(dv[node],dpv[x.s]) <= dpu[node] + dpv[node]){
						dpu[node] = min(du[node],dpu[x.s]);
						dpv[node] = min(dv[node],dpv[x.s]);
					}
 
					pq.push({-ds[node],node});
				}
			}
		}
	}
 
	ans = min(ans,dpu[end]+dpv[end]);
 
	return ans;
}

signed main(){
	setIO();
	int n,m,s,t,u,v;
	cin >> n >> m;

	cin >> s >> t;

	cin >> u >> v;

	s--;
	t--;
	u--;
	v--;

	graph.resize(n);
	visited.resize(n);

	forn(i,m){
		int a,b,c;

		cin >> a >> b >> c;
		a--,b--;

		graph[a].pb({b,c});
		graph[b].pb({a,c});
	}

	ds = djikstra1(s,n);
	du = djikstra1(u,n);
	dv = djikstra1(v,n);

	int res = djikstra2(s,n,t,v);
	cout << res << endl;
}