#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define forn(i,j) for(ll i = 0; i < j; i++)
#define forrange(i,j,k) for(int i = j; i < k; ++i)
#define rof(i,j) rof(int i = j; i >= 0; --i)
#define pii pair<int,int>
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
#define debug(x) cerr << #x << " is " << x << endl;

#define MOD 1000000007

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int l,q;
	cin >> l >> q;

	while(q--){
		string s;
		ll h;
		cin >> s >> h;

		if(s == "alojzije"){
			ll v = (1 << 20);
			vll a;

			for(int i = 19; i >= 0; --i){
				if((1 << i) & h){
					v += (1 << i);
					a.pb(v);
				}
			}

			cout << a.size() << " ";

			for(int i = 0; i < a.size(); ++i){
				cout << a[i] << " ";
			}

			cout << endl;
		}

		if(s == "benjamin"){
			ll v = (1 << 20);
			vll b;

			for(int i = 19; i >= 0; --i){
				if((1 << i) & h ){
					v += (1 << i);
				}

				if(!((1 << i) & h)){
					ll m = (1 << i);
					b.pb(v+m);
				}
			}

			cout << b.size() << " ";

			forn(i,b.size()){
				cout << b[i] << " ";
			}

			cout << endl;
		}

		if(s == "cecilija"){
			int t = 0;
			
			while(h--){
				int a;
				cin >> a;

				if(a > 1){
					t++;
				}
			}

			if(t == 0){
				cout << "B" << endl;
			}

			else{
				cout << "A" << endl;
			}
		}
	}
}