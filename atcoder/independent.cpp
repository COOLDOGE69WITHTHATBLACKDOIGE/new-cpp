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
vvi dp(100001, vi(2, 1));

//0 == white
//1 == black

void dfs(int node, int parent){
	for(int x : graph[node]){
		if(x != parent){
			dfs(x,node);
			dp[node][0] *= (dp[x][1] + dp[x][0]) % MOD;
			dp[node][0] %= MOD;
		}
	}

	for(int x : graph[node]){
		if(x != parent){
			dp[node][1] *= dp[x][0] % MOD;
			dp[node][1] %= MOD;
		}
	}
}

int main(){
	setIO();

	int n;
	cin >> n;

	graph.resize(n+1);

	forn(i,n-1){
		int a,b;
		cin >> a >> b;

		graph[a].pb(b);
		graph[b].pb(a);
	}

	dfs(1,0);

	ll ans = dp[1][0] + dp[1][1];
	ans %= MOD;
	cout << ans << endl;
}