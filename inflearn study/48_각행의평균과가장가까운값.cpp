#include<bits/stdc++.h>
using namespace std;

int arr[10][10]; //always 2 size up for prevent error

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//	freopen("input.txt", "rt", stdin);

	for(int i = 1; i <= 9; i++) {
		for(int j = 1; j <= 9; j++) {
			int val;
			cin >> val;
			arr[i][j] = val;
		}
	}
	
	for(int i = 1; i <= 9; i++) {
		double sum = 0;
		int avgVal = 0; //double
		int nearAvgVal = 2147000000;
		for(int j = 1; j <= 9; j++) {
			sum += arr[i][j];
		}

		// average needs to be round up to first decimal place 
		double avgWithDecimal = sum / 9;
		avgVal = sum / 9;
		while(avgWithDecimal > 0) {
			if(avgWithDecimal < 1) break;
			avgWithDecimal -= 1;
		}
		int firstPlace = avgWithDecimal * 10;
		if(firstPlace >= 5) avgVal += 1;
		
		int diffVal[] = {0,0,0,0,0,0,0,0,0,0};
		for(int j = 1; j <= 9; j++) {
			diffVal[j] = abs(arr[i][j] - avgVal);
		}

		int tempVal = 2147000000;
		for(int j = 1; j <= 9; j++) {
			if(tempVal > diffVal[j]) {
				tempVal = diffVal[j];
				nearAvgVal = arr[i][j];
			}
			else if(tempVal == diffVal[j]) {
				tempVal = diffVal[j];
				if(nearAvgVal < arr[i][j]) {
					nearAvgVal = arr[i][j];
				}
			}
		}
		cout << avgVal << " " << nearAvgVal << "\n";
	}
	
	return 0;
}

