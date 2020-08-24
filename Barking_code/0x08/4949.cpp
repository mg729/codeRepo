#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while(true) {
		string str;
		getline(cin, str);
		
		if(str == ".")	break;

		stack<int> st;
		bool isValidate = true;

		for(auto s : str) {
			if(s == '(' ||  s == '[') {
				st.push(s);
			}
			else if(s == ')') {
				if(st.empty() || st.top() != '(') {
					isValidate = false;
					break;
				}
				st.pop();
			}
			else if(s == ']') {
				if(st.empty() || st.top() != '[') {
					isValidate = false;
					break;
				}
				st.pop();
			}
		}
		if(!st.empty()) isValidate = false;
		if(!isValidate)
			cout << "no\n";
		else 
			cout << "yes\n";
	}
	return 0;
}



//------my solution
//****** Declare stack as local variable -> then no need to clear the container
//****** Think about using a flag for printing the result
//stack<char> st;
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	
//	while(true) {
//		string str;
//		getline(cin, str);
//		
//		if(str == ".")
//			break;
//		
//		for(auto s : str) {
//			if(s == '(' ||  s == '[') {
//				st.push(s);
//			}
//			else if(s == ')') {
//				if(!st.empty() && st.top() == '(') {
//					st.pop();
//				}
//				else
//					st.push(s);
//			}
//			else if(s == ']') {
//				if(!st.empty() && st.top() == '[') {
//					st.pop();
//				}
//				else
//					st.push(s);
//			}
//		}
//		if(!st.empty())
//			cout << "no\n";
//		else 
//			cout << "yes\n";
//		
//		//every end of the test case, container sholud be cleared
//		while(!st.empty()) {
//			st.pop();
//		}
//	}
//	
//	
//	return 0;
//}
