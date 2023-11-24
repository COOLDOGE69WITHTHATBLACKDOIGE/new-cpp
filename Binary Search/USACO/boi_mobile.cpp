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

#define MOD 1000000007

void siout(string name = "") { 

	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
    siout();
    ll n, l;
    cin >> n >> l;
    pii coord[n];

    forn(i,n){ cin >> coord[i].f >> coord[i].s;}

    double hi = 1e9;
    double lo = 1;
    double ans;

    while(hi - lo > 1e-3){ 
        double mid = (hi + lo)/2;
        double m = 0;

        forn(i,n){
            double v = sqrt((mid*mid) - (coord[i].s*coord[i].s));       
            double a = coord[i].f - v;        
            double b = coord[i].f + v;
            
            if(a <= m){ m = max(m, b);}
        }

        if(m >= l){ hi = mid;} 
        else{ lo = mid;}
    }

    cout << fixed <<  setprecision(4) << lo << endl;
}