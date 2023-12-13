#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
// #define _GLIBCXX_DEBUG 1
// #define _GLIBCXX_DEBUG_PEDANTIC 1
// #pragma GCC optimize("trapv")

// #define dbg(TXTMSG) cerr << "\n" << TXTMSG
// #define dbgv(VARN) cerr << "\n" << #VARN << " = "<< VARN << ", line: " << __LINE__ << "\n"

#define ld long double
#define int long long
#define forn(i,j) for(int i = 0; i < j; i++)
#define forrange(i,j,k) for(int i = j; i < k; ++i)
#define rof(i,j) rof(int i = j; i >= 0; --i)
#define pii pair<int,int>
#define vi vector<int>
#define vpii vector<pii>
#define vvi vector<vi>
#define vvpii vector<vector<pii>>
#define vb vector<bool>
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define eb emplace_back
#define qi queue<int>
#define qpii queue<pii>
#define pqpii priority_queue<pii>
#define pqi priority_queue<int>

#define MOD 1000000007

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

signed main(){
	setIO("fortmoo");
	int n,m;
	cin >> n >> m;

	string s[n];

	forn(i,n){
		cin >> s[i];
	}

	vvi row_pref(n,vi(m+1,0));
	vvi column_pref(m,vi(n+1,0));

	forn(row,n){
		forrange(column,1,m+1){
			row_pref[row][column] = row_pref[row][column-1];

			if(s[row][column-1] == 'X'){
				row_pref[row][column]++;
			}
		}
	}

	forn(column,m){
		forrange(row,1,n+1){
			column_pref[column][row] = column_pref[column][row-1];

			if(s[row-1][column] == 'X'){
				column_pref[column][row]++;
			}
		}
	}

	int mx_area = 0;

	forrange(column1,1,m+1){
		forrange(column2,column1,m+1){
			vi valid_rows;
			int diff = column2 - column1 + 1;

			forn(row,n){
				if(row_pref[row][column2] - row_pref[row][column1 - 1] == 0){
					valid_rows.pb(row+1);
				}
			}

			int sze = valid_rows.size();
			int ptr = 0;
			int mx_height = 0;

			forn(i,sze){
				while(ptr < sze-1 && (column_pref[column2-1][valid_rows[ptr+1]] - column_pref[column2 - 1][valid_rows[i]-1]
				<= 0) && (column_pref[column1-1][valid_rows[ptr+1]] - column_pref[column1-1][valid_rows[i]-1] <= 0)){
					ptr++;
				}

				mx_height = max(mx_height,valid_rows[ptr]-valid_rows[i]+1);
			}

			mx_area = max(mx_area,diff*mx_height);
		}
	}

	cout << mx_area << endl;
}