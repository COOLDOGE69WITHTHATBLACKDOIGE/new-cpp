#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 2e5 + 5;
const ll M = 4*N;
ll a[N];

struct segtree{
    ll seg[M];

    void build(int l, int r, int pos){
        if(l == r){
            seg[pos] = a[l];
            return;
        }

        int mid = (l + r)/2;
        build(l, mid, 2*pos);
        build(mid+1, r, (2*pos) + 1);

        seg[pos] = seg[2*pos] + seg[2*(pos) + 1];
    }

    void update(int l, int r, int pos, int index, int value){
        if(l == r){
            seg[pos] = value;
            return;
        }

        int mid = (l+r)/2;
        if(index <= mid){
            update(l, mid, 2*pos, index, value);
        }

        else{
            update(mid+1, r, 2*(pos)+1, index, value);
        }

        seg[pos] = seg[2*pos] + seg[2*(pos)+1];
    }

    ll add(int l, int r, int pos, int ql, int qr){
        if(ql > r || qr < l){
            return 0;
        }

        if(ql <= l && qr >=r){
            return seg[pos];
        }

        int mid = (l+r)/2;
        return add(l,mid,2*pos,ql,qr) + add(mid+1,r,2*(pos)+1,ql,qr);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;

    segtree S;

    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    S.build(0,n-1,1);

    while(q--){
        int d,e,f;
        cin >> d >> e >> f;

        if(d == 1){
            e--;
            S.update(0,n-1,1,e,f);
        }

        if(d==2){
            e--;
            f--;
            ll k = S.add(0,n-1,1,e,f);
            cout << k << endl;
        }
    }
}