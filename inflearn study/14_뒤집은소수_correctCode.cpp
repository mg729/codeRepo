#include<bits/stdc++.h>

using namespace std;
int n;

int reverse(int x) {
	int res = 0;

	while(x > 0) {
		int val = x % 10;
		res = (res * 10) + val;
		x /= 10;
	}
	
	return res;
}

bool isPrime(int x) {
	int limit = sqrt(x);
	for(int i = 2; i <= limit ; i++) {
		if(x % i == 0) {
			return false;
		}
	}
	return true;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;
		int reversedNum = reverse(val);
		if(reversedNum == 1) continue; //need to consider 100 --> 1 
		// 1 is not prime number
		if(isPrime(reversedNum)) {
			cout << reversedNum << " ";
		}
	}
	
	return 0;
}