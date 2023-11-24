#include<bits/stdc++.h>
using namespace std;
#define ll long long


void siout(string name = "") { 

	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
	#define int ll
	siout("snakes");
	int n, k;
	cin >> n >> k;

	vector<int> a(n);

	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}

    int dp[n][k+1];

    int total_area = 0;

	int largest = -1;

	for(int i = 0; i < n; ++i){
		
		largest = max(largest, a[i]);
		
		dp[i][0] = largest * (i+1);

		total_area+=a[i];

		for(int j = 1; j <= k; ++j){
			dp[i][j] = INT32_MAX;
			int curr = a[i];
			for (int g = i - 1; g >= 0; g--) {
				dp[i][j] = min(dp[i][j], dp[g][j - 1] + curr * (i - g));
				curr = max(curr, a[g]);
			}
		}
	}

	cout << dp[n-1][k] - total_area << endl;
}
	