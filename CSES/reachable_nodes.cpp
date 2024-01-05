#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> T;
 
// #define _GLIBCXX_DEBUG 1
// #define _GLIBCXX_DEBUG_PEDANTIC 1
// #pragma GCC optimize("trapv")

// #define dbg(TXTMSG) cerr << "\n" << TXTMSG
// #define dbgv(VARN) cerr << "\n" << #VARN << " = "<< VARN << ", line: " << __LINE__ << "\n"

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
const int maxN = 5e4 + 1;

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

bitset<maxN> dp[maxN];
int indegree[maxN];

signed main(){
	setIO();
	int n,m;
	cin >> n >> m;

	vvi graph(n);

	forn(i,m){
		int a,b;
		cin >> a >> b;
		a--,b--;

		graph[b].pb(a);
		indegree[a]++;
	}

	queue<int> q;

	forn(i,n){
		if(indegree[i] == 0){
			dp[i].set(i);
			q.push(i);
		}
	}

	while(!q.empty()){
		int node = q.front();
		q.pop();

		for(int k : graph[node]){
			indegree[k]--;
			dp[k] |= dp[node];

			if(indegree[k] == 0){
				dp[k].set(k);
				q.push(k);
			}
		}
	}

	forn(i,n){
		cout << dp[i].count() << " ";
	}
}