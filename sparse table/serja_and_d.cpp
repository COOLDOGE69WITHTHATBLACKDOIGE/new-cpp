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

const int N = 100'000;
const int LOG = 17;
int a[N];
int k[N][LOG];

int rmq(int l, int r){
    int x = 0;
    int len = r - l + 1;

    for(int i = 1; (1<<i) < len+1; ++i){
        x++;
    }

    int f = max(k[r][x], k[r - (1<<x) + 1][x]);

    return x;
}

int query(int r, int d){
    int lo = 0;
    int hi = r-1;

    while(lo < hi){
    int mid = lo + (hi-lo)/2;
    int j = rmq(mid,r);

    if(j <= d){
        hi = mid;
    }

    else{
        lo = mid+1;
    }
    }

    return lo+1;
}

int main(){
    int n,m;
    cin >> n;

    forn(i,n){ cin >> a[i];}
    cin >> m;

    for(int i = 0; i < n-1; ++i){ 
        k[i][1] = a[i+1] - a[i];
    }

    for(int i = 0; i < n; ++i){
        for(int j = 2; i - (1<<j) > 0; ++j){
            k[i][j] = max(k[i][j-1], k[i - (1<<(j-1))+1][j-1]);
        }
    }

    while(m--){
        int t,d;
        cin >> t >> d;
        int k = upper_bound(a, a+n, t)- a - 1;
        
        int g = query(k,d);
        cout << g << endl;
    }
}