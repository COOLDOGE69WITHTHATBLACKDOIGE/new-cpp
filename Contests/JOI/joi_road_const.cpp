#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 2e5 + 5;
const ll M = 4*N;
ll a[N];

struct road{
    int mn;
    int mx;
};

struct segtree{
    road seg[M];

    void build(int l, int r, int pos){
        if(l == r){
            seg[pos].mn = a[l];
            seg[pos].mx = a[l];
            return;
        }

        int mid = (l + r)/2;
        build(l, mid, 2*pos);
        build(mid+1, r, (2*pos) + 1);

        seg[pos].mx = max(seg[2*pos].mx, seg[2*(pos) + 1].mx);
        seg[pos].mn = min(seg[2*pos].mn, seg[2*(pos) + 1].mn);
    }

    void update(int l, int r, int pos, int index, int value){
        if(l == r){
            seg[pos].mx = value;
            seg[pos].mn = value;
            return;
        }

        int mid = (l+r)/2;
        if(index <= mid){
            update(l, mid, 2*pos, index, value);
        }

        else{
            update(mid+1, r, 2*(pos)+1, index, value);
        }

        seg[pos].mx = max(seg[2*pos],seg[2*(pos)+1]);
        seg[pos].mn = min(seg[2*pos], seg[2*(pos)+1]);
    }

    ll add(int l, int r, int pos, int ql, int qr, int ub, int lb){
        if(ql > r || qr < l){
            return 0;
        }

        if(ql <= l && qr >=r){
            if((segtree[pos].mx < lb) || (segtree[pos].mn > ub)){
                return 0;
            }

            if((segtree[pos].mx <= ub) && (segtree[pos].mn >= lb)){
                return (r - l + 1);
            }

            else{
                int mid = (l+r)/2;

                return add(l,mid,2*pos,ql,qr,ub,lb) + add(mid+1,r,(2*pos) + 1,ql,qr,ub,lb);
            }
        }

        int mid = (l+r)/2;
        return add(l,mid,2*pos,ql,qr,ub,lb) + add(mid+1,r,2*(pos)+1,ql,qr,ub,lb);
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
}