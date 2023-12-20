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
int n,m;

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
int seg[4*maxN];
int h[maxN];

void build(int l, int r, int pos){
	if(l == r){
		seg[pos] = h[l];
		return;
	}

	int mid = l+r; mid /= 2;
	build(l,mid,2*pos);
	build(mid+1,r,2*(pos)+1);

	seg[pos] = max(seg[2*pos],seg[2*(pos) + 1]);
}

void update(int l, int r, int pos, int idx, int val){
	if(l == r){
		seg[pos] += val;
		return;
	}

	int mid = l+r; mid /= 2;

	if(mid < idx){
		update(mid+1,r,2*(pos)+1,idx,val);
	}

	else{
		update(l,mid,2*pos,idx,val);
	}

	seg[pos] = max(seg[2*pos],seg[2*(pos)+1]);
}

void query(int l, int r, int pos, int val){
	if(l == r){
		update(0,n-1,1,l,-val);
		cout << l+1 << " ";
		return;
	}

	int mid = l+r; mid /= 2;

	if(seg[2*(pos)] >= val){
		query(l,mid,2*pos,val);
	}

	else{
		query(mid+1,r,2*(pos)+1,val);
	}
}

signed main(){
	setIO(); cin >> n >> m; vi a(m);
	forn(i,n){
		cin >> h[i];
	}

	build(0,n-1,1);

	forn(i,m){ cin >> a[i];}
	forn(i,m){
		if(a[i] > seg[1]){
			cout << 0 << " ";
		}

		else{
			query(0,n-1,1,a[i]);
		}
	}
}

/*
                      /^--^\     /^--^\     /^--^\   nya!
                      \____/     \____/     \____/
                     /      \   /      \   /      \
                    |        | |        | |        |
                     \__  __/   \__  __/   \__  __/
|^|^|^|^|^|^|^|^|^|^|^|^\ \^|^|^|^/ /^|^|^|^|^\ \^|^|^|^|^|^|^|^|^|^|^|^|
| | | | | | | | | | | | |\ \| | |/ /| | | | | | \ \ | | | | | | | | | | |
| | | | | | | | | | | | / / | | |\ \| | | | | |/ /| | | | | | | | | | | |
| | | | | | | | | | | | \/| | | | \/| | | | | |\/ | | | | | | | | | | | |
#########################################################################
| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |
| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |


*/