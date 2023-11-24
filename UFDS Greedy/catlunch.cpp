#include <algorithm>
#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    ll n;
    ll k;
    cin >> n >> k;

    priority_queue<ll> q;

    for(int i = 0; i < k; i++){
        ll x;
        cin >> x;
        q.push(x);
    }

    ll maximum = 0;
    ll sum = 0;
    for(int i = 0; i < n-k; i++){
        sum+= q.top();
        maximum = max(sum, maximum);
        q.pop();
        ll x;
        cin >> x;
        q.push(x);
    }

    while(q.size()!=0){
        sum+= q.top();
        q.pop();
        maximum = max(sum,maximum);
    }

    cout << maximum;
}