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
	setIO();
	int n,k;
	cin >> n >> k;

	vi nums(n);

	forn(i,n){
		cin >> nums[i];
	}

	int ptr = -1;
	map<int,int> freq;
	int dist = 0;
	int res = 0;

	forn(i,n){
		while(ptr < n-1){
			if(freq[nums[ptr+1]] == 0 && dist == k){
				break;
			}

			else{
				if(freq[nums[ptr+1]] == 0){
					dist++;
				}

				ptr++;
				freq[nums[ptr]]++;
			}
		}

		res += ptr - i + 1;
		freq[nums[i]]--;
		
		if(freq[nums[i]] == 0){
			dist--;
		}
	}

	cout << res << endl;
}