#include <bits/stdc++.h>
/**
* 1. stoi() 
* 2. char -> int 
* 3. to_string()
* 4. string :: find()
* 5. string :: substr()
* 6. strtok() 
*/
using namespace std;

deque<int> dq;
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
		int x = 0;
		for(int i =0 ; i <arr.size(); i++) {
			if(arr[i] == '[')
				continue;
			else if('0' <= arr[i] && '9' >= arr[i]) {
				x = x*10 + (int)(arr[i]-'0');
			}
			else if(arr[i] == ',' || arr[i] == ']'){
				if(x > 0)
					dq.push_back(x);
				x = 0;
			}				
		}
		
		bool isError = false;
		bool isReverse = false;
		while(allOrder.size() > 0) {
			char order = allOrder.front();
			if(order == 'R') 
				isReverse = !isReverse;
			else if(order == 'D') {
				if(dq.empty()) {
					isError = true;
					break;
				}
				else {
					if(isReverse)
						dq.pop_back();
					else 
						dq.pop_front();
				}
			}
			allOrder.pop_front();
		}
		
		// print out the result
		if(isError) 
			cout <<"error\n";
		else if(dq.empty()) 
	   	    cout << "[]\n";
		else if(!isReverse) {
			cout << "[";
			while(dq.size() > 1) {
				cout << dq.front() << ",";
				dq.pop_front(); 
			}
			cout << dq.front() << "]\n";		
			
		}
		else {
			cout << "[";
			while(dq.size() > 1) {
				cout << dq.back() << ",";
				dq.pop_back(); 
			}
			cout << dq.back() << "]\n";		
		}
		
		//should clear up all container for each test cases
		dq.clear();
		allOrder.clear();
	}
	
	return 0;
	
}
