#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
#define _GLIBCXX_DEBUG 1
#define _GLIBCXX_DEBUG_PEDANTIC 1
#pragma GCC optimize("trapv")

#define dbg(TXTMSG) cerr << "\n" << TXTMSG
#define dbgv(VARN) cerr << "\n" << #VARN << " = "<< VARN << ", line: " << __LINE__ << "\n"

#define ll long long
#define ld long double
#define forn(i,j) for(ll i = 0; i < j; i++)
#define forrange(i,j,k) for(int i = j; i < k; ++i)
#define rof(i,j) rof(int i = j; i >= 0; --i)
#define pii pair<int,int>
#define vll vector<ll>
#define vi vector<int>
#define vvll vector<vll>
#define vvi vector<vi>
#define vb vector<bool>
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define eb emplace_back
#define qi queue<int>
#define qpii queue<pii>

#define MOD 1000000007

void setIO(string name = ""){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	if(!name.empty()){
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".in").c_str(), "w", stdout);
	}
}

int main(){
	int n, m;
	cin >> n >> m;

	int arr[4] = {1,0,-1,0};
	int rra[4] = {0,1,0,-1};

	char dir[4] = {'D','R','U','L'};

	string grid[n];
	qpii q;
	bool visited[n][m];
	string label[n][m];
	string backtrack[n][m];

	forn(i,n){
		cin >> grid[i];
	}

	forn(i,n){
		forn(j,m){
			if(grid[i][j] == 'M' || grid[i][j] == 'A'){
				q.push({i,j});
				label[i][j] = grid[i][j];

				backtrack[i][j] = label[i][j];
			}
		}
	}

	while(!q.empty()){
		pii h = q.front();
		q.pop();
		if(visited[h.f][h.s]){
			continue;
		}

		visited[h.f][h.s] = true;
		forn(i,4){
			if((h.f + arr[i] < 0 || h.f + arr[i] >= n || h.s + rra[i] < 0 || h.s + rra[i] >= m) || visited[h.f + arr[i]][h.s + rra[i]]){
				continue;
			}

			else{
				if(!visited[h.f + arr[i]][h.s + rra[i]] && grid[h.f + arr[i]][h.s + rra[i]] == '.'){

					label[h.f + arr[i]][h.s + rra[i]] = label[h.f][h.s];
					backtrack[h.f + arr[i]][h.s + rra[i]] = dir[i];
				}
			}
		}
	}

	forn(i,n){
		forn(j,m){
			if(grid[i][j] = '#' || !visited[i][j]){
				dbgv(grid[i][j]);
			}

			else{
				dbgv(label[i][j]);
			}
		}
	}
}