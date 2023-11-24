#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool compareByEndTime(const pair<ll, ll> &a, const pair<ll, ll> &b) {
    return a.second < b.second;
}

int main() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> vec;

    for (ll i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        vec.emplace_back(x, y);
    }

    sort(vec.begin(), vec.end(), compareByEndTime);

    ll movieCount = 0;
    ll endTime = 0;

    for (auto x : vec) {
        if (x.first >= endTime) {
            movieCount++;
            endTime = x.second;
        }
    }

    cout << movieCount;

    return 0;
}
