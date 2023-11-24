#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> seg(n);

    // Find the maximum endpoint value to dynamically allocate memory
    int maxEndpoint = -1;
    for (int i = 0; i < n; i++) {
        cin >> seg[i].first >> seg[i].second;
        maxEndpoint = max(maxEndpoint, seg[i].second);
    }

    // Dynamically allocate memory for arrays based on the maximum endpoint value
    vector<int> count(maxEndpoint + 2, 0);
    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++) {
        count[seg[i].first]++;
        count[seg[i].second + 1]--;
    }

    for (int i = 1; i < maxEndpoint + 2; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = 0; i < maxEndpoint + 2; i++) {
        while (count[i] > k) {
            int pos = -1;
            for (int p = 0; p < n; p++) {
                if (!ans[p] && (seg[p].first <= i && i <= seg[p].second) &&
                    (pos == -1 || seg[pos].second < seg[p].second)) {
                    pos = p;
                }
            }
            assert(pos != -1);

            for (int m = seg[pos].first; m < seg[pos].second + 1; m++) {
                count[m]--;
            }
            ans[pos] = 1;
        }
    }

    cout << accumulate(ans.begin(), ans.end(), 0) << endl;

    for (int i = 0; i < n; i++) {
        if (ans[i] == 1) {
            cout << i + 1 << ' ';
        }
    }

    return 0;
}