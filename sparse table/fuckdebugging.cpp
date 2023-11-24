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

const int LOG = 17;
const int N = 100'000;
int a[N];
pii chutiya[N][LOG];

pii compare(pii a, pii b){
    if(a.f > b.f){
        return a;
    }

    else{
        return b;
    }
}

pii madarchod(int l, int r){
    int len = r - l + 1;
    int x = 0;
    for(int i = 1; (1<<i) <= len; ++i){
        x++;
    }

    pii y = compare(chutiya[l][x], chutiya[r - (1<<x) + 1][x]);

    return y;
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n-1; ++i){
        cin >> a[i];
        a[i]--;
    }

    a[n-1] = 0;

    for(int i = 0; i< n-1; ++i){
        pii b = make_pair(a[i],i);
        chutiya[i][0] = b;
    }

    for(int j = 1; j < LOG; ++j){
        for(int i = 0; i + (1<<j) - 1 <= n-1; ++i){
            chutiya[i][j] = compare(chutiya[i][j-1], chutiya[i+(1<<(j-1))][j-1]);
        }
    }

    int q;
    cin >> q;

    while(q--){
        int i;
        cin >> i;

        cout << madarchod(i+1, a[i]).f << endl;
    }
}