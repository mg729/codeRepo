#include<bits/stdc++.h>
using namespace std;

int n, m, val;
vector<int> a;
vector<int> b;
vector<int> res;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("input.txt", "rt", stdin);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> val;
		a.push_back(val);
	}
	sort(a.begin(), a.end());
	cin >> m;
	for(int i = 0; i < m; i++) {
		cin >> val;
		b.push_back(val);
	}
	sort(b.begin(), b.end());
	
	int idxA = 0;
	int idxB = 0;
	while(idxA < n && idxB < m) {
		if(a[idxA] == b[idxB]) {
			res.push_back(a[idxA]);
			idxA++;
			idxB++;
		}
		else if (a[idxA] < b[idxB] ){
			idxA++;
		}
		else if (a[idxA] > b[idxB]) {
			idxB++;
		}
	}
	for(auto x : res) cout << x << " ";



	return 0;
}