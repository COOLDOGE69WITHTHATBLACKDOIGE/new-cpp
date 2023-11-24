#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define forn(i,j) for(ll i = 0; i < j; i++)
#define pi pair<int,int>
#define pl pair<ll,ll>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pi>
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

const int N = 2000000;
vi adj[N];
bool visited[N];

void dfs(int x, double mid){
    visited[x] = true;

    for(auto y : adj[x]){
        
    }
}

int main(){
    siout();
    int n, m, r;
    cin >> n >> m >> r;
}
/*To do:
1. Find a way to work DFS with the adjacency list of pairs.
2. Somehow make a list of vertex and edges with weights. (main problem)
3. Then binary search on the maximum safety factor.*/