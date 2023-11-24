#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#pragma GCC optimize("trapv")

#define dbg(TXTMSG) cerr << "\n" << TXTMSG
#define dbgv(VARN) cerr << "\n" << #VARN << " = "<< VARN << ", line: " << __LINE__ << "\n"

#define ll long long
#define ld long double
#define int ll
#define forn(i,j) for(ll i = 0; i < j; i++)
#define forrange(i,j,k) for(int i = j; i < k; ++i)
#define rof(i,j) rof(int i = j; i >= 0; --i)
#define pii pair<int,int>
#define vll vector<ll>
#define vi vector<int>
#define vvll vector<vll>
#define vvi vector<vi>
#define vb vector<bool>
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define eb emplace_back
#define qi queue<int>
#define qpii queue<pii>

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
	setIO("input");
	int n,m,t;
	cin >> n >> m >> t;

	string s;

	cin >> s;

	int p[n+1][m];
	vvi dist(m, vi(m, (int)1e10));

	forn(i,m){
		p[0][i] = 0;
	}

	forn(i,m){
		forn(j,m){
			int f;
			cin >> f;

			dist[i][j] = min(dist[i][j],f);
		}
	}

	forn(k,m){
		forn(i,m){
			forn(j,m){
				int curr = dist[i][k] + dist[k][j];

				if(curr < dist[i][j]){
					dist[i][j] = curr;
				}
			}
		}
	}

	forn(i,m){
		forrange(j,1,n+1){
			p[j][i] = p[j-1][i] + dist[s[j-1] - 'a'][i];
		}
	}

	int M = (int)1e10;

	int mn[n+1];
	int dp[n+1][m];
	memset(dp, 63, sizeof dp);
    memset(mn, 63, sizeof mn);

	mn[0] = 0;

	forrange(i,1,n+1){
		forn(j,m){
			dp[i][j] = min(dp[i-1][j] + dist[s[i-1] - 'a'][j], dp[i][j]);

            if (i >= t) dp[i][j] = min(dp[i][j], p[i][j]- p[i-t][j] + mn[i-t]);

            mn[i] = min(mn[i], dp[i][j]);
		}
	}

	cout << mn[n] << endl;
}