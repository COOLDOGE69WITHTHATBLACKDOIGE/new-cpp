#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define pll pair<ll,ll>

indexed_set<pll> orz;

int main(){
	int n,q;
	cin >> n >> q;

	ll a[n];

	for(ll i = 0; i < n; ++i){
		cin >> a[i];
		orz.insert({a[i],i});
	}

	while(q--){
		char b;
		cin >> b;

		if(b == '!'){
			ll k, x;
			cin >> k >> x;
			k--;
			orz.erase({a[k],k});
			a[k] = x;
			orz.insert({a[k],k});
		}

		if(b == '?'){
			ll d,f;
			cin >> d >> f;

			cout << orz.order_of_key({f, 100000}) - orz.order_of_key({d-1,100000}) << endl; 
		}
	}
}