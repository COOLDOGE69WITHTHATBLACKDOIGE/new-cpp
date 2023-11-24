/* First of all to check whether the graph is valid or not, check the values -1,-0.5,0,0.5,1 if they work or not, if they do, then the graph
is valid, else print NO. The reason for this is say there is a cycle in a graph giving some system of equations, the only valid sols to any such
equation are -1,-0.5,0,0.5,1, so in case there is such a cycle in the graph, we will check if one of these values work or not, if only one of them
work, then we need to take that value only bc no other value might work, if they all work, then say a vertex in a connected component has value x,
then there will be things with abs value |1-x|, |2-x|, |2+x|, the min. value of this sum will be the median of 1,2,-2 , 
so for each vertex, we store the value k such that |k - x| is the vertex value after setting the root = x, then we can take the median easily by a 
sorting algorithm, if the size is even, then just take the avg. of the n/2th and n+2/2th element, and if it is odd, take the median equal to 
n+1/2th element.*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define forn(i,j) for(ll i = 0; i < j; i++)
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<vector<int>>
#define pb push_back
#define p push
#define f first
#define s second
#define all(x) x.begin, x.end()
#define eb emplace_back
#define mp make_pair

#define MOD 1000000007

void siout(string name = "") { 

	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

ll n;
vector<vector<pii>> adj;
vector<bool> visited;
vector<bool> group;
vi value;
vector<bool> bad;
int connected_comp = 0;
array<double,5> a = {-1,-0.5,0,0.5,1};
int b = 0;

void dfs(int x, double g){
    visited[x] = 1;
    value[x] = g;

    for(auto u : adj[x]){
        if(visited[u.f]){
            if(value[u.f] + value[x] != u.s){
                //it fails here
                bad[connected_comp] = true;
                b = 1;
            }
        }
        
        if(!visited[u.f]){ 
            value[u.f] = g - u.s;
            x = value[u.f];
            dfs(u.f,x);
            }
    }
}

vector<int> val;

void validity(){
    for(auto x : a){
        for(int i = 1; i <= n; ++i){
            if(!visited[i]){
                dfs(i,x);
                connected_comp++;
            }
            if(b == 0){ val.eb(a);}
            int b = 0;
            fill(bad.begin(),bad.end(),false);
            fill(visited.begin(), visited.end(), false);
        }
    }
}

void sum(double g){
    
}

int main(){
    siout();
    ll m;
    cin >> n >> m;

    adj.resize(n+1);
    visited.resize(n+1);
    group.resize(n+1);
    value.resize(n+1);
    
    forn(i,m){
        int a,b,c;
        cin >> a >> b >> c;

        adj[a].eb(mp(b,c));
        adj[a].eb(mp(a,c));
    }

    for(int i = 1; i<= n; ++i){
        if(!visited[i]){
            dfs(i, 0);
            connected_comp++;
        }
    }

    if(a.empty()){
        cout << "NO" << endl;
    }

    else if(a.size() == 1){
        sum(val[0]);
    }

    else{

    }
}