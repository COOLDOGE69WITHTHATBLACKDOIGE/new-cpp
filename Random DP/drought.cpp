#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#pragma GCC optimize("trapv")

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

vi h;
int n;

int dp[101][1001];
int pref[101][1002];

int solve(int x){
	memset(dp,0,sizeof(dp));
	memset(pref,0,sizeof(pref));
	vi b;
	b = h;

	forn(i,n){
		b[i] -= x;
	}

	forn(i,n){
		forn(j,b[i]+1){
			if(i == 0){
				dp[i][j] = 1;
				continue;
			}

			dp[i][j] += pref[i-1][b[i] - j + 1];
		}

		forrange(j,1,1003){
			pref[i][j] = pref[i][j-1] + dp[i][j-1];
		}
	}

	return dp[n-1][0];
}

signed main(){
	setIO("input");
	cin >> n;

	h.resize(n);
	int maxh = 0;
	int mn = MOD;

	forn(i,n){
		cin >> h[i];
		maxh = max(maxh,h[i]);
		mn = min(mn,h[i]);
	}

	if(n % 2 == 0){
		int ans = solve(0);

		cout << ans << endl;
	}

	else{
		int ans = 0;

		forn(i,mn+1){
			ans += solve(i);
		}

		cout << ans << endl;
	}
}