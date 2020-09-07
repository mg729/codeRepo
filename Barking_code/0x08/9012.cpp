#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	
	for(int i = 0; i < tc; i++) {
		stack<char> st;
		
		string str;
		cin >> str;
		bool isEmpty = false;
		for(int i = 0; str[i]; i++) {
			if(str[i] == '(')
				st.push(str[i]);
			else {
				if(st.empty()) {
					isEmpty = true; break;
				}
				st.pop();
			}
		}
		
		if(!st.empty() || isEmpty) 
			cout << "NO\n"; 
		else
			cout << "YES\n";
		
	}
	
	
	return 0;
}
