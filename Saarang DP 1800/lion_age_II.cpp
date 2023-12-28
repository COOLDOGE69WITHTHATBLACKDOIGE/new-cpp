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
 
int dp[100][101][26];
int cst[26][26];
 
signed main(){
    setIO();
    string a; cin >> a;
    int n = a.size();
    int c;
    int g;
    cin >> c >> g;
 
    forn(i,g){
        char ty,tu; cin >> ty >> tu;
        int st; cin >> st;
 
        cst[ty - 'a'][tu - 'a'] = st;
    }
 
    forrange(i,1,n){
        forn(chr,26){
            if(chr == a[i] - 'a'){
                dp[i][0][a[i]-'a'] = dp[i-1][0][a[i-1] - 'a'] + cst[a[i-1]-'a'][a[i]-'a'];
            }
 
            else{
                dp[i][0][chr] = -INF;
            }
        }
    }
 
    forn(chr,26){
        if(a[0] - 'a' != chr){
            dp[0][0][chr] = -INF;
        }
    }
 
    forrange(i,1,n){
        forrange(k,1,c+1){
            forn(chr,26){
                dp[i][k][chr] = max(dp[i][k-1][chr],dp[i][k][chr]);
                forn(chr2,26){
                    if(a[i] - 'a' == chr){
                        dp[i][k][chr] = max(dp[i][k][chr],dp[i-1][k][chr2] + cst[chr2][chr]);
                    }
 
                    else{
                        dp[i][k][chr] = max(dp[i][k][chr],dp[i-1][k-1][chr2] + cst[chr2][chr]);
                    }
                }
            }
        }
    }
 
    int ans = 0;
    forn(k,c+1){
        forn(chr,26){
            ans = max(ans,dp[n-1][k][chr]);
        }
    }
 
    cout << ans << endl;
}