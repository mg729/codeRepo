#include<bits/stdc++.h>
using namespace std;

int n, tmp;
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
	
	for(int i = 1; i < n ; i++) {
		tmp = v[i];
		int j;
		for(j = i-1; j >= 0 ; j--) {
			if(v[j] > tmp)  v[j+1] = v[j];
			else break;
		}
		v[j+1] = tmp;
	}
	
	for(auto x : v) cout << x <<" ";

	return 0;
}