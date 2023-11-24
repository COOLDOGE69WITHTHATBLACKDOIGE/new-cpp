#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define forn(i,j) for(ll i = 0; i < j; i++)
#define pii pair<int,int>
#define vi vector<ll>
#define vii vector<vector<int>>
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin(), x.end()

ll n;
ll a[100'000];
ll k;
ll psum[100'001];

#define MOD 1000000007

void siout(string name = "") { 

	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

bool is_possible(const ll mid){
    forn(l, n){
        ll r = upper_bound(a, a+n, a[l]+mid) - a;
        ll moves = a[l]*(l+1) - psum[l+1] + psum[n] - psum[r+1] - (a[l]+mid)*(n - r);
        if(moves <= k){
            return true;
        } 
    }

    forn(r,n){
        ll l = lower_bound(a, a+n, a[r] - mid) - a;
        ll moves = (a[r]-mid)*(l) - psum[l+1] + psum[n] - psum[r+1] - a[r]*(n - r);
        if(moves <= k){
            return true;
        }
    }
    return false;
}

int main(){
    siout();
    cin >> n >> k;

    psum[0] = 0;

    forn(i,n){ cin >> a[i];}
    sort(a, a+n);

    forn(i,n){ psum[i+1] = psum[i] + a[i];}

    ll lo = 0;
    ll hi = 1e9;
    ll min;

    while(lo < hi){
        ll mid = (lo+hi)/2;

        if(is_possible(mid)){
            hi = mid;
        } else{
            lo = mid + 1;
        }
    }

    cout << lo << endl;
}