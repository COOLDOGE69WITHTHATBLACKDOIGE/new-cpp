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

bool comp(pii a, pii b){
	return a.f + a.s < b.f + b.s;
}

multiset<int> low, high;
multiset<int> low2, high2;

int sze;

void insert(int val){
	int a = *low.rbegin();

	if(a < val){
		high.insert(val);

		if(high.size() > sze/2){
			low.insert(*high.begin());
			high.erase(high.find(*high.begin()));
		}
	}

	else{
		low.insert(val);

		if(low.size() > (sze + 1)/2){
			high.insert(*low.rbegin());
			low.erase(low.find(*low.rbegin()));
		}
	}
}

void erase(int val){
	if(high.find(val) != high.end()){
		high.erase(high.find(val));
	}

	else{
		low.erase(low.find(val));
	}

	if(low.empty()){
		low.insert(*high.begin());
		high.erase(high.find(*high.begin()));
	}
}

signed main(){
	setIO("input");
	int n,k;
	cin >> k >> n;

	int res = 0;
	vpii nums;

	forn(i,n){
		char p;
		int s;
		char q;
		int t;

		cin >> p >> s >> q >> t;

		if(p == q){
			res += abs(t-s);
		}

		else{
			nums.pb({s,t});
		}
	}
	sort(all(nums),comp);

	if(k == 1){
		sze = 2*nums.size();
		if(nums[0].f > nums[0].s){
			low.insert(nums[0].s);
			high.insert(nums[0].f);
		}

		else{
			low.insert(nums[0].f);
			high.insert(nums[0].s);
		}

		forrange(i,1,nums.size()){
			insert(nums[i].f);
			insert(nums[i].s);
		}

		int median = *low.rbegin();

		for(pii j : nums){
			res += abs(median - j.f);
			res += abs(median - j.s);
			res += 1;
		}

		cout << res << endl;
	}

	else{
	}
}