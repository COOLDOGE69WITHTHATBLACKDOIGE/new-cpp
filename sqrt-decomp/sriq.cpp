#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
// #define _GLIBCXX_DEBUG 1
// #define _GLIBCXX_DEBUG_PEDANTIC 1
// #pragma GCC optimize("trapv")

#define dbg(TXTMSG) cerr << "\n" << TXTMSG
#define dbgv(VARN) cerr << "\n" << #VARN << " = "<< VARN << ", line: " << __LINE__ << "\n"

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

#define MOD 1000000007

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

const int M = 1e5+5;

struct FT{
	vi ft;
	int n;

	FT(int x): ft(x,0), n(x){};

	void update(int k, int x){
		while(k < n){
			ft[k] += x;
			k += k&-k;
		}
	}

	int query(int k){
		int s = 0;

		while(k > 0){
			s += ft[k];
			k -= k&-k;
		}

		return s;
	}
};

FT f(M);

vi a;
int block_size;

struct Query{
	int left,right,index;
};

bool comp(const Query &a, const Query &b){
	int x = a.left/block_size;
	int y = b.left/block_size;

	if(x == y){
		return a.right < b.right;
	}

	return a.left < b.left;
}

int res = 0;

void radd(int ind){
	int j = a[ind];
	f.update(j,1);
	int h = f.query(M) - f.query(j);

	res += h;
}

void rremove(int ind){
	int j = a[ind];
	int h = f.query(M) - f.query(j);
	f.update(j,-1);
	res -= h;
}

void ladd(int ind){
	int j = a[ind];
	int h = f.query(j-1);
	f.update(j,1);

	res += h;

}

void lremove(int ind){
	int j = a[ind];
	f.update(j,-1);
	int h = f.query(j-1);

	res -= h;
}

int mo_left = 0;
int mo_right = -1;

int query(int l, int r){
	while(mo_right < r){
		mo_right++;
		radd(mo_right);
	}

	while(mo_right > r){
		rremove(mo_right);
		mo_right--;
	}

	while(mo_left > l){
		mo_left--;
		ladd(mo_left);
	}

	while(mo_left < l){
		lremove(mo_left);
		mo_left++;
	}

	return res;
}

signed main(){
	setIO();
	int n,q;
	cin >> n >> q;

	block_size = sqrt(n);

	a.resize(n);
	vi b(n);

	forn(i,n){
		cin >> b[i];
	}

	vi g;
	g = b;

	sort(all(g));

	forn(i,n){
		auto k = lower_bound(all(g),b[i]);

		int x = k - g.begin() + 1;
		a[i] = x;
	}

	vector<Query> Q(q);

	forn(i,q){
		cin >> Q[i].left >> Q[i].right;
		Q[i].right--;

		Q[i].index = i;
	}

	sort(all(Q),comp);
	vi ans(q);

	for(Query t : Q){
		int w = t.left;
		int u = t.right;

		ans[t.index] = query(w,u);
	}

	forn(i,q){
		cout << ans[i] << endl;
	}
}