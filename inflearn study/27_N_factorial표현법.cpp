#include<bits/stdc++.h>
using namespace std;

int n;
vector<unsigned long> isPrimeV;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);
	cin >> n;
	cout << n << "! = ";
    // int 범위가 n! factorial 범위를 수용하지 못함
	// unsigned long long 0 ~ 18,446,744,073,709,551,615 
	unsigned long long res = 1;
	// 1. get factoriaal result value of input 'n' 
	for(int i = 1; i <= n; i++) {
		res *= i;
	}

	isPrimeV.push_back(2);
	for(int i = 3; i*i <= res; i += 2) {
		bool isPrimeValue = true;
		for(int j = 3; j < i ; j++) {
			if(i % j == 0)  {
				isPrimeValue = false;
				break;	
			}
		}
		if(isPrimeValue) isPrimeV.push_back(i);
	}

	int numberOfPrimeVal = isPrimeV.size();
	// 2. divide value with prime number from lower value
	for(int i = 0; i <= numberOfPrimeVal; i++) {
		if(res == 1 || res == 0) break;
		int cnt = 0;
		while(res % isPrimeV[i] == 0) {
			res /= isPrimeV[i];
			cnt++;
		}
		cout << cnt << " ";
	}
	
	
	return 0;
}