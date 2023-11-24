#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;

	char arr[n][n];
	bool trap[n][n];

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> arr[i][j];

			if(arr[i][j] == '.'){
				trap[i][j] = false;
			}

			else{
				trap[i][j] = true;
			}
		}
	}

	vector<vector<int>> dp(n, vector<int>(n, 0));
	dp[0][0] = 1;


	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(trap[i][j]){
				dp[i][j] = 0;
			}

			else{
				if(i > 0){
					dp[i][j] += dp[i-1][j];
				}
				if(j > 0){
					dp[i][j] += dp[i][j-1];
				}
			}

			dp[i][j] %= 1000000007;
		}
	}

	cout << dp[n-1][n-1] << endl;
}

/*
10
.*......*.
...*...*..
......*...
...*.*....
....*.....
..*..*....
..*.......
....*..*..
*........*
....*.....
*/