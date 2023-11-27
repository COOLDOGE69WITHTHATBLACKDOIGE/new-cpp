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

	vb meth(n);
	vi a(n);
	vi v(n+1);
	vi v1(n+1);
	vi v2(n+1);
	map<int,int> mp;

	block_size = sqrt(n);

	forn(i,n){
		int h;
		cin >> h;

		if(h == 1){
			meth[i] = true;
		}

		else{
			meth[i] = false;
		}
	}

	forn(i,n){
		int e;
		cin >> e;

		if(meth[i]){
			a[i] = e;
		}

		else{
			a[i] = -e;
		}
	}

	v[0] = 0;

	forrange(i,1,n+1){
		v[i] = v[i-1] + a[i-1];
	}

	vi u;
	u = v;
	sort(all(u));

	int t = 1;

	for(int d : u){
		if(mp[d] == 0){
			mp[d] = t;
			t++;
		}

		else{
			continue;
		}
	}

	vi j(n+1);

	forn(i,n+1){
		int r = mp[v[i]];
		r--;

		j[i] = r;

		int g = mp[v[i] - k];
		g--;

		v1[i] = g;

		g = mp[k - v[i]];
		g--;

		v2[i] = g;
	}

	int q;
	cin >> q;

	vector<Query> Q;

	forn(i,q){
		Query w;

		cin >> w.left >> w.right;

		w.index = i;
		Q.pb(w);
	}

	sort(all(Q),comp);

	int mo_left = -1;
	int mo_right = -1;

	vi occ(n+1);
	vi ans(q);
	int res = 0;

	for(Query o : Q){
		dbgv(o.index);
		int l = o.left;
		int r = o.right;

		while(mo_right < r){
			mo_right++;
			occ[j[mo_right]]++;

			if(v1[mo_right] != -1){
				res += occ[v1[mo_right]];
			}
		}

		while(mo_right > r){
			if(v1[mo_right] != -1){
				res -= occ[v1[mo_right]];
			}

			occ[j[mo_right]]--;
			mo_right--;
		}

		while(mo_left > l){
			mo_left--;
			occ[j[mo_left]]++;

			if(v2[mo_left] != -1){
				res += occ[v2[mo_left]];
			}
		}

		while(mo_left < l){
			if(mo_left == -1 || mo_left == 0){
				mo_left++;
				continue;
			}

			else{
				if(v2[mo_left] != -1){
					res -= occ[v2[mo_left-1]];
					res -= occ[v2[mo_left]];
				}

				occ[j[mo_left-1]]--;
				mo_left++;
			}
		}

		if(o.index == 2){
			dbgv(occ[1]);
		}

		ans[o.index] = res;
	}

	forn(i,q){
		cout << ans[i] << endl;
	}
}