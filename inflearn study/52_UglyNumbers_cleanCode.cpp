#include<bits/stdc++.h>
using namespace std;

int n, p2, p3, p5, minVal;
int arr[1502];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("input.txt", "rt", stdin);
	cin >> n;
	
	int i = 1;
	arr[i]  = 1;
	p2 = p3 = p5 = 1;

	for(i = 2; i <= n; i++) {		
		minVal = min(arr[p2] * 2, arr[p3] *3);
		minVal = min(minVal, arr[p5] * 5);
		
		if(arr[p2] * 2 == minVal) p2++;
		if(arr[p3] * 3 == minVal) p3++;
		if(arr[p5] * 5 == minVal) p5++;
		
		arr[i] = minVal;
	}
	
	cout << arr[n];
	
	return 0;
}