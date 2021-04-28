#include<bits/stdc++.h>
using namespace std;

int n, m, cnt;
vector<int> linkedList[22];
int check[22];

void dfs(int vertex) {
	if(vertex >= n) {
		cnt++;
		return;
	}
	for(int i = 0; i < linkedList[vertex].size(); i++) {
		int idx = linkedList[vertex][i];
		if(check[idx] == 0) {
			check[idx] = 1;
			dfs(idx);
			check[idx] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int node1, node2;
		cin >> node1 >> node2;
		linkedList[node1].push_back(node2);
	}
	check[1] = 1;
	dfs(1);
	cout << cnt;

	return 0;
}