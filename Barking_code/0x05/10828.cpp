#include<bits/stdc++.h>
using namespace std;

stack<int> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	
	while(tc) {
		string order;
		cin >> order;
		
		// cf )) cannot use switch for below code
		/**
		C/C++ doesn't really support strings as a type.
		Cannot use string in either switch or case.
		*/
		if( order == "push" ) {
			int x;
			cin >> x;
			
			s.push(x);
		}
		else if ( order == "pop" ) {
			if(!s.empty()) {
				cout << s.top() <<'\n';
				s.pop();
			}
			else
				cout << "-1" <<'\n';
		}
		else if ( order == "size" ) {
			cout << s.size() <<'\n';
		}
		else if ( order == "empty" ) {
			if(!s.empty())
				cout << "0" <<'\n';
			else
				cout << "1" <<'\n';
		}
		else if ( order == "top" ) {
			if(!s.empty())
				cout << s.top() <<'\n';
			else
				cout << "-1" <<'\n';
		}
		
		
		--tc;
	}
	return 0;
}
