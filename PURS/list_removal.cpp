#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
	int n;
	cin >> n;

	indexed_set<int> S;

	for(int i = 0; i < n; ++i){
		int a;
		std::cin >> a;

		S.insert(a);
	}

	while(n--){
		int g;
		cin >> g;
		int m = *S.find_by_order(g);
		cout << a << endl;
		S.erase(m);
	}
}