#include <iostream>

int arr[10000];

using namespace std;

int main() {
	int n, x;
//	cin >> n, x;  // cin은 >> 로 입력받아야함.!! 
	cin >> n>> x;
	for (int i = 0 ; i < n; i++) {
		cin >> arr[i];
	}
	
	for (int i = 0 ; i < n; i++) {
		if( arr[i] < x ) {
			cout << arr[i] << " ";
		}
	}
	return 0;
}
