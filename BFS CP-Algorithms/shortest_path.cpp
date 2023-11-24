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

const int N = 100000;
vii adj;
vector<bool> visited;
set<pii> bad[N];
int dp[N][N];

void siout(string name = "") { 

	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

void bfs(){
	queue<pii> q;
	visited[1] = true;
	q.push({0,1});
	dp[0][1] = 0;

	while(!q.empty()){
		int v = q.front().s;
		int w = q.front().f;
		q.pop();

		for(int x : adj[v]){
			auto b = make_pair(v,x);
			if(!visited[x] && (bad[w].find(b) == bad[w].end())){
				visited[x] = true;
				dp[v][x] = dp[v][w]+1;
			}

			if(visited[x] && (bad[w].find(b) == bad[w].end())){ 
				q.push({v,x});
				dp[v][x] = min(dp[v][w]+1,dp[v][x]);
			}
		}
	}
}

int main(){
	int n, m, k;
	cin >> n >> m >> k;

	adj.resize(n+1);
	visited.resize(n+1);
	
	forn(i, m){
		int a,b;
		cin >> a >> b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	forn(i,k){
		int j,k,l;
		cin >> j >> k >> l;
		auto g = make_pair(j,k);
		auto h = make_pair(k,l);
		auto c = make_pair(j,l);

		bad[l].insert(g);
		bad[j].insert(h);
		bad[k].insert(c);
	}

	if(!visited[n]){
		cout << -1 << endl;
	}

	else{
		for(auto x : adj[n]){
			int pp = N;
			pp = min(pp, dp[x][n]);

			cout << pp << endl;
		}
	}	
}