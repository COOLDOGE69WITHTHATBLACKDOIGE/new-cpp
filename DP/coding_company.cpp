#include<bits/stdc++.h>
using namespace std;

#define ll long long

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
const int C = (int)5e3;
const int MOD = (int)1e9+7;

int main(){
	#define int ll
	setIO();	
	int n, x;
	cin >> n >> x;

	int skill[n];

	int dp[2][101][x+C+1];

	for(int i = 0; i < n; ++i){
		cin >> skill[i];
	}

	sort(skill, skill+n);

	for(int i = C; i <+ x+C; ++i){
		dp[0][0][i] = 1;
	}
	
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < (n-i)+1; ++j){
			for(int k = C; k < x+C+1; ++k){
				if (!dp[0][j][k]) { continue; }

				dp[1][j][k] += dp[0][j][k];  // i has their own group

				if (j && k + skill[i] <= x + C) {
					dp[1][j - 1][k + skill[i]] += j * dp[0][j][k];  // finish group
				}

				if (j + 1 <= n - (i + 1)) {
					dp[1][j + 1][k - skill[i]] += dp[0][j][k];  // create new unfinished group
				}

				if (j <= n - (i + 1)) {
					dp[1][j][k] += j * dp[0][j][k];  // extend unfinished group
				}
			}
		}

		//resetting values
		for(int j = 0; j < 100; ++j){  //j = 0
			for(int k = C; k <= x+C; ++k){   // K = 5000
				dp[0][j][k] = dp[1][j][k] % MOD;  // dp[0] is the new dp[1] (in order to progress)
				dp[1][j][k] = 0; //resetting the value 
			}
		}
	}

	int s = 0;

	for(int i = C; i <= x+C; ++i){
		s+= dp[0][0][i];
		s = s % MOD;
	}

	cout << s << endl;
}