#include<bits/stdc++.h>
using namespace std;

int rand(int a, int b){
	return a + rand() % (b-a+1);
}

int main(int argc, char* argv[]){
	srand(atoi(argv[1]));
	int n = rand(2,10);
	int q = rand(2,10);
	cout << n << " " << q << endl;

	for(int i = 2; i < n+1; ++i){
		int p = rand(1,i-1);

		cout << i << " " << p << endl;
	}

	while(q--){
		int a = rand(1,n); int b = rand(1,n);
		cout << a << " " << b << endl;
	}
}