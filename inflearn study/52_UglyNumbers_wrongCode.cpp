#include<bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//	freopen("input.txt", "rt", stdin);
	cin >> n;
	int number = 1;
	int idx = 1;
	
	while(true) {
		int tmp = number;
		while(tmp > 2 && tmp % 2 == 0) {
			tmp /= 2;
		}
		while(tmp > 3 && tmp % 3 == 0) {
			tmp /= 3;
		}
		while(tmp > 5 && tmp % 5 == 0) {
			tmp /= 5;
		}
		if(tmp == 2 || tmp == 3 || tmp == 5) {
			idx++;
		}		
		if(idx == n) break;
		number++;
	}
	
	cout << number;
	
	return 0;
}
