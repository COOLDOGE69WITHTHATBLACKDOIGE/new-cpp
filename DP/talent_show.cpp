#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int n, w;

vector<int> weight(300), talent(300);

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
ll dp[1001];

bool knapsack(int r){

	for(int i = 0; i < w+1; ++i){
		dp[i] = -MOD;
	}

	dp[0] = 0;

	for(int i = 0; i < n; ++i){
		ll curr_value = (ll)talent[i] - (ll)(r * weight[i]);
		int curr_weight = weight[i];

		for(int j = w; j >= 0; --j){
			ll h = min(w, j + weight[i]);

			if(dp[j] != -MOD){
				dp[h] = max(dp[j] + curr_value, dp[h]);
			}
			
		}
	}

	return dp[w] >= 0;
}


int main(){
	setIO("talent");
	cin >> n >> w;

	for(int i = 0; i < n; ++i){
		cin >> weight[i] >> talent[i];
		talent[i] = 1000 * talent[i];
	}

    ll lo = 0;
	ll hi = 10000000;

	while(hi - lo > 1){
		ll mid = lo + (hi - lo)/2;

		if(knapsack(mid)){
			lo = mid;
		}

		else{
			hi = mid - 1;
		}
	}

	cout <<  hi << endl;;
}