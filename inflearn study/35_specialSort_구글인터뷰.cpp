#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> nv;
vector<int> pv;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		int val;
		cin>> val;
		if(val < 0) {
			nv.push_back(val);
		}
		else {
			pv.push_back(val);
		}
	}
	
	for(auto x : nv) cout << x << " ";
	for(auto x : pv) cout << x << " ";

	return 0;
}