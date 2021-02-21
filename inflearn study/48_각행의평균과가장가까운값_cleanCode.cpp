#include<bits/stdc++.h>
using namespace std;

int arr[10][10]; //always 2 size up for prevent error

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//	freopen("input.txt", "rt", stdin);

	for(int i = 1; i <= 9; i++) {
		int sum = 0;
		for(int j = 1; j <= 9; j++) {
			int val;
			cin >> val;
			arr[i][j] = val;
			sum += arr[i][j];
		}
		int avg = (sum / 9.0) + 0.5;
		cout << avg << " ";
		
		int minVal = 2147000000;
		int res = 0;
		for(int j = 1; j <=9; j++) {
			int tempVal = abs(arr[i][j] - avg);
			if(tempVal < minVal) {
				minVal = tempVal;
				res = arr[i][j];
			}
			else if(tempVal == minVal) {
				if(arr[i][j] > res) res = arr[i][j];
			}
		}
		cout << res << "\n";
	}
	
	
	return 0;
}

