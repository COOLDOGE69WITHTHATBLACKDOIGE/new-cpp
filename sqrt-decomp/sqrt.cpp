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

const int MOD = 1000000007;

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

struct SQRT{
	int sze;
	vi nums;
	vi blocks;

	SQRT(int sqrtn, vi arr) : sze(sqrtn), blocks(sqrtn,0){
		nums = arr;
		forn(i,nums.size()){
			blocks[i/sze] += nums[i];
		}
	}

	void update(int ind, int val){
		ind--;
		blocks[ind/sze] -= nums[ind];
		nums[ind] = val;
		blocks[ind/sze] += nums[ind];
	}

	int query(int r){
		int sum = 0;
		int h = r/sze;

		forn(i,h){
			sum += blocks[i];
		}

		forrange(i,h*sze,r){
			sum += nums[i];
		}

		return sum;
	}

	int rquery(int l, int r){
		return query(r) - query(l-1);
	}
};

signed main(){
	setIO();
	int n,q;
	cin >> n >> q;

	vi arr(n);

	forn(i,n){
		cin >> arr[i];
	}

	int j = ceil(sqrt(n));

	SQRT s(j,arr);

	while(q--){
		int type;
		cin >> type;

		if(type == 1){
			int ind, val;
			cin >> ind >> val;

			s.update(ind,val);
		}

		if(type == 2){
			int a,b;
			cin >> a >> b;

			int f = s.rquery(a,b);

			cout << f << endl;
		}
	}
}