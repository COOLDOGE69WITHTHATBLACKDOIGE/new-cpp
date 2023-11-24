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

vector<vector<pii>> graph;
vb visited;
vi backtrack;
vi freq;
vvi tre;
vi dist(10000,1000000);

void dijsktra(int u){
	priority_queue<pii> q;

	q.push({0,u});

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
					backtrack[j.f] = x.s;
				}

				else if(-x.f + j.s == dist[j.f]){
					backtrack[j.f] = max(backtrack[j.f],x.s);
				}
			}
		}
	}
}

void dfs(int node, int parent){
	for(int x : tre[node]){
		if(x != parent){
			dfs(x,node);

			freq[node] += freq[x];
		}
	}
}

int main(){
	setIO("input");
	int n,m,t;
	cin >> n >> m >> t;

	freq.resize(n);
	graph.resize(n);
	visited.resize(n,false);
	tre.resize(n);
	backtrack.resize(n);

	forn(i,n){
		cin >> freq[i];
	}

	forn(i,m){
		int a,b,t;
		cin >> a >> b >> t;
		a--;
		b--;
		graph[a].pb({b,t});
		graph[b].pb({a,t});
	}

	dist[0] = 0;

	dijsktra(0);

	forrange(i,1,n){
			tre[i].pb(backtrack[i]);
			tre[backtrack[i]].pb(i);
	}

	int mx = 0;
	dfs(0,-1);

	forn(i,n){
		mx = max(mx, freq[i]*(dist[i] - t));
	}

	cout << mx << endl;
}