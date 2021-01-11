#include<bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	cin >> n;
	cout << n << "! = ";
	
	vector<int> v(n+1);
	for(int i = 2; i <= n; i ++) {
		int tmp = i;
		int j = 2;
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
	
	for(int i = 2; i <= n; i++) {
		if(v[i] != 0) cout << v[i] <<" ";
	}
	
	
	return 0;
}