#include<bits/stdc++.h>
using namespace std;

int n, m;
int matrix[22][22];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);
	
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int vertex1, vertex2;
		cin >> vertex1 >> vertex2;
		int edge;
		cin >> edge;
		matrix[vertex1][vertex2] = edge;
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <=n; j++) {
			cout << matrix[i][j] <<" ";
		}
		cout << "\n";
	}

	return 0;
}