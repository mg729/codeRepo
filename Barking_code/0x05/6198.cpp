#include <bits/stdc++.h>
using namespace std;
stack<long long> st;
long long sum;
int main() {	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	
	for(int i = 0; i < tc; i++) {
		int val;
		cin >> val;
		
		while(!st.empty()) {
			if(val < st.top()) {
				sum += st.size();
				break;
			}
			else
				st.pop();
		}
		
		st.push(val);
		
	}
	
	cout << sum;
	
	return 0;
}
