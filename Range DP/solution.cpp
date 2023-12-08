#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 210
#define INF 0x3FFFFFFF

int opt[MAXN];
int psum[MAXN];
int canon[MAXN*2][MAXN*2];
vector<int> lparents[MAXN][MAXN];
vector<int> rparents[MAXN][MAXN];

int dp[MAXN][MAXN][MAXN][2];

int main() {
  int N; cin >> N;
  vector<pair<long long, long long> > A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i].first >> A[i].second;
  }

  /* Create the underlying string from the polygon.  Represent the exit as
   * 0.  Represent clockwise turns as -1, counter clockwise as -2.  Represent
   * lengths by their length.
   */
  vector<int> S(1, 0);
  for (int i = 0; i < N; i++) {
    int j = (i + 1) % N;
    int k = (i + 2) % N;
    S.push_back(abs(A[i].first - A[j].first) +
                abs(A[i].second - A[j].second));

    /* Use a cross product to determine which way the polygon turned. */
    if ((A[i].first - A[j].first) * (A[k].second - A[j].second) -
        (A[k].first - A[j].first) * (A[i].second - A[j].second) > 0) {
      S.push_back(-1);
    } else {
      S.push_back(-2);
    }
  }
  S.back() = 0;

  /* Compute the lights-on cost for each corner. */
  for (int i = 0; i < N; i++){
    psum[i + 1] = opt[i + 1] = opt[i] + S[2 * i + 1];
  }
  opt[N] = 0;
  for (int i = N - 1; i >= 0; i--) {
    opt[i] = min(opt[i], opt[i + 1] + S[2 * i + 1]);
  }

  /* Compute j = canon[i][ln] to be the first j s.t. S[j:j+ln-1] = S[i:i+ln-1].
     The canonical starting position of the string S[i:i+ln-1].
   */
  for (int ln = 1; ln <= S.size(); ln++) {
    for (int i = 0; i + ln <= S.size(); i++) {
      for (int& j = canon[i][ln]; j < i; j++) {
        /* If ln - 1 matches and the last character matches... */
        if (canon[j][ln - 1] == canon[i][ln - 1] &&
            S[j + ln - 1] == S[i + ln - 1]) {
          break;
        }
      }
    }
  }
  
  /* Pre-compute the state transitions; how to extend left and right for each
   * possible string. */
  for (int i = 0; i < S.size(); i += 2) {
    for (int ln = 3; i + ln <= S.size(); ln += 2) {
      if (i != canon[i][ln]) {
        continue;
      }
      lparents[canon[i + 2][ln - 2] / 2][ln / 2].push_back(i / 2);
      rparents[canon[i][ln - 2] / 2][ln / 2].push_back(i / 2);
    }
  }

  int result = 0;
  for (int ln = N; ln >= 1; ln--) {
    for (int i = 0; i + ln <= N + 1; i++) {
      if (canon[2 * i][2 * ln - 1] != 2 * i) {
        /* Non-canonical string, skip. */
        continue;
      }

      int dist_across = psum[i + ln - 1] - psum[i];
      for (int strt = 0; strt < ln; strt++) {
        for (int side = 0; side < 2; side++) {
          if (i == 0 || i + ln == N + 1) {
            /* We're at the exit. */
            dp[i][ln][strt][side] = -opt[i + strt];
            continue;
          }

          /* Compute the worst case cost for left and right. */
          int lft_cst = -INF;
          for (int j : lparents[i][ln]) {
            lft_cst = max(lft_cst, S[2 * j + 1] + dp[j][ln + 1][strt + 1][0]);
          }

          int rht_cst = -INF;
          for (int j : rparents[i][ln]) {
            rht_cst = max(rht_cst,
                          S[2 * (j + ln) - 1] + dp[j][ln + 1][strt][1]);
          }

          /* Add in the cost for crossing the string if we choose to extend the
           * far side of the string. */
          (side ? lft_cst : rht_cst) += dist_across;

          /* Result is just the min of these two choices. */
          dp[i][ln][strt][side] = min(lft_cst, rht_cst);

          /* Update the result if this is a 1 length string. */
          if (ln == 1) {
            result = max(result, dp[i][ln][strt][side]);
          }
        }
      }
    }
  }
  cout << result << endl;
  
  return 0;
}

