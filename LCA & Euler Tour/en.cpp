#include <bits/stdc++.h>
using namespace std;
int rnd(int a, int b){
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]){
    int seed = atoi(argv[1]);
    srand(seed);

    int n = rnd(1, 10);
    int q = rnd(1,10);

    cout<<n<<endl;
    cout<<q<<endl;
    int i = 0;

    while(i < n-1){
        int x = rnd(1, n);

        if(x != i+2){
            cout<<x<<" ";
            i++;
        }
    }

    cout << endl;

    for(int i = 0; i < q; i++){
        int x = rnd(1,n);
        int y = rnd(1,n);
        cout << x << " " << y << endl;
    }
}