#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define forn(i,j) for(ll i = 0; i < j; i++)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<vector<int>>
#define vll vector<ll>
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define eb emplace_back

#define MOD 1000000007

void setIO(string name = "") { 

	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

struct Member{
	ll aud;

	vector<ll> player;

	bool operator>(const Member &m) const{
		return aud > m.aud;
	}
};

int main(){
	setIO();
	ll n,p,k;
	cin >> n >> p >> k;

	Member m;
	m.player = vector<ll>(p);

	vector<Member> M(n+1, m);


	for(ll i = 1; i < n+1; ++i){
		cin >> M[i].aud;
	}

	for(ll i = 1; i < n+1; ++i){
		for(ll j = 0; j < p; ++j){
			cin >> M[i].player[j];
		}
	}
	sort(M.begin(), M.end(), greater<>());

	vector<vll> dp(n + 1, vll(1 << p, -1e17));

	dp[0][0] = 0;

	for(ll i = 1; i < n+1; ++i){
		for(ll j = 0; j < 1 << p; ++j){
			for(ll l = 0; l < p; ++l){

				if(j & (1 << l)){
					dp[i][j] = max(dp[i][j], dp[i-1][j - (1 << l)] + M[i].player[l]);
				}

				if (i - __builtin_popcount(j) <= k){
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + M[i].aud);
                }

				else{
					dp[i][j] = max(dp[i][j], dp[i-1][j]);
				}
			}
		}
	}

	cout << dp[n][(1 << p) - 1] << endl;
}