#include <bits/stdc++.h>

using namespace std;

queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		string str;
		cin >> str;
		
		if(str == "push") {
			int val;
			cin >> val;
			
			q.push(val);
		}
		else if(str == "pop") {
			if(q.empty()) {
				cout << "-1" << '\n';
				continue;
			}
			cout << q.front() << '\n';
			q.pop();
		}
		else if(str == "size") {
			cout << q.size() << '\n';
		}
		else if(str == "empty") {
			if(q.empty()) {
				cout << "1" << '\n';
			}
			else {
				cout << "0" << '\n';
			}
		}
		else if(str == "front") {	
			if(q.empty()) {
				cout << "-1" << '\n';
				continue;
			}
			cout << q.front() << '\n';
		}
		else if(str == "back") {
			if(q.empty()) {
				cout << "-1" << '\n';
				continue;
			}
			cout << q.back() << '\n';			
		}
		
	}
	
	return 0;
}
