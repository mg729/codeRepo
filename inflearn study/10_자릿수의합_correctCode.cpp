#include<bits/stdc++.h>

using namespace std;
int n, sumVal;
vector<int> number;
int result;
int digit_sum(int x) {
	int sum = 0;
	while(x != 0) {
		sum += x % 10;
		x /= 10;
	}
	return sum;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
    cin >> n;
    for (int i = 0; i < n ; i++) {
    	int val;
   		cin >> val;
		number.push_back(val);
	}
	
	int maxVal = -1;
	for (int i = 0; i < n ; i++) {
		sumVal = digit_sum(number[i]);
		if(sumVal > maxVal) {
			maxVal = sumVal;
			result = number[i];
		}
		else if(sumVal == maxVal) {
			if(result < number[i]) result = number[i];
		}
	}
	cout << result;
	
	return 0;
}