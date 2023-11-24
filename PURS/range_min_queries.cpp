#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 2e5 + 5;
ll a[N];
ll segtree[4 * N];

void build(int l,int r, int pos){
    if(l == r){
        segtree[pos] = a[l];
        return;
    }

    int mid = (l + r)/2;
    build(l, mid, 2*pos);
    build(mid+1, r, (2*pos) + 1);
    segtree[pos] = min(segtree[(2*pos) + 1], segtree[2*pos]);
}

ll mint(int l, int r, int pos, int ql, int qr){
    if(ql > r || qr < l){
        return 1e9;
    }

    if(ql <= l && qr >= r){
        return segtree[pos];
    }

    int mid = (l + r)/2;
    return min(mint(l, mid, 2*pos, ql, qr), mint(mid+1, r, (pos*2) + 1, ql, qr));
}

void update(int l, int r, int pos, int index, int value){
    if(l == r){
        segtree[pos] = value;
        return;
    }

    int mid = (l + r)/2;
    if(index <= mid){
        update(l, mid, pos*2, index, value);
    }

    else{
        update(mid+1, r, (pos*2) + 1, index, value);
    }

    segtree[pos] = min(segtree[pos*2], segtree[(pos * 2)+1]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;

    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    build(0,n-1,1);

    while(q--){
        int d,e,f;
        cin >> d >> e >> f;

        if(d == 1){
            e--;
            update(0,n-1,1,e,f);
        }

        if(d==2){
            e--;
            f--;
            ll k = mint(0,n-1,1,e,f);
            cout << k << endl;
        }
    }
}