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

	for(int i = 0; i < n; ++i){
		int x = rand(0,10000);
		cout << x << " ";
	}

	cout << endl;

	for(int i = 0; i < q; ++i){
		int y = rand(1,2);
		int h = rand(1,n);
		int j = rand(h,n);

		cout << y << " " << h << " " << j << endl;
	}
}