#include<bits/stdc++.h>

using namespace std;
int n, k;
int num[100002];
int sumArr[100002];

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
	int maxVal = -2147000000;
	for(int i = 0; i < k; i++) {
		sum += num[i];
	}
	for(int i = k; i < n; i++) {
		sum += (num[i] - num[i-k]);
		if(maxVal < sum) maxVal = sum;		
	}
	cout << maxVal;
	
	return 0;
}