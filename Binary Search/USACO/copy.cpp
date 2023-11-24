#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200000;
unordered_set<int> adj[MAX_N];
set<int> unvis;  // the set of nodes that have not been visited
int sz[MAX_N];   // sz[i] = size of the ith connected component
int cur = 0;     // current amount of groups

void dfs(int x) {
	sz[cur]++;
	auto it = unvis.begin();
	while (it != unvis.end()) {
		// if there is no edge between x and *it, skip
		if (adj[x].count(*it)) {
			it++;
		} else {
			// there is a edge between last and x
			int last = *it;
			// note it = unvis.erase(it) doesn't work here because it could be
			// erased later
			unvis.erase(it);
			dfs(last);
			// find the node after last
			it = unvis.upper_bound(last);
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].insert(b);
		adj[b].insert(a);
	}
	for (int i = 0; i < n; i++) { unvis.insert(i); }
	for (int i = 0; i < n; i++) {
		auto it = unvis.find(i);
		if (it != unvis.end()) {
			unvis.erase(it);
			dfs(i);
			cur++;
		}
	}
	cout << cur << endl;
	sort(sz, sz + cur);
	for (int i = 0; i < cur; i++) { cout << sz[i] << ' '; }
	cout << endl;
}