#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define forn(i,j) for(int i = 0; i < j; i++)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<int<int>>
#define pb push_back
#define p push
#define f first
#define s second

#define MOD 1000007000

void siout(string name = "") { 

	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int last_true(int lo, int hi, function<bool(int)> f) {
	while (lo < hi) {
		
		int mid = lo + (hi - lo) / 2;
		if (f(mid)) {
			hi = mid-1;
		} else {
			lo = mid + 1;
		}
	}
	return lo;
}

int main(){
    /*siout("angry");*/
    int n, k;
    cin >> n >> k;

    int arr[n];
	forn(i,n) { cin >> arr[i];}
	
	cout << last_true(1, n, [&](int x) {
		ll cow = 0;
		ll a = 0;
		for (int i = 0; i < n; i++) {
			if(arr[i] - 2*(x) > arr[a]){
				cow++;
				a = i;
			} 
			
			else{
				continue;
			}
		}
		return cow <= k;
	}) << endl;
}