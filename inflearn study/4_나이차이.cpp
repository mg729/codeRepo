#include<bits/stdc++.h>

using namespace std;
int n;
vector <int> v;
 
int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
    //freopen("input.txt", "rt", stdin); // rt : read mode
	
	cin >> n;
    for(int i = 0; i < n; i++) {
		int val;
		cin>> val;
		v.push_back(val);
	}
	
	int minVal = v[0];
	int maxVal = v[0];
	for(auto x : v) {
		minVal = min(minVal, x);
		maxVal = max(maxVal, x);
	}
	cout << maxVal - minVal;
	
	
	return 0;
}