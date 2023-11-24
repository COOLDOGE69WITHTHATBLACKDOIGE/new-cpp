#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#pragma GCC optimize("trapv")

#define dbg(TXTMSG) cerr << "\n" << TXTMSG
#define dbgv(VARN) cerr << "\n" << #VARN << " = "<< VARN << ", line: " << __LINE__ << "\n"

#define ld long double
#define int long long
#define forn(i,j) for(int i = 0; i < j; i++)
#define forrange(i,j,k) for(int i = j; i < k; ++i)
#define rof(i,j) rof(int i = j; i >= 0; --i)
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define vvi vector<vi>
#define vvpii vector<vector<pii>>
#define vb vector<bool>
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define eb emplace_back
#define qi queue<int>
#define qpii queue<pii>
#define pqpii priority_queue<pii>
#define pqi priority_queue<int>

#define MOD 1000000007

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

vvi graph;
vi dist;

vi dt;

void dfs(int u){
	for(int x : graph[u]){
		dt[x] = max(dt[x],dt[u] + 1);
		dfs(x);
	}
}

bool comp(int &u, int &v){
	return dist[u] > dist[v];
}

signed main(){
	auto begin = std::chrono::high_resolution_clock::now();
	setIO();
	int n,m,q;
	cin >> n >> m >> q;
	graph.resize(n);
	dist.assign(n,-1);

	int h = sqrt(n);

	forn(i,m){
		int a,b;
		cin >> a >> b;
		a--;
		b--;

		graph[b].pb(a);
	}

	vvpii dp(n);

	forn(i,n){
		vi nodes;
		dist[i] = 0;
		nodes.pb(i);

		vb used(n,false);

		for(int x : graph[i]){
			for(pii j : dp[x]){
				if(!used[j.f]){
					used[j.f] = true;
					nodes.pb(j.f);
				}

				dist[j.f] = max(dist[j.f],j.s+1);
			}
		}

		sort(all(nodes),comp);
		int t = 0;

		for(int j : nodes){
			if(t < h){
				dp[i].pb({j,dist[j]});
				dist[j] = 0;

				t++;
			}

			else{
				break;
			}
		}
	}

	
	while(q--){
		vb deleted(n,false);

		int ind,del;
		cin >> ind >> del;

		ind--;

		forn(i,del){
			int a;
			cin >> a;
			a--;

			deleted[a] = true;
		}

		if(del <= h){
			int ans = -1;
			int k = 0;

			for(pii j : dp[ind]){
				if(!deleted[j.f]){
					ans = max(ans,j.s);
					k++;
				}

				if(k > 0){
					break;
				}
			}

			cout << ans << endl;
		}

		else{
			dt.assign(n,-1);

			dt[ind] = 0;

			dfs(ind);

			int ans = -1;

			forn(i,n){
				if(!deleted[i]){
					ans = max(ans,dt[i]);
				}
			}

			cout << ans << endl;
		}
	}

	auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
}