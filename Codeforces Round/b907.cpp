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

void solve(){
	int n; cin >> n;
	vi a(n);
	map<int,int> used;
	map<int,int> freq;

	forn(i,n){
		cin >> a[i];

		freq[a[i]]++;
	}

	int tr = 0;
	stack<int> st;

	forn(i,n){
		if(tr == 2){
			break;
		}

		if(freq[a[i]] > 1 && !used[a[i]]){
			used[a[i]] = 1;
			tr++;
			st.push(a[i]);
		}
	}

	if(tr < 2){
		cout << -1 << endl;
	}

	else{
		int fir = st.top(); st.pop();
		int sir = st.top(); st.pop();

		int ay = 0;
		int by = 0;

		forn(i,n){
			if(a[i] == fir){
				if(ay == 0){
					cout << 3 << " ";
					ay++;
				}

				else{
					cout << 1 << " ";
				}
			}

			else if(a[i] == sir){
				if(by == 0){
					cout << 2 << " ";
					by++;
				}

				else{
					cout << 1 << " ";
				}
			}

			else{
				cout << 1 << " ";
			}
		}

		cout << endl;
	}
}

signed main(){
	setIO(); int t; cin >> t;

	while(t--){
		solve();
	}
}