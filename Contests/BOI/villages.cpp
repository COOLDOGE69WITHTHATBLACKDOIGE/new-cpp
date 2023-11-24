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

int mn = 0;
vvi graph;
vi backtrack;

void dfs(int node, int parent){
	
	for(int child : graph[node]){
		if(child != parent){
			dfs(child,node);
		}
	}

	if(parent > 0 && backtrack[node] == node){
		backtrack[node] = backtrack[parent];
		backtrack[parent] = node;

		mn += 2;
	}

	if(parent == 0 && backtrack[node] == node){
		backtrack[node] = backtrack[graph[node][0]];
		backtrack[graph[node][0]] = node;

		mn += 2;
	}
}

int main(){
	setIO();
	int n;
	cin >> n;

	graph.resize(n+1);
	backtrack.resize(n+1);

	forrange(i,1,n){
		backtrack[i] = i;

		int a,b;
		cin >> a >> b;

		graph[a].pb(b);
		graph[b].pb(a);
	}

	backtrack[n] = n;

	dfs(1,0);

	cout << mn << endl;

	forrange(i,1,n+1){
		cout << backtrack[i] << " ";
	}

	cout << endl;
}