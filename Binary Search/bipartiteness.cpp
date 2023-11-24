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
vector<bool> group;

void dfs(int x, bool g = 0){
    visited[x] = 1;
    group[x] = g;

    for(auto u : adj[x]){
        if(!visited[u]){ dfs(u, !g);}
    }
}

int main(){
    int n, m;
    cin >> n;

    adj.resize(n+1);
    visited.resize(n+1);
    group.resize(n+1);

    forn(i,n-1){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    ll a = 0;
    ll b = 0;

    for(int i = 1; i <= n; ++i){
        if(group[i]){ a++;}
        else{ b++;}
    }

    ll c = a*b;
    ll d = c - (n-1);

    cout << d;
}