#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define forn(i,j) for(ll i = 0; i < j; ++i)

using namespace std;

int main(){
    ll n;
    cin >> n;

    ll arr[n];

    forn(i, n){
        cin >> arr[i];
        arr[i] = (i+1) - arr[i];
    }

    ll x, y;
    cin >> x >> y;
    ll rec[n];

    if(x >= 1){
        forn(i, x){
            arr[i] = 1;
        }
    }

    if(arr[0] == 0){
        rec[0] = 1;
    }

    else{
        rec[0] = 0;
    }

    for(ll i = 1; i < n; ++i){
        if(abs(arr[i]) <= rec[i-1] && arr[i] <= 0){
            rec[i] = rec[i-1] + 1;
        }

        else{
            rec[i] = rec[i-1];
        }
    }

    cout << rec[n-1];   
}
