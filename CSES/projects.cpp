#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

tree<int, null_type, less<int>, rb_tree_tag,
tree_order_statistics_node_update> T;
 
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

struct Project{
	int start,end,profit;
};

bool comp(Project &a, Project &b){
	if(a.end == b.end){
		return a.start < b.start;
	}

	return a.end < b.end;
}

signed main(){
	setIO("input"); int n; cin >> n;
	vector<Project> projects(n);
	set<int> val; map<int,int> id;
	forn(i,n){ 
		cin >> projects[i].start >> projects[i].end >> projects[i].profit; projects[i].end++;
		val.insert(projects[i].start); val.insert(projects[i].end);
	}
	sort(all(projects),comp);
	int t = 1;
	for(int j : val){ id[j] = t; t++;}
	vector<pair<bool,int>> start(t+1,{false,0}); vi start_profit(t+1);

    forn(i,n){
    	projects[i].start = id[projects[i].start]; projects[i].end = id[projects[i].end];
    	start[projects[i].start].f = true; start[projects[i].start].s = projects[i].end; start_profit[projects[i].start] = projects[i].profit;
    }
	vi dp(t+1,0);
    forrange(i,1,t){
    	if(start[i].f){
    		dp[start[i].s] = max(dp[start[i].s],dp[i]+start_profit[i]);
    	}

    	dp[i+1] = max(dp[i+1],dp[i]);
    }

    cout << dp[t] << endl;
}