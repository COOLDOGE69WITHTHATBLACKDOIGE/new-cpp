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
#define str string

#define MOD 1000000007

void siout(string name = "") { 

	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

const int N = 1000;
string building[N];
bool visited[N][N];
int row;
int column;

void floodfill(int r, int c){
    stack<pii> s;
    s.push({r,c});

    while(!s.empty()){
        int r = s.top().f;
        int c = s.top().s;
        s.pop();

        if((r < 0 || r >= row || c < 0 || c >= column) || building[r][c] == '#' || visited[r][c])
            continue;
        
        visited[r][c] = true;
        
        s.push({r+1,c});
        s.push({r-1,c});
        s.push({r,c-1});
        s.push({r,c+1});
    }
}

int main(){
    siout();
    cin >> row >> column;

    for (int i = 0; i < row; i++) { cin >> building[i];}

    int rooms = 0;

    for (int i = 0; i < row; i++){
		for (int j = 0; j < column; j++){
			if (!visited[i][j]){
				floodfill(i, j);

                if(visited[i][j]){ rooms++;}
			}
		}
	}
    cout << rooms << endl;
}