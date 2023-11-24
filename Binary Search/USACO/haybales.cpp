#include<bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define forn(i,j) for(int i = 0; i < j; i++)

using namespace std;

void setIO(string name = "") {  // name is nonempty for USACO file I/O

	ios_base::sync_with_stdio(0);
	cin.tie(0);  // see Fast Input & Output
	// alternatively, cin.tie(0)->sync_with_stdio(0);
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);  // see Input & Output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main(){
    setIO("haybales");
    int B, Q;
    cin >> B >> Q;

    vector<int> bale_loc(B);
    forn(i,B){ cin >> bale_loc[i];}

    sort(all(bale_loc));

    forn(i, Q){
        int query_start = 0;
        int query_end = 0;
        cin >> query_start >> query_end;

        cout << upper_bound(all(bale_loc), query_end) - lower_bound(all(bale_loc), query_start) << '\n';
    }
}