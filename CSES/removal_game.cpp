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

const int MOD = 1e12 + 7;
const int INF = 1e17 + 1;

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

pii t = {-MOD,-MOD};
vector<vector<pii>> dp1(5002, vpii(5002,t));
vector<vector<pii>> dp2(5002, vpii(5002,t));

void vall(){
	forn(i,5002){
		forn(j,5002){
			dp1[i][j] = t; dp2[i][j] = t;
		}
	}
}

signed main(){
	setIO("input");
	int n;
	cin >> n;
	vi a(n); forn(i,n){ cin >> a[i];}

	forn(i,n){
		dp1[i][i] = make_pair(a[i],0);
		dp2[i][i] = make_pair(0,a[i]);
	}

	forrange(len,2,n+1){
		forn(l,n-len+1){
			int r = l + len - 1;
			if(dp1[l][r].f < dp2[l+1][r].f + a[l]){
				dp1[l][r].f = dp2[l+1][r].f + a[l];
				dp1[l][r].s = dp2[l+1][r].s;
			}

			if(dp1[l][r].f < dp2[l][r-1].f + a[r]){
				dp1[l][r].f = dp2[l][r-1].f + a[r];
				dp1[l][r].s = dp2[l][r-1].s;
			}

			if(dp2[l][r].s < dp1[l+1][r].s + a[l]){
				dp2[l][r].s = dp1[l+1][r].s + a[l];
				dp2[l][r].f = dp1[l+1][r].f;
			}

			if(dp2[l][r].s < dp1[l][r-1].s + a[r]){
				dp2[l][r].s = dp1[l][r-1].s + a[r];
				dp2[l][r].f = dp1[l][r-1].f; 
			}
		}
	}

	cout << dp1[0][n-1].f << endl;
	cout << dp1[0][n-1].s << endl;
}