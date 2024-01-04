#include<bits/stdc++.h>
using namespace std;

int rand(int a, int b){
	return a + rand() % (b-a+1);
}

int main(int argc, char* argv[]){
	srand(atoi(argv[1]));

	int n = rand(39,40);
	int x = rand(1,24);

	cout << n << " " << x << endl;

	for(int i = 0; i < n; ++i){
		int a = rand(1,20);

		cout << a << " ";
	}
}