#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define forn(i,j) for(int i = 0; i < j; i++)
#define pii pair<ll,ll>
#define vi vector<ll>
#define vii vector<int<int>>
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

int custom_binary_search(ll lo, ll hi, function<bool(ll)> f){
    while(lo < hi){
        ll mid = lo + (hi - lo)/2;

        if(f(mid)){
            //if x works, so does everything below x
            lo = mid;
        } else{
            //if x does not works, so does nothing above x
            hi = mid - 1;
        }
    }

    return lo;
}

void solve(){
    siout("socdist");
    ll n, m;
    cin >> n >> m;
    vector<pii> arr(m);

    for(int i = 0; i < m; i++) { cin >> arr[i].f >> arr[i].s;}
    int k = arr[m-1].s;
    int l = k/n;
    l++;

    sort(arr.begin(),arr.end());

    cout << custom_binary_search(1, l, [&](int x){
        int t = 1;
        vector<int> positions(n+1);

        positions[0] = arr[0].f;

        int i = 0;
        int j = 0;

        while(i < n && j < m){
            if(positions[i] + x > arr[j].s){
                j++;
                i++;
                t++;
                positions[i] = arr[j].f;
            }

            else{
                int z = positions[i];
                i++;
                positions[i] = z + x;
                i++;
                t++;
            }
        }

        return t >= n;
    }) << endl;
}

int main(){
    solve();
}