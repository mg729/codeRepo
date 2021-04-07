#include<bits/stdc++.h>
using namespace std;

int n;
int a[1501];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//	freopen("input.txt", "rt", stdin);
	cin >> n;
	int number = 1;
	int p2, p3, p5;
	int min = 2147000000;
	
	a[1] = 1;
	p2=p3=p5=1;
	for(int i = 2; i<=n; i++) {
		if(a[p2]*2 < a[p3]*3) min = a[p2]*2;
		else min = a[p3]*3;
		if(a[p5]*5 < min) min = a[p5]*5;
		
		if(a[p2] * 2 == min) p2++;
		if(a[p3] * 3 == min) p3++;
		if(a[p5] * 5 == min) p5++;
		a[i] = min;
	}
	cout << a[n];
	
	return 0;
}


/*#include<bits/stdc++.h>
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
*/
