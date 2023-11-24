#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define forn(i,j) for(ll i = 0; i < j; i++)
#define forrange(i,j,k) for(int i = j; i < k; ++i)
#define rof(i,j) rof(int i = j; i >= 0; --i)
#define pii pair<int,int>
#define vll vector<ll>
#define vi vector<int>
#define vvll vector<vll>
#define vvi vector<vi>
#define vb vector<bool>
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define eb emplace_back
#define debug(x) cerr << #x << " is " << x << endl;

#define MOD 1000000007

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".in").c_str(), "w", stdout);
	}
}

vvi graph;
int dp[200001][2];
vi degree;

void dfs(int node, int parent){
	int a = 1, b = 1;
	for(int x : graph[node]){
		if(x != parent){
			dfs(x,node);

			if(dp[x][1] >= a){
				b = a;
				a = dp[x][1];
			}

			else{
				b = max(b, dp[x][1]);
			}

			dp[node][1] = max(dp[node][1], degree[x] + degree[node] - 2);
		}
	}

	dp[node][0] = a + 1;
	dp[node][1] = a + b + degree[node] - 3; 
}

int main(){
	int n;
	cin >> n;

	graph.resize(n+1);
	degree.resize(n+1,0);

	forn(i,n-1){
		int a,b;
		cin >> a >> b;

		graph[a].pb(b);
		graph[b].pb(a);

		degree[a]++;
		degree[b]++;
	}

	dfs(1,0);

	cout << max(dp[1][0],dp[1][1]) << endl;
}