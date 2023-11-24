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

void setIO(string name = "") { 

	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

vector<vector<int>> dp(5001, vector<int>(5000, INT_MAX));

int main(){
	string str1;
	string str2;

	cin >> str1 >> str2;

	int n = str1.size();
	int m = str2.size();

	if(str1[0] != str2[0]){
		dp[0][0] = 1;
	} else{
		dp[0][0] = 0;
	}

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(i > 0){
				dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
			}

			if(j > 0){
				dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
			}

			if(i > 0 && j > 0){
				dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (str1[i] != str2[j]));
			}
		}
	}

	cout << dp[n-1][m-1] << endl;
}


/*
   M  O  V  I  E
L  1  2  3  4  5
O  2  1  2  3  4
V  3  2  1  2  3
E  4  3  2  2  2

*/