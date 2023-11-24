#include<bits/stdc++.h>
using namespace std;

void siout(string name = "") { 

    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int moves(int a, int b){
    if(a == 0){
        if(b == 2){
            return 1;
        }
        else{
            return 0;
        }
    }

    if(a == 1){
        if(b == 0){
            return 1;
        }
        else{
            return 0;
        }
    }

    else{
        if(b == 1){
            return 1;
        }
        else{
            return 0;
        }
    }
}

int main(){
    siout();

    cout << moves(2,0) << ' ' << moves(2,1);
}