#include<bits/stdc++.h>
using namespace std;
 
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

const int MOD = 998244353;
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

int power(int a, int b){
	int res = 1;

	while(b > 0){
		if(b % 2 == 1){
			res *= a;
			res %= MOD;
		}

		a*=a;
		a %= MOD;
		b /= 2;
	}

	return res;
}

signed main(){
	setIO();
	int n;
	cin >> n;

	vi a(n,0);
	vi b(n,0);
	vi ans(n);

	forrange(i,1,n){
		a[i] = 180*(power(10,n-i-1));
		a[i] %= MOD;
	}

	forrange(i,1,n){
		b[i] = 810*(n-i-1);
		b[i] *= power(10,n-i-2);
		b[i] %= MOD;
	}

	forrange(i,1,n){
		ans[i] = a[i] + b[i];
		ans[i] %= MOD;
	}

	forrange(i,1,n){
		cout << ans[i] << " ";
	}

	cout << 10;
}


/// aaa...[llll....l]...bbbb
/// length, n - length choices - 1