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
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define pb push_back
#define p push
#define f first
#define all(x) x.begin(), x.end()
#define eb emplace_back
#define debug(x) cerr << #x << " " << x << endl;

#define MOD 1000000007

template <class T>
struct FT{
	vll vec;

	FT(int n): vec(n){}

	int itr(int ind){
		return (ind & -ind);
	}

	void add(int ind, int val){
		while(ind < vec.size()){
			vec[ind] += val;
			ind += itr(ind);
		}
	}

	T sum(int ind){
		int res = 0;

		while(ind > 0){
			res += vec[ind];
			ind -= itr(ind);
		}

		return res;
	}
};

vvi graph;
vll tin;
vll tout;
ll timer = 0;

void dfs(int node, int parent){
	timer++;
	tin[node] = timer;

	for(int x : graph[node]){
		if(x != parent){
			dfs(x,node);
		}
	}

	tout[node] = timer;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,q;
	cin >> n >> q;

	graph.resize(n+1);
	tin.resize(n+1);
	tout.resize(n+1);

	vll v(n+1);

	forn(i,n){
		cin >> v[i+1];
	}

	forn(i,n-1){
		ll a,b;
		cin >> a >> b;

		graph[a].pb(b);
		graph[b].pb(a);
	}

	FT<ll> ft(n+1);
	dfs(1,0);

	forn(i,n){
		if(tout[i+1] + 1 >= n+1){
			ft.add(tin[i+1],v[i+1]);
		}

		else{
			ft.add(tin[i+1],v[i+1]);
			ft.add(tout[i+1]+1, -v[i+1]);
		}
	}

	while(q--){
		ll type, index;
		cin >> type >> index;

		if(type == 1){
			ll val;
			cin >> val;

			if(tout[index]+1 >= n+1){
				ft.add(tin[index],val - v[index]);
			}

			else{
				ft.add(tin[index], val - v[index]);
				ft.add(tout[index] + 1, - (val - v[index]));
			}

			v[index] = val;
		}

		if(type == 2){
			cout << ft.sum(tin[index]) << endl;
		}
	}
}