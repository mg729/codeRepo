#include<bits/stdc++.h>

using namespace std;

stack<char> st;
vector<pair<int, bool> > v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	cin >> s;
	
	int piece = 0;
	
//	for(int i = 0; i < s.size(); i++) {
//		v.push_back({i, false});
//	}
	
	for(int i = 0; i < s.size(); i++) {
		
		if(s[i] == '(') {
			st.push(s[i]);
			
			if(i!= 0 && s[i-1]==')') {
				if(!st.empty())
					piece -= (st.size() - 1);
			}	
		}
		else if(s[i] ==')') {
			if(i!= 0 && s[i-1]=='(') {
				if(!st.empty()) {	
					st.pop();
					piece += st.size();
				}
			}
			else {
				piece += st.size();
				st.pop();
			}

		}
		
//		if(i!= 0 && s[i-1]=='(' &&s[i] ==')') {
//			piece += st.size();
//			st.pop();
//			v[i].second = true;
//		}
//		else if(s[i] == '(') {
//			st.push(s[i]);
//			if(i != 0 && s[i-1] == ')' && !v[i-1].second)
//				piece -= st.size();
//		}
//		else if(s[i] == ')') {
//			piece += st.size();
//			st.pop();
//		}
			
		
	}
	cout << piece;
	return 0;
}
