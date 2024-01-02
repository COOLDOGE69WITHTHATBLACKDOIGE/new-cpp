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
const int maxN = 2e5 + 1;
const int L = 2e6 + 1;

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int w[2001][2001];
int dp[2001][2001];
string grid;
int cst[2001];
bool visited[L];
int n,m;

void floodfill(int st, int t){
	queue<int> q;
	q.push(st);

	while(!q.empty()){
		int node = q.front();
		q.pop();

		if((visited[node]) || (grid[node] == '.')){
			continue;
		}


		visited[node] = true;
		cst[t] += grid[node] - '0';

		if((node % m != 0)){
			if(!visited[node-1]){
				q.push(node-1);
			}
		}

		if((node % m != m-1)){
			if(!visited[node+1]){
				q.push(node+1);
			}
		}

		if((node >= m)){
			if(!visited[node-m]){
				q.push(node-m);
			}
		}

		if((node < m*(n-1))){
			if(!visited[node+m]){
				q.push(node+m);
			}
		}
	}
}

vi floodfill2(int st){
	queue<int> q;
	vb col(m,false);
	vb vis(L,false);
	vi columns;

	q.push(st);

	while(!q.empty()){
		int node = q.front();
		q.pop();

		if((vis[node]) || (grid[node] == '.')){
			continue;
		}

		int cj = (node % m);
		vis[node] = true;

		if(!col[cj]){
			columns.pb(cj);
			col[cj] = true;
		}

		if((node % m != 0)){
			if(!vis[node-1]){
				q.push(node-1);
			}
		}

		if((node % m != m-1)){
			if(!vis[node+1]){
				q.push(node+1);
			}
		}

		if((node >= m)){
			if(!vis[node-m]){
				q.push(node-m);
			}
		}

		if((node < m*(n-1))){
			if(!vis[node+m]){
				q.push(node+m);
			}
		}
	}

	return columns;
}

void dnc(int i, int l, int r, int optl, int optr){
	if(l > r){
		return;
	}

	int mid = (l+r)/2;
	int opt = 1;
	dp[mid][i] = 0;

	forrange(j,optl,min(mid,optr)+1){
		int sum = w[mid][j];

		if(dp[mid][i] < dp[j][i-1] + sum){
			dp[mid][i] = dp[j][i-1] + sum;
			opt = j;
		}
	}

	dnc(i,l,mid-1,optl,opt);
	dnc(i,mid+1,r,opt,optr);
}

signed main(){
	setIO();

	cin >> n >> m;

	cin >> grid;

	forn(i,n-1){
		string s;
		cin >> s;

		grid = grid + s;
	}
	int c = 0;

	vpii conn_comp;

	forn(node,m*n){
		if(!visited[node] && (grid[node] != '.')){
			floodfill(node,c);
			conn_comp.pb({c,node});
			c++;
		}
	}

	forn(i,conn_comp.size()){
		vi col1 = floodfill2(conn_comp[i].s);

		for(int k : col1){ 
			w[k+1][0] += cst[conn_comp[i].f];
			forn(j,m){
				if(j == k){
					continue;
				}

				if(k > j){
					w[k+1][j+1] += cst[conn_comp[i].f];
				}
			}
		}

		forn(k,col1.size()){
			forn(j,k+1){
				if(k == j){
					continue;
				}

				int t1 = col1[k] + 1; int t2 = col1[j] + 1;
				if(t1 < t2){
					swap(t1,t2);
				}

				w[t1][t2] -= cst[conn_comp[i].f];
			}
		}
	}


	forrange(i,1,m+1){
		dnc(i,1,m,0,m-1);

		int res = 0;

		forrange(j,1,m+1){
			res = max(dp[j][i],res);
		}

		cout << res << endl;
	}
}