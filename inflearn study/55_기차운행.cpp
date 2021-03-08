#include<bits/stdc++.h>
using namespace std;

int n, val, cnt, i;
stack<int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("input.txt", "rt", stdin);
	cin >> n;
	string str = "";
	cnt  = i = 1;
	while(cnt <= n) {		
		if(i <= n) {
			cin >> val;
		}
		
		if(cnt == val) {
			cnt++;
			str.append("PO");
		}
		else if(!s.empty()&& s.top() == cnt) {
			str.append("O");
			s.pop();
			cnt++;
		}
		else {
			s.push(val);
			str.append("P");
		}
		i++;
	}
	
	if(s.empty()) cout << str;
	else cout << "impossible";

	return 0;
}