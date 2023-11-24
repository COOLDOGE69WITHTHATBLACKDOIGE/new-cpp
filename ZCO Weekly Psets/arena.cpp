#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#pragma GCC optimize("trapv")

#define dbg(TXTMSG) cerr << "\n" << TXTMSG
#define dbgv(VARN) cerr << "\n" << #VARN << " = "<< VARN << ", line: " << __LINE__ << "\n"

#define ll long long
#define ld long double
#define forn(i,j) for(ll i = 0; i < j; i++)
#define forrange(i,j,k) for(int i = j; i < k; ++i)
#define rof(i,j) rof(int i = j; i >= 0; --i)
#define pii pair<int,int>
#define vll vector<ll>
#define vi vector<int>
#define vvll vector<vll>
#define vvi vector<vi>
#define vb vector<bool>
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define eb emplace_back
#define qi queue<int>
#define qpii queue<pii>

const ll mod = 998244353;

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

ll fact[501];
ll ifact[501];

ll power(ll a, ll b){
	a %= mod;
	ll res = 1;

	while (b > 0) {
		if (b % 2 == 1) { res = res * a % mod; }
		a = a * a % mod;
		b /= 2;
	}

	return res;
}

void factorial(){
	fact[0] = 1;
	for(int i = 1; i < 501; ++i){
		fact[i] = (fact[i-1]*i) % mod;
	}	
}

void ifactorial(){
	ifact[500] = power(fact[500],mod-2); 

	for(int j = 499; j > 0; --j){
		ifact[j] = (ifact[j+1]*(j+1)) % mod;
	}
}

int nPr(int n, int r){
	ll h = fact[n];

	if(r > n || r < 0){
		return 0;
	}

	else{
		h *= ifact[r];
		h %= mod;

		return h;
	}
}

int main(){
	int n,x;
	cin >> n >> x;

	if(n > x){
		cout << power(x,n) << endl;
	}

	else{
		factorial();
	    ifactorial();

	    ll dp[n+1];
	    dp[0] = 0;
	    dp[1] = 0;
	    dp[2] = x;

	    if(n == 2){
	    	cout << x << endl;
	    }

	    else{
	    	for(int i = 3; i <= n; ++i){
	    		dp[i] = (dp[i-1]*x) % mod;
	    		dp[i] += (nPr(x,i-1)*(i-1)) % mod;
	    	}

	    	cout << dp[n] << endl;
	    }
	}
}