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
#define eb emplace_back
#define SUM 10000

#define MOD 1000000007

int dp[SUM][71];

void setIO(string name = "") { 

	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

vi backtrack(10000);

vector<int> primes = {

    2,   3,   5,   7,   11,  13,  17,  19,  23,  29,  31,  37,  41,  43,

    47,  53,  59,  61,  67,  71,  73,  79,  83,  89,  97,  101, 103, 107,

    109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181,

    191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263,

    269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349};

int order = 0;

void getorder(int g){
	order = 0;
	//transition dp

	for(int i = 0; i < g+1; ++i){  //i = 0, i < 6
		for(int j = 1; j < 71; ++j){
			if(i == 0){
				dp[i][j] = 0;
			}

			int curr = primes[j-1];
			int power = 1;
			int value = log(curr);

			while(i - curr >= 0){
				if(dp[i][j] < dp[i-curr][j-1] + value){
					dp[i][j] = dp[i-curr][j-1] + value;
					backtrack[i] = curr;
				}

				curr *= primes[j-1];
				power++;
			}
		}
	}

	order = dp[g][70];
}

vi cycles(71, 1000000);

void solve(int g){

	getorder(g);

	int curr = g;
	int size = 0;

	while(curr > 0){
		int h = backtrack[curr];
		curr -= h;
		cycles[size] = h;
		size++;
	}

	sort(cycles.begin(), cycles.end());

	int j = 0;
	int cur = 1;

	while(j < size){
		int m = cur;
		cur += cycles[j];
		for(int i = m; i < cur+1; ++i){
			if(i = cur){
				cout << cur - cycles[j] << ' ';
			}

			cout << i + 1 << ' ';
		}
	}

	cout << endl;
}

int main(){
	setIO("maximal");
	int d;
	cin >> d;
	int query[d];

	for(int i = 0; i < d; ++i){
		cin >> query[i];
	}

	for(int i = 0; i < d; ++i){
		int a = query[i];
		solve(a);
		memset(dp, 0, sizeof(dp));
		fill(backtrack.begin(), backtrack.end(), 0);
	}
}