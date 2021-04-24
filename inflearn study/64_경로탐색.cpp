#include<bits/stdc++.h>
using namespace std;

int n, m, cnt;
int matrix[22][22];

void dfs(int level) {
	if(level >= n) {
		cnt++;
		return;
	}
	
	// How to search 4 -> 2 -> 5 route???? 
	for(int i = 1; level + i <= n; i++) {
		if(matrix[level][level+i]) {
			cout << level << " ";
			dfs(level+i);	
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int v1, v2; // vertex
		cin >> v1 >> v2;
		matrix[v1][v2] = 1;
	}
	
	dfs(1);
	cout << cnt;

	return 0;
}
