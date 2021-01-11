#include<bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);
	cin >> n;
	
	vector<int> v(n+1);
	
	for(int i = 2; i <= n; i++) {
		int j = 2;
		int tmp = i;
		while(1) {
			if(tmp % j == 0) {
				tmp /= j;
				v[j]++;
			}
			else {
				j++;
			}			
			if(tmp == 1) break;
		}
	}
	int minVal = min(v[2], v[5]);
	
	cout <<minVal;
	
	return 0;
}