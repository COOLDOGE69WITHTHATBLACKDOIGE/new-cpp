#include<bits/stdc++.h>
using namespace std;

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
	setIO("feast");
	int t, a, b;
	cin >> t >> a >> b;

	bool dp[t+1];
	memset(dp, false, sizeof(dp));

	dp[0] = true;

	for(int i = 0; i < t+1; ++i){
		if(i - a >= 0){
			if(dp[i-a]){
				dp[i] = true;
			}
		}

		if(i - b >= 0){
			if(dp[i-b]){
				dp[i] = true;
			}
		}
	}

	int c = t/2;

	for(int i = 0; i < c+1; ++i){
		if(dp[2*i]){
			dp[i] = true;
		}

		if((2*i)+1 <= t){
			if(dp[(2*i)+1]){
				dp[i] = true;
			}
		}
	}

	for(int i = 0; i < t+1; ++i){
		if(i - a >= 0){
			if(dp[i-a]){
				dp[i] = true;
			}
		}

		if(i - b >= 0){
			if(dp[i-b]){
				dp[i] = true;
			}
		}
	}

	while(t >= 0){
		if(dp[t]){
			cout << t << endl;
			break;
		}

		else{
			t--;
		}
	}
}