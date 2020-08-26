#include<bits/stdc++.h>

using namespace std;
vector<int> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int minVal = -1;
	
	for(int i = 0; i < 7; i++) {
		int val;
		cin >> val;
		
		if(val%2 != 0)
			v.push_back(val);
	}
	
	if(!v.empty()) {
		int sum = 0;
		minVal = v[0];
		for(int i = 1; i < v.size(); i++) {
			minVal = min (minVal, v[i]);
		}
		for(auto x : v) 
			sum += x;
		
		cout << sum <<'\n';		
	}
	
	cout << minVal;

	return 0;
}
