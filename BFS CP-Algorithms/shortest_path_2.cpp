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

const int N = 50000;
vii adj;
vector<bool> visited;
set<pii> bad[N];
int dp[N];
queue<pii> q;
vi prev_point;

void bfs(){
    visited[1] = true;
    pii x = make_pair(0,1);
    q.push(x);

    while(!q.empty()){
        int u = q.front().s;
        int v = q.front().f;
        q.pop();

        for(auto w : adj[v]){
            pii z = make_pair(u,w);
            if(!visited[w] && (bad[v].find(z) == bad[v].end())){
                dp[w] = dp[v]+1;
                prev_point[w] = v;
            }

            if(visited[w] && (bad[v].find(z) == bad[v].end())){
                if((dp[v]+1) < dp[w]){
                    prev_point[w] = v;
                    dp[w] = dp[v]+1;
                }
            }
        }
    }
}

int main(){
    siout();
    int n, m, k;

    cin >> n >> m >> k;

    adj.resize(n+1);
    visited.resize(n+1);
    prev_point.resize(n+1);

    forn(i,m){
        int a,b;
        cin >> a >> b;

        adj[a].eb(b);
        adj[b].eb(a);
    }

    forn(i,k){
        int j,k,l;
        cin >> j >> k >> l;

        pii a = make_pair(j,k);
        pii b = make_pair(k,l);
        pii c = make_pair(j,l);

        bad[j].insert(b);
        bad[k].insert(c);
        bad[l].insert(a);
    }

    bfs();

    if(!visited[n]){
        cout << -1 << endl;       
    } else{
        cout << dp[n];
    }
}