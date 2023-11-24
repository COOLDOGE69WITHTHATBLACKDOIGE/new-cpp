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

bool cmp(pii &a, pii &b){
	if(a.f == b.f){
		return a.s < b.s;
	}

	else{
		return a.f < b.f;
	}
}

vi find_lis(vi a){
	vi dp;

	for(int i : a){
		int pos = upper_bound(dp.begin(),dp.end(),i) - dp.begin();

		if(pos > 0){
			if(dp[pos - 1] == i){
				continue;
			}
		}

		if(pos == dp.size()){
			dp.pb(i);
		}

		else{
			dp[pos] = i;
		}
	}

	return dp;
}

int main(){
	setIO();
	int n;
	cin >> n;

	vi time(n);
	vi pos(n);
	vb mark(n,false);

	forn(i,n){
		cin >> pos[i] >> time[i];
	}

	vector<pii> p(n);

	forn(i,n){
		p[i].f = pos[i] - time[i];
		p[i].s = pos[i] + time[i];
	}

	sort(all(p),cmp);
	vi dp;
	vi index(n);
	

	forn(i,n){
		int j = p[i].s;

		int pos = upper_bound(all(dp),j) - dp.begin();

		if(pos > 0){
			if(dp[pos - 1] == j){
				continue;
			}
		}

		if(pos == dp.size()){
			dp.pb(j);
			index[dp.size()] = i;
			mark[i] = true;
		}

		else{
			mark[index[pos]] = false;
			index[pos] = i;
			dp[pos] = j;

			mark[i] = true;
		}
	}

	cout << dp.size() << endl;

	forn(i,n){
	}
}