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
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define eb emplace_back

#define MOD 1000000007
#define debug(x) cerr << #x << " " << x << endl;

int parent[200000][20];
vvi graph;
vi tin;
vi tout;
vi deep;
int timer = 0;
int depth = -1;

void dfs(int at, int prev){
    tin[at] = timer++;
    deep[at] = depth++;
    parent[at][0] = prev;

    for(int y : graph[at]){
        if(y != prev){
            dfs(y,at);
        }
    }

    tout[at] = timer;
}

bool ancestor(int a, int b){
	if(tin[a] <= tin[b] && tout[a] >= tout[b]){
		return true;
	}

	return false;
}

int lca(int a,int b){

	if(ancestor(b,a)){
		return b;
	}

	if(ancestor(a,b)){
		return a;
	}

	for(int i = 18; i >= 0; --i){
		if(parent[a][i] == 0){
			continue;
		}

		if(!ancestor(parent[a][i], b)){
			a = parent[a][i];
		}
	}

	return parent[a][0];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;

	memset(parent, 0, sizeof(parent));

	graph.resize(n+1);
	tin.resize(n+1);
	tout.resize(n+1);
	deep.resize(n+1);

	for(int i = 2; i < n+1; ++i){
		int a;
		cin >> a;

		graph[a].pb(i);
		graph[i].pb(a);
	}

	dfs(1,0);

	for(int at = 1; at < n+1; ++at){
		for(int i = 1; i < 20; ++i){
	    	parent[at][i] = parent[parent[at][i-1]][i-1];
	    }
	}

	while(q--){
		int a,b;
		cin >> a >> b;

		cout << lca(a,b) << endl;
	}
}