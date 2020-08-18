#include<bits/stdc++.h>
using namespace std;

stack<int> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	
	while(tc) {
		
		int val;
		cin >> val;
		
		if(val == 0)
			s.pop();
		else
			s.push(val);
		
		--tc;
	}
	/**
	using operator[] on a std::stack is not desirable
	You should use the .top() method to check what's on top of the stack, not indexing.
	*/
	int sum = 0;
	while(!s.empty()){
		sum += s.top();
		s.pop();
	}
	
	cout << sum;
	return 0;
	
}
