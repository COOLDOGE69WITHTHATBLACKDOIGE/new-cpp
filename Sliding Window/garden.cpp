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

vvi pref;

int rect(int x1, int y1, int x2, int y2){
	//take note that x1,y1 should be the top right thing, and x2,y2 the bottom left
	return (pref[x1][y1] - pref[x1][y2] - pref[x2][y1] + pref[x2][y2]);
}

signed main(){
	setIO("input");
	int n,m,q,t;
	cin >> n >> m >> q >> t;

	vvi grid(n,vi(m,0));

	forn(i,q){
		int x,y;
		cin >> x >> y;

		x--,y--;
		grid[y][x]++;
	}

	pref.assign(n+1,vi(m+1,0));

	forrange(row,1,n+1){
		forrange(column,1,m+1){
			pref[row][column] = pref[row][column-1] + pref[row-1][column] - pref[row-1][column-1] + grid[row-1][column-1];
		}
	}


	int ptr_left = MOD;
	int ptr_right = MOD;

	forrange(base_column,1,m+1){
		forrange(k,1,base_column+1){
			int ptr = 1;
			int mn_width = MOD;

			forrange(row,1,n){
				while(ptr < n && rect(ptr,base_column,row,base_column - k) < t){
					ptr++;
				}

				if(rect(ptr,base_column,row,base_column - k) == t){
					mn_width = min(mn_width,ptr-row+1);
				}
			}

			ptr_left = min(ptr_left,2*(mn_width + base_column - k + 1));
		}

		forrange(k,1,m + 1 - base_column){
			int ptr = 1;
			int mn_width = MOD;

			forrange(row,1,n+1){
				while(ptr < n && rect(ptr,base_column+k,row,base_column) < t){
					ptr++;
				}

				if(rect(ptr,base_column+k,row,base_column) == t){
					mn_width = min(mn_width,ptr-row+1);
				}
			}

			ptr_right = min(ptr_right,2*(mn_width + k));
		}
	}

	int res = ptr_right + ptr_left;
	int ptr_down = MOD;
	int ptr_up = MOD;

	forrange(base_row,1,n+1){
		forrange(k,1,base_row+1){
			int ptr = 1;
			int mn_height = MOD;

			forrange(column,1,m+1){
				while(ptr < m && rect(base_row,ptr,base_row-k,column) < t){
					ptr++;
				}

				if(rect(base_row,ptr,base_row-k,column) == t){
					mn_height = min(mn_height,ptr-column+1);
				}
			}

			ptr_down = min(ptr_down,2*(mn_height + k));
		}

		forrange(k,1,n+1-base_row){
			int ptr = 1;
			int mn_height = MOD;

			forrange(column,1,m+1){
				while(ptr < m && rect(base_row+k,ptr,base_row,column) < t){
					ptr++;
				}

				if(rect(base_row+k,ptr,base_row,column) == t){
					mn_height = min(mn_height,ptr-column+1);
				}
			}

			ptr_up = min(ptr_up,2*(mn_height + k));
		}	
	}

	res = min(ptr_up + ptr_down, res);

	cout << res << endl;
}