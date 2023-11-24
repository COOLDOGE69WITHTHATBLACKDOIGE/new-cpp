#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#pragma GCC optimize("trapv")

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

const int M = 100000000;

int n,q;
int block_size;
vi values(M);
vi val;
int diff = 0;

struct Query{
	int x,y,ind;
};

bool comp(Query &a, Query &b){
	int h = a.x/block_size;
	int j = b.x/block_size;

	if(h == j){
		return a.y < b.y;
	}

	return a.x < b.x;
}

void add(int ind){
	values[val[ind]]++;

	if(values[val[ind]] == 1){
		diff++;
	}
}

void remove(int ind){
	values[val[ind]]--;

	if(values[val[ind]] == 0){
		diff--;
	}
}

signed main(){
	cin >> n >> q;
	block_size = sqrt(n);

	val.resize(n);

	forn(i,n){
		cin >> val[i];
	}

	vi ans(q);

	vector<Query> Q;
	int a = 0;

	forn(i,q){
		Query m;
		cin >> m.x >> m.y;

		m.ind = i;
		m.x--;
		m.y--;

		Q.pb(m);
	}

	sort(all(Q),comp);
	int mleft = -1;
	int mright = -1;

	forn(i,q){
		int left = Q[i].x;
		int right = Q[i].y;

		while(mright < right){
			mright++;
			add(mright);
		}

		while(mleft > left){
			mleft--;
			add(mleft);
		}

		while(mright > right){
			remove(mright);
			mright--;
		}

		while(mleft < left){
			remove(mleft);
			mleft++;
		}

		

		ans[Q[i].ind] = diff;
	}

	forn(i,q){
		cout << ans[i] << endl;
	}
}