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


signed main(){
	setIO("248");
	int n;
	cin >> n;
	vi a(n);
	forn(i,n){
		cin >> a[i];
	}

	int ans = -1;
	vvi dp(n+1,vi(n+1,-1));

	for(int len = 1; len <= n; ++len){
		for(int l = 0; l < n - len + 1; ++l){
			int r = len + l - 1;

			if(r == l){
				dp[l][r] = a[l];
				continue;
			}

			for(int j = l; j < r; ++j){
				if(dp[l][j] != -1 && dp[l][j] == dp[j+1][r]){
					dp[l][r] = max(dp[l][r], dp[l][j]+1);	
				}
			}

			ans = max(ans, dp[l][r]);
		}
	}

	cout << ans << endl;
}