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
int n,k;

multiset<int> low;
multiset<int> high;

void insrt(int val){
	int median = *low.rbegin();

	if(median < val){
		high.insert(val);

		if(high.size() > k/2){
			low.insert(*high.begin());
			high.erase(high.find(*high.begin()));
		}
	}

	else{
		low.insert(val);

		if(low.size() > (k+1)/2){
			high.insert(*low.rbegin());
			low.erase(low.find(*low.rbegin()));
		}
	}
}

void erse(int val){
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
	setIO();
	cin >> n >> k;

	vi val(n);

	forn(i,n){
		cin >> val[i];
	}

	low.insert(val[0]);

	forrange(i,1,k){
		insrt(val[i]);
	}

	cout << *low.rbegin() << " ";

	forrange(i,k,n){
		if(k == 1){
			insrt(val[i]);
			erse(val[i-k]);
		}

		else{
			erse(val[i-k]);
			insrt(val[i]);
		}

		cout << *low.rbegin() << " "; 
	}
}