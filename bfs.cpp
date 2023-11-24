#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define forn(i,j) for(ll i = 0; i < j; i++)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin, x.end()
#define eb emplace_back

#define MOD 1000000007

void siout(string name = "") { 

	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
vii adj;
vector<bool> visited;
queue<int> q;
vi d;
vi p;

void bfs(int u){
	visited[u] = true;
	d[u] = 0;
	p[u] = -1;

	q.push(u);

	while(!q.empty()){
		int v = q.front();
		q.pop();

		for(auto x : adj[v]){
			if(!visited[x]){ 
				q.push(x);
				visited[x] = true;
				d[x] = d[v] + 1;
				p[x] = v;
			}
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;

	adj.resize(n+1);
	visited.resize(n+1);
	d.resize(n+1);
	p.resize(n+1);

	forn(i, m){
		int a,b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	bfs(1);

	cout << d[5];
}