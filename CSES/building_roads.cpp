#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define forn(i,k,j) for(ll i = k; i < j; i++)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define p push
#define f first
#define s second

#define MOD 1000000007

ll n;
vii adj;
vector<bool> visited;
vi adding_roads;

void siout(string name = "") { 

	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

void dfs(ll u){
    visited[u] = true;

    for(auto x : adj[u]){
        if(!visited[x]){ dfs(x);}
    }
}

ll connected_components(){
    ll count = 0;
    forn(i,1,n+1){
        if(!visited[i]){
            count++;
            adding_roads.pb(i);
            dfs(i);
        } else{ continue;}
    }
    return count;
}

int main(){
    ll m;
    cin >> n >> m;
    adj.resize(n+1);
    visited.resize(n+1, false);

    forn(i,0,m){
        ll x, y;
        cin >> x >> y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    ll c = connected_components();

    cout << c-1 << endl;
    forn(i,0,c-1){
        cout << adding_roads[i] << ' ' << adding_roads[i+1] << endl;
    }
}