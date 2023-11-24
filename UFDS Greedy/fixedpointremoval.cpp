#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define forn(i,j) for(ll i = 0; i < j; ++i)

using namespace std;

int main(){
    ll n,q;
    cin >> n >> q;

    ll arr[n];

    forn(i, n){
        cin >> arr[i];
        arr[i] = (i+1) - arr[i];
    }

    while(q--){
        ll x, y;
        cin >> x >> y;

        ll rec[n];
        
        forn(i,x){
            rec[i] = 1;
        }

        for(ll i = n-y; i < n; ++i){
            rec[i] = 1;
        }

        if(arr[0] == 0){
            rec[0] = 1;
        }


        else {
            rec[0] = 1;
        }

        for(ll i = 1; i < n; ++i){

            if(abs(arr[i]) <= rec[i-1]){
                rec[i] = rec[i-1]+1;                
            }

            else {
                rec[i] = rec[i-1];
            }
        }

        cout << rec[n] << endl;
    }
}
