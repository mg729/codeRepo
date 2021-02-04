#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;
		v.push_back(val);
	}
	sort(v.begin(), v.end());
	
	//binary search
	int pivot = v.size();
	
	while(1) {
		if(v[pivot] == m) break;
		else if(v[pivot] < m) {
			pivot *= 2;
		}
		else {
			if(pivot / 2 == 0 ) pivot = pivot / 2 - 1;
			else pivot = pivot / 2;
		}
	}
	cout << pivot + 1;
	return 0;
}