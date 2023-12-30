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

#define MOD 1000000007

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int block_size = 447;

struct Query{
	int left,right,index;
};

const int M = 1e6+1;

bool comp(Query &a, Query &b){
	int block1 = a.left/block_size;
	int block2 = b.left/block_size;

	if(block1 == block2){
		return a.right < b.right;
	}

	return a.left < b.left;
}

int freq[M], a[M], ans[M];
Query Q[M];

int res = 0;

void add(int i){
	res -= (freq[a[i]]*freq[a[i]])*a[i];
	freq[a[i]]++;

	res += (freq[a[i]]*freq[a[i]])*a[i];
}

void remove(int i){
	res -= (freq[a[i]]*freq[a[i]])*a[i];
	freq[a[i]]--;

	res += (freq[a[i]]*freq[a[i]])*a[i];
}

int mo_left = 0;
int mo_right = -1;

int query(int L, int R){
	while(mo_right < R){
		add(++mo_right);
	}

	while(mo_right > R){
		remove(mo_right--);
	}

	while(mo_left > L){
		add(--mo_left);
	}

	while(mo_left < L){
		remove(mo_left++);
	}

	return res;
}

signed main(){
	setIO();

	int n,q;
	cin >> n >> q;

	forn(i,n){
		cin >> a[i];	
	}

	forn(i,q){
		cin >> Q[i].left >> Q[i].right;
		Q[i].left--;
		Q[i].right--;
		Q[i].index = i;
	}

	sort(Q,Q+q,comp);

	for(int i = 0; i < q; ++i){
		Query t = Q[i];
		int l = t.left;
		int r = t.right;

		int h = query(l,r);
		ans[t.index] = h;
	}

	forn(i,q){
		cout << ans[i] << endl;
	}
}