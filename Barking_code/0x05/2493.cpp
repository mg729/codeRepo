#include <bits/stdc++.h>
using namespace std;
/**
O(n) by using stack
stack - insert, delete --> O(1) 
*/
stack< pair<int,int> > s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		int val;
		cin >> val;
		while(!s.empty()) {
			if(s.top().second >= val) {
				cout << s.top().first << ' ';
				break;
			}
			else {
				s.pop();
			}
		}
		if(s.empty()) 
			cout << "0 " ;
		
		s.push({i, val});
	}

	return 0;
}
