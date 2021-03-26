#include<bits/stdc++.h>
using namespace std;

int n, sum, cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//	freopen("input.txt", "rt", stdin);
	cin >> n;
	
	for(int i = n-1; i >= 1; i--) {
		sum = 0;
		bool isMatch = false;
		int j;
		for(j = i; j <= n; j++) {
			sum += j;			
			if(sum == n) {
				isMatch = true;
				cnt++;
				break;
			}
			else if (sum > n) break;
		}
		
		if(isMatch) {
			for(int k = i; k < j; k++) {
				cout << k << " + ";
			}
			cout << j  << " = " << n << "\n";
		}
	}
	
	cout << cnt;
	
	return 0;
}