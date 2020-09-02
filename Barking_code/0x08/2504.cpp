#include<bits/stdc++.h>
//https://chocodrogba.tistory.com/9
using namespace std;

stack<char> str;
stack<int> num;
stack<int> tempN;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string brt; //bracket
	cin >> brt;
	
	int sum = 0;
	int temp = 0;
	for (int i = 0; brt[i]; i++) {
		switch(brt[i]) {
			case '(' : {	
				str.push(brt[i]);
				break;
			}
			case '[' : {
				str.push(brt[i]);				
				break;
			}
			case ')' : {
				if(str.empty()){
						cout << __LINE__ <<endl;
					cout << "0";
					return 0;
				}
				
//				while(str.size() > 1) {
					char tempC = str.top();
					str.pop();
					
					if(i!=0 && brt[i-1] == '(') {
						tempN.push(2);
						temp = 0;
					}
					else if (tempC == '(') {
						tempN.push(2*temp);
					}
					
					if(temp == 0)
						temp = tempN.top();
					else {
//						while(!tempN.empty()) {
//							temp += tempN.top();
//							tempN.pop();
//						}
						temp = tempN.top();
					}
//				}
				cout << "# " << i << ": " << temp << endl;
				num.push(temp);
				
				break;
			}
//			case ']' : {
//				if(str.empty()){
//					cout << "0";
//					return 0;
//				}
//				
//				if( i!=0 && brt[i-1] == '[' ) {
//					num.push(3);
//					str.pop();
//				}
//				else {
//					while(str.top() != '[') {
//						tempN.push(num.top());
//						num.pop();
//					}
//					
//					if(tempS.size() == 1) {
//						num.push(tempN.top() * 3);
//						tempN.pop();
//					}
//					else {
//						int temp = 0;
//						while(!tempN.empty()) {
//							temp += tempN.top();
//							tempN.pop();
//						}
//						num.push(temp * 3);						
//					}
//				}
//				break;
//			}
			default: {
				cout << __LINE__ <<endl;
				cout << "0";
				return 0;
				break;
			}
			
		}
	}
	
	if(!str.empty()) {
		cout << __LINE__ <<endl;
		cout << "0";
		return 0;
	}
		
	while (!num.empty()) {
		int val = num.top();
		sum += val;
		num.pop();
	}
		cout << __LINE__ <<endl;
	cout << sum;	
	
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
