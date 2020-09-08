#include<bits/stdc++.h>

using namespace std;

stack<char> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	cin >> s;
	
	int piece = 0;
	
	for(int i = 0; s[i]; i++) {
		
		if(s[i] == '(') {
			st.push(s[i]);
		}
		else if(s[i] ==')') {
			if(s[i-1]=='(') {
				if(!st.empty()) {
					st.pop();
					piece += st.size();
				}
			}
			else {
				piece += 1;
				st.pop();
			}

		}		
	}
	cout << piece;
	return 0;
}
