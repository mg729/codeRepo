#include<bits/stdc++.h>
using namespace std;

int n, m, val, cnt;
int arr[12];
int path[12];

void dfs (int level, int sum) {
	if(level > n) {
		if(sum == m) {
			for(int i = 1; i < level; i++) cout << path[i]  << " ";
			cout << "\n";
			cnt++;
		}
		return;
	}
	path[level] = arr[level];
	dfs(level + 1, sum + arr[level]);
	path[level] = 0;
	dfs(level + 1, sum);
	path[level] = -(arr[level]);
	dfs(level + 1, sum - arr[level]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> val;
		arr[i] = val;
	}
	
	dfs(1, 0);
	if(cnt != 0) cout << cnt;
	else cout << "-1";
	
	return 0;
}