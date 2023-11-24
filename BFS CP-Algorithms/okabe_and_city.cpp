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

const int N = 100'000;
vector<bool> visited;
int dp[N][N];


int main(){
    int n,m,k;
    cin >> n >> m >> k;

    forn(i, k){
        int a,b;
        cin >> a >> b;
    }
}

/*To Do:
0. Make a bipartite graph somehow.
(i) I DONT KNOW HOW TO DO IT.

1. Initialize cost for everything in the first row or column.

2. Use DP transitioning to calculate the rest, visit each vertex using BFS, note that we will be minimizing
it each time we visit a vertex using BFS.

3. Take out the answer.*/