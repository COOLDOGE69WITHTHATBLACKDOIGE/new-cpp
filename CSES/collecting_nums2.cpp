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
	int n,m;
	cin >> n >> m;

	vi nums(n);
	vi pos(n+2,0);

	forn(i,n){
		cin >> nums[i];

		pos[nums[i]] = i+1;
	}

	pos[n] = n+1;


	int t = 1;

	forn(i,n){
		if(pos[i] > pos[i+1]){
			t++;
		}
	}

	forn(i,m){
		int a,b;
		cin >> a >> b;

		int k = nums[a-1],l = nums[b-1];
		swap(nums[a-1],nums[b-1]);

		if(pos[k-1] < pos[k] && pos[k-1] >= b){
			t++;
		}

		if(pos[k-1] > pos[k] && pos[k-1] <= b){
			t--;
		}

		if(pos[k+1] > pos[k] && pos[k+1] <= b){
			t++;
		}

		if(pos[k+1] < pos[k] && pos[k+1] >= b){
			t--;
		}

		if(pos[l-1] < pos[l] && pos[l-1] >= a){
			t++;
		}

		if(pos[l-1] > pos[l] && pos[l-1] <= a){
			t--;
		}

		if(pos[l+1] > pos[l] && pos[l+1] <= a){
			t++;
		}

		if(pos[l+1] < pos[l] && pos[l+1] >= a){
			t--;
		}

		pos[l] = a, pos[k] = b;
		cout << t << endl;
	}
}