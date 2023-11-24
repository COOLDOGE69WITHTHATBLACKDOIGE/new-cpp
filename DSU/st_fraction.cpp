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
	int wt1, wt2, x, y;
	ld wt3;
};

bool comp(Edge &a, Edge &b){
	return a.wt3 > b.wt3;
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

signed main(){
	setIO("input");
	int n,m;
	cin >> n >> m;
	vector<Edge> e;

	forn(i,m){
		Edge b;
		cin >> b.x >> b.y >> b.wt1 >> b.wt2;
		b.wt3 = 0;

		e.pb(b);
	}

	ld hi = 1e18;
	ld lo = 1;
	ld prec = 1e-10;
	ll sum1, sum2;

	while(hi - lo > prec){
		dsu d(n);
		ld mid = (lo + hi)/2;
		ld c = mid;

		forn(i,m){
			Edge b;
			b.x = e[i].x;
			b.y = e[i].y;
			b.wt1 = e[i].wt1;
			b.wt2 = e[i].wt2;

			b.wt3 = b.wt1 - (c * b.wt2);

			e[i] = b;
		}

		sort(all(e),comp);
		ld sum = 0;
		sum1 = 0;
		sum2 = 0;

		for(Edge k : e){
			if(d.unite(k.x,k.y)){
				sum += k.wt3;
				sum1 += k.wt1;
				sum2 += k.wt2; 
			}
		}

		if(sum >= 0){
			lo = mid;
		}

		else{
			hi = mid;
		}
	}

	ll k = gcd(sum1,sum2);
	sum1 /= k;
	sum2 /= k;

	cout << sum1 << "/" << sum2 << endl;
}