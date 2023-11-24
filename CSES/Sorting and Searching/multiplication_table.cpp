#include <algorithm>
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

#define MOD 1000000007

void siout(string name = "") { 

	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}


bool is_possible(const int x, const int n){
	ll occ = 0;

    forn(i,n){
        int m = x/(i+1);
        occ += m;
    }

    ll median = ((n*n) + 1)/2;

    return occ >= median;
}

int main(){
	siout();
    ll n;
    cin >> n;

    ll lo = 1;
    ll hi = n*n;

	while(lo < hi){
		ll mid = (lo+hi)/2;

		if(is_possible(mid, n)){
			hi = mid;
		}

		else{
			lo = mid + 1;
		}
	}

	cout << hi;
}