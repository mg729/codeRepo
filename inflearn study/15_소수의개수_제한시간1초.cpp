#include<bits/stdc++.h>

using namespace std;

int n, cnt;

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	
	cin >> n;
	
	for(int i = 2; i <= n; i++) {
		bool isPrime = true;
		int limit = sqrt(i);
		for(int j = 2; j <= limit; j++) {
			if(i % j == 0) {
				isPrime = false;
				break;
			}
		}
		
		if(isPrime) cnt++;
		
	}

	cout << cnt;
	
	return 0;
}