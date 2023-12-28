#include<bits/stdc++.h>
using namespace std;
 
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

const int MOD = 1e9 + 7;
const int INF = 1e17 + 1;
const int maxN = 2e5 + 1;

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

void solve(){
	int n; cin >> n;
	vi a(n);

	forn(i,n){
		cin >> a[i];
	}

	int mex = 0;
	vi freq(n+1,0);
	vi freqm(n+1,0);
	int local_ans = 0;

	forn(i,n){
		freq[a[i]]++;

		while(freq[mex]){
			mex++;
		}

		freqm[mex]++;
		local_ans += mex;
	}

	deque<pii> dq;
	int mx = local_ans;

	forn(i,n+1){
		if(freqm[i]){
			dq.pb({i,freqm[i]});
		}
	}

	forn(i,n-1){
		local_ans -= dq.front().f;
		dq.front().s--;
		int fr = 0;

		if(dq.front().s == 0){
			dq.pop_front();
		}

		while(!dq.empty() && dq.back().f > a[i]){
			pii bd = dq.back();

			dq.pop_back();

			local_ans -= bd.f*(bd.s);
			fr += bd.s;
		}

		dq.push_back({a[i],fr});
		dq.push_back({n,1});

		local_ans += n + a[i]*(fr);

		mx = max(local_ans,mx);
	}

	cout << mx << endl;
}

signed main(){
	setIO(	);
	int t; cin >> t;

	while(t--){
		solve();
	}
}