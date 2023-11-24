#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

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
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define eb emplace_back
#define debug(x) cerr << #x << " is " << x << endl;

#define MOD 1000000007

const int N = 4e3;

string grid[N];

int cost(pii a, pii b){
	if(grid[a.f][a.s] != grid[b.f][b.s]){
		return 1;
	}

	else{
		return 0;
	}
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int dx[] = {1,0,-1,0};
	int dy[] = {0,1,0,-1};
	int h,w;
	cin >> h >> w;

	vvi dp(h, vi(w, 0));

	forn(i,h){
		cin >> grid[i];
	}

	deque<pii> s;
	dp[0][0] = 1;
	s.push_back({0,0});
	int mx = 0;

	while(!s.empty()){
		pii k = s.front();
		s.pop_front();
		mx = max(dp[k.f][k.s], mx);

		forn(i,4){
			int m = k.f + dx[i];
			int n = k.s + dy[i];
			pii g = {m,n};

			if((m < 0 || n < 0 || m >= h || n >= w) || grid[m][n] == '.' || dp[m][n] != 0){
				continue;
			}

			else{
				if(cost(g,k) == 1){
					dp[m][n] = dp[k.f][k.s] + 1;
					s.push_back(g);
				}

				else{
					dp[m][n] = dp[k.f][k.s];
					s.push_front(g);
				}
			}
		}
	}

	cout << mx << endl;
}