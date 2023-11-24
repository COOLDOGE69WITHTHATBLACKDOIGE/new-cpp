#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define forn(i,j) for(int i = 0; i < j; i++)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<int<int>>
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin(), x.end()

#define MOD 1000007000
#define mp make_pair

void siout(string name = "") { 

	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

vector<int> F(vector<int> &p, int n){
	sort(all(p));

	vector<int> ptr;

	forn(i, n-1){ ptr[i] = i+1;}

	priority_queue<pii> pq;
	forn(i,n-1){ 
		pq.p(mp(-(p[i] + p[ptr[i]]), i));
	}
	return p;

/* TO do: Implement with taking some help*/
}

int main(){
	siout();
	int n;
	cin >> n;
	vector<int> p;

	forn(i, n){ int x; cin >> x; p.pb(x);} 

	forn(k,n){
		F(p, n-k);
	}
}