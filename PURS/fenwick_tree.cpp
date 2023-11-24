#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define forn(i,j) for(ll i = 0; i < j; i++)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define eb emplace_back

#define MOD 1000000007

void setIO(string name = "") { 

	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

const ll N = 1e5;

int fen(int k){
	return (k & -k);
}

struct fenwick {
	int n;
	vector<int> arr;

	fenwick(int x) : arr(x){n = x;}

	void update(int k, int x){
		while(k < n){
			arr[k] += x;
			k += fen(k);
		}
	}

	int sum(int k){
		int psum = 0;
		while(k > 0){
			psum += arr[k];
			k -= fen(k);
		}

		return psum;
	}
};

int main(){
	setIO();
	int size, q;
	cin >> size >> q;

	fenwick F;
	F.n = size;

	int a[size];

	forn(i,size){
		cin >> a[i];

		F.update(i, a[i]);
	}

	while(q--){
		int type;
		cin >> type;

		if(type == 1){
			int f, g;
			cin >> f >> g;
			f--;
			int val = g - a[f];
			F.update(f, val);
		}

		if(type == 2){
			int f,g;
			cin >> f >> g;
			f--;
			g--;

			cout << F.sum(g) - F.sum(f-1) << endl;
		}
	} 
}
