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
int res = 0;
int dp[21][maxN];

int l = 0; int r = 0;
int freq[maxN];

void mv(int cl, int cr){
	while(l > cl){
		--l;
		res += freq[a[l]];
		freq[a[l]]++;
	}

	while(l < cl){
		++l;
		freq[a[l]]--;
		res -= freq[a[l]];
	}

	while(r < cr){
		r++;
		res += freq[a[r]];
		freq[a[r]]++;
	}

	while(r > cr){
		r--;
		freq[a[r]]--;
		res -= freq[a[r]];
	}
}

void dnc(int i, int l, int r, int optl, int optr){
	if(l > r){
		return;
	}

	int mid = (l+r)/2;
	dp[i][mid] = INF;
	int opt = 1;

	forrange(j,optl,min(mid,optr)+1){
		if(j == mid){
			break;
		}

		mv(j+1,mid);

		if(dp[i][mid] > dp[i-1][j] + res){
			dp[i][mid] = dp[i-1][j] + res;
			opt = j;
		}
	}

	dnc(i,l,mid-1,optl,opt);
	dnc(i,mid+1,r,opt,optr);
}

signed main(){
	setIO("input");
	int n,k;

	cin >> n >> k;

	forn(i,n){
		cin >> a[i+1];
	}

	dp[0][0] = 0;

	forrange(i,1,n+1){
		mv(1,i);
		dp[0][i] = res;
	}

	forrange(i,1,k+1){
		dnc(i,1,n,0,n-1);
	}

	cout << dp[0][n] << endl;
}