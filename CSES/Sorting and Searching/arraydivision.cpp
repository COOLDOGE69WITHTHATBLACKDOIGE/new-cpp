#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define forn(i,j) for(int i = 0; i < j; i++)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define p push
#define f first
#define s second

#define MOD 1000000007

ll MAX_SUM = 2e5 * 1e9;

void siout(string name = "") { 

	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}


bool is_possible(const vector<ll> &v, const int k, ll max_sum){
	ll subset_count = 0;
	ll sum = 0;

	for(const int &x : v){
		if(x > max_sum){ return false;}

		if(sum + x > max_sum){
			subset_count++;
			sum = 0;
		}

		sum += x;
	}

	if(sum > 0){ subset_count++;}
	
	return subset_count <= k;
}

int main(){
	siout();
    ll n,k;
    cin >> n >> k;

    vector<ll> v(n);
    forn(i, n){ cin >> v[i];}

	ll lo = 1;
	ll hi = MAX_SUM;

	while(lo < hi){
		ll mid = (lo+hi)/2;

		if(is_possible(v, k, mid)){
			hi = mid;
		}

		else{
			lo = mid + 1;
		}
	}

	cout << hi;
}