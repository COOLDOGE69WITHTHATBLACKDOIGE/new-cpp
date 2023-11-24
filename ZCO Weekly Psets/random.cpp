#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#pragma GCC optimize("trapv")

#define dbg(TXTMSG) cerr << "\n" << TXTMSG
#define dbgv(VARN)                                                             \
  cerr << "\n" << #VARN << " = " << VARN << ", line: " << __LINE__ << "\n"

#define ll long long
#define ld long double
#define int long long
#define forn(i, j) for (ll i = 0; i < j; i++)
#define forrange(i, j, k) for (int i = j; i < k; ++i)
#define rof(i, j) rof(int i = j; i >= 0; --i)
#define pii pair<int, int>
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

void setIO(string name = "") {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  if (!name.empty()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

void solve() {}

int32_t main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int h[n];

    forn(i, n) { cin >> h[i]; }

    vector<pii> dp(n);
    vector<pii> dp1(n);

    // first stores number of buildings
    // second stores number of floors to be built

    dp[0].f = 0;
    dp[0].s = 0;
    dp1[0].f = 0;
    dp1[0].s = 0;

    forrange(i, 1, n) {
      if (dp[i - 1].f == dp1[i - 1].f) {
        dp[i].f = dp[i - 1].f;
        dp[i].s = min(dp[i - 1].s, dp1[i - 1].s);
      }

      else {
        if (dp[i - 1].f > dp1[i - 1].f) {
          dp[i].f = dp[i - 1].f;
          dp[i].s = dp[i - 1].s;
        }

        if (dp1[i - 1].f > dp[i - 1].f) {
          dp[i].f = dp1[i - 1].f;
          dp[i].s = dp1[i - 1].s;
        }
      }

      if (i != n - 1) {
        dp1[i].f = dp[i - 1].f + 1;
        int curr = max(h[i - 1], h[i + 1]);
        dp1[i].s = dp[i - 1].s;
        dp1[i].s += max(0LL, curr + 1 - h[i]);
      }
    }

    cout << dp[n - 1].s << endl;
  }
}