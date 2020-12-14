#include<bits/stdc++.h>

using namespace std;
string input;
stack<char> st;

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "rt", stdin);
	
	cin >> input;
	for(int i = 0; i < input.length(); i++) {
		if(input[i] == '(') 	
			st.push(input[i]);
		else {
			if(st.empty()) {
				cout << "NO";
				return 0;
			}
			st.pop();
		}
	}
	if(st.empty())
		cout << "YES";
	else
		cout << "NO";
	return 0;
}