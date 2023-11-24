#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define forn(i,j) for(int i = 0; i < j; i++)

using namespace std;

void setIO(string name = "") {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
    setIO("cowdance");
    int n, t;
    cin >> n >> t;
    int ar[n];

    forn(i,n){ cin >> ar[i];}

    int lo = 1, hi = n;
    int sol = n;

    while(lo <= hi){
        int mid = lo + (hi - lo)/2; 
        int size = 0, time = 0, j = 0;
        priority_queue<int> pq;

        while(size < mid && j < n){
            pq.push(-ar[j]);
            j++;
            size++;
        }

        while((int)pq.size()){
            time += max(0,-pq.top()-time);
            pq.pop();
            if(j < n){
                pq.push(-(ar[j]+time));
                j++;
            }
        }

        if(time > t){
            lo = mid + 1;
        } else {
            sol = min(mid, sol);
            hi = mid - 1;
        }
    }

    cout << sol << '\n';
}