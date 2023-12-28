#include<bits/stdc++.h>
using namespace std;
// #define _GLIBCXX_DEBUG 1
// #define _GLIBCXX_DEBUG_PEDANTIC 1
// #pragma GCC optimize("trapv")

// #define dbg(TXTMSG) cerr << "\n" << TXTMSG
// #define dbgv(VARN) cerr << "\n" << #VARN << " = "<< VARN << ", line: " << __LINE__ << "\n"

#define ld long double
#define ll long long
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
const int INF = 1e9 + 50;
const int maxN = 2e5 + 1;

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

signed main(){
	setIO();
	int n,m,T;
	cin >> n >> m >> T;
	vvpii graph;
	graph.resize(n);

	vvpii dp(n,vpii(n+1,{0,0}));

	forn(i,m){
		int a,b,t; cin >> a >> b >> t;
		a--,b--;

		graph[a].pb({b,t});
	}

	stack<pii> st;
	st.push({0,1});

	while(!st.empty()){
		pii j = st.top();
		st.pop();
		int par = j.f;
		int nd = j.s;

		for(pii cd : graph[par]){
			int node = cd.f;
			int time = cd.s;

			if(time >= 1e9 && (node != n-1)){
				continue;
			}

			if(dp[node][nd+1].f > dp[par][nd].f + time || (dp[node][nd+1].f == 0)){

				dp[node][nd+1].f = dp[par][nd].f + time;
				dp[node][nd+1].s = par;

				st.push({node,nd+1});
			}
		}
	}

	for(int j = n; j > 0; --j){
		if(dp[n-1][j].f != 0 && (dp[n-1][j].f <= T)){
			cout << j << endl;

			dp[0][1].s = -1;
			int len = j;
			int tu = n-1;
			stack<int> sy;

			while(tu != -1){
				sy.push(tu);

				if(tu == 0){
					break;
				}

				tu = dp[tu][len].s;
				len--;
			}

			while(!sy.empty()){
				cout << sy.top() + 1 << " ";
				sy.pop();
			}

			return 0;
		}
	}
}