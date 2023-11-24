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
#define rof(i,j) rof(int i = j; i > 0; --i)
#define pii pair<int,int>
#define vpii vector<pii>
#define vll vector<ll>
#define vi vector<int>
#define vvll vector<vll>
#define vvi vector<vi>
#define vvpii vector<vpii>
#define vb vector<bool>
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define eb emplace_back
#define qi queue<int>
#define qpii queue<pii>

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
vi succ;

struct dsu{
	vi e;
	int m;

	dsu(int n){ e = vi(n,-1);}

	int get(int x){
		return e[x] < 0 ? x : e[x] = get(e[x]);
	}

	int size(int x){
		return -e[get(x)];
	}

	bool same_set(int a, int b){
		return get(a) == get(b);
	}

	bool unite(int a, int b){
		int c = get(a);
		int d = get(b);

		if(c == d){
			return false;
		}

		else{
			succ[a]++;
			e[c] += e[d];
			e[d] = c;

			return true;
		}
	}
};

int main(){
	setIO("closing");
	int n, m;
	cin >> n >> m;
	bool added[m+1];
	int t = 0;

	dsu d(n+1);

	graph.resize(n+1);
	succ.resize(n+1,0);

	forrange(i,1,m+1){
		int a, b;
		cin >> a >> b;

		graph[a].pb(b);
		graph[b].pb(a);
	}

	int perm[n];
	bool per[n];

	forn(i,n){
		cin >> perm[i];
	}

	for(int i = n - 1; i >= 0; --i){
		added[perm[i]] = true;

		for(int x : graph[perm[i]]){
			if(added[x]){
				d.unite(perm[i],x);
			}
		}

		t += 1 - succ[perm[i]];

		if(t == 1){
			per[i] = true;
		}

		else{
			per[i] = false;
		}
	}

	forn(i,n){
		if(per[i]){
			cout << "YES" << endl;
		}

		else{
			cout << "NO" << endl;
		}
	}
}