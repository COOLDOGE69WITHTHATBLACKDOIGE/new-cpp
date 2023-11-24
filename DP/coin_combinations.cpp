#include<bits/stdc++.h>
using namespace std;
#define ll long long

void setIO(string name = "") { 

	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

const int MOD = 1000000007;
ll dp[1000001];

int main(){
	#define int ll
	setIO();
	int n, x;
	cin >> n >> x;

	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}

	dp[0] = 1;

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < x+1; ++j){
			if(j - a[i] >= 0){
				dp[j] += dp[j-a[i]];
				dp[j] %= MOD;
			}
		}
	}

	cout << dp[x] << endl;
}