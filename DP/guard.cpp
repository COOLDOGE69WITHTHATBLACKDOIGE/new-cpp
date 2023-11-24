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

struct Cow{
	int weight;
	int height;
	int strength;
};

int main(){
	setIO("guard");
	int n, h;
	cin >> n >> h;

	vector<Cow> C(n);

	forn(i,n){
		cin >> C[i].height >> C[i].weight >> C[i].strength;
	}

	pii b = {0,-1};

	vector<pii> dp((1 << n), b);

	dp[0] = {0, INT_MAX};

	for(int i = 1; i < 1 << n; ++i){
		for(int j = 0; j < n; ++j){

			if(i & (1 << j)){
				dp[i].f += C[j].height;

				dp[i].s = max(dp[i].s, min(dp[i ^ (1 << j)].s - C[j].weight, C[j].strength));
			}
		}
	}

	int mu = -1;

	for(int i = 1; i < 1 << n; ++i){
		if(dp[i].f >= h){
			mu = max(mu, dp[i].s);
		}
	}

	if(mu >= 0){
		cout << mu << endl;
	}

	else{
		cout << "Mark is too tall" << endl;
	}
}