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

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

struct Edge{
	int st,en,power;
};

vi dist;
int neg_cycle = 0;
int n,m;
vector<Edge> E;
int t = -1;
vi back;

void bellman_ford(int start){
	dist[start] = 0;

	forn(i,n-1){
		for(Edge e : E){
			if(dist[e.en] > dist[e.st] + e.power){
				dist[e.en] = dist[e.st] + e.power;
				back[e.en] = e.st;
			}
		}
	}
	vi prev = dist;
	
	for(Edge e : E){
		if(dist[e.en] > dist[e.st] + e.power){
			dist[e.en] = dist[e.st] + e.power;
			back[e.en] = e.st;
		}
	}

	forrange(i,1,n+1){
		if(prev[i] > dist[i]){
			neg_cycle++;
			t = i;
			return;
		}
	}
}

signed main(){
	setIO();
	cin >> n >> m; dist.resize(n+1); back.resize(n+1);

	forn(i,m){
		int a,b,c; cin >> a >> b >> c;
		Edge k; k.st = a; k.en = b; k.power = c; E.pb(k);
	}

	bellman_ford(1);

	if(t == -1){
		cout << "NO" << endl;
		return 0;
	}

	vi sy;
	vb vis(n+1,false);

	forn(i,n){
		t = back[t];
	}

	while(!vis[t]){
		vis[t] = true;
		sy.pb(t);
		t = back[t];
	}

	cout << "YES" << endl;
	cout << sy[0] << " ";
	for(int i = sy.size() - 1; i >= 0; --i){
		cout << sy[i] << " ";
	}
}