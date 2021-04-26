#include<bits/stdc++.h>
using namespace std;

int n, m, cnt;
int matrix[22][22];
int check[22];
int pathArr[22];

void dfs(int level, int path) {
	if(level == n) {
		for(int i = 0; i < path; i++) {
			cout << pathArr[i] << " ";
		}
		cout << endl;
		cnt++;
		return;
	}
	
	for(int i = 1; i <= n; i++) {
		if(matrix[level][i] && check[i] == 0) {
			check[i] = 1;
			pathArr[path] = i;
			dfs(i, path+1);
			check[i] = 0;
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);
	
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int v1, v2; // vertex
		cin >> v1 >> v2;
		matrix[v1][v2] = 1;
	}

	check[1] = 1;
	pathArr[0] = 1;
	dfs(1, 1);
	cout << cnt;

	return 0;
}