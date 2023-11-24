#include<bits/stdc++.h>
using namespace std;

void siout(string name = ""){ 

	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int moves(int a, int b){
    if(a == 0){
        if(b == 2){
            return 1;
        }
        else{
            return 0;
        }
    }

    if(a == 1){
        if(b == 0){
            return 1;
        }
        else{
            return 0;
        }
    }

    else{
        if(b == 1){
            return 1;
        }
        else{
            return 0;
        }
    }
}

int main(){
    siout("hps");
    int n,K;
    cin >> n >> K;
    vector<int> v(n);

    for(int i = 0; i < n; ++i){
        char d;
        cin >> d;

        if(d == 'H'){
            v[i] = 0;
        }

        if(d == 'P'){
            v[i] = 1;
        }

        else{
            v[i] = 2;
        }
    }

    int dp[n+1][K+1][3];

    memset(dp, -1, sizeof(dp));

    for(int i = 0; i < 3; ++i){
        dp[0][0][i] = 0;
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= K; ++j){
            for(int m = 0; m < 3; ++m){
                dp[i+1][j][m] = max(dp[i+1][j][m], dp[i][j][m] + moves(m, v[i]));  //stay the same
            }

            for(int m = 0; m < 3; ++m){
                dp[i + 1][j + 1][0] = max(dp[i + 1][j + 1][0], dp[i][j][m] + moves(0,v[i])); 
				dp[i + 1][j + 1][1] = max(dp[i + 1][j + 1][1],dp[i][j][m] + moves(1,v[i])); 
				dp[i + 1][j + 1][2] = max(dp[i + 1][j + 1][2], dp[i][j][m] + moves(2,v[i])); 
            }
        }
    }

    int mx = -1;

    for(int i = 0; i < 3; ++i){        
            mx = max(mx, dp[n][K][i]);
    }

    cout << dp[4][1][1] << endl;
}