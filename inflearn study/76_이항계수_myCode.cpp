#include<bits/stdc++.h>
using namespace std;

int n, r;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("input.txt", "rt", stdin);
	cin >> n >> r;
	int v1 = 1;
	int v2 = 1;
	
	for(int i = n; i >= n-r+1 ; i--) {
		v1 *= i;
	}
	
	for(int i = r; i >=1; i--) {
		v2 *= i;
	}
	
	cout << v1/v2;
	

 	return 0;
}