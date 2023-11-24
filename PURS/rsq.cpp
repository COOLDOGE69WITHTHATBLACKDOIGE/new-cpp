#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define forn(i,j) for(ll i = 0; i < j; i++)
#define forrange(i,j,k) for(int i = j; i < k; ++i)
#define rof(i,j,k) rof(int i = j; i > k; ++i)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define eb emplace_back

#define MOD 1000000007

const ll N = 2e5;
const ll M = 4*N;

ll diff[N];
ll seg[M];

struct segtree{
    ll seg[M];

	void build(int l, int r, int pos){
	if(l == r){
		seg[pos] = diff[l];
		return;
	}

	int mid = (l + r)/2;
	build(l, mid, 2*pos);
	build(mid+1, r, (2*pos)+1);
	seg[pos] = seg[2*pos] + seg[(2*pos)+1];
	}

	void update(int l, int r, int pos, int ind, int value){
	if(l == r){
		seg[pos] += value;
		return;
	}

	int mid = (l+r)/2;
	if(ind <= mid){
		update(l, mid, 2*pos, ind, value);
	}

	else{
		update(mid+1, r, 2*(pos)+1, ind, value);
	}

	seg[pos] = seg[2*pos] + seg[2*(pos)+1];
	}

	ll sum(int l, int r, int pos, int ql, int qr){
	if(l > qr || r < ql){
		return 0;
	}

	if(ql <= l && r <= qr){
		return seg[pos];
	}

	int mid = (l+r)/2;
	return sum(l, mid, 2*pos, ql, qr) + sum(mid+1, r, 2*(pos)+1, ql, qr);
	}
    
};



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, q;
	cin >> n >> q;

	ll a[n];

	forn(i,n){
		cin >> a[i];
	}

	diff[0] = a[0];

	for(int i = 1; i < n; ++i){
		diff[i] = a[i] - a[i-1];
	}

	segtree S;

	S.build(0, n-1, 1);

	while(q--){
		int type;
		cin >> type;

		if(type == 1){
			int l, r, value;
			cin >> l >> r >> value;
			int u = -value;

			if(r == n){
				S.update(0,n-1,1,l-1,value);
			}

			else{
				S.update(0,n-1,1,l-1,value);
				S.update(0,n-1,1,r,u);
			}
		}

		if(type == 2){
			int ind;
			cin >> ind;
			ind--;

			cout << S.sum(0,n-1,1,0,ind) << endl;
		}
	}
}