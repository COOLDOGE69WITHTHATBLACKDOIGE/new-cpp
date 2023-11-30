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

struct Point{
	int next,steps,power;
};

int32_t main(){
	setIO();

	int n,m;
	cin >> n >> m;

	int block_size = sqrt(n);
	vector<Point> a(n);

	forn(i,n){
		int ak;
		cin >> ak;

		a[i].power = ak;
	}

	for(int t = n; t > 0; --t){
		int i = t;
		i--;

		int curr = i/block_size;
		int m = (i + a[i].power)/block_size;

		if(m > curr && (i+a[i].power) < n){
			a[i].next = i+a[i].power;
			a[i].steps = 1;
		}

		else if(i+a[i].power > n - 1){
			a[i].next = i;
			a[i].steps = 0; 
		}

		else{
			a[i].next = a[(i+a[i].power)].next;
			a[i].steps = a[(i+a[i].power)].steps + 1;
		}
	}

	while(m--){
		int type;
		cin >> type;

		if(!type){
			int index,p;
			cin >> index >> p;

			int i = index;
			i--;
			a[i].power = p;

			int curr_block = i/block_size;
			int new_block = (i+p)/block_size;

			if(new_block > curr_block && (i+p) < n){
				a[i].next = i+p;
				a[i].steps = 1;
			}

			else if(i+p > n-1){
				a[i].next = i;
				a[i].steps = 0;
			}

			else{
				a[i].next = a[i+p].next;
				a[i].steps = a[i+p].steps + 1;
			}

			int en = min(((curr_block+1)*block_size), n);
			int st = (((curr_block)*block_size) + 1);

			for(int t = en; t > st-1; --t){
				int i = t-1;

				int curr = i/block_size;
				int m = (i + a[i].power)/block_size;

				if(m > curr && (i+a[i].power) < n){
					a[i].next = i+a[i].power;
					a[i].steps = 1;
				}

				else if(i+a[i].power > n - 1){
					a[i].next = i;
					a[i].steps = 0; 
				}

				else{
					a[i].next = a[(i+a[i].power)].next;
					a[i].steps = a[(i+a[i].power)].steps + 1;
				}
			}
		}


		else{
			int index;
			cin >> index;

			int i = index;
			i--;
			int res = 0;

			while(i != a[i].next){
				res += a[i].steps;
				i = a[i].next;
			}

			cout << (i+1) << " " << (res+1) << endl;
		}
	}
}