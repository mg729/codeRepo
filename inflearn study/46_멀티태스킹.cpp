#include<bits/stdc++.h>
using namespace std;

int n, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//	freopen("input.txt", "rt", stdin);
	
	cin >> n;
	vector<int> v(n+1);
	for(int i = 1; i <= n; i++) {
		int val;
		cin >> val;
		v[i] = val;
	}
	cin >> k;
	
	int bp = 0; // breakpoint
	int res = -1;
	int pos = 1;
	while(k) {
		if(pos > n) pos = 1;
		if(v[pos] > 0) {
			--v[pos];
			k--;
		}
		pos++;
	}
	
	bool isLeft = false;
	for(auto x : v) {
		if(x > 0) {
			isLeft = true;
			break;
		}
	}
	if(!isLeft) {
		cout << -1;
		return 0;
	}
	
	while(1) {
		if(pos > n) pos = 1;
		if(v[pos] != 0) {
			cout << pos;
			break;
		}
		pos++;
	}
	return 0;
}

