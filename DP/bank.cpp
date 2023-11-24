#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define forn(i,j) for(ll i = 0; i < j; i++)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin(), x.end()
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

ll dp[1 << 20];
ll leftamt[1 << 20];


int main(){
	int n, m;
	cin >> n >> m;

	vi salary(n);
	vi banknotes(m);

	forn(i,n){
		cin >> salary[i];
	}

	forn(i,m){
		cin >> banknotes[i];
	}

	for(int mask = 0; mask < (1 << m); ++mask){
		for(int i = 0; i < m; ++m){
			if(i & mask){
				ll j = mask ^ (1 << i);
				ll amt = leftamt[j] + banknotes[i];
				ll person = dp[j];

				if(amt < salary[person]){
					if(dp[j] >= dp[mask]){
						dp[mask] = dp[j];
						leftamt[mask] = amt;
					}
				}

				if(amt == salary[person]){
					if(dp[j]+1 >= dp[mask]){
						leftamt[mask] = 0;
						dp[mask] = dp[j]+1;
					}
				}
			}
		}
	}

	int t = 0;

	for(int mask = 1; mask < (1 << m); ++mask){
		if(dp[mask] == n){
			cout << "YES" << endl;
			return 0;
		}
	}

	cout << "NO" << endl;
}