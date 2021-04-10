#include<bits/stdc++.h>
using namespace std;

int n;
stack<int> s;

void recursiveFunc1(int x) { //1 2 3 
	if(x == 0) 	return;
	else {
		recursiveFunc1(x-1);
		cout << x << " ";
	}
}

void recursiveFunc2(int x) { //3 2 1
	if(x == 0) 	return;
	else {
		cout << x << " ";
		recursiveFunc2(x-1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("input.txt", "rt", stdin);
	cin >> n;
	recursiveFunc1(n);
	cout << "\n";
	recursiveFunc2(n);
	
	return 0;
}
