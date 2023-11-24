#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
// #define _GLIBCXX_DEBUG 1
// #define _GLIBCXX_DEBUG_PEDANTIC 1
// #pragma GCC optimize("trapv")

// #define dbg(TXTMSG) cerr << "\n" << TXTMSG
// #define dbgv(VARN) cerr << "\n" << #VARN << " = "<< VARN << ", line: " << __LINE__ << "\n"

#define ll long long
#define ld long double
#define forn(i,j) for(ll i = 0; i < j; i++)
#define forrange(i,j,k) for(int i = j; i < k; ++i)
#define rof(i,j) rof(int i = j; i >= 0; --i)
#define pii pair<int,int>
#define vll vector<ll>
#define vi vector<int>
#define vvll vector<vll>
#define vvi vector<vi>
#define vb vector<bool>
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define eb emplace_back
#define qi queue<int>
#define qpii queue<pii>

#define MOD 1000000007

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
	int n, m;
	cin >> n >> m;

	vi b;
	vi a;

	b.pb(0);
	a.pb(0);

	forn(i,n){
		int c;
		cin >> c;

		if(c < 0){
			b.pb(c);
		}

		else{
			a.pb(c);
		}
	}

	sort(all(b));
	sort(all(a));

	int g = b.size();
	int h = a.size();

	pii dp1[g+1][h+1];
	pii dp2[g+1][h+1];

	forn(i,g+1){
		forn(j,h+1){
			dp1[i][j] = {-1,-1};

			dp2[i][j] = {-1.-1};
		} 
	}

	dp1[g][0] = {0,0};
	dp2[g][0] = {0,0};

	for(int j = 1; j < h; ++j){
		if(dp2[g-1][j].f > dp2[g-1][j-1].f + max(0, m - dp2[g-1][j-1].s + x[j] - x[j-1])){
			continue;
		}

		if(dp2[g-1][j].f == dp2[g-1][j-1].f + max(0, m - dp2[g-1][j-1].s - x[j] + x[j-1])){
			dp2[g-1][j].s = min(dp2[g-1][j].s, dp2[g-1][j-1].s + (x[j]) - x[j-1]);
		}

		else{
			dp2[g-1][j] = {dp2[g-1][j].f + max(0,m - dp2[g-1][j-1].s - x[j] + x[j-1]), dp2[g-1][j-1].s + x[j] - x[j-1]};
		}

		if(dp1[g-1][j].f > dp2[g-1][j].f){
			continue;
		}

		if(dp1[g-1][j].f == dp2[g-1][j].f){
			dp1[g-1][j].s = min(dp1[g-1][j].s, dp2[g-1][j].s + x[j]);
		}

		else{
			dp1[g-1][j] = {dp2[g-1][j].f, dp2[g-1][j].s + x[j]};
		}
	} 

	for(int i = g - 2; i > -1; --i){
		for(int j = 0; j < h; ++j){

			//jump from left to right

			if(dp1[i][j].f > dp1[i+1][j].f + max(0, m - dp1[i+1][j].s - abs(x[i+1] - x[i]))){
				continue;
			}

			if(dp1[i][j].f == dp1[i+1][j].f + max(0, m - dp1[i+1][j].s - abs(x[i+1] - x[i]))){
				dp1[i][j].s = min(dp1[i][j].s, dp1[i+1][j].s + abs(x[i+1] - x[i]));
			}

			else{
				dp1[i][j] = {dp1[i+1][j].f + max(0.m - dp1[i+1][j].s - abs(x[i+1] - x[i]))};
			}

			//jump from right to left

			if(dp1[i][j].f > dp2[i+1][j].f + max(0, m - dp2[i+1][j].s - x[j] + x[i])){
				continue;
			}

			if(dp1[i][j].f == dp1[i+1][j].f + max(0, m - dp1[i+1][j].s - abs(x[i+1] - x[i]))){
				dp1[i][j].s = min(dp1[i][j].s, dp1[i+1][j].s + abs(x[i+1] - x[i]));
			}

			else{
				dp1[i][j] = {dp1[i+1][j].f + max(0.m - dp1[i+1][j].s - abs(x[i+1] - x[i]))};
			}			
		}
	}
}