#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define forn(i,j) for(ll i = 0; i < j; i++)
#define forrange(i,j,k) for(int i = j; i < k; ++i)
#define rof(i,j,k) rof(int i = j; i > k; ++i)
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define eb emplace_back

#define MOD 1000000007

const int N = 2e5;
const int M = 4*N;
ll a[N];

struct segtree{
	ll seg[M];

	void build(int l, int r, int pos){
		if(l == r){
			seg[pos] = a[l];
			return;
		}

		int mid = (l+r)/2;
		build(l, mid, 2*pos);
		build(mid+1, r, (2*pos)+1);
		seg[pos] = seg[2*pos] + seg[(2*pos)+1];
	}

	void update(int l, int r, int pos, int ind, int value){
		if(l == r){
			seg[pos] = value;
			return;
		}

		int mid = (l+r)/2;
		if(ind <= mid){
			update(l,mid,2*pos,ind,value);
		}

		else{
			update(mid+1,r,(2*pos)+1,ind,value);
		}

		seg[pos] = seg[2*pos] + seg[(2*pos)+1];
	}

	ll sum(int l, int r, int pos, int ql, int qr){
		if(ql > r || qr < l){
			return 0;
		}

		if(ql <= l && qr >= r){
			return seg[pos];
		}

		int mid = (l+r)/2;

		return sum(l,mid,2*pos,ql,qr) + sum(mid+1,r,(2*pos)+1,ql,qr);
	}
};

vvi adj;
vi start;
vi end_time;
int timer = 0;

void eulertour(int u, int v){
	timer++;
	start[u] = timer;

	for(int x : adj[u]){
		if(x != v){
			eulertour(x,u);
		}
	}

	end_time[u] = timer;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,q;
	cin >> n >> q;

	start.resize(n);
	adj.resize(n);
	end_time.resize(n);

	vi value(n);

	forn(i,n){
		cin >> value[i];
	}


	forn(i, n-1){
		int a,b;
		cin >> a >> b;
		a--;
		b--;

		adj[a].pb(b);
		adj[b].pb(a);
	}

	eulertour(0,-1);

	for(int i = 0; i < n; ++i){
		a[start[i]] = value[i];
	}

	segtree S;
	S.build(1,n,1);

	for(int i = 0; i < q; ++i){
		int type;
		cin >> type;

		if(type == 1){
			int g,h;
			cin >> g >> h;

			S.update(1,n,1,start[g-1],h);
		}

		if(type == 2){
			int f;
			cin >> f;
			f--;

			cout << S.sum(1,n,1,start[f],end_time[f]) << endl;
		}
	}
}