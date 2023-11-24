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

ll n;
vii adj;
vector<bool> visited;

void dfs(ll u){
    visited[u] = true;

    for(auto x : adj[u]){
        if(!visited[x]){ dfs(x);}
    }
}

int main(){
    ll t;
    cin >> t;
    while(t--){
    adj.clear();

    ll m;
    cin >> n >> m;

    adj.resize(n+1);
    visited.resize(n+1);
    fill(visited.begin(), visited.end(), false);

    forn(i,m){
        ll x,y;
        cin >> x >> y;
        adj[x].eb(y);
        adj[y].eb(x);
    }

    dfs(1);
    ll ma = 0;
    
    forn(i, n+1){
        if(visited[i]){
            ma = std::max(i, ma);
        }
    }

    fill(visited.begin(), visited.end(), false);

    dfs(n);
    ll min = n;

    forn(i, n+1){
        if(visited[i]){
            min = std::min(i, min);
        }
    }

    ll b = ma - min;

    if(b%2==0){
        ll c = b/2;
        ll d = 2*c*c;
        cout << d << endl;
    }

    else{
        ll c = b/2;
        ll d = (b/2) + 1;
        ll e = (c*c) + (d*d);
        cout << e << endl;
    }
    }
}