#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define forn(i,j) for(ll i = 0; i < j; i++)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin, x.end()
#define eb emplace_back

#define MOD 1000000007

void siout(string name = "") { 

	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

vector<ll> dp(1000001, INT_MAX);

int main(){

	ll n,x;
	cin >> n >> x;
	vector<ll> c(n+1);

	for(int i = 0; i < n; ++i){
		cin >> c[i];
		dp[c[i]] = 1;
	}

	for(int i = 0; i < x+1; ++i){
		for(int j = 0; j < n; ++j){
			if(i - c[j] >= 0){
				dp[i] = min(dp[i], dp[i-c[j]]+1); 
			}
		}
	}

	if(dp[x] > 1000001){
		cout << -1 << endl;
	}

	else{
		cout << dp[x] << endl;
	}
}