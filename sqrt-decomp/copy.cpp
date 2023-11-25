#include <bits/stdc++.h>
#define FOR(i, x, y) for (int i = x; i < y; i++)
using namespace std;

const int sqrt_n = 300;
int containers[100001];
int dp[100001 + sqrt_n][sqrt_n];

int main() {
	iostream::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	while (k--) {
		int a, l, d;
		cin >> a >> l >> d;
		if (d >= sqrt_n) FOR(i, 0, l) containers[a + i * d]++;
		else {
			dp[a][d]++;
			dp[a + (l * d)][d]--;
		}
	}

	FOR(j, 1, sqrt_n) FOR(i, j, n + 1) dp[i][j] += dp[i - j][j];

	FOR(i, 1, n + 1) {
		FOR(j, 1, sqrt_n) containers[i] += dp[i][j];
		cout << containers[i] << ' ';
	}
}