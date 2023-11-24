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

pii find_lis(vi a){
	map<int,int> dp;
	int mx = 0;
	int x = 0;

	for(int i : a){
		dp[i] = dp[i-1] + 1;

		if(dp[i] > mx){
			mx = dp[i];
			x = i;
		}
	}
	return {mx,x};
}

int main(){
	int n;
	cin >> n;
	vi a;

	forn(i,n){
		int d;
		cin >> d;

		a.pb(d);
	}

	pii r = find_lis(a);

	int j = r.f;
	int x = r.s;

	cout << j << endl;

	vi b;

	for(int i = 0; i < j; ++i){
		b.pb(x - j + i + 1);
	}

	int t = 0;

	for(int i = 0; i < n; ++i){
		if(t != b.size()){
			if(a[i] == b[t]){
				cout << i + 1 << " ";

				t++;
			}
		}

		if(t == b.size()){
			break;
		}
	}
}