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
#define eb emplace_back

#define MOD 1000000007

ll max = 3000;

ll n;
vii adj(3001);
vector<bool> visited(3001);
vector<bool> closed(3001);
ll nodes = 0;

void siout(string name = "") { 

	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

void dfs(ll u){
    if(visited[u] || closed[u]){
        return;
    }

    visited[u] = true;
    nodes++;

    for(auto x : adj[u]){
        if(!visited[x]){ dfs(x);}
    }
}

int main(){
    siout("closing");    
    ll m;
    cin >> n >> m;

    forn(i,0,m){
        ll x,y;
        cin >> x >> y;
        adj[x].eb(y);
        adj[y].eb(x);
    }

    vi ord(3001);
    forn(i,0,n){ cin >> ord[i];}

    dfs(1);

    if(nodes == n){
        cout << "YES" << endl;
    }

    else{
        cout << "NO" << endl;
    }

    forn(i,0,n-1){
        nodes = 0;
        closed[ord[i]] = true;
        fill(visited.begin(), visited.end(), false);

        dfs(ord[n-1]);

        if(nodes == n-i-1){
            cout << "YES" << endl;
        }

        else{
            cout << "NO" << endl;
        }
    }
}