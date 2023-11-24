#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#pragma GCC optimize("trapv")

#define dbg(TXTMSG) cerr << "\n" << TXTMSG
#define dbgv(VARN) cerr << "\n" << #VARN << " = "<< VARN << ", line: " << __LINE__ << "\n"

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

#define MOD 1000000007

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".in").c_str(), "w", stdout);
	}
}

vi dp1;
vi dp2;
vvi graph;

void dfs(int node, int parent, int mod){
	for(int x : graph[node]){
		if(x != parent){
			dfs(x,node, mod);

			dp1[node] *= (dp1[x] + 1);
			dp1[node] %= mod;
		}
	}
}

void dfs2(int node, int parent, int mod){
	vll pref(graph[node].size()+2,1);
	vll suff(graph[node].size()+2,1);

	vi nickname(graph[node].size()+2,1);
	vi realname(graph[node].size()+2,1);

	int id = 1;
	for(int x : graph[node]){
		if(x != parent){
			nickname[x] = id;
			realname[id] = x;

			id++;	
		}
	}

	for(int i = id-1; i > 0; --i){
		suff[i] = suff[i+1]*(dp1[realname[i]] + 1);
		suff[i] %= mod;
	}

	for(int i = 1; i <= id-1; ++i){
		pref[i] = pref[i-1]*(dp1[realname[i]] + 1);
		pref[i] %= mod;
	}

	for(int x : graph[node]){
		if(x != parent){
			dp2[x] = 1 + (dp2[node] * suff[nickname[x]+1] * pref[nickname[x]-1]);
			dp2[x] %= mod;
			dfs2(x, node, mod);
		}
	}
}

int main(){
	setIO();
	int n, m;
	cin >> n >> m;

	graph.resize(n+1);
	dp1.resize(n+1,1);
	dp2.resize(n+1,1);

	forn(i,n-1){
		int a,b;
		cin >> a >> b;

		graph[a].pb(b);
		graph[b].pb(a);
	}

	dfs(1,0,m);
	dfs2(1,0,m);

	forrange(i,1,n+1){
		cout << (dp1[i]*dp2[i])%m << endl;
	}
}