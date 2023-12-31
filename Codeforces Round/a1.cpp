#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> T;
 
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

const int MOD = 1e9 + 7;
const int INF = 1e17 + 1;
const int maxN = 2e5 + 1;

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}


signed main(){
	setIO("input");
	int q;
	cin >> q;

	while(q--){
		int n,k;
		cin >> n >> k;

		vi b(n);

		int t = 0;
		vi c; c.pb(7); c.pb(17);
		vi freq(2,0);

		forn(i,n){
			cin >> b[i];

			forn(j,2){
				if(b[i] == c[j]){
					t++;
					freq[j]++;
				}
		}

		if(t < n){
			cout << "NO" << endl;
		}

		else{
			int res = 3 - freq[0] - freq[1];
			if((freq[0] > 1) || (freq[1] > 2) || (res > k)){
				cout << "NO" << endl;
			}

			else{
				cout << "YES" << endl;
				int bd = k;

				if(freq[0] < 1){
					cout << 7 << " ";
					freq[0]++;
					bd--;
				}

				if(freq[1] < 2){
					while(freq[1] < 2){
						cout << 17 << " ";
						freq[1]++;
						bd--;
					}
				}

				forn(i,bd){
					cout << 1 << " ";
				}

				cout << endl;
			}	
	 	}
	}
}
}