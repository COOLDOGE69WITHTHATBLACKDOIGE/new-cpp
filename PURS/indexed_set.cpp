#include<bits/stdc++.h>
using namespace std;


#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


int main(){
	int q;
	cin >> q;
	while(q--){
		indexed_set<int> s;

		int n;
		cin >> n;
		
		int inversions = 0;

		for(int i = 0; i < n; ++i){
			int j;
			cin >> j;
			inversions += i - s.order_of_key(j);
			s.insert(j);
			
		}

		cout << inversions << endl;
	}
}