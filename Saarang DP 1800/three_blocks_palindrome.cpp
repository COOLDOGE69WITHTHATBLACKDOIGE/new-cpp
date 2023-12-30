#include<bits/stdc++.h>
using namespace std;
 
// #define _GLIBCXX_DEBUG 1
// #define _GLIBCXX_DEBUG_PEDANTIC 1
// #pragma GCC optimize("trapv")

// #define dbg(TXTMSG) cerr << "\n" << TXTMSG
// #define dbgv(VARN) cerr << "\n" << #VARN << " = "<< VARN << ", line: " << __LINE__ << "\n"

#define ld long double
#define ll long long
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

// const int MOD = 1e9 + 7;
// const int INF = 1e17 + 1;
// const int maxN = 2e5 + 1;

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

void solve(){
	int n; 
	cin >> n;

	vi a(n);
	int freq[201][n+1];

	forn(i,n){
		cin >> a[i];
	}

	forrange(j,1,201){
		freq[j][0] = 0;
		forrange(i,1,n+1){
			freq[j][i] = freq[j][i-1] + (a[i-1] == j);
		}
	}

	int res = 0;

	forrange(j,1,201){
		res = max(freq[j][n],res);
		int pos[n+1];

		forrange(i,1,n+1){
			if(a[i-1] == j){
				pos[freq[j][i]] = i;
			}
		}

		forrange(i,1,201){
			if(freq[j][n] < i){
				break;
			}

			int l = pos[i];
			int r = pos[freq[j][n] - i + 1];

			if(r <= l){
				break;
			}

			forrange(b,1,201){
				if(b == j){
					continue;
				}

				res = max(res,freq[b][r-1] - freq[b][l] + 2*(i));
			}
		}
	}

	cout << res << endl;
}

signed main(){
	setIO();
	int t;
	cin >> t;

	while(t--){
		solve();
	}
}