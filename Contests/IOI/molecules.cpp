#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
// #include "molecules.h"
using namespace std;
using namespace __gnu_pbds;
 
// #define _GLIBCXX_DEBUG 1
// #define _GLIBCXX_DEBUG_PEDANTIC 1
// #pragma GCC optimize("trapv")

// #define dbg(TXTMSG) cerr << "\n" << TXTMSG
// #define dbgv(VARN) cerr << "\n" << #VARN << " = "<< VARN << ", line: " << __LINE__ << "\n"

#define ll long long
#define ld long double
#define forn(i,j) for(ll i = 0; i < j; i++)
#define forrange(i,j,k) for(int i = j; i < k; ++i)
#define rof(i,j) rof(int i = j; i >= 0; --i)
#define pii pair<int,int>
#define vll vector<ll>
#define vi vector<int>
#define vvll vector<vll>
#define vvi vector<vi>
#define vb vector<bool>
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define eb emplace_back
#define qi queue<int>
#define qpii queue<pii>

#define MOD 1000000007

void setIO(string name = ""){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if(!name.empty()){
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".in").c_str(), "w", stdout);
    }
}

bool t(int sum, int l, int u){
    return (sum >= l && sum <= u);
}

std::vi find_subset(int l, int u, vi w){
    sort(all(w));

    vi pref(w.size());

    pref[0] = w[0];

    for(int i = 1; i < w.size(); ++i){
        pref[i] = pref[i-1] + w[i];
    }

    for(int k = 1; k < w.size(); ++k){
        int minsum = pref[k];
        int maxsum = pref[w.size()] - pref[w.size() - k];

        int h = minsum;

        if((minsum <= l && maxsum >= u) || t(maxsum,l,u) || t(minsum,l,u)){
            vi a;
            vi b;

            forn(i,k){
                a.pb(w[i]);
                b.pb(w[w.size() - i - 1]);
            }
            if(t(minsum,l,u)){
                return a;
            }

            if(t(maxsum,l,u)){
                return b;
            }

            else{
                forn(i,k){
                    h += w[w.size() - k + i] - w[i];
                    a[i] = w[w.size() - k + i];

                    if(t(h,l,u)){
                        return a;
                    }
                }
            }
        }
    }

    vi f(1,0);

    return f;
}

int main(){
    int n,l,u;
    cin >> n >> l >> u;

    vi g;

    forn(i,n){
        int a;
        cin >> a;
        g.pb(a);
    }

    vi d = find_subset(l,u,g);

    if(d.size() == 1 && d[0] == 0){
        cout << "NO" << endl;
    }

    else{
        cout << "YES" << endl;
    }
}