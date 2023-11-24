#include<bits/stdc++.h>
using namespace std;

#define ll long long;

int knapsack(vector<int> weight, vector<int> value, int n, int s){
	int dp[n][s+1];
	memset(dp, 0, sizeof(dp)); //dp = {0,0,0,0,0,0,0,0,0,0,0}

	for(int j = weight[0]; j < s+1; ++j){
		dp[0][j] = value[0];
	}

	for(int i = 0; i < n; ++i){
		int curr_cost = weight[i];   //curr_cost = 4
		int curr_page = value[i];  //curr_page = 5

		for(int j = 1; j < s+1; ++j){
			if(i > 0){
				dp[i][j] = max(dp[i][j], dp[i-1][j]);  //dp[0][1], dp[0][2], dp[0][3] = 0, dp[0][4] = 5

				if(j >= curr_cost){
					dp[i][j] = max(dp[i][j], dp[i-1][j- curr_cost] + curr_page);
				}
			}
		}
	}

	return dp[n-1][s];
}

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".our").c_str(), "r", stdout);
	}
}

int main(){
	int s, value_types;
	cin >> s >> value_types;

	vector<int> weight;
	vector<int> value;
	int n = -1;

	for(int i = 0; i < n; ++i){
		int val, wgt, copies;
		cin >> val >> wgt >> copies;
		int j = s/wgt;
		copies = min(copies,j);

		if(copies == 0){
			continue;
		}

		else{
			while(copies--){
				n+=copies;
				value.push_back(val);
				weight.push_back(wgt);
			}
		}
	}

	cout << knapsack(weight, value, n, s) << endl;
}