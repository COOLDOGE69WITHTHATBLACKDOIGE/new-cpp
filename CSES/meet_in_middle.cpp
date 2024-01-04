#include<bits/stdc++.h>
using namespace std;
 
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

int sum[(1 << 20)];
int sum2[(1 << 20)];

signed main(){
	setIO();
	int n,x;

	cin >> n >> x;

	vi a(n);

	forn(i,n){
		cin >> a[i];
	}

	vi sum1;
	vi sum2;

	int half = n/2;
	int oth = n - half;

	forn(mask,(1 << half)){
		int g = 0;
		forn(i,half){
			if(mask & (1 << i)){
				g += a[i];
			}
		}

		sum1.pb(g);
	}

	forn(mask,(1 << oth)){
		int g = 0;
		forn(i,oth){
			if(mask & (1 << i)){
				g += a[half + i];
			}
		}

		sum2.pb(g);
	}

	sort(all(sum1));
	sort(all(sum2));

	int ptr1 = 0;
	int res = 0;

	for(int k : sum1){
		int high = upper_bound(all(sum2),x-k) - sum2.begin();
		int low = lower_bound(all(sum2),x-k) - sum2.begin();

		res += high - low;
	}

	cout << res << endl;
}