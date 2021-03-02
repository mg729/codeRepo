#include<bits/stdc++.h>
using namespace std;

int n, k, val;
string str;
stack<string> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//	freopen("input.txt", "rt", stdin);
	cin >> n >> k;

	while(1) {
		if(n<k) {
			str = to_string(n);
			s.push(str);
			break;
		}
		if(n % k == 0) {
			s.push("0");
		}
		else {
			if(k == 16) {
				val = n % 16;
				if(val == 10) str = "A";
				else if(val == 11) str = "B";
				else if(val == 12) str = "C";
				else if(val == 13) str = "D";
				else if(val == 14) str = "E";
				else if(val == 15) str = "F";
				else str = to_string(val);
				s.push(str);
			}
			else {
			
				val = n % k;
				s.push(to_string(val));
			}
		}
		n /= k;
	}	
	

	while(!s.empty()) {
		cout << s.top();
		s.pop();
	}

	return 0;
}