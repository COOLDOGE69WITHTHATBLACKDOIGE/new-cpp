#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
// #define _GLIBCXX_DEBUG 1
// #define _GLIBCXX_DEBUG_PEDANTIC 1
// #pragma GCC optimize("trapv")

// #define dbg(TXTMSG) cerr << "\n" << TXTMSG
// #define dbgv(VARN) cerr << "\n" << #VARN << " = "<< VARN << ", line: " << __LINE__ << "\n"

#define ld long double
#define int long long
#define forn(i,j) for(int i = 0; i < j; i++)
#define forrange(i,j,k) for(int i = j; i < k; ++i)
#define rof(i,j) rof(int i = j; i >= 0; --i)
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define vvi vector<vi>
#define vvpii vector<vector<pii>>
#define vb vector<bool>
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define eb emplace_back
#define qi queue<int>
#define qpii queue<pii>
#define pqpii priority_queue<pii>
#define pqi priority_queue<int>

#define MOD 1000000007

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

signed main(){
	setIO("hayfeast");
	int n,m;
	cin >> n >> m;

	vi flav(n);
	vi spicy(n);

	forn(i,n){
		cin >> flav[i] >> spicy[i];
	}

	multiset<int> s;

	int r = -1;
	int res = 0;
	int mn = 1e17;

	forn(i,n){
		while(r < n && res < m){
			r++;
			res += flav[r];
			s.insert(spicy[r]);
		}

		if(res < m){
			cout << mn << endl;
			return 0;
		}

		else{
			mn = min(mn,*s.rbegin());
			s.erase(s.find(spicy[i]));
			res -= flav[i];	
		}
	}

	cout << mn << endl;
}