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

int dp[100000][103];

int main(){
	int n, m;
	cin >> n >> m;

	int a[n];

	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}

	for(int i = 0; i < n; ++i){
		if(a[i] == 1 || a[i] == 0){
			dp[i][1] = 1;
		}
		else{
			dp[i][1] = 0;
		}
	}

	for(int i = 1; i < m+1; ++i){
		if(a[0] == 0 || a[0] == i){
			dp[0][i] = 1;
		}

		else{
			dp[0][i] = 0;
	    }
    }

    int t = 0;

    for(int i = 1; i < n; ++i){
    	for(int j = 2; j < m+1; ++j){
    		if(a[i] != 0){
    			if(a[i] != j){
    				dp[i][j] = 0;
    			}
    			else{
    				dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j+1];
    			}
    		}

    		else{
    			dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j+1];
    		}

    		t = max(t, dp[i][j]);
    	}
    }

    cout << t << endl;
}
/*
dp[i][v] = dp[i-1][v-1] + dp[i-1][v] + dp[i-1][v+1] 
*/