#include<bits/stdc++.h>
#include <map>
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

const int LOG = 18;
const int N = 100'000;
int a[N];
int m[N][LOG];

//make rmq for gcd

int find_gcd(int l, int r){
    int len = r - l + 1;
    int x = 0;

    for(int i = 1; (1<<i) <= len; ++i){
        x = i;
    }

    int y = gcd(m[l][x], m[r - (1<<x)+1][x]);

    return y;
}

int main(){
    int n;
    cin >> n;

    forn(i,n){ cin >> a[i];}

    forn(i,n){
        m[i][0] = a[i];
    }

    int log = 0;

    for(int i = 1; (1<<i) <= n; ++i){
        log++;
    }

    for(int j = 1; j < log+1; ++j){
        for(int i = 0; i + (1<<j) - 1 < n; ++i){
            m[i][j] = gcd(m[i][j-1], m[i + (1<<(j-1)) - 1][j-1]);
        }
    }


    map<int, int> ma;
    map<int, ll> frequency;

    forn(i,n){
        int w = n - i + 1;   //tracker whether we passed n or not
        int c = a[i];        //intial gcd when we fix the left endpoint
        ll lo = i;           //starting point
        int y = a[i];


        while(w > 0){
            int x = lo;  //to keep track of the point we started from
            ll hi = n-1;

            while(lo <= hi){  //wannabe binary search
                ll mid = (lo + hi+1)/2;   //calculation boy

                y = find_gcd(i,mid); //this is right, ive tested it a million times before using it....

                if(lo == hi){
                    break;
                }

                if(y == c){     //if the gcd is still is equal to to the past gcd, then go to mid + 1 and search from there
                    lo = mid+1;
                }
//either the binary search is wrong, bc im storing the values in a right way, or the find_gcd function is fucked
                else{          //the gcd isn't same, so the point is in between lo and mid
                    hi = mid;
                }
            }

            if(hi == n-1){        //gcd didnt change :(
                ll s = hi - x + 1;                //removal
                frequency[c] += s;                //incrementing the frequency of c in s
                break;
            }

            else{                                 //it did change :)
                ll s = hi - x;                    //the number of things that are equal to the previous gcd
                w -= s;                           //removal
                frequency[c] += s;                //incrementing the frequency of c by s
                c = find_gcd(i, hi);         //new gcd to start search from 
            }
        }
    } //the only problematic part, rest is sorted for

    forn(i,n){
        int l = gcd(i,n-1);
        int k = gcd(i, n-2);
        frequency[l]--;
        frequency[k]++;
    }

    int q;

    cin >> q;

    while(q--)
    {
        int x;
        cin >> x;

        cout << frequency[x] << endl;
    }
}

/*
3
2 6 3
what should come out for the following queries vs the reality

      intended         real output
1 :       1                 0
2 :       2                 3
3 :       2                 1
4 :       0                 0
6 :       1                 2
*/