#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define forn(i,j,k) for(ll i = j; i < k; i++)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define p push
#define x first
#define y second
#define all(x) x.begin, x.end()
#define eb emplace_back
#define rsz resize

#define MOD 1000000007

ll nodes = 0;
ll n;
vii adj;
vector<bool> visited;

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
    nodes++;

    for(auto x : adj[u]){
        if(!visited[x]){ dfs(x);}
    }
}

int main(){
    siout("moocast");
    cin >> n;

    pii coord[n];
    adj.rsz(n+1);
    visited.rsz(n+1);

    forn(i,0,n){
        cin >> coord[i].x >> coord[i].y;
    }

    ll lo = 1;
    ll hi = 1e9;

    while(lo < hi){
        ll mid = (lo+hi)/2;
        nodes = 0;
        adj.clear();
        adj.rsz(n+1);
        fill(visited.begin(), visited.end(), false);

        forn(i,0,n-1){
            forn(j,i+1,n){
                ll a = abs(coord[i].x - coord[j].x);
                ll b = abs(coord[i].y - coord[j].y);

                if((a*a) + (b*b) <= mid){
                    adj[i].eb(j);
                    adj[j].eb(i);
                }
            }
        }

        dfs(1);

        if(nodes == n){
            hi = mid;
        }

        else{
            lo = mid+1;
        }
    }

    cout << hi << endl;
}