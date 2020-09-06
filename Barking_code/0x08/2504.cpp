#include<bits/stdc++.h>

using namespace std;

stack<char> str;
int num[100];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string brt; //bracket
	cin >> brt;
	
	int pos = 0;
	for (int i = 0; i < brt[i] ; i++) {
		switch(brt[i]) {
			case '(' : {
				str.push(brt[i]);
				pos++;
				break;
			}
			case '[' : {
				str.push(brt[i]);
				pos++;
				break;
			}
			case ')' : {
				if(str.empty()) {
					cout << "0"; return 0;
				}
				
				if(str.top() != '(') {
					cout << "0"; return 0;
				}
				pos--;
				if(num[pos+1] > 0) {
					num[pos] += num[pos+1] * 2;
					num[pos+1] = 0;
				}
				else
					num[pos] += 2;
				
				str.pop();
				break;
			}
			case ']' : {
				if(str.empty()) {
					cout << "0"; return 0;
				}
				
				if(str.top() != '[') {
					cout << "0"; return 0;
				}
				pos--;	
				if(num[pos+1] > 0) {
					num[pos] += num[pos+1] * 3;
					num[pos+1] = 0;
				}
				else
					num[pos] += 3;
				str.pop();				
				break;
			}
			
			default : {
				cout << "0"; return 0;
				break;
			}
		}
	}
	
	if(!str.empty()) {
		cout << "0"; return 0;
	}
	
	cout << num[0];	
	return 0;
}

//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	string str;
//
//	int tmp = 1, sum = 0;
//	bool wrong = false;
//	cin >> str;
//	
//	for (int i = 0; str[i]; i++) {
//		if (str[i] == '(') {
//		  tmp *= 2;
//		  st.push('(');
//		} 
//		else if (str[i] == '[') {
//		  tmp *= 3;
//		  st.push('[');
//		} 
//		else if (str[i] == ')') {
//		  if (str[i - 1] == '(') sum += tmp;
//		  if (st.empty()) {
//		    wrong = true;
//		    break;
//		  }
//		  if (st.top() == '(') st.pop();
//		  tmp /= 2;
//		} 
//		else {
//		  if (str[i - 1] == '[') sum += tmp;
//		  if (st.empty()) {
//		    wrong = true;
//		    break;
//		  }
//		  if (st.top() == '[') st.pop();
//		  tmp /= 3;
//		}
//	}
//	if (wrong || !st.empty()) cout << 0;
//	else cout << sum;
//
//
//	return 0;
//}
