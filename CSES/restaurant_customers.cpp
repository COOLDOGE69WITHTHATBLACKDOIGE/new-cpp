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

const int S = 5e5;

signed main(){
	setIO();
	int n;
	cin >> n;

	vi pref(S,0);

	vi a(300000,0);
	vpii people(n);
	vi compress;
	map<int,int> coord;

	forn(i,n){
		cin >> people[i].f >> people[i].s;

		compress.pb(people[i].f);
		compress.pb(people[i].s);
	}

	sort(all(compress));
	int t = 1;
	int mx = 0;

	coord[compress[0]] = 0;

	forrange(i,1,compress.size()){
		if(compress[i] == compress[i-1]){
			continue;
		}

		else{
			coord[compress[i]] = t;
			t++;
		}
	}

	int end = 0;

	forn(i,n){
		people[i].f = coord[people[i].f];
		people[i].s = coord[people[i].s];
		end = max(end,people[i].s);
	}

	forn(i,n){
		pref[people[i].f]++;
		pref[people[i].s]--;
	}

	int MX = 0;

	forrange(i,1,pref.size()){
		pref[i] += pref[i-1];
		MX = max(MX,pref[i]);
	}

	cout << MX << endl;
}