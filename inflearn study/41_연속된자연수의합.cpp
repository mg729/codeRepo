#include<bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	cin >> n;
	vector<int> v(n+1);
	for(int i = 1; i <= n; i++) {
		v[i] = i;
	}
	int sumNum = 0;
	for(int i = n-1; i > 0; i--) {
		int pos = i;
		int sum = 0;
		bool isEqual = false;
		
		while(1) {
			sum += v[pos];
			if(sum == n) {
				isEqual = true;
				sumNum++;
				break;
			}
			else if(sum > n) {
				break;
			}
			pos++;
		}
		
		if(isEqual) {
			for(int j = i; j < pos; j++) {
				cout << j << " + " ;
			}
			cout << pos << " = " << n << "\n"; 
		}
	}
	cout << sumNum;
	return 0;
}