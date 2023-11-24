#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define forn(i,j) for(ll i = 0; i < j; i++)
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define p push
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

ll dp[10000][256];

int main(){
	int n;
	cin >> n;

	vi a(n);
	vi k(n);
	forn(i,n){
		cin >> a[i];
	}

	forn(i,n){
		cin >> k[i];
	}

	ll mx = 1;

	for(int i = 1; i < n+1; ++i){  
		for(int mask = 0; mask < (1 << 8); ++mask){  
			if(__builtin_popcount(mask & a[i-1]) == k[i-1]){
				dp[i][a[i-1]] = max(dp[i][a[i-1]] , dp[i-1][mask]+1);
				mx = max(mx, dp[i][a[i-1]]);   
			}
		}

		for(int mask = 0; mask < (1 << 8); ++mask){
			dp[i][mask] = dp[i+1][mask];
		}
	}

	cout << mx << endl;
}

/*
4
1   2   3   4
10  0   1   0

*/