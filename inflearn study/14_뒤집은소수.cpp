#include<bits/stdc++.h>

using namespace std;
int n;
stack <int> s;

int reverse(int x) {
	int res = 0;

	while(x > 0) {
		int val = x % 10;
		s.push(val);
		x /= 10;
	}
	int i = 1;
	while(!s.empty()) {
		if(res == 0 && s.top() == 0) {
			s.pop();
			continue;
		}
		res += s.top() * i;
		i *= 10;
		s.pop();
	}
	
	return res;
}

bool isPrime(int x) {
	int limit = sqrt(x);  //need to check -- Be Cautious : timeout 
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