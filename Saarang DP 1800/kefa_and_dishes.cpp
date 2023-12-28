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
 
int cnt_bits(int mask){
	return __builtin_popcount(mask);
}
 
int dp[(1 << 18)][18];
int cst[18][18];

signed main(){
	setIO();
	int n,m,k;
	cin >> n >> m >> k;
	vi a(n);
 
	forn(i,n){
		cin >> a[i];
	}
 
	forn(i,k){
		int ir,j; cin >> ir >> j;
		cin >> cst[ir-1][j-1];
	}

    int res = 0;
 
	forn(mask,(1 << n)){
		forn(i,n){
			if((1 << i) & mask){
                dp[mask][i] = max(dp[mask][i],a[i]);
				forn(j,n){
					if(i == j || !(mask & (1 << j))){
                        continue;
                    }

                    else{
                        dp[mask][i] = max(dp[mask][i],dp[mask ^ (1 << i)][j] + cst[j][i] + a[i]);
                    }
				}

                if(cnt_bits(mask) == m){
                    res = max(res,dp[mask][i]);
                }
			}
		}
	}
 
	cout << res << endl;
}