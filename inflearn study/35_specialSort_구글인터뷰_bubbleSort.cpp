#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);
	cin >> n;
	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;
		v.push_back(val);
	}
	
	for(int i = 0; i < n-1; i++) {
		for(int j = 0; j < n-i-1 ; j++) {
			if(v[j] > 0 &&  v[j+1] < 0) {
				int tmp = v[j];
				v[j] = v[j+1];
				v[j+1] = tmp;	
			}
		}
	}
	
	for(auto x : v) cout << x <<" ";

	return 0;
}