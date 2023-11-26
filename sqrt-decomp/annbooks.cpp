#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
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

#define MOD 1000000007

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int block_size;

struct Query{
	int left,right,index;
};

bool comp(Query &a, Query &b){
	int block1 = a.left/block_size;
	int block2 = b.left/block_size;

	if(block1 == block2){
		return a.right < b.right;
	}

	return a.left < b.left;
}

signed main(){
	setIO("input");
	int n,k;
	cin >> n >> k;

	vb math(n);
	vi a(n);
	vi psum(n);
	vi rival(n);
	vi viral(n);
	vector<Query> Q;

	block_size = sqrt(n);

	map<int,int> mp;

	forn(i,n){
		int a;
		cin >> a;
		if(a == 1){
			math[i] = true; 
		}

		else{
			math[i] = false;
		}
	}

	forn(i,n){
		int j;
		cin >> j;

		if(math[i]){
			a[i] = j;
		}

		else{
			a[i] = -j;
		}
	}

	psum[0] = a[0];

	forrange(i,1,n){
		psum[i] = psum[i-1]+a[i];
	}

	vi u(n);

	u = psum;

	sort(all(u));

	forn(i,n){
		int g = u[i];

		if(mp[g] == 0){
			mp[g] = i+1;
		}

		else{
			continue;
		}
	}

	vpii j(n);

	forn(i,n){
		int index = mp[psum[i]] - 1;

		j[i] = {psum[i],index};
	}

	u.clear();

	forn(i,n){
		int h = psum[i] - k;
		int t = mp[h];
		if(t == 0){
			rival[i] = -1;
		}

		else{
			rival[i] = t-1;
		}

		h = k - psum[i];
		t  = mp[h];

		if(t == 0){
			viral[i] = -1;
		}

		else{
			viral[i] = t-1;
		}
	}

	psum.clear();

	int q;
	cin >> q;

	forn(i,q){
		Query w;

		cin >> w.left >> w.right;
		w.left--;
		w.right--;

		w.index = i;

		Q.pb(w);
	}

	sort(all(Q),comp);

	int mo_left = -1;
	int mo_right = -1;

	vi occ(n);
	vi ans(q);
	int res = 0;

	for(Query t : Q){
		int l = t.left;
		int r = t.right;

		while(mo_right < r){
			mo_right++;
			occ[j[mo_right].s]++;

			if(rival[mo_right] != -1){
				res += occ[rival[mo_right]];
			}
		}

		while(mo_left > l){
			mo_left--;
			occ[j[mo_left].s]++;

			if(viral[mo_left] != -1){
				res += occ[viral[mo_left]];
			}
		}

		while(mo_right > r){
			if(rival[mo_right] != -1){
				res -= occ[rival[mo_right]];
			}

			occ[j[mo_right].s]--;
			mo_right--;
		}

		while(mo_left < l){
			if(viral[mo_left] != -1){
				res -= occ[viral[mo_left]];
			}

			occ[j[mo_left].s]--;
			mo_left++;
		}

		ans[t.index] = res;
	}

	forn(i,q){
		cout << ans[i] << endl;
	}
}