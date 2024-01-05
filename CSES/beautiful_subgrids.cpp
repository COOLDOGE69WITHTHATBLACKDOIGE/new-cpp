#include<bits/stdc++.h>
using namespace std;

#pragma GCC target("popcnt")
 
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
const int maxN = 3e3 + 1;

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

bitset<maxN> bt[maxN];

signed main(){
	setIO();
	int n;
	cin >> n;

	forn(i,n){
		string str;
		cin >> str;

		forn(j,n){
			if(str[j] == '1'){
				bt[i].set(n - 1 - j);
			}
		}
	}

	int res = 0;

	forn(i,n){
		forrange(j,i+1,n){
			int cnt = (bt[i] & bt[j]).count();

			cnt *= (cnt - 1); cnt /= 2;
			res += cnt;
		}
	}

	cout << res << endl;
}