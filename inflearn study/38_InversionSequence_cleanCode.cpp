#include<bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);
	cin >> n;
	
	vector<int> is(n+1), os(n+1);
	for(int i = 1; i <= n; i++) {
		int val;
		cin >> val;
		is[i] = val;
	}
	
	for(int i = n; i >= 1; i--) {
		int pos = i;
		for(int j = 1; j <= is[i]; j++) {
			os[pos] = os[pos+1];
			pos++;
		}
		os[pos] = i;
	}
	
	for(int i = 1; i <= n; i++) {
		cout << os[i] << " " ;
	}

	return 0;
}