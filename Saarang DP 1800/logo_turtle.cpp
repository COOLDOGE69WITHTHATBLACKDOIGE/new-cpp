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

int dp1[100][51][2];
int dp2[100][51][2];

signed main(){
	setIO();
	string a;
	int c;
	cin >> a >> c;

	int n = a.size();

	if(a[0] == 'F'){
		dp1[0][0][1] = 1;
		dp1[0][1][0] = 0;

		dp1[0][0][0] = -INF;
	}

	else{
		dp1[0][0][0] = 0;
		dp1[0][1][1] = 0;

		dp1[0][0][1] = -INF;
	}

	forrange(i,1,n){
		if(a[i] == 'F'){
			if(dp1[i-1][0][1] == -INF){
				dp1[i][0][1] = -INF;
			}

			else{
				dp1[i][0][1] = dp1[i-1][0][1] + 1;
			}

			if(dp1[i-1][0][0] == -INF){
				dp1[i][0][0] = -INF;
			}

			else{
				dp1[i][0][0] = dp1[i-1][0][0] - 1; 
			}
		}

		else{
			if(dp1[i-1][0][0] == -INF){
				dp1[i][0][1] = -INF;
			}

			else{
				dp1[i][0][1] = dp1[i-1][0][0];
			}

			if(dp1[i-1][0][1] == -INF){
				dp1[i][0][0] = -INF;
			}

			else{
				dp1[i][0][0] = dp1[i-1][0][1];
			}
		}
	}

	forrange(i,1,n){
		forrange(k,1,c+1){
			if(a[i] == 'F'){
				dp1[i][k][1] = dp1[i-1][k][1] + 1;

				if(dp1[i-1][k-1][0] != -INF){
					dp1[i][k][1] = max(dp1[i][k][1],dp1[i-1][k-1][0]);
				}

				dp1[i][k][0] = dp1[i-1][k][0] - 1;

				if(dp1[i-1][k-1][1] != -INF){
					dp1[i][k][0] = max(dp1[i][k][0],dp1[i-1][k-1][1]);
				}
			}

			else{
				dp1[i][k][1] = dp1[i-1][k][0];

				if(dp1[i-1][k-1][1] != -INF){
					dp1[i][k][1] = max(dp1[i][k][1],dp1[i-1][k-1][1]+1);
				}

				dp1[i][k][0] = dp1[i-1][k][1];

				if(dp1[i-1][k-1][0] != -INF){
					dp1[i][k][0] = max(dp1[i][k][0],dp1[i-1][k-1][0]-1);
				}
			}
		}
	}


	if(a[0] == 'F'){
		dp2[0][0][1] = 1;
		dp2[0][1][0] = 0;

		dp2[0][0][0] = INF;
	}

	else{
		dp2[0][0][0] = 0;
		dp2[0][1][1] = 0;

		dp2[0][0][1] = INF;
	}

	forrange(i,1,n){
		if(a[i] == 'F'){
			if(dp2[i-1][0][1] == -INF){
				dp2[i][0][1] = -INF;
			}

			else{
				dp2[i][0][1] = dp2[i-1][0][1] + 1;
			}

			if(dp2[i-1][0][0] == -INF){
				dp2[i][0][0] = -INF;
			}

			else{
				dp2[i][0][0] = dp2[i-1][0][0] - 1; 
			}
		}

		else{
			if(dp2[i-1][0][0] == -INF){
				dp2[i][0][1] = -INF;
			}

			else{
				dp2[i][0][1] = dp2[i-1][0][0];
			}

			if(dp2[i-1][0][1] == -INF){
				dp2[i][0][0] = -INF;
			}

			else{
				dp2[i][0][0] = dp2[i-1][0][1];
			}
		}
	}

	forrange(i,1,n){
		forrange(k,1,c+1){
			if(a[i] == 'F'){
				dp2[i][k][1] = dp2[i-1][k][1] + 1;

				if(dp2[i-1][k-1][0] != -INF){
					dp2[i][k][1] = min(dp2[i][k][1],dp2[i-1][k-1][0]);
				}

				dp2[i][k][0] = dp2[i-1][k][0] - 1;

				if(dp2[i-1][k-1][1] != -INF){
					dp2[i][k][0] = min(dp2[i][k][0],dp2[i-1][k-1][1]);
				}
			}

			else{
				dp2[i][k][1] = dp2[i-1][k][0];

				if(dp2[i-1][k-1][1] != -INF){
					dp2[i][k][1] = min(dp2[i][k][1],dp2[i-1][k-1][1]+1);
				}

				dp2[i][k][0] = dp2[i-1][k][1];

				if(dp2[i-1][k-1][0] != -INF){
					dp2[i][k][0] = min(dp2[i][k][0],dp2[i-1][k-1][0]-1);
				}
			}
		}
	}

	int l = abs(min(dp2[n-1][c][0],dp2[n-1][c][1]));
	int m = max(dp1[n-1][c][0],dp1[n-1][c][1]);

	cout << max(l,m) << endl;
}