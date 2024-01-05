#include<bits/stdc++.h>
using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// template <class T>
// using oset =
//     tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
// #define _GLIBCXX_DEBUG 1
// #define _GLIBCXX_DEBUG_PEDANTIC 1
// #pragma GCC optimize("trapv")

// #define dbg(TXTMSG) cerr << "\n" << TXTMSG
// #define dbgv(VARN) cerr << "\n" << #VARN << " = "<< VARN << ", line: " << __LINE__ << "\n"

#define int long long
#define forn(i,j) for(int i = 0; i < j; i++)
#define forrange(i,j,k) for(int i = j; i < k; ++i)
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define vvi vector<vi>
#define vvpii vector<vector<pii>>
#define vb vector<bool>
#define pb push_back
#define f first
#define s second

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

struct Node{
	char val;
	int pri,subtree;
	Node *left, *right;

	Node(char c): val(c), pri(rand()), left(NULL), right(NULL){}
} *root;

int subtree_size(Node *a){
	if(!a){
		return 0;
	}

	return a->subtree;
}

void split(Node *treap, Node *&left, Node *&right, int value){
	if(!treap){
		left = right = NULL;
		return;
	}

	if(subtree_size(treap->left) < value){
		split(treap->right,left,treap->right,value - subtree_size(treap->left))
	}
}

signed main(){}