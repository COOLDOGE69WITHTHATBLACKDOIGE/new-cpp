#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#pragma GCC optimize("O3")

#pragma GCC optimize("unroll-loops")
 
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
#define vll vector<ll>
#define vi vector<int>
#define vvll vector<vll>
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

const int MOD = (int)1e9 + 7;

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

vi freq;
vi mn;
vi mx;
vvpii graph;
vb visited;
vi dist;

void dijkstra(int u){
	priority_queue<pii> q;

	q.push({0LL,u});
	freq[u] = 1;

	while(!q.empty()){
		pii x = q.top();
		q.pop();

		if(visited[x.s]){
			continue;
		}

		else{
			visited[x.s] = true;

			for(pii j : graph[x.s]){
				if(dist[j.f] == -x.f + j.s){
					freq[j.f] += freq[x.s] % MOD;
					freq[j.f] %= MOD;
					mn[j.f] = min(mn[j.f], mn[x.s] + 1);
					mx[j.f] = max(mx[j.f], mx[x.s] + 1);
				}

				else if(-x.f + j.s < dist[j.f]){
					freq[j.f] = freq[x.s];
					freq[j.f] %= MOD;
					mn[j.f] = mn[x.s] + 1;
					mx[j.f] = mx[x.s] + 1;

					dist[j.f] = -x.f + j.s;

					q.push({-dist[j.f],j.f});
				}
			}
		}
	}
}

signed main(){
	setIO();
	int n,m;
	cin >> n >> m;

	dist.resize(n);
	graph.resize(n);
	visited.resize(n);
	mn.resize(n);
	mx.resize(n);
	freq.resize(n);

	fill(all(dist),100000000000000);

	forn(i,m){
		int a,b,t;
		cin >> a >> b >> t;
		a--;
		b--;

		graph[a].pb({b,t});
	}

	dijkstra(0);

	cout << dist[n-1] << " " << freq[n-1] << " " << mn[n-1] << " " << mx[n-1];
}