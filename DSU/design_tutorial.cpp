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
#define vll vector<ll>
#define vvi vector<vi>
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define eb emplace_back

#define MOD 1000000007
#define debug(x) cerr << #x << " " << x << endl;

void printvec(vi x){
	for(int i : x){
		cerr << i << " ";
	}

	cerr << endl;
}

struct dsu{
	vi e;

	dsu(int n){ e = vi(n,-1);}

	int get(int x){
		return e[x] < 0 ? x : e[x] = get(e[x]);
	}

	int size(int x){
		return -e[get(x)];
	}

	bool same_set(int a, int b){
		return get(a) == get(b);
	}

	bool unite(int a, int b){
		a = get(a);
		b = get(b);

		if(a == b){
			return false;
		}

		else{
			e[a] += e[b];
			e[b] = a;

			return true;
		}
	}
};


struct Edge{
	int wt,x,y;
};

bool comp(Edge &a, Edge &b){
	return a.wt < b.wt;
}

vector<vector<pii>> graph;
vi dist;

void dfs(int at, int prev){
    for(pii y : graph[at]){
        if(y.f != prev){
        	dist[y.f] = dist[at] + y.s;
            dfs(y.f,at);
        }
    }
}

bool check(vvi distance, int i, int n){
	forn(j,n){
		if(distance[i][j] == dist[j]){
			continue;
		}

		else{
			return false;
		}
	}

	return true;
}

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<Edge> e;
	vvi distance(n, vi(n,0));

	graph.resize(n);
	dist.resize(n);
	dsu d(n);
	int l = 0;

	forn(i,n){
		forn(j,n){
			cin >> distance[i][j];

			if(i != j && distance[i][j] == 0){
				cout << "NO" << endl;
				return 0;
			}

			Edge b;
			b.wt = distance[i][j];
			b.x = i;
			b.y = j;

			e.pb(b);
		}
	}

	sort(all(e),comp);

	for(Edge a : e){
		if(d.unite(a.x,a.y)){
			graph[a.x].pb({a.y,a.wt});
			graph[a.y].pb({a.x,a.wt});
		}
	}

	int z = 0;
	bool g = true;

	forn(i,n){
		dist[i] = 0;
		dfs(i,-1);

		forn(j,n){
			if(distance[i][j] == dist[j]){
				continue;
			}

			else{
				g = false;
				break;
			}
		}

		if(!g){
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;
}