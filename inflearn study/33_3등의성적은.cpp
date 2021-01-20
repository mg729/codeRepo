#include<bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	cin >> n;
	
	set<int> s;
	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;
		s.insert(val);
	}
	int j = 1;
	auto it = s.end();
	it++;
	while(1) {
		if(j == 3) {
			cout << *it << " ";
			break;
		}
		if(it == s.begin()) break;
		it--;
		j++;
	}
	return 0;
}