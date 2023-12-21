#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
typedef vector<int> vi; typedef vector<vector<int>> vvi; typedef vector<bool> vb; typedef vector<vector<bool>> vvb; typedef pair<int, int> pii; typedef pair<int, pair<int, int>> pipii; typedef deque<int> di; typedef deque<deque<int>> ddi; typedef map<int, int> mii; typedef map<int, pair<int, int>> mipii; typedef map<pair<int, int>, int> mpiii;
const int mod = 1000000007; // 10^9 + 7
 
struct SegTree {
    int n;
    vi a, seg, lazy_cnt, lazy_add;
    
    SegTree(vi &a)
        : n{(int)a.size()}, a{a},
          seg(4*n), lazy_cnt(4*n, 0),
          lazy_add(4*n, 0) { build(0, n-1, 1); }
    
    int build(int l, int r, int pos){
        if (l == r)
            return seg[pos] = a[l];
        int mid = (l+r)/2;
        return seg[pos] = build(l, mid, 2*pos)
                    + build(mid+1, r, 2*pos+1);
    }
    
    void update_lazy(int l, int r, int pos){
        int sz = r-l+1;
        seg[pos] += lazy_add[pos]*sz
                 + ((sz*(sz+1))/2)*lazy_cnt[pos];
        if (l < r){
            int mid = (l+r)/2;
            lazy_add[2*pos] += lazy_add[pos];
            lazy_add[2*pos+1] += lazy_add[pos]
                              + lazy_cnt[pos]*(mid-l+1);
            lazy_cnt[2*pos] += lazy_cnt[pos];
            lazy_cnt[2*pos+1] += lazy_cnt[pos];
        }
        lazy_add[pos] = lazy_cnt[pos] = 0;
    }
    
    void update(int ql, int qr, int l, int r, int pos){
        if (lazy_add[pos] != 0 || lazy_cnt[pos] != 0)
            update_lazy(l, r, pos);
        if (r < ql || qr < l)
            return;
        if (ql <= l && r <= qr){
            lazy_add[pos] += (l-ql);
            lazy_cnt[pos]++;
            update_lazy(l, r, pos);
            return;
        }
        int mid = (l+r)/2;
        update(ql, qr, l, mid, 2*pos);
        update(ql, qr, mid+1, r, 2*pos+1);
        seg[pos] = seg[2*pos] + seg[2*pos+1];
    }
    
    int query(int ql, int qr, int l, int r, int pos){
        if (lazy_add[pos] != 0 || lazy_cnt[pos] != 0)
            update_lazy(l, r, pos);
        if (r < ql || qr < l)
            return 0;
        if (ql <= l && r <= qr)
            return seg[pos];
        int mid = (l+r)/2;
        return query(ql, qr, l, mid, 2*pos)
             + query(ql, qr, mid+1, r, 2*pos+1);
    }
};
 
void solve(){
    int n, q; cin >> n >> q;
    vi a(n);
    for (int &x : a) cin >> x;
    SegTree tree(a);
    while (q--){
        int typ, l, r;
        cin >> typ >> l >> r;
        l--, r--;
        if (typ == 1)
            tree.update(l, r, 0, n-1, 1);
        else
            cout << tree.query(l, r, 0, n-1, 1) << endl;
    }
}
 
 
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1; //cin >> T;
    for (int i = 1; i <= T; i++){

        solve();
    }
    
    return 0;
}