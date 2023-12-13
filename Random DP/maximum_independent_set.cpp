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

bool getbit(int mask, int bit){
	return (mask & (1LL << bit));
}

int highestbit(int size, int mask){
	int k = size - 1;

	for(int i = k; i >= 0; --i){
		if(getbit(mask,i)){
			return i;
		}
	}

	return 0;
}

vi graph;
int n;
int half;

bool sv(int mask, int i){
	if(graph[i] & mask == mask){
		return true;
	}

	return false;
}

bool merge(int clique1, int clique2){
	if(__builtin_popcount(clique1) > __builtin_popcount(clique2)){
		swap(clique1,clique2);
	}

	forn(i,n){
		if(getbit(clique1,i)){
			if(graph[i] & clique2 == clique2){
				continue;
			}

			else{
				return false;
			}
		}
	}

	return true;
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
	setIO("input");
	int m;
	cin >> n >> m;

	graph.resize(n,(1LL << n)-1);

	forn(i,m){
		int a,b;
		cin >> a >> b;

		graph[a] = graph[a] & (1LL << b);
		graph[b] = graph[b] & (1LL << a);
	}

	vi cliques;
	vi cliques2;
	half = n/2;

	vb dp((1LL << n),false);

	forn(i,n){
		dp[(1LL << i)] = true;
	}

	forn(mask,(1LL << half)){
		if(dp[mask]){
			cliques.pb(mask);
			continue;
		}

		else{
			int k = highestbit(half,mask);

			int l = mask ^ (1LL << k);

			if(dp[l]){
				if(graph[k] & l == l){
					cerr << "HELLO" << endl;
					dp[mask] = true;
					cliques.pb(mask);
				}

				else{
					dp[mask] = false;
				}
			}

			else{
				dp[mask] = false;
			}
		}
	}		

	int mx = 0;
	int fg = 0;

	for(int mask : cliques){
		for(int mask2 : cliques2){
			if(merge(mask,mask2)){
				int t = mask ^ mask2;
				int sz = __builtin_popcount(t);

				if(mx < sz){
					mx = sz;
					fg = t;
				}
			}
		}
	}

	cout << mx << endl;
	cout << fg << endl;
}