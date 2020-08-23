#include <bits/stdc++.h>
/**
* 1. stoi() 
* 2. char -> int 
* 3. to_string()
*/
using namespace std;

deque<int> dq;
deque<int> ans;
deque<char> allOrder;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin>> tc;
	
	for(int t = 0; t < tc; t++) {
		string str;
		cin >> str;
		for(auto x : str)
			allOrder.push_back(x);
		
		int n;
		cin >> n;
		
		string arr;
		cin >> arr;
		
		string allString;
		for(int i = 0; i < arr.size(); i++) {
			if(arr[i] != '[' && arr[i] != ',' && arr[i] != ']') {
				while(arr[i] != ',' &&  arr[i] != ']') {
					allString += arr[i];
					++i;
				}
				int val = stoi(allString);
				dq.push_back(val);
				allString.clear();
			}
		}
			
		while(true) {
			if(allOrder.empty()) 
				break;
			
			char order = allOrder[0];
			if(order == 'R') {
				if(!dq.empty()) {
					if(!ans.empty()) {
						ans.clear();
					}
					// swap the contents by reversing 
					for(int i = dq.size()-1; i >=0; i--) {
						ans.push_back(dq[i]);
					}
					dq.clear();
					dq = ans;
				}
			}
			else if(order == 'D') {
				if(dq.empty()) {
					cout << "error\n";
					break;
				}
				else
					dq.pop_front();
			}
			allOrder.pop_front();

		}
		
		if(!dq. empty()) {
			cout << "[";
			for(int i = 0; i < dq.size() -1; i++) {
				cout << dq[i] << ","; 
			}
			cout << dq[dq.size() -1] << "]";	
			
			cout << '\n';		
		}
		dq.clear();
		ans.clear();
		allOrder.clear();
	}
	
	return 0;
	
}
