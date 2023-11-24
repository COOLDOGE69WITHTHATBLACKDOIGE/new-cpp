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
#define vb vector<bool>
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define eb emplace_back
#define debug(x) cerr << #x << " is " << x << endl;

#define MOD 1000000007

vvi graph;
vvi gra;
vb visited;
queue good;
vi outdegree;
vi indegree;
queue<int> selected;

void bfs(int u){
	queue<int> q;

	for(int x : graph[u])
}

void modifiedbfs(int u){
	selected.push(u);
	for(int x : gra[u]){
		if(!deleted[x]){

			deleted[x] = true;

			for(int y : gra[x]){
				if(!deleted[y]){
					outdegree[y]--;

					if(outdegree[y] == 0){
						good.push(y);
					}
				}
			}
		}
	}
}

int main(){
	int n, m;
	cin >> n >> m;

	graph.resize(n+1);
	gra.resize(n+1);
	visited.resize(n+1);

	forn(i,m){
		int a,b; 
		cin >> a >> b;

		graph[a].pb(b);
		gra[b].pb(a);
		outdegree[a]++;
		indegree[b]++;
	}

	forrange(i,1,n+1){
		if(outdegree[i] == 0){
			good.push(i);
		}
	}

	while(!good.empty()){
		int h = good.top();
		good.pop();

		modifiedbfs(h);
	}
}