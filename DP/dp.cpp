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

void siout(string name = "") { 

	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
    int n;
    cin >> n;

    int h[n];

    forn(i,n){ cin >> h[i];}

    vi dp(n, INT_MAX);

    dp[0] = 0;
    
    for(int i = 0; i< n-1; ++i){
        dp[i+1] = min(dp[i+1], dp[i] + abs(h[i+1] - h[i]));

        if(i+2 < n){
            dp[i+2] = min(dp[i+2], dp[i] + abs(h[i+2] - h[i]));
        }
    }
    cout << dp[n-1] << endl;
}