#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll t;
    cin >> t;
    while(t--){
    ll n;
    cin >> n;
    ll a[n];

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll product;
    ll maximum = a[0] * a[1];

    for(ll i = 0; i < n-1; i++){
        product = a[i] * a[i+1];
        maximum = max(product, maximum);
    }

    cout << maximum << endl;
    }
}