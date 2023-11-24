#include<bits/stdc++.h>
using namespace std;
#define ll long

long long dp[1000001];

int main(){
	int n;
	cin >> n;
	

	if(n == 1 || n == 2 || n == 3 || n == 4 || n == 5 || n == 6){
		if(n == 1){
		   cout << 1 << endl;
	    }

	    if(n == 2){
		   cout << 2 << endl;
	    }

	    if(n == 3){
		   cout << 4 << endl;
	    }

	    if(n == 4){
		   cout << 8 << endl;
	    }

	    if(n==5){
		   cout << 16 << endl;;
	    }

	    if(n==6){
		   cout << 32 << endl;
	    }
	}


	else{
		dp[1] = 1;
	    dp[2] = 2;
	    dp[3] = 4;
	    dp[4] = 8;
	    dp[5] = 16;
	    dp[6] = 32;
		for(int i = 7; i <= n; ++i){
			for(int j = 1; j < 7; ++j){
				dp[i] += dp[i-j];
			}

			dp[i] %= 1000000007;
		}

		cout << dp[n] << endl;
	}
}