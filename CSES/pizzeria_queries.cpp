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

struct node{
    int mx1, mx2;
};

node seg[2*maxN];
int n,q;

node combine(node &a, node &b){
    node c; c.mx1 = min(a.mx1,b.mx1); c.mx2 = min(a.mx2,b.mx2);

    return c;
}

void update(int idx, int val1, int val2){
    idx += n;
    seg[idx].mx1 = val1; seg[idx].mx2 = val2;

    for(idx /= 2; idx; idx /= 2){
        seg[idx] = combine(seg[2*idx],seg[2*(idx) + 1]);
    }
}

int query(int left, int right, int type){
    if(!type){
        int ra = INF, rb = INF;

        for(left += n, right += n+1; left < right; left /= 2, right /= 2){
            if(left & 1){ ra = min(seg[left++].mx1,ra);}
            if(right & 1){ rb = min(rb,seg[--right].mx1);}
        }

        return min(ra,rb);
    }

    else{
        int ra = INF, rb = INF;

        for(left += n, right += n+1; left < right; left /= 2, right /= 2){
            if(left & 1){ ra = min(seg[left++].mx2,ra);}
            if(right & 1){ rb = min(rb,seg[--right].mx2);}
        }

        return min(ra,rb);
    }
}

signed main(){
    setIO(); cin >> n >> q; vi p(n);
    forn(i,n){
        cin >> p[i];
        update(i,p[i] - i,p[i] + i);
    }

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int k,x; cin >> k >> x; k--;
            update(k,x - k, x + k);
        }

        else{
            int b; cin >> b; b--;

            if(b == n-1){
                int c1 = query(0,b,0) + b;

                cout << c1 << endl;
            }

            else{
                int c1 = query(0,b,0) + b;
                int c2 = query(b+1,n-1,1) - b;

                cout << min(c1,c2) << endl;
            }
        }
    }
}

/*
                      /^--^\     /^--^\     /^--^\   meow!
                      \____/     \____/     \____/
                     /      \   /      \   /      \
                    |        | |        | |        |
                     \__  __/   \__  __/   \__  __/
|^|^|^|^|^|^|^|^|^|^|^|^\ \^|^|^|^/ /^|^|^|^|^\ \^|^|^|^|^|^|^|^|^|^|^|^|
| | | | | | | | | | | | |\ \| | |/ /| | | | | | \ \ | | | | | | | | | | |
| | | | | | | | | | | | / / | | |\ \| | | | | |/ /| | | | | | | | | | | |
| | | | | | | | | | | | \/| | | | \/| | | | | |\/ | | | | | | | | | | | |
#########################################################################
| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |
| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |


*/

