#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#pragma GCC optimize("trapv")

#define dbg(TXTMSG) cerr << "\n" << TXTMSG
#define dbgv(VARN) cerr << "\n" << #VARN << " = "<< VARN << ", line: " << __LINE__ << "\n"

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

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

const int N = 1e5;
const int h = 300;
int psum[N+h][h];
int ans[N];

signed main(){
	setIO();
	int n,q;
	cin >> n >> q;

	while(q--){
		int a,l,d;
		cin >> a >> l >> d;
		a--;

		if(d < h){
			psum[a][d]++;
			psum[a + (l*d)][d]--;
		}

		else{
			while(l > 0){
				ans[a]++;
				a += d;
				l--;
			}
		}
	}

	forn(j,h){
		forrange(i,j,n){
			psum[i][j] += psum[i-j][j];
		}
	}

	forn(i,n){
		forn(j,min(i,h)){
			ans[i] += psum[i][j];
		}
	}

	forn(i,n){
		cout << ans[i] << " ";
	}

	cout << endl;
}