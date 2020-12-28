#include<bits/stdc++.h>

using namespace std;
int n, k;
int num[100002];

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	
	cin >> n >> k;


	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;
		num[i] = val;
	}
	int sum = 0;
	int maxVal = -1;

	for(int i = n-1; i>-1; i--) {
		for(int j = 0; j < k; j++) {
			sum += num[i-j];
		}
		if(maxVal < sum) maxVal = sum;
		sum = 0;		
	}

	cout << maxVal;
	
	
	return 0;
}