#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,sse4,fma")
 
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
#define qpii queue<pii>
#define pqpii priority_queue<pii>
#define pqi priority_queue<int>
 
const int MOD = 1e9 + 7;
const int INF = 1e17 + 1;
const int maxN = 2e5 + 1;
 
void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int par[maxN];

void init(int n){
	forn(i,n){
		par[i] = -1;
	}
}

int find_par(int x){
	if(par[x] < 0){
		return x;
	}

	return par[x] = find_par(par[x]);
}

bool unite(int x, int y){
	if(find_par(x) == find_par(y)){
		return false;
	}

	x = find_par(x); y = find_par(y);

	par[x] = y;

	return true;
}

struct Query{
	int l,r,idx;
};

bool comp(Query &a, Query &b){
	return ((a.l + a.r) < (b.l + b.r));
}
 
 
signed main(){
	setIO();

	int n,m,q;

	cin >> n >> m >> q;

	vpii edges;

	forn(i,m){
		int a,b;
		cin >> a >> b;
		edges.pb({a-1,b-1});
	}

	vector<Query> Q;
	vpii vtx(q);

	vi ans(q);

	forn(i,q){
		cin >> vtx[i].f >> vtx[i].s;
		vtx[i].f--; vtx[i].s--;

		if(vtx[i].f == vtx[i].s){
			ans[i] = -1;
		}

		else{
			Q.pb({0,m,i});
		}
	}

	init(n);

	while(!Q.empty()){
		vector<Query> Q1;
		queue<Query> qi;
		int ptr = 0;

		for(Query c : Q){
			if(c.l == c.r){
				ans[c.idx] = c.l;
			}

			else{
				int mid = (c.l+c.r)/2;

				while(ptr <= mid){
					unite(edges[ptr].f,edges[ptr].s);
					ptr++;
				}

				if(find_par(vtx[c.idx].f) == find_par(vtx[c.idx].s)){
					while(!qi.empty() && (qi.front().l + qi.front().r <= c.l + mid)){
						Q1.pb(qi.front());
						qi.pop();
					}

					Q1.pb({c.l,mid,c.idx});
				}

				else{
					qi.push({mid+1,c.r,c.idx});
				}
			}
		}

		while(!qi.empty()){
			Q1.pb(qi.front());
			qi.pop();
		}

		Q = Q1;
		init(n);
	}

	forn(i,q){
		if(ans[i] == m){
			cout << -1 << endl;
		}

		else{
			cout << ans[i] + 1 << endl;
		}
	}
}