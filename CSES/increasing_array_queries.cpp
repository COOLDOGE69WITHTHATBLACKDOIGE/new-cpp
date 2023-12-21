#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> T;
 
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

int n,q;

struct Query{
	int left;
	int right;
	int index;
};

bool comp(const Query &a, const Query &b){
	return a.left > b.left;
}

int seg[2*maxN];

void update(int idx, int value){
	idx += n;
	seg[idx] += value;

	for(idx /= 2; idx; idx /= 2){
		seg[idx] = seg[2*idx] + seg[2*(idx)+1];
	}
}

int query(int left, int right){
	int ra = 0; int rb = 0;

	for(left += n, right += n+1; left < right; left /= 2, right /= 2){
		if(left & 1){
			ra += seg[left++];
		}

		if(right & 1){
			rb += seg[--right];
		}
	}
	int res = ra=rb;

	return res;
}

signed main(){
	int n,q; cin >> n >> q; vi val(n);

	forn(i,n){ cin >> val[i]};

	vector<Query> Q(q);

	forn(i,q){
		cin >> Query[i].left >> Query[i].right; Query[i].left--, Query[i].right--;
		Query[i].index = i;
	}

	sort(all(Q),comp);

	for(Query g : Q){
		int tl = g.left;
	}
}