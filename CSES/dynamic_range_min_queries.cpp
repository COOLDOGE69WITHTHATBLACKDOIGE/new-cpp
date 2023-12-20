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
int a[maxN];
int st[2*maxN];
int n;
 
void update(int idx, int val){
	idx += n;
	st[idx] = val;
 
	for(idx /= 2; idx; idx /=2){
		st[idx] = min(st[2*idx],st[2*(idx)+1]);
	}
}
 
int query(int left, int right){
	int ra = INF, rb = INF;
 
	for(left += n, right += n+1; left < right; left /= 2, right /= 2){
		if(left & 1){ ra = min(ra,st[left++]);	}
		if(right & 1){ rb = min(rb,st[--right]);}
	}
 
	return min(ra,rb);
}
 
signed main(){
	setIO(); int q; cin >> n >> q;
 
	forn(i,n){ 
		cin >> a[i];
		update(i,a[i]);
	}
 
	while(q--){
		int type;
		cin >> type;
 
		if(type == 1){
			int k,value;
			cin >> k >> value;
			k--; update(k,value);
		}
 
		else{
			int a,b;
			cin >> a >> b; a--,b--;
			cout << query(a,b) << endl;
		}
	}
}