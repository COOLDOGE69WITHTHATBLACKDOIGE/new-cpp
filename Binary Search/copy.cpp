#include <bits/stdc++.h>
using namespace std;

#define int long long

int val = 1e18; // value of 2 * x for current connected component (not x, as I'm very wary about dealing with doubles :clown:)
const int emp = 1e18; // if val == emp, this means that for this connected component, a value for x 
// hasn't yet been finalized, and thus, if need be, we can still change the value x
bool bad = false;

pair<int, int> operator+(pair<int, int> a, pair<int, int> b) { 
	return make_pair(a.first + b.first, a.second + b.second);
}

int32_t main(){
	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> adj(n);
	vector<vector<int>> conncomps;
	vector<bool> vis(n);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c; 

		--a, --b;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}

	vector<pair<int, int>> coeffs(n, make_pair(-1e18, -1e18)); // coeffs[i].first * x + coeffs[i].second 

	function<void(int)> dfs = [&](int u) {
		conncomps.back().push_back(u); // push u into its connected component
        vis[u] = 1;
		for (auto& [v, w] : adj[u]) {
			if (vis[v]) {
			    pair<int, int> res = coeffs[u] + coeffs[v];
				if (res.first == 0 && res.second != w) { // "1 + x and 2 - x sum to 2", not possible
                    bad = true;
				} else if (res.first != 0 && val == emp) { // the value for this connected component hasn't yet been finalized, so give it a value according to this edge
					if (res.first == 2) { 
						val = w - res.second;
					} else {
						val = res.second - w;
					}
				} else if (res.first != 0 && val != emp) {
					if (res.first == 2) {
						if (val != w - res.second) { // contradicts existing info, not possible
                            bad = true;
							return;
						}
					} else if (res.first == -2) {
						if (val != res.second - w) { // contradicts existing info, not possible
							bad = true;
							return;
						}
					}
				}
			} else { // this vertex hasn't been visited yet
				coeffs[v] = make_pair(-coeffs[u].first, w - coeffs[u].second); 
				dfs(v);
			}
		}
	};

	vector<int> vals;

	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			conncomps.emplace_back();
			val = emp; // value of x isn't yet set
			coeffs[i] = {1, 0}; // first vertex has value x
            dfs(i);
			vals.push_back(val);
		}
	}

	for (int i = 0; i < n; i++) {
		vis[i] = 0;
	}

    vector<double> ans(n);

	function<void(int)> out = [&](int u) {
		vis[u] = 1;
		for (auto& [v, w] : adj[u]) {
			if (!vis[v]) {
				ans[v] = (double)w - ans[u]; // according to this edge
				out(v);
			}
		}
	};

	if (bad) {
		cout << "NO" << '\n';
	} else {
		cout << "YES" << '\n';
		for (int i = 0; i < conncomps.size(); i++) {
			if (vals[i] == emp) { // x can be anything
				vector<int> compvals;
                for (int j = 0; j < conncomps[i].size(); j++) {
					if (coeffs[conncomps[i][j]].first == 1) {
                        compvals.push_back(-coeffs[conncomps[i][j]].second);
					} else {
                        compvals.push_back(coeffs[conncomps[i][j]].second);
					}
				}
				sort(compvals.begin(), compvals.end());
				ans[conncomps[i][0]] = (double)(compvals[(compvals.size() - 1) / 2] + compvals[compvals.size() / 2]) / (double)2; // x median is the optimal choice
				out(conncomps[i][0]);
			} else { // value of x is finalized
				ans[conncomps[i][0]] = (double)vals[i] / (double)2;
                out(conncomps[i][0]);
			}
		}
		for (int i = 0; i < n; i++) {
			cout << fixed << setprecision(6) << ans[i] << ' ';
		}
	}
}