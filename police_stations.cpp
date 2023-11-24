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

void siout(string name = ""){ 

	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
    siout();
    int n,k,d;
    cin >> n >> k >> d;

    vii adj(n+1);
    vector<bool> visited(n+1);
    unordered_set<int> deleted[n+1];
    int edges[n+1][n+1];
    vi deleted_edges(n+1);

    int police_station[n];
    queue<int> q[k];

    forn(i,k){
        cin >> police_station[i];
    }

    forn(i, n-1){
        int a,b;
        cin >> a >> b;
        edges[a][b] = i+1;
        edges[b][a] = i+1;
        adj[a].eb(b);
        adj[b].eb(a);
    }
    
    vi depth(n+1);

    // forn(i,k){  //bfs on police stations
    //     int u = police_station[i];
    //     q[i].push(u);
    //     visited[u] = true;
    //     depth[u] = 0;
    //     int dep = 0;

    //     cout << k -1 << endl;

    //     while(!q[i].empty() && dep < d){
    //         int v = q[i].front();
    //         q[i].pop();
    //         dep = depth[u]+1;
            
    //         for(int w : adj[v]){
    //             if(visited[w] && (deleted[v].count(w) == 0)){
    //                 deleted[w].insert(v);
    //                 deleted[v].insert(w);
    //                 int x = edges[w][v];
    //                 cout << x << ' ';
    //             }

    //             if(!visited[w] && (deleted[v].count(w) == 0)){
    //                 visited[w] = true;
    //                 q[i].push(w);
    //                 depth[w] = depth[v]+1;
    //             }
    //         }
    //     }     
    // }
}