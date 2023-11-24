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

void query(int l, int r){
    int len = r - l + 1;
    int k = 0;

    for(int i = 1; (1<<i) < len; ++i){
        k++;
    }

    int d = min(m[l][k], m[r-(1<<k)+1][k]);

    cout << d << endl;
}

int main(){
    int n, q;
    cin >> n;

    int log[n+1];

    log[1] = 0;

    for(int i = 2; i < n+1; ++i){
        log[i] = log[i/2] + 1;
    }

    forn(i,n){
        cin >> a[i];
    }

    forn(i,n){
        m[i][0] = a[i];
    }


    for(int a = 1; a < LOG; ++a){
        for(int j = 0; j + (1<<a)- 1 < n; j++){
            m[j][a] = min(m[j][a-1], m[j + (1<<(a-1))][a-1]);
        }
    }

    cin >> q;

    while(q--){
        int l, r;
        cin >> l >> r;

        query(l,r);
    }
}