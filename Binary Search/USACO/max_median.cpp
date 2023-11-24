#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define forn(i,j) for(int i = 0; i < j; i++)

using namespace std;

int last_true(int lo, int hi, function<bool(int)> f) {
	// if none of the values in the range work, return lo - 1
	lo--;
	while (lo < hi) {
		// find the middle of the current range (rounding up)
		int mid = lo + (hi - lo + 1) / 2;
		if (f(mid)) {
			// if mid works, then all numbers smaller than mid also work
			lo = mid;
		} else {
			// if mid does not work, greater values would not work either
			hi = mid - 1;
		}
	}
	return lo;
}

int main(){
    int n, max_ops;
    cin >> n >> max_ops;

    vector<int> arr(n);

    forn(i,n){ cin >> arr[i];}

    sort(arr.begin(), arr.end());

    cout << last_true(1, 2e9, [&](int x) {
		// Returns true if the median can be raised to x
		ll ops_needed = 0;
		for (int i = (n - 1) / 2; i < n; i++) {
			ops_needed += max(0, x - arr[i]);
		}
		return ops_needed <= max_ops;
	}) << endl;
}