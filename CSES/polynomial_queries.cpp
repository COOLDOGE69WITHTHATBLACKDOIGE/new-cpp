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
 
struct node{
	int sum,stt,freq;
};
 
node seg[4*maxN];
int a[maxN];
 
void pushdown(int pos, int l, int r, int mid){
	if(seg[pos].stt != 0){
		seg[2*pos].stt += seg[pos].stt, seg[2*(pos)+1].stt += seg[pos].stt + ((mid - l + 1)*seg[pos].freq);
		seg[2*pos].freq += seg[pos].freq, seg[2*(pos)+1].freq += seg[pos].freq;
 
		int t1 = (mid - l + 1)*(mid - l + 2)*(seg[pos].freq); t1 /= 2;
		seg[2*pos].sum += t1 + ((seg[pos].stt-seg[pos].freq)*(mid-l+1));
 
		int t2 = (r - mid)*(r - mid + 1)*(seg[pos].freq); t2 /= 2;
		seg[2*(pos)+1].sum += t2 + ((seg[pos].stt + (mid - l)*seg[pos].freq)*(r-mid));
 
		seg[pos].stt = seg[pos].freq = 0;
	}
}
 
void pushup(node &a, node &b, node &c){
	c.sum = a.sum + b.sum;
}
 
void build(int pos, int l, int r){
	seg[pos].stt = seg[pos].freq = 0;
	if(l == r){
		seg[pos].sum = a[l];
		return;
	}
 
	int mid = (l+r)/2;
	build(2*pos,l,mid); build((2*(pos))+1,mid+1,r);
 
	pushup(seg[2*pos],seg[(2*pos)+1],seg[pos]);
	return;
}
 
void add(int pos, int l, int r, int ql, int qr){
	if((qr < l) ||  (ql > r)){
		return;
	}
 
	if((l >= ql) && (qr >= r)){
		seg[pos].stt += (l-ql+1); seg[pos].freq++;
		int t1 = (l-ql+1) + (r-ql+1); t1 *= (r-l+1); t1 /= 2;
		seg[pos].sum += t1;
 
		return;
	}
 
	int mid = (l+r)/2;
	pushdown(pos,l,r,mid);
	add((2*pos),l,mid,ql,qr); add((2*pos)+1,mid+1,r,ql,qr);
	pushup(seg[2*pos],seg[(2*pos)+1],seg[pos]);
	return;
}
 
int query(int pos, int l, int r, int ql, int qr){
	if((qr < l) || (ql > r)){
		return 0;
	}
 
	if((l >= ql) && (r <= qr)){
		return seg[pos].sum;
	}
 
	int mid = (l+r)/2;
	pushdown(pos,l,r,mid);
	return query(2*pos,l,mid,ql,qr) + query((2*pos)+1,mid+1,r,ql,qr);
}
 
signed main(){
	setIO(); int n,q; cin >> n >> q;
	forn(i,n){
		cin >> a[i];
	}
 
	build(1,0,n-1);
 
	while(q--){
		int type,lt,rt; cin >> type >> lt >> rt; lt--,rt--;
 
		if(type == 1){
			add(1,0,n-1,lt,rt);
		}
 
		if(type == 2){
			cout << query(1,0,n-1,lt,rt) << endl;
		}
	}
}