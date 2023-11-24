#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

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
#define debug(x) cerr << #x << " is " << x << endl;

#define MOD 1000000007

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

vvi graph;
vb visited;
vi dist[3];

void bfs(int u, int ord){
	queue<int> q;
	q.push(u);
	dist[ord][u] = 0;

	while(!q.empty()){
		int m = q.front();
		visited[m] = true;
		q.pop();

		for(int x : graph[m]){
			if(!visited[x]){
				dist[ord][x] = dist[ord][m]+1;
				q.push(x);
			}
		}
	}
}

int main(){
	int b,e,p,n,m;
	cin >> b >> e >> p >> n >> m;

	graph.resize(n+1);
	visited.resize(n+1);
	dist[0].resize(n+1);
	dist[1].resize(n+1);
	dist[2].resize(n+1);

	forn(i,m){
		int a,b;
		cin >> a >>b;

		graph[a].pb(b);
		graph[b].pb(a);
	}

	bfs(1,0);

	fill(visited.begin(), visited.end(), false);

	bfs(2,1);

	fill(visited.begin(), visited.end(), false);

	bfs(n,2);

	int mn = (int)1e6;

	forrange(i,1,n+1){
		int ans = 0;
		ans += b*dist[0][i];
		ans += e*dist[1][i];
		ans += p*dist[2][i];

		mn = min(ans,mn);
	}

	cout << mn << endl;
}