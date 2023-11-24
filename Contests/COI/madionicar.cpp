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

bool check(int l,int r){
    cout << "? " << l << ' ' << r << endl;
    int a;cin>>a;
    return a==1;
}

int main(){
	int n;
	cin >> n;

	int mtx = 0;

	forrange(i,1,n+1){
		if(i + mtx + 1 < n + 1 && i - mtx - 1 > 0){
			if(check(i - mtx - 1,i + mtx + 1)){
				mtx++;
			}
		}
	}

	if(mtx == 0){
		cout << "!" << 1 << endl;
	}

	else{
		cout << "!" << mtx << endl;
	}
}