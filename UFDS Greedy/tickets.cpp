#include <bits/stdc++.h>
using namespace std;
#define forn(i,n) for(int i=0;i<n;++i)    
#define all(x) x.begin(),x.end()
#define pb push_back
#define pi pair<int,int>
#define f first
#define s second
using ll = long long;
     
ll find_maximum(int k, vector<vector<int>>a) {    
    int n = a.size(), m = a[0].size();
    int sum = 0;
    vector<vector<int>> v(n);
    forn(i,n) forn(j,m) v[i].pb(a[i][j]);

    sort(all(v));

    forn(i,n){
        forn(j,k){
            sum -= v[i][j];
        }
    }

    priority_queue<int> q;
    int b;

    forn(i,n){
        forn(j,k){
            b = v[i][j] + v[i][m-k+j];
            q.push(b);
        }
    }

    int value;

    forn(i, k*n/2){
        value = q.top();
        q.pop();

        sum += value;
    }

    return sum;    
}

int main(){
    int j, h, k;
    cin >> j >> h >> k;

    vector<vector<int>> a(j, vector<int>(h));
    int value;

    forn(i,j){
        forn(v,h){
            cin >> a[i][v];
        }
    }

    ll result = find_maximum(k,a);
    cout << result << endl;
}
