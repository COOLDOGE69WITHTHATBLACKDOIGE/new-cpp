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

void calculate5(int a){
	int x = 0;

	while(a % 5 == 0){
		a = a/5;
		x++;
	}

	return x;
}

void calculate2(int a){
	int x = 0;

	while(a % 2 == 0){
		a = a/2;
		x++;
	}
}

int main(){
	int n,k;
	cin >> n >> k;

	vector<int> a(n);
	vector<int> pw5(n);
	vector<int> pw2(n);

	forn(i,n){
		cin >> a[i];

		pw5[i] = calculate5(a[i]);
		pw2[i] = calculate2(a[i]);
	}

	int dp[n][k+1][300];

	dp[0][1][pw5[0]] = min(pw2[0], pw5[0]);

	for(int i = 0; i < n; ++i){
		for(int j = 1; j < k+1; ++j){
			for(int l = 0; l < 300; ++l){
				dp[i][j][l] = 
			}
		}
	}
}