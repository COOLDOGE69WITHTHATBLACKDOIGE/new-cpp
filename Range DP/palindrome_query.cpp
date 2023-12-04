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

int dp[5000][5000];

signed main(){
	string s;
	cin >> s;

	int q;
	cin >> q;

	string d[s.size()][s.size()];
	string r[s.size()][s.size()];

	forn(i,s.size()){
		forrange(j,i,s.size()){
			if(i == j){
				d[i][j] = s[i];
			}

			else{
				d[i][j] = d[i][j-1] + s[j];
			}
		}
	}

	forn(i,s.size()){
		forrange(j,i,s.size()){
			if(i == j){
				r[i][j] = s[i];
			}

			else{
				r[i][j] = s[j] + r[i][j-1];
			}
		}
	}

	for(int len = 1; len <= s.size(); ++len){
		for(int l = 0; l < s.size() - len + 1; ++l){
			int r = l + len - 1;

			if(l == r){
				dp[l][r] = 1;
			}

			else{
				if(len % 2 == 1){
					
				}
			}
		}
	}
}