#include<bits/stdc++.h>
using namespace std;

const int N = 6e5;

vector<int> a(N);
vector<vector<int>> b(N);
vector<int> freq(N,0);
vector<int> cnt(N);

int maxsum(vector<int> g, int sze){
    int m = 0;
    int curr = 0;
    int mi = 0;

    int d = sze;

    for(int i = 0; i < d; ++i){
        curr += g[i];
        m = max(curr, m);

        if(curr < 0){
            curr = 0;
        }
    }

    return m;
}

int extraction(int d){
    int s = freq[d];
    vector<int> g(s,0);
    g[0] = 1;

    for(int i = 1; i < s; ++i){
        g[i] = 1 - (cnt[b[d][i]] - cnt[b[d][i-1]]);
    }

    int h = maxsum(g,s);
    return h;
}


int main(){
    int n,c;
    cin >> n >> c;

    queue<int> q;
    

    for(int i = 0; i < n; ++i){
        cin >> a[i];

        if(freq[a[i]] == 0){
            q.push(a[i]);
        }
        freq[a[i]]++;

        b[a[i]].push_back(i);
    }
    
    if(a[0] == c){
        cnt[0] = 1;
    }

    else{ cnt[0] = 0;}

    for(int i = 1; i < n; ++i){
        if(a[i] == c){
            cnt[i] = cnt[i-1]+1;
        }

        else{
            cnt[i] = cnt[i-1];
        }
    }

    if(q.size() == 1){
        cout << n << endl;
    }

    else{
        int y = 1;
        while(!q.empty()){
            int t = extraction(q.front());
            y = max(y,t);
            q.pop();
        }

        int v = cnt[n-1];

        cout << (v+y) << endl;
    }
}
