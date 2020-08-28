#include<bits/stdc++.h>

using namespace std;

stack<char> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;

	int tmp = 1, sum = 0;
	bool wrong = false;
	cin >> str;
	
	for (int i = 0; str[i]; i++) {
		if (str[i] == '(') {
		  tmp *= 2;
		  st.push('(');
		} 
		else if (str[i] == '[') {
		  tmp *= 3;
		  st.push('[');
		} 
		else if (str[i] == ')') {
		  if (str[i - 1] == '(') sum += tmp;
		  if (st.empty()) {
		    wrong = true;
		    break;
		  }
		  if (st.top() == '(') st.pop();
		  tmp /= 2;
		} 
		else {
		  if (str[i - 1] == '[') sum += tmp;
		  if (st.empty()) {
		    wrong = true;
		    break;
		  }
		  if (st.top() == '[') st.pop();
		  tmp /= 3;
		}
	}
	if (wrong || !st.empty()) cout << 0;
	else cout << sum;


	return 0;
}
