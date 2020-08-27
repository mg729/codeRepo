#include<bits/stdc++.h>

using namespace std;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	for(int i = 0; i < 5; i++) {
		int val;
		cin >> val;
		v.push_back(val);
	}
	
	int avgVal = 0;
	for(int i = 0; i < 5; i++) {
		avgVal += v[i];
	}
	sort(v.begin(), v.end());
	
	
	cout << avgVal/5 << '\n';
	cout << v[2];
	
	return 0;
}
