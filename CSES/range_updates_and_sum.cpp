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

struct node{
	int sum;
	int lz_add;
	int lz_set;
};

node seg[4*maxN];

void pushdown(int pos,int l,int r,int mid){
	if(seg[pos].lz_set > 0){
		seg[2*pos].lz_set = seg[2*(pos)+1].lz_set = seg[pos].lz_set;
		seg[2*pos].lz_add = seg[2*(pos)+1].lz_add = 0;

		seg[2*pos].sum = (mid - l + 1)*(seg[2*pos].lz_set);
		seg[2*(pos)+1].sum = (r - mid)*(seg[2*(pos)+1].lz_set);
		seg[pos].lz_set = 0;
	}

	else if(seg[pos].lz_add > 0){
		seg[2*pos].sum += (mid - l + 1)*seg[pos].lz_add;
		seg[2*(pos)+1].sum += (r-mid)*(seg[pos].lz_add);
		if(seg[2*pos].lz_set == 0){
			seg[2*pos].lz_add += seg[pos].lz_add;
		}

		else{
			seg[2*pos].lz_add = 0; seg[2*pos].lz_set += seg[pos].lz_add;
		}

		if(seg[2*(pos)+1].lz_set == 0){
			seg[2*(pos)+1].lz_add += seg[pos].lz_add;
		}

		else{
			seg[2*(pos)+1].lz_add = 0; seg[2*(pos)+1].lz_set += seg[pos].lz_add;
		}

		seg[pos].lz_add = 0;
	}
}

void pushup(node &a, node &b, node &c){
	c.sum = a.sum + b.sum;
}

void build(int pos,int l, int r){
	seg[pos].lz_add = 0; seg[pos].lz_set = 0;
	if(l == r){
		seg[pos].sum = a[l];
		return;
	}

	int mid = (l+r)/2;
	build(2*pos,l,mid);
	build(2*(pos)+1,mid+1,r);
	pushup(seg[2*pos],seg[2*(pos)+1],seg[pos]);
}

void add(int pos, int l, int r, int ql, int qr,int value){
	if((qr < l) || (ql > r)){
		return;
	}

	if((ql <= l) && (qr >= r)){
		seg[pos].sum += (r-l+1)*value;
		if(seg[pos].lz_set == 0){
			seg[pos].lz_add += value;
		}

		else{
			seg[pos].lz_set += value;
		}

		return;
	}

	int mid = (l+r)/2;
	pushdown(pos,l,r,mid);
	add(2*pos,l,mid,ql,qr,value); add(2*(pos)+1,mid+1,r,ql,qr,value);
	pushup(seg[2*pos],seg[2*(pos)+1],seg[pos]);
	return;
}

void set_val(int pos, int l, int r, int ql, int qr, int value){
	if((qr < l) || (ql > r)){
		return;
	}

	if((qr >= r) && (ql <= l)){
		seg[pos].sum = (r-l+1)*value;
		seg[pos].lz_set = value; seg[pos].lz_add = 0;

		return;
	}

	int mid = (l+r)/2;
	pushdown(pos,l,r,mid);
	set_val(2*pos,l,mid,ql,qr,value); set_val(2*(pos)+1,mid+1,r,ql,qr,value);
	pushup(seg[2*pos],seg[2*(pos)+1],seg[pos]);
	return;
}

int query(int pos, int l, int r, int ql, int qr){
	if((qr < l) || (ql > r)){
		return 0;
	}

	if((qr >= r) && (ql <= l)){
		return seg[pos].sum;
	}

	int mid = (l+r)/2;
	pushdown(pos,l,r,mid);
	return query(2*pos,l,mid,ql,qr) + query(2*(pos)+1,mid+1,r,ql,qr); 
}

signed main(){
	setIO(); int n,q;
	cin >> n >> q;
	forn(i,n){
		cin >> a[i];
	}

	build(1,0,n-1);

	while(q--){
		int type; cin >> type;

		if(type == 1){
			int left,right,value; cin >> left >> right >> value; left--,right--;
			add(1,0,n-1,left,right,value);
		}

		else if(type == 2){
			int left,right,value; cin >> left >> right >> value; left--,right--;
			set_val(1,0,n-1,left,right,value);
		}

		else{
			int left,right; cin >> left >> right; left--,right--;
			cout << query(1,0,n-1,left,right) << endl;
		}
	}
}


/*
Implementation:
1.) Implement the pushdown function (pushing down the lazy updates)
a.) If lazy.set(), then like melt down the updates (the things below have everything = 0 except the set value)
b.) If lazy.add(), then melt down the updates, if the set value > 0, increase the set value, and the value of the node itself
*/