#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define forn(i,j) for(ll i = 0; i < j; i++)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin, x.end()
#define eb emplace_back

#define MOD 1000000007

void setIO(string name = "") { 

	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

ll dp[1 << 20][20];

// come_from[i] contains the cities that can fly to i

vector<int> outdegree[MAX_N];

int main(){
	setIO();
	int n,m;
	cin >> n >> m;

	forn(i,m){
		int vertex1;
		int vertex2;
		cin >> vertex1 >> vertex2;

		vertex1--;
		vertex2--;

		outdegree[vertex2].pb(vertex1);
	}

	dp[1][0] = 1;

	for(int str = 2; str < (1 << n); ++str){	
		if(str & (1 << 0) == 0){
			continue;
		}

		if ((str & (1 << (n - 1))) && str != ((1 << n) - 1)){
			continue;
		}

		for(int v = 0; v < n; ++v){
			if(str & (1<<v) == 0){
				continue;
			}

			int s = str - (1 << v);

			for(int x : outdegree[v]){
				if(str & (1<<x)){
					dp[str][v] += dp[s][x];
					dp[str][v] %= MOD;
				}
			}
		}
	}

	cout << dp[(1 << n) - 1][n-1] << endl;
}