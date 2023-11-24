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
#define mp make_pair


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
    ll n, t;
    cin >> n >> t;

    ll time[n];

    forn(i,n){ cin >> time[i];}

    ll lo = 1;
    ll hi = 1e18;
    ll sol = 1e18;

    while(lo < hi){
        ll mid = (lo + hi)/2;
        ll exp = 0;

        forn(i,n){
            if(exp >= t){
                break;
            }
            exp += (mid/time[i]);

        }

        if(exp < t){
            lo = mid + 1;
        }

        else{
            sol = mid;
            hi = mid;
        }
    }

    cout << sol << endl;
}