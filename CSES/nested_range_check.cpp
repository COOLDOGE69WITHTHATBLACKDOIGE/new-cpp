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

#define MOD 1000000007

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
const int M = 4e5 + 2;

vi ft(M,0);
set<int> st;

void update(int idx, int val){
	for(int i = idx; i < M; i += i&-i){ ft[i] += val;}
}

int query(int idx){
	int res = 0;
	for(int i = idx; i > 0; i -= i&-i){ res += ft[i];}
	return res;
}

void resetft(){
	ft.assign(M,0);
}

struct Ranges{
	int l,r,index;
};

bool comp(Ranges &a, Ranges &b){
	if(a.l == b.l){
		return a.r > b.r;
	}

	return a.l < b.l;
}

signed main(){
	setIO();
	int n; cin >> n;
	vector<Ranges> range(n);
	forn(i,n){ cin >> range[i].l >> range[i].r; range[i].index = i; st.insert(range[i].l); st.insert(range[i].r);}
	sort(all(range),comp); vi contains(n), contained(n);
	map<int,int> ids;
	int tf = 1;
	for(int k : st){
		ids[k] = tf; tf++;
	}

	forn(i,n){
		range[i].l = ids[range[i].l];
		range[i].r = ids[range[i].r];
	}

	for(int i = n-1; i > -1; --i){
		contains[range[i].index] = query(range[i].r);
		update(range[i].r,1);
	}

	resetft();

	forn(i,n){
		contained[range[i].index] = i-query(range[i].r-1);
		update(range[i].r,1);
	}

	forn(i,n){
		cout << contains[i] << " ";
	}

	cout << endl;

	forn(i,n){
		cout << contained[i] << " ";
	}
}