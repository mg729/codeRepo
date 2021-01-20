#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;
		v.push_back(val);
	}
	
	sort(v.begin(), v.end());
	
	for(auto x : v) {
		cout << x << " ";
	}
    
	return 0;
}