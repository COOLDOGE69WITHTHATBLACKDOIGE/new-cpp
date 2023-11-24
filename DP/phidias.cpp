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
	siout();
	int w,h;
	cin >> w >> h;

	int n;
	cin >> n;

	pii pairs[n];

	for(int i = 0; i < n; ++i){
		int a, b;
		cin >> a >> b;
		pairs[i].first = a;
		pairs[i].second = b;
	}

	int dp[w+1][h+1];

	for(int i = 0; i < w+1; ++i){
		for(int j = 0; j < h+1; ++j){
			dp[i][j] = i*j;
		}
	}

	for(int i = 0; i < n; ++i){
		int a = pairs[i].first;
		int b = pairs[i].second;

		dp[a][b] = 0;
	}

	//iterate through each row and column

	for(int i = 1; i < w+1; ++i){
		for(int j = 1; j < h+1; ++j){
			for(int x = 0; x < j; ++x){
				dp[i][j] = min(dp[i][j], dp[i][x] + dp[i][j-x]);
			}

			for(int y = 0; y < i; ++y){
				dp[i][j] = min(dp[i][j], dp[y][j] + dp[i-y][j]);
			}
		}
}

	cout << dp[w][h] << endl;
}