#include<bits/stdc++.h>
using namespace std;

string str;
stack<char> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//	freopen("input.txt", "rt", stdin); 
	cin >> str;
	
	for(int i = 0; i < str.size(); i++) { //int i = 0; str[i] != '\0'; i++
		char c = str[i];
		if(c == '(') s.push('(');
		else if(c == ')') {
			if(s.empty()) {
				cout << "NO";
				return 0;
			}
			s.pop();
		}
	}
	
	if(s.empty()) cout << "YES";
	else cout << "NO";
	
	return 0;
}