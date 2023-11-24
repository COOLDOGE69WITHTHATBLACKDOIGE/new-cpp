#include<bits/stdc++.h>
using namespace std;

#define ll long long;

int main(){
	int n,x; //n = 4, x = 10
	cin >> n >> x;
	vector<int> cost(n), pages(n);

	for(int i = 0; i < n; ++i){
		cin >> cost[i];   //{4,8,5,3}
	}

	for(int i = 0; i < n; ++i){
		cin >> pages[i];  //{5,12,8,1}
	}

	int dp[n][x+1];
	memset(dp, 0, sizeof(dp)); //dp = {0,0,0,0,0,0,0,0,0,0,0}

	for(int j = cost[0]; j < x+1; ++j){
		dp[0][j] = pages[0];
	}

	for(int i = 0; i < n; ++i){
		int curr_cost = cost[i];   //curr_cost = 4
		int curr_page = pages[i];  //curr_page = 5

		for(int j = 1; j < x+1; ++j){
			if(i > 0){
				dp[i][j] = max(dp[i][j], dp[i-1][j]);  //dp[0][1], dp[0][2], dp[0][3] = 0, dp[0][4] = 5

				if(j >= curr_cost){
					dp[i][j] = max(dp[i][j], dp[i-1][j- curr_cost] + curr_page);
				}
			}
		}
	}

	cout << dp[n-1][x] << endl;
}