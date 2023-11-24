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
#define int ll
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
	int x,y,wt;
};

void dijsktra(int u,vi dist,vector<vector<pii>> graph,vb visited){
	priority_queue<pii> q;

	q.push({0,u});

	while(!q.empty()){
		pii x = q.top();
		q.pop();

		if(visited[x.s]){ continue;}

		else{
			visited[x.s] = true;
			int sc = -x.f;

			for(pii j : graph[x.s]){
				if(sc + j.s < dist[j.f]){
					dist[j.f] = sc + j.s;
					q.p({-dist[j.f],j.f});
				}
			}
		}
	}
}


signed main(){
	int n,m;
	cin >> n >> m;

	vector<vector<pii>> graph1(n);
	vector<vector<pii>> graph2(n);
	vb visited1(n,false);
	vb visited2(n,false);

	vi dist1(n,10000000000);
	vi dist2(n,10000000000);
	vector<Edge> edges;

	forn(i,m){
		Edge e;
		int a,b,c;
		cin >> a >> b >> c;
		a--;
		b--;

		e.x = a;
		e.y = b;
		e.wt = c;

		graph1[a].pb({b,c});
		graph2[b].pb({a,c});
		edges.pb(e);
	}
	dijsktra(0,dist1,graph1,visited1);
	dijsktra(n-1,dist2,graph2,visited2);

	int mn = 10000000000;

	for(Edge j : edges){
		int curr = dist1[j.x] + dist2[j.y] + (j.wt/2);
		mn = min(mn,curr);
		dbgv(curr);
	}

	cout << mn << endl;
}