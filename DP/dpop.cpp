#include<bits/stdc++.h>
using namespace std;

void siout(string name = "") { 

	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
	siout("teamwork");
	int n, k;
	cin >> n >> k;

	vector<int> a(n);

	for(int i = 0; i < n; ++i){ cin >> a[i];}

	vector<int> dp(n, -1);

	for(int i = 0; i < n; ++i){
		int curr = a[i];
		for(int j = i; j > i-k && ~j; j--){
			curr = max(a[j], curr);
			if(j > 0){
				dp[i] = max(dp[i], dp[j-1] + (curr*(i-j+1)));
			}
			
			else{
				dp[i] = max(dp[i], curr*(i-j+1));
			}
		}
	}

	cout << dp[n-1] << endl;
}
	