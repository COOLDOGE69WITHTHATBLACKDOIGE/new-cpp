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

#define MOD 1000000007

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int find_lis(vi a){
	vi dp;

	for(int i : a){
		int pos = upper_bound(dp.begin(),dp.end(),i) - dp.begin();

		if(pos == dp.size()){
			dp.pb(i);
		}

		else{
			dp[pos] = i;
		}
	}

	return dp.size();
}

int main(){
	setIO();
	int n,m;
	cin >> n >> m;
	vi a;

	forn(i,n){
		int d;
		cin >> d;

		a.pb(d);
	}

	vi b;

	for(int i = 1; i <= n; ++i){
		if((i*m) >= a[i - 1]){
			b.pb((i*m) - a[i - 1]);
		}

	}

	cout << n - find_lis(b) << endl;
}