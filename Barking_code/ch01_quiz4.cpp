#include<iostream>
using namespace std;
/*
문제 4 : N이하의 수 중에서 가장 큰 2의 거듭제곱수를 반환하는 문제 
*/
//int main() {
//	int n;
//	cin >> n;
//	// 2 4 8 16 32 64 128
//	int val = 1;
//	for(int i = 0; i < n; i++) {
//		if(val < n) {
//			val *= 2;
//			if(val > n) {
//				val /= 2;
//				break;
//			}
//		}
//		else {
//			break;
//		}
//	}
//	
//	cout << val;
//	
//	return 0;
//}

int main() {
	int n;
	cin >> n;
	// 2 4 8 16 32 64 128
	int val = 1;
	while ((val * 2) < n) {
		val *= 2;
	}
	
	cout << val;
	
	return 0;
}

