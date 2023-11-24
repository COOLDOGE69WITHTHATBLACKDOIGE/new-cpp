#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define forn(i,j) for(ll i = 0; i < j; i++)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin, x.end()
#define eb emplace_back

#define MOD 1000000007

void siout(string name = "") { 

	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

const int N = 200'005;
const int LOG = 18;
int a[N];
int m[N][LOG];
int z = 0;

void query(int l, int r){
    int d = a[l-1];
    int e = 0;
    for(int i = l; i < r-1; ++i){
        if(a[i] > d){
            e++;
        }   

        else{ continue;}
    }

    if(e > 0){
        z++;
    }
}

int main(){
    int n, q;
    cin >> n >> q;

    forn(i,n){
        cin >> a[i];
    }

    while(q--){
        int l, r;
        cin >> l >> r;

        query(l,r);
    }

    cout << z;
}