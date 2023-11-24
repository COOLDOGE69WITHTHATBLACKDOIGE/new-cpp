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
vii adj;
vii jda;
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

void dfs(int u){
    visited[u] = true;

    for(int x : adj[u]){
        if(!visited[x]){ dfs(x);}
    }
}

void sfd(int u){
    visited[u] = true;

    for(int x : jda[u]){
        if(!visited[x]){ sfd(x);}
    }
}

#define all(x) x.begin(), x.end()

int main(){
    siout();
    ll m;
    cin >> n >> m;

    adj.resize(n+1);
    jda.resize(n+1);
    visited.resize(n+1);

    forn(i,0,m){
        ll x,y;
        cin >> x >> y;
        adj[x].eb(y);
        jda[y].eb(x);
    }

    dfs(1);

    int count = 0;

    forn(i,1,n+1){
        if(!visited[i]){
            cout << "NO" << endl;
            cout << 1 << ' ' << i << endl;
            count++;
            break;
        }
    }

    fill(all(visited), false);

    sfd(1);

    if(count == 0){
    forn(i,1,n+1){
        if(!visited[i]){
            cout << "NO" << endl;
            cout << i << ' ' << 1 << endl;
            count++;
            break;
        }
    }
    }

    if(count == 0){
        cout << "YES" << endl;
    }
}