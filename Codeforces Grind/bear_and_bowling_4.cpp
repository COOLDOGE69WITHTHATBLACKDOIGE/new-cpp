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

const int MOD = 1e9 + 7;
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

int dp[maxN];
int psum[maxN];
int cst[maxN];

void dnc(int l, int r, int optl, int optr){
    if(l > r){
        return;
    }

    int mid = (l+r)/2;
    dp[mid] = -INF;
    int opt = 1;

    forrange(j,max(optl,mid),optr+1){
        int sum = cst[j] - cst[mid-1] - ((psum[j] - psum[mid-1])*(mid-1));

        if(sum > dp[mid]){
            dp[mid] = sum;
            opt = j; 
        }
    }

    dnc(l,mid-1,optl,opt);
    dnc(mid+1,r,opt,optr);
}

signed main(){
    setIO();
    int n;
    cin >> n;
    vi a(n);

    forn(i,n){
        cin >> a[i];

        psum[i+1] = a[i] + psum[i];
        cst[i+1] = cst[i] + (a[i]*(i+1));
    }

    int res = 0;

    dnc(1,n,1,n);

    forrange(i,1,n+1){
        res = max(res,dp[i]);
    }

    cout << res << endl;
}