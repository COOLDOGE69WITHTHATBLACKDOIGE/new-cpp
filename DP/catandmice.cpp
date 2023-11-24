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

struct Mouse{
	ld x, y, time;

	bool operator>(const Mouse m) const{
		return x > m.x;
	}
};

vector<Mouse> T(20);
ld dp[1 << 20][20];
int n;
ld m_power[20];

ld origin_distance(Mouse a){
	ld d = (a.x * a.x) + (a.y * a.y);
	ld g = sqrt(d);

	return g;
}

ld distance(Mouse a, Mouse b){
	ld d = abs((a.x - b.x)*(a.x - b.x));
	ld e = abs((a.y - b.y)*(a.y - b.y));

	ld f = d + e;

	ld g = sqrt(f);

	return g;
}

bool simulation(ld v){
	for(int i = 0; i < (1 << 20); ++i){
		for(int j = 0; j < n; ++j){
			dp[i][j] = MOD;
		}
	}

	//intialization
	forn(i,n){
		ld g = origin_distance(T[i]);
		ld ti = g/v;

		if(ti <= T[i].time){
			dp[1 << i][i] = ti;
		}
	}

	//transition
	for(int mask = 1; mask < (1 << n); ++mask){
		int power = __builtin_popcount(mask) - 1;
		for(int j = 0; j < n; ++j){
			if((1 << j) & mask){
				int prev = mask ^ (1 << j);

				for(int i = 0; i < n; ++i){
					if(prev & (1 << i)){
						ld curr_v = (v* (m_power[power]));
						ld ti = dp[prev][i] + distance(T[i], T[j])/curr_v;

						if(dp[prev][i] != MOD && ti <= T[j].time){
							dp[mask][j] = min(dp[mask][j], ti);
						}
					}
				}
			}
		}
	}

	int t = 0;

	for(int i = 0; i < n; ++i){
		if(dp[(1 << n) - 1][i] != MOD){
			return true;
		}
	}

	return false;

}

int main(){
	ld m;
	cin >> n;

	forn(i,n){
		cin >> T[i].x >> T[i].y >> T[i].time;
 	}

 	cin >> m;

 	m_power[0] = 1;

 	for(int i = 1; i < 20; ++i){
 		m_power[i] = m_power[i-1]*m;
 	}

 	cout << simulation(10) << endl;
}

