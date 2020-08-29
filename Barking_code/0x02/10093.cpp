#include<bits/stdc++.h>

using namespace std;
/**
1. swap() ÇÔ¼ö
2. integer data range 
*/
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
    long long n1, n2;
	cin >> n1 >> n2;
	if (n1 == n2) {
		cout << 0;
		return 0;
	}
	
	if(n1 > n2)
		swap(n1, n2);
	
    long long diff = n2 - n1 -1;
	if(diff == 1)
		return 0;
		
	cout << diff  << '\n';
	
	for(long long i = n1 + 1; i < n2;  i++) {
		cout << i << " ";
	}

	return 0;
}
