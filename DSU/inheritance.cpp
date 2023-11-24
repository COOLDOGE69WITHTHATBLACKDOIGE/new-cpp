#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
// #define _GLIBCXX_DEBUG 1
// #define _GLIBCXX_DEBUG_PEDANTIC 1
// #pragma GCC optimize("trapv")

// #define dbg(TXTMSG) cerr << "\n" << TXTMSG
// #define dbgv(VARN) cerr << "\n" << #VARN << " = "<< VARN << ", line: " << __LINE__ << "\n"

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

struct Edge{
	int index;
	int cost;
	int x;
	int y;
};

bool comp(Edge &a, Edge &b){
	return a.cost > b.cost;
}

struct dsu{
	vi e;

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
		a = get(a);
		b = get(b);

		if(a == b){
			return false;
		}

		else{
			e[a] += e[b];
			e[b] = a;

			return true;
		}
	}
};

int main(){
	setIO("");
	int n,m,k;
	cin >> n >> m >> k;

	vector<Edge> e;
	vector<dsu> d(k, dsu(n+1));
	vi ans(m,0);

	forn(i,m){
		Edge b;
		b.index = i;
		cin >> b.x >> b.y >> b.cost;
		b.x--;
		b.y--;

		e.pb(b);
	}

	sort(all(e),comp);

	forn(i,m){
		Edge h = e[i];
		int lo = 0;
		int hi = k-1;

		while(lo < hi - 1){
			int mid = (lo+hi)/2;
			if(!d[mid].same_set(h.x, h.y)){
				
				hi = mid - 1;
			}

			else{
				lo = mid+1;
			}
		}

		if(d[lo].unite(h.x,h.y)){
			ans[h.index] = lo + 1;
		}
		else{
			continue;
		}
	}

	forn(i,m){
		cout << ans[i] << endl;
	}
}