    #include<bits/stdc++.h>
     
    using namespace std;
    const int N=1e6+5;
    typedef long long ll;
    typedef pair<ll,ll> pll;
    typedef array<ll,3> p3;
    int mod=998244353;
    const int maxv=4e6+5;
     
     
    struct node
    {
    	int l,r,maxv,tag;
    	#define l(x) tr[x].l
    	#define r(x) tr[x].r
    	#define maxv(x) tr[x].maxv
    	#define tag(x) tr[x].tag
    } tr[N];
     
     
     
    void update(int p)
    {
    	maxv(p)=max(maxv(p*2),maxv(p*2+1));
    }
     
    void build(int p,int l,int r)
    {
    	if(l==r){
    		tr[p]={l,l,0,0};
    		return ;
    	}
    	l(p)=l,r(p)=r;
    	int mid=(l+r)/2;
    	build(p*2,l,mid);
    	build(p*2+1,mid+1,r);
    }
     
    void pushdown(int p)
    {
    	if(tag(p)){
    		tag(p*2)+=tag(p);
    		tag(p*2+1)+=tag(p);
    		maxv(p*2)+=tag(p);
    		maxv(p*2+1)+=tag(p);
    		tag(p)=0;
    	}
     
    }
     
    void modify(int p,int l,int r)
    {
    	if(l<=l(p)&&r(p)<=r){
    		maxv(p)++;
    		tag(p)++;
    		return ;
    	}
    	pushdown(p);
    	int mid=(l(p)+r(p))/2;
    	if(l<=mid) modify(p*2,l,r);
    	if(r>mid) modify(p*2+1,l,r);
    	update(p);
    }
     
    int query(int p,int l,int r)
    {
    	if(l<=l(p)&&r(p)<=r){
    		return maxv(p);
    	}
    	pushdown(p);
    	int mid=(l(p)+r(p))/2;
    	int res=0;
    	if(l<=mid) res=max(res,query(p*2,l,r));
    	if(r>mid) res=max(res,query(p*2+1,l,r)); 
    	return res;
    }
     
     
    void solve()
    {
    	int n,k;
    	cin>>n>>k;
    	build(1,1,2e5);
    	vector<p3> a(n+5);
    	for(int i=1;i<=n;i++){
    		int l,r;
    		cin>>l>>r;
    		a[i]={l,r,i};
    	}
    	sort(a.begin()+1,a.begin()+1+n,[](p3 x,p3 y){
    		if(x[1]==y[1]) return x[0]<y[0];
    		return x[1]<y[1];
    	});
    	//int cnt=0;
    	vector<int> ans;
    	for(int i=1;i<=n;i++){
    		auto [l,r,idx]=a[i];
    		int t=query(1,l,r);
    		//cout<<l<<" "<<r<<" "<<t<<endl;
    		if(t<k) modify(1,l,r);
    		else{
    			ans.push_back(idx);
    		}
    	}
    	cout<<ans.size()<<endl;
    	for(auto x: ans) cout<<x<<" ";
    	cout<<endl;
    }
     
     
     
     
     
     
     
    int main()
    {
        ios::sync_with_stdio(0);
    	cin.tie(0);
    	cout.tie(0);
    	int t;
    	t=1;
    	//cin>>t;
    	//ol();
    	while(t--){
    		solve();
    	}
        system("pause");
        return 0;
    }