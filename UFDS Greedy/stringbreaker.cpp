#include<bits/stdc++.h>
#define ll long long
#define forn(i,j) for(ll i = 0; i<j; ++i)
#define pb push_back

using namespace std;

ll min(ll a, ll b){
    if(a >= b){
        return b;
    }
    else{
        return a;
    }
}


void stringbreaker(){
    ll N, K;
    cin >> N >> K;

    char arr[N];

    forn(i,N){
        cin >> arr[i];
    }

    vector<ll> p(N);

    ll b = 0;
    forn(i, N){
        b += 2 * (arr[i] - '0') - 1;
        p[i] = abs(b);
    }

    vector<ll> ans(N, 0);
    vector<ll> mint(N);
    mint[N-1] = p[N-1];

    for(ll i = N-2; i >= 0; --i){
        mint[i] = min(mint[i+1], p[i]);
    }

    ll pos = 0;

    forn(i, N){
        if(p[i] - pos > K && (i == N-1 || p[i] <= mint[i+1])){
            ans[i] = 1;
            pos = p[i] - 1;
        }
    }

    ans[0] = 1;

    forn(i, N){
        cout << ans[i];
    }

    cout << endl;
   
}


int main(){
    ll T;
    cin >> T;
    while(T--){
        stringbreaker();
    }
}