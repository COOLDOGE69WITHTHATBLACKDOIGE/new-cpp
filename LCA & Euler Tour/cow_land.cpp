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
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define eb emplace_back
#define debug(x) cerr << #x <<  " is " << x << endl;

#define MOD 1000000007

const int N = 1e5 + 1;

vi bit(N, 0);
vvi graph;
vi tin;
vi tout;
int parent[N][20];
int timer = 0;

void dfs(int at, int prev){
    timer++;
    tin[at] = timer;
    parent[at][0] = prev;

    for(int y : graph[at]){
        if(y != prev){
            dfs(y,at);
        }
    }

    tout[at] = timer;
}

void update(int ind, int value, int n){
	while(ind < n){
		bit[ind] ^= value;
		debug(bit[ind])
		ind += ind&-ind;
	}
}

int XOR(int ind){
	int q = 0;
	while(ind > 0){
		q ^= bit[ind];
		ind -= ind&-ind;
	}

	return q;
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
	int n, q;
	cin >> n >> q;

	memset(parent,0,sizeof(parent));

	graph.resize(n+1);
	tin.resize(n+1);
	tout.resize(n+1);

	vi v(n+1);

	forn(i,n){
		cin >> v[i+1];
	}

	forn(i,n-1){
		int a,b;
		cin >> a >> b;

		graph[a].pb(b);
		graph[b].pb(a);
	}

	dfs(1,1);

	for(int i = 1; i < n+1; ++i){
		for(int l = 1; l < 19; ++l){
			parent[i][l] = parent[parent[i][l-1]][l-1];
		}
	}

	forn(i,n){
		if(tout[i+1]+1 >= n+1){
			update(tin[i+1],v[i+1],n);
		}

		else{
			update(tin[i+1],v[i+1],n);
			update(tout[i+1]+1,v[i+1],n);
		}
	}

	while(q--){
		int type;
		cin >> type;

		if(type == 1){
			int i, val;
			cin >> i >> val;
			
			update(tin[i],v[i],n);
			update(tout[i]+1, v[i],n);

			v[i] = val;

			update(tin[i],v[i],n);
			update(tout[i]+1, v[i],n);
		}

		if(type == 2){
			int i, j;
			cin >> i >> j;

			int l = lca(i,j);
			int g = XOR(tin[i]);
			int h = XOR(tin[j]);
			h ^= g;
			h ^= v[l];

			cout << h << endl;
		}
	}
}