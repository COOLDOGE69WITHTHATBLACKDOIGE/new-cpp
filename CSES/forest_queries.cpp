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
const int maxN = 1001;

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int pref[maxN][maxN];

int query(int x1, int y1, int x2, int y2){
	return (pref[x1][y1] - pref[x1][y2] - pref[x2][y1] + pref[x2][y2]);
}

signed main(){
	setIO("input"); int n,q; cin >> n >> q;
	string grid[n];
	forrange(i,1,n+1){
		cin >> grid[n-i];
	}

	forrange(i,1,n+1){
		forrange(j,1,n+1){
			pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1];

			if(grid[i-1][j-1] == '*'){
				pref[i][j]++;
			}
		}
	}

	while(q--){
		int x1,y1,x2,y2;
		cin >> y2 >> x2 >> y1 >> x1;

		cout << query(x1,y1,x2,y2) << endl;
	}
}