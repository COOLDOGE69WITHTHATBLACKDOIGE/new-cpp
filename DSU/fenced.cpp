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
	int wt;
	int x,y;
};

bool comp(Edge &a, Edge &b){
	return a.wt < b.wt;
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
	setIO();
	int A,B,n,m;
	cin >> A >> B >> n >> m;

	vi a(n+1);
	vi b(n+1);
	vector<Edge> e;
	dsu d(100000);

	forrange(i,1,n+1){
		cin >> a[i];
	}

	a.pb(A);

	forrange(i,1,m+1){
		cin >> b[i];
	}

	b.pb(B);

	sort(all(a));
	sort(all(b));

	int curr = 0;
	int row = 1;

	while(row < m+2){
		forn(i,n){
			Edge c;
			c.wt = b[row] - b[row-1];
			c.x = curr;
			c.y = curr+1;

			e.pb(c);
			curr++;
		}

		curr++;
		row++;
	}

	curr = n+1;
	int col = 1;

	while(col < n+2){
		int prev = curr;
		forn(j,m){
			Edge c;
			c.wt = a[col] - a[col-1];
			c.x = curr;
			c.y = curr - (n+1);

			e.pb(c);
			curr += n+1;	
		}

		curr = prev + 1;
		col++;
	}

	int sum = 0;

	sort(all(e), comp);

	for(Edge f : e){
		if(d.unite(f.x, f.y)){
			sum += f.wt;
		}
	}

	cout << sum << endl;
}