#include<bits/stdc++.h>
using namespace std;

int n;
int arr[1502];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("input.txt", "rt", stdin);
	cin >> n;
	
	int val = 1;
	int i = 1;
	arr[1]  = 1;
	while(1) {
		if(i > n) break;
		
		val++;
		
		int tmp = val;
		while(1) {
			if(tmp % 2 == 0)
				tmp /= 2;
			else if(tmp % 3 == 0)
				tmp /= 3;
			else if(tmp % 5 == 0)
				tmp /= 5;
			else
				break;
		}
		
		if(tmp == 1)
		{
			i++;
		   	arr[i] = val;
		}
	}
	
	cout << arr[n];
	
	return 0;
}