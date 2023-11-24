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

void siout(string name = "") { 

	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}


int interacting(const ll mid){
    cout << '?' << ' ' << 1 << ' ' << mid << endl;
    ll x;
    cin >> x;

    return x; 
}

bool is_possible(const ll k, const ll index){
    ll x = interacting(index);

    return x <= index - k;
}

int main(){
	siout();
    ll n,k;
    cin >> n >> k;

	ll lo = 1;
	ll hi = n;

	while(lo < hi){
		ll mid = (lo+hi)/2;

		if(is_possible(k, mid)){
            hi = mid;
        }

		else{
            lo = mid+1;
		}
	}

	cout << hi;
}