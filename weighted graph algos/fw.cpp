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
#define int ll

const int MOD = 100000000000000007;

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

signed main(){
	setIO();
	int n, m,q;
	cin >> n >> m >> q;
	vector<vector<int>> mindist(n, vi(n, MOD));

	forn(i,m){
		int a,b,c;
		cin >> a >> b >> c;
		a--;
		b--;
		mindist[a][a] = 0;
		mindist[b][b] = 0;

		if(c < mindist[a][b]){
			mindist[a][b] = c;
			mindist[b][a] = c;
		}
	}


	forn(k,n){
		forn(i,n){
			forrange(j,i+1,n){
				int curr = mindist[i][k] + mindist[j][k];

				if(curr < mindist[i][j]){
					mindist[i][j] = curr;
					mindist[j][i] = curr;
				}
			}
		}
	}

	forn(i,n){
		forrange(j,i+1,n){
			if(mindist[i][j] >= MOD){
				mindist[i][j] = -1;
				mindist[j][i] = -1;
			}
		}
	}

	forn(i,q){
		int a,b;
		cin >> a >> b;
		a--;
		b--;

		cout << mindist[a][b] << endl;
	}
}