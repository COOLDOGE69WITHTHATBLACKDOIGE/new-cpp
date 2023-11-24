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

#define MOD 1000000007

void siout(string name = "") { 

	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

const int N = 200000;
unordered_set<int> adj[N];
set<int> unvisited;
int arr[N];
int connected_comp = 0;

void dfs(int x){
	auto it = unvisited.begin();
	arr[connected_comp]++;

	while(it != unvisited.end()){
		if(adj[x].count(*it)){
			it++;
		}

		else{
			int a = *it;
			unvisited.erase(it);
			dfs(a);
			it = unvisited.upper_bound(a); 
		}
	}
}

int main(){
	siout();
	ll n,m;
	cin >> n >> m;

	forn(i,m){
		ll a,b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].insert(b);
		adj[b].insert(a);
	}

	forn(i,n){ unvisited.insert(i);}

	forn(i,n){
		auto it = unvisited.find(i);

		if(it != unvisited.end()){
			unvisited.erase(it);
			dfs(i);
			connected_comp++;
		}
	}

	sort(arr, arr+connected_comp);
	cout << connected_comp << endl;

	forn(i, connected_comp){ cout << arr[i] << ' ';}
}

/*
1. Use unordered set to store values of things that don't have edge between them (it then takes O(1) time to read)
2. Use a set of unvisited nodes except of using a boolean array
3. Mantain an array of connected components*/