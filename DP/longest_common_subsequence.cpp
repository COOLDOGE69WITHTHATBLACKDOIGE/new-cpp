#include<bits/stdc++.h>
using namespace std;

void setIO(string name = " "){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
	setIO("subsequence");
	string text1;
	string text2;

	cin >> text1 >> text2;

	if(text1.empty() || text2.empty()){
		cout << 0 << endl;
	}

	int n = text1.size();
	int m = text2.size();

	vector<vector<int>> dp(n, vector<int>(m, 0));

	if(text1[0] == text2[0]){
		dp[0][0] = 1;
	}


	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(text1[i] == text2[j]){
				if((i-1) >= 0 && (j-1) >= 0){
					dp[i][j] = dp[i-1][j-1] + 1;
				}

				else{
					dp[i][j] = 1;
				}
			}

			else{
				if((i-1) >= 0){
					dp[i][j] = max(dp[i][j], dp[i-1][j]);
				}

				if((j-1) >= 0){
					dp[i][j] = max(dp[i][j], dp[i][j-1]);
				}
			}
		}
	}

	cout << dp[n-1][m-1] << endl;
}


/*
  a  b  c  e
a 1  1  1  1
c 1  1  2  2
e 1  1  2  3
*/