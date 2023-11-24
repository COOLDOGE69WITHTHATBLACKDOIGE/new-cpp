#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define forn(i,j) for(ll i = 0; i < j; i++)
#define pii pair<ll,ll>
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

const int LOG = 17;
const int N = 200'000;
ll a[N];
pii sparse_table[N][LOG];

pii compare(pii a, pii b){
    if(a.f > b.f){
        return a;
    }

    else{
        return b;
    }
}

pii rmq(ll l, ll r){
    ll len = r - l + 1;
    ll x = 0;
    for(int i = 1; (1<<i) <= len; ++i){
        x++;
    }

    pii y = compare(sparse_table[l][x], sparse_table[r - (1<<x) + 1][x]);

    return y;
}

int main(){
    siout();
    ll n;
    cin >> n;
    ll dp[n];

    for(int i = 0; i < n-1; ++i){
        cin >> a[i];
        a[i]--;
    }

    a[n-1] = 0;

    for(int i = 0; i< n-1; ++i){
        pii b = make_pair(a[i],i);
        sparse_table[i][0] = b;
    }

    for(int j = 1; j < LOG; ++j){
        for(int i = 0; i + (1<<j) - 1 <= n-1; ++i){
            sparse_table[i][j] = compare(sparse_table[i][j-1], sparse_table[i+(1<<(j-1))][j-1]);
        }
    }

    if(n == 1){
        cout << 0 << endl;
    }

    if(n == 2){
        cout << 1 << endl;
    }
    
    else{
        dp[n-1] = 0;
        dp[n-2] = 1;
        int k;
        for(int i = n-3; i >= 0; --i){
            k = rmq(i+1,a[i]).s;
            dp[i] = dp[k] - (a[i] - k) + (n-i-1);
        }

        ll dpsum = 0;

        for(int i = 0; i < n; ++i){
            dpsum += dp[i];
        }

        cout << dpsum;       
    }
}