#include<bits/stdc++.h>
using namespace std;

int main(){
	pair<int,int> j = {5, 5};
	pair<int,int> k = {4,}3;
	set<pair<int,int>> s; s.insert(j);
	pair<int,int> l = *s.lower_bound(k);

	cout << l.first << " " << l.second;
}