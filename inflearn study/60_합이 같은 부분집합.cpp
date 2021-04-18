#include<bits/stdc++.h>
using namespace std;

int n, val;
int sumArr[58];
vector<int> v;
bool isEqualSum; // false

void dfs(int x) {
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);
	
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> val;
		v.push_back(val);
	}
	
	dfs(n);
	
	if(isEqualSum) cout << "YES";
	else cout << "NO";
	
	return 0;
}