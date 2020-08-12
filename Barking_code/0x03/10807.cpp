#include <bits/stdc++.h>
using namespace std;
int arr[202];

int main() {
	int n;
	cin >> n;
	
	for(int i = 0; i <n; i++) {
		cin >> arr[i];
	}
	
	int val;
	cin >> val;
	int count = 0;
	for(int i = 0; i <n; i++) {
		if(arr[i] == val) {
			count++;
		}
	}
	
	cout << count;
	return 0;
}
