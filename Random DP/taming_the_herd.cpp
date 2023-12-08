#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
// #define _GLIBCXX_DEBUG 1
// #define _GLIBCXX_DEBUG_PEDANTIC 1
// #pragma GCC optimize("trapv")

#define dbg(TXTMSG) cerr << "\n" << TXTMSG
#define dbgv(VARN) cerr << "\n" << #VARN << " = "<< VARN << ", line: " << __LINE__ << "\n"

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
	setIO("taming");
	int n;
	cin >> n;

	vi a(n);

	forn(i,n){
		cin >> a[i];
	}

	vvi diff(n,vi(n,0));
	vvi dp(n+1,vi(n,MOD));

	forrange(len,1,n+1){
		forn(l,n - len + 1){
			int r = l + len - 1;
			int t = len - 1;

			if(r == 0){
				if(a[r] == 0){
					diff[l][r] = 0;
				}

				else{
					diff[l][r] = 1;
				}
			}

			else{
				if(a[r] == t){
					diff[l][r] = diff[l][r-1];
				}

				else{
					diff[l][r] = diff[l][r-1] + 1;
				}	
			}
		}
	}

	forrange(i,1,n+1){
		forrange(j,i-1,n){
			if(j == 0){
				if(a[j] == 0){
					dp[i][j] = 0;
				}

				else{
					dp[i][j] = 1;
				}
			}

			else{
				dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
				dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);

				if(j > a[j]){
					dp[i][j] = min(dp[i][j], dp[i-1][j - a[j] - 1] + diff[j-a[j]][j]);
				}

				else if(j == a[j] & i == 1){
					dp[i][j] = min(dp[i][j],diff[0][j]);
				}
			}
		}
	}

	forrange(i,1,n+1){
		cout << dp[i][n-1] << endl;
	}
}