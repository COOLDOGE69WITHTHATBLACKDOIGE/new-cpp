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
#define vpii vector<pii>
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

vvi graph;
vpii dp1;
vpii dpm2;
vpii dp2;
vi a;

void dfs1(int node, int parent){
	for(int x : graph[node]){
		if(x != parent){
			dfs1(x,node);

			if(dp1[x].f - 1 == dp1[node].f){
				int k = min(dp1[x].s, dp1[node].s);
				dp1[node].s = k;
 			}

 			if(a[x] - 1 == dp1[node].f){
 				int k = min(x,dp1[node].s);
 				dp1[node].s = k;
 			}

			if(dp1[x].f - 1 > dp1[node].f || a[x] - 1 > dp1[node].f){
				dpm2[node].f = dp1[node].f;
				dpm2[node].s = dp1[node].s;

				if(dp1[x] > a[x]){
					dp1[node].f = dp1[x].f - 1;
					dp1[node].s = dp1[x].s;
				}

				else{
					if(dp1[x].f == a[x]){
						int l = min(dp1[x].s,x)

						if(dp1[node] < dp1[x] - 1){
							dp1[node].f = dp1[x].f - 1;
							dp1[node].s = l;
						}
					}

					else{
						dp1[node].f = a[x] - 1;
						dp1[node].s = x;
					}
				}
			}

			else{
				if(dp1[x].f - 1 == dpm2[node].f){
					int k = min(dp1[x].s, dpm2[node].s);
					dpm2[node].s = k;
	 			}

	 			if(a[x] - 1 == dpm2[node].f){
	 				int k = min(x,dpm2[node].s);
	 				dpm2[node].s = k;
	 			}

				if(dp1[x].f - 1 > dpm2[node].f || a[x] - 1 > dpm2[node].f){
					if(dp1[x] > a[x]){
						dpm2[node].f = dp1[x].f - 1;
						dpm2[node].s = dp1[x].s;
					}

					else{
						if(dp1[x].f == a[x]){
							int l = min(dp1[x].s,x);	
							dp1[node].f = dp1[x].f - 1;
							dp1[node].s = l;
						}

						else{
							dp1[node].f = a[x] - 1;
							dp1[node].s = x;
						}
					}
				}				
			}
		}
	}
}

void dfs2(int node, int parent){
	for(int x : graph[node]){
		if(x != parent){
			if(a[node] - 1 >)

			dfs2(x,node);
		}
	}
}

int main(){
	int n, k;
	cin >> n >> k;

	graph.resize(n+1);
	a.resize(n+1);
	dp1.resize(n+1,0);
	dpm2.resize(n+1,0);
	dp2.resize(n+1,0);

	forrange(i,1,n+1){
		cin >> a[i];
	}

	forn(i,n-1){
		int a,b;
		cin >> a >> b;

		graph[a].pb(b);
		graph[b].pb(a);
	}

	dfs1(1,0);
	dfs2(1,0);

	forrange(i,1,n+1){
		cout << 
	}
}