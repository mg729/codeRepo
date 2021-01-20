#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	cin >> n;
	
	for(int i = 0; i< n; i++) {
		int val;
		cin >> val;
		v.push_back(val);
	}
	
	for(int i = 0; i < n-1; i++) {
		int idx = i;
		for(int j = i+1; j < n; j++) {
			if(v[j]<v[idx]) idx = j;
		}
		int tmp = v[idx];
		v[idx] = v[i];
		v[i] = tmp;
	}
	
	for(auto x : v) cout << x;
	
	return 0;
}