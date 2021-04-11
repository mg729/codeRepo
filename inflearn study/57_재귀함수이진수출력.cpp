#include<bits/stdc++.h>
using namespace std;

int n;

void printBinary(int x) {
	if(x == 1) {
		cout << "1";
		return;
	}
	else {
		printBinary(x/2);
		cout << x%2 ;	
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//	freopen("input.txt", "rt", stdin);
	cin >> n;
	printBinary(n);
	
	return 0;
}