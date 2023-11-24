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

const int MOD = 1000000007;

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

vb visited;
vi dist;
vector<vector<pii>> graph;

void dijsktra(int u){
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
	setIO();
	int n,m;
	cin >> n >> m;

	graph.resize(n);
	visited.resize(n,false);

	dist.resize(n,(int)1e18);

	forn(i,m){
		int a,b,c;
		cin >> a >> b >> c;
		a--;
		b--;

		graph[a].pb({b,c});
	}

	dist[0] = 0;
	dijsktra(0);

	forn(i,n){
		cout << dist[i] << " ";
	}
}