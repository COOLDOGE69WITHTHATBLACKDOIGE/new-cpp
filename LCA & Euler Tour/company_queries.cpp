#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define forn(i,j) for(ll i = 0; i < j; i++)
#define forrange(i,j,k) for(int i = j; i < k; ++i)
#define rof(i,j,k) rof(int i = j; i > k; ++i)
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define eb emplace_back

#define MOD 1000000007

const ll N = 2e5;
const ll LOG = 20;

int gol[N];

void calculatinglog(int n){
	gol[0] = -1;
	gol[1] = 0;
	for(int i = 2; i < n; ++i){
		gol[N] = gol[N/2]+1;
	}
}

int parent[N][LOG];
vvi adj;

void dfs(int u, int v){
	parent[u][0] = v;

	for(int x : adj[u]){
		if(x != v){
			dfs(x,u);
		}
	}
}

int findparent(int k, int x){
	int logk = gol[k];

	if(logk == -1){
		return x;
	}

	else{
		return findparent((k - (1 << logk)), parent[x][logk]);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n,q;
	cin >> n >> q;
	calculatinglog(n);

	adj.resize(n+1);

	for(int i = 1; i < n; ++i){
		int a;
		cin >> a;
		a--;

		adj[a].pb(i);
		adj[i].pb(a);
	}
	
	dfs(0,0);

	for(int j = 0; j < LOG; ++j){
		parent[0][j] = -1;
	}

	for(int i = 1; i < n; ++i){
		for(int j = 1; j < LOG; ++j){

			if(parent[i][j-1] == -1){
				parent[i][j] = -1;
			}
			else{
				parent[i][j] = parent[parent[i][j-1]][j-1];
			}
		}
	}

	while(q--){
		int x,k;
		cin >> x >> k;

		if(findparent(k,x-1) == -1){
			cout << -1 << endl;
		}

		else{
			cout << findparent(k,x-1) + 1 << endl;
		}
	}
}