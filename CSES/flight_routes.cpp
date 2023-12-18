#include<bits/stdc++.h>
using namespace std;

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

const int MOD = 1e9 + 7;
const int INF = 1e17 + 1;
const int maxN = 1e5 + 1;

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

pqi pq[maxN];
vvpii graph;
int k;

void djisktra(int u){
	pqpii gg;
	pq[u].push(0);
	gg.push({0,u});

	while(!gg.empty()){
		pii j = gg.top(); gg.pop(); int node = j.s; int dist = -j.f;

		if(pq[node].top() < dist){
			continue;
		}

		for(pii h : graph[node]){
			int w = dist + h.s; int child = h.f;

			if(pq[child].size() < k){
				pq[child].push(w);
				gg.push({-w,child});
			}
			else{
				if(pq[child].top() > w){
					pq[child].pop(); pq[child].push(w);
					gg.push({-w,child});
				}
			}
		}
	}	
}


signed main(){
	setIO(); int n,m; cin >> n >> m >> k; 
	graph.resize(n);

	forn(i,m){
		int a,b,c; cin >> a >> b >> c;
		graph[a-1].pb({b-1,c});
	}

	djisktra(0);
	vi ans;
	while(!pq[n-1].empty()){
		ans.pb(pq[n-1].top()); pq[n-1].pop();
	}

	reverse(all(ans));

	for(int kk : ans){
		cout << kk << " ";
	}
}