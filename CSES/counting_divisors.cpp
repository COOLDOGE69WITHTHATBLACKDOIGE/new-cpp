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
const int PR = 1001;

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

vi primes;
bool p[PR+1];

int cnt_div(int num){
	int res = 1;

	for(int k : primes){
		if(k*k > num){
			break;
		}

		if(num % k == 0){
			int e = 1;
			num = num/k;

			while((num % k) == 0){
				e++;
				num = num/k;
			}

			res *= (e+1);
		}
	}

	if(num > 1){
		res *= 2;
		num = 1;
	}

	return res;
}

signed main(){
	setIO();

	forrange(i,2,PR+1){
		if(!p[i]){
			primes.pb(i);

			for(int k = i; k < PR+1; k += i){
				p[k] = true;
			}
		}
	}

	int t; cin >> t;

	while(t--){
		int n; cin >> n;

		cout << cnt_div(n) << endl;
	}
}