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

int fact[501];
int rfact[501];
int dp[500][500];

int bpower(int a, int b){
	int ans = 1;
	while(b > 0){
		if(b % 2 == 1){
			ans *= a;
			ans %= MOD;
		}

		a *= a;
		a %= MOD;
		b /= 2;
	}

	return ans;
}

void facto(){
	fact[0] = 1;

	forrange(i,1,501){
		fact[i] = fact[i-1]*i;
		fact[i] %= MOD;
	}
}

void rfacto(){
	rfact[0] = 1;
	forrange(i,1,501){
		rfact[i] = bpower(fact[i],MOD-2);
	}
}

int nck(int n, int k){
	if(k > n){
		return 0;
	}

	int j = fact[n]*rfact[k]*rfact[n-k];

	j %= MOD;

	return j;
}

signed main(){
	setIO("input");
	string str;
	cin >> str;
	int n = str.size();

	facto();
	rfacto();

	forrange(len,1,n+1){
		forn(l,n-len+1){
			int r = r + len - 1;

			if(l == r){
				dp[l][r] = 0;
			}

			if(l == r-1){
				if(str[l] == str[r]){
					dp[l][r] = 1;
				}
			}

			else{
				for(int j = l+1; j <= r; ++j){
					if(str[l] == str[j]){
						if(j == r){
							dp[l][r] += dp[l+1][j-1];	
						}

						else{
							int h = (r - l + 1)/2;
							int g = (j - l + 1)/2;	

							dp[l][r] += dp[l+1][j-1]*dp[j+1][r]*nck(h,g);
							dp[l][r] %= MOD;
						}
					}
				}
			}
		}
	}

	cout << dp[0][n-1] << endl;
}