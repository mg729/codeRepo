#include<bits/stdc++.h>
using namespace std;

int n;
int arr[1000];
bool isPrime(int val) {
	bool isPrimeval = true;
	for(int i = 2; i < val; i++) {
		if(val % i == 0) {
			isPrimeval = false;
			break;
		}
	}
	return isPrimeval;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	cin >> n;
	cout << n << "! = ";
	
	int maxLimit = -1;
	for(int i = 2; i <= n; i++) {
		if(isPrime(i)) {
			arr[i]++;
			if(maxLimit < i) 	maxLimit = i;
		}
		else {
			int tmp = i;
			for(int j = 2; j < i; j++) {
				int cnt = 0;
				while(tmp % j == 0) {
					if(tmp <= 1) break;
					tmp /= j;
					cnt++;
				}
				arr[j] += cnt;
				if(maxLimit < j) 	maxLimit = j;
			}
		}
	}
	for(int i = 2; i <= maxLimit; i++) {
		if(isPrime(i)) cout << arr[i] <<" ";
	}
	return 0;
}