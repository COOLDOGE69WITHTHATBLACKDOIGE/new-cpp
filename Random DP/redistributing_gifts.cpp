#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
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

#define MOD 1000000007

bool getbit(int a, int b){
	//a should be the mask, b should be the bit

	return (a & (1 << b));
}

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
	int n;
	cin >> n;

	vi graph(n,0);
	vi ans((1 << n),0);
	vvi dp((1 << n),vi(n,0));

	forn(i,n){
		vi a(n);

		forn(j,n){
			cin >> a[j];
			a[j]--;
		}

		forn(j,n){
			graph[i] |= (1 << a[j]);

			if(a[j] == i){
				break;
			}
		}
	}

	forn(i,n){
		//there is exactly one way for a mask only having i with the last being i
		dp[(1 << i)][i] = 1;
	}

	forn(i,n){
		//the highest bit
		forrange(mask,(1 << i),(1 << (i+1))){
			//the not reassigned cow
			forn(last,i+1){
				//extend the existing cycle
				forn(j,i){
					if(!getbit(mask,j) && getbit(graph[last],j)){
						dp[mask + (1 << j)][j] += dp[mask][last];
					}
				}

				//close the existing cycle
				if(getbit(graph[last],i)){
					ans[mask] += dp[mask][last];
				}
			}

			//start a new cycle
			forrange(k,i+1,n){
				dp[mask + (1 << k)][k] += ans[mask];
			}
		}
	}

	int q;
	cin >> q;

	forn(i,q){
		string s;
		cin >> s;
	
		int g = 0;
		int h = 0;

		forn(i,n){
			if(s[i] == 'H'){
				g |= (1 << i);
			}

			else{
				h |= (1 << i);
			}
		}

		if(h == 0 || g == 0){
			if(g == 0){
				cout << ans[h] << endl;
			}

			else{
				cout << ans[g] << endl;
			}
		}

		else{
			cout << ans[h]*ans[g] << endl;
		}
	}
}