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
#define vpii vector<pii>
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

struct dsu{
	vi e;
	vvi comp;

	dsu(int n){
		e = vi(n,-1);
		comp = vvi(n);

		forn(i,n){
			comp[i].pb(i);
		}
	}

	int get(int a){
		return e[a] < 0 ? a : e[a] = get(e[a]);
	}

	bool unite(int a, int b, vi &val, vi &ans){
		int curr = val[b];
		a = get(a);
		b = get(b);

		if(a == b){
			return false;
		}

		if(val[a] == val[b]){
			for(int i : comp[a]){
				comp[b].pb(i);
			}

			comp[a].clear();
			e[a] = b;

			return true;
		}

		if(val[a] > val[b]){ swap(a,b);}

		if(val[a] < val[b]){
			for(int i : comp[a]){
				if(curr > val[i]){
					ans[i] = 0;
				}

				else{
					ans[i] = val[i] - curr;
				}
			}

			comp[a].clear();
			e[a] = b;

			return true;
		}

		return false;
	}
};

int main(){
	setIO();
	int n, m;
	cin >> n >> m;

	dsu d(n*m);
	vi val(n*m);
	vi ans(n*m);
	vpii cell;

	forn(i, n*m){
		cin >> val[i];
		ans[i] = val[i];

		cell.pb({val[i],i});
	}

	sort(all(cell));

	while(!cell.empty()){
		pii h = cell.back();
		cell.pop_back();

		int curr = h.s;

		if(curr - m >= 0 && val[curr-m] >= val[curr]){
			d.unite(curr-m,curr,val,ans);
		}

		if(curr + m < (m*n) && val[curr] <= val[curr+m]){
			d.unite(curr+m,curr,val,ans);
		}

		if(curr % m != 0 && val[curr - 1] >= val[curr]){
			d.unite(curr-1,curr,val,ans);
		}

		if((curr+1)%m != 0 && val[curr + 1] >= val[curr]){
			d.unite(curr+1,curr,val,ans);
		}
	}

	forn(i,n*m){
		if((i+1)%m == 0){
			cout << ans[i] << endl;
		}

		else{
			cout << ans[i] << ' ';
		}
	}
}