#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

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
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define eb emplace_back
#define debug(x) cerr << #x << " is " << x << endl;

#define MOD 1000000007

const int N = 1e3;
int n,m;
string grid[N];
char backtrack[N][N];
bool visited[N][N];
int dist[N][N];
int t = 0;

void floodfill(int r, int c){
    stack<pii> s;
    visited[r][c] = true;
    s.push({r+1,c});
    s.push({r,c-1});
    s.push({r-1,c});
    s.push({r,c+1});
    pii initial = {r,c};

    dist[r][c] = 0;

    while(!s.empty()){
        int k = s.top().f;
        int l = s.top().s;
        s.pop();

        if((k < 0 || k >= n || l < 0 || l >= m) || grid[k][l] == '#' || visited[k][l])
            continue;
        
        if(initial.f != k){
        	if(initial.f - k == 1){
        		backtrack[k][l] = 'U';
        	}

        	else{
        		backtrack[k][l] = 'D';
        	}
        }

        else{
        	if(initial.s - l == 1){
        		backtrack[k][l] = 'L';
        	}

        	else{
        		backtrack[k][l] = 'R';
        	}
        }
        visited[k][l] = true;
        dist[k][l] = dist[initial.f][initial.s] + 1;
        initial = {k,l};
        
        s.push({k+1,l});
        s.push({k-1,l});
        s.push({k,l-1});
        s.push({k,l+1});
    }
}

int main(){
	cin >> n >> m;
	pii start;
	pii end;

	forn(i,n){
		cin >> grid[i];
	}

	forn(i,n){
		forn(j,m){
			if(grid[i][j] == 'A'){
				start = {i,j};
			}

			if(grid[i][j] == 'B'){
				end = {i,j};
			}
		}
	}

	floodfill(start.f, start.s);

	if(!visited[end.f][end.s]){
		cout << "NO" << endl;
	}

	else{
		cout << "YES" << endl;
		cout << dist[end.f][end.s] << endl;
		vector<char> bb(dist[end.f][end.s] - 1);
		int k = end.f;
		int l = end.s;

		while(dist[end.f][end.s] > 1){

			cout << backtrack[k][l];

			if(backtrack[k][l] == 'L'){
				l++;
			}

			if(backtrack[k][l] == 'R'){
				l--;
			}

			if(backtrack[k][l] == 'U'){
				k++;
			}

			if(backtrack[k][l] == 'D'){
				k--;
			}

			dist[end.f][end.s]--;
		}

		forn(i,dist[end.f][end.s]-1){
			cout << bb[i];
		}
	}
}