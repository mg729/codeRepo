#include<bits/stdc++.h>
using namespace std;

int n, m, edge;
vector<int> linkedList[22];
queue<int> q;
int check[22];
int dis[22];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);
	
	cin >> n >> m;
	for(int i = 1; i <=m; i++) {
		int node1, node2;
		cin >> node1 >> node2;
		linkedList[node1].push_back(node2);
	}
	
	check[1] = 1;
	q.push(1);
	while(!q.empty()) {
		int frontVal = q.front();
		for(int i = 0; i < linkedList[frontVal].size(); i++) {
			int node = linkedList[frontVal][i];
			if(check[node] == 0) {	
				check[node] = 1;
				q.push(node);
				dis[node] = dis[frontVal] + 1;
			}
		}
		q.pop();		
	}
	
	for(int i = 2; i <= n; i++) {
		cout << i << " : " << dis[i] << "\n";
	}
	return 0;
}
