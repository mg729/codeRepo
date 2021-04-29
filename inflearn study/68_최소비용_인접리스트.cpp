#include<bits/stdc++.h>
#define X first
#define Y second

using namespace std;

int n, m, weight;
vector<pair<int,int> > linkedList[22];
int check[22];
int minVal = 2147000000;
int sum;

void dfs(int node, int sum) {
	if(node == n) {
		if(sum < minVal) minVal = sum;
		return;
	}
	for(int i = 0; i < linkedList[node].size(); i++) {
		int edge = linkedList[node][i].X;
		if(check[edge] == 0) {
			check[edge] = 1;
			dfs(edge, sum + linkedList[node][i].Y);
			check[edge] = 0;			
		}
	}
}

// void dfs(int node) {
// 	if(node == n) {
// 		minVal = min(minVal, sum);
// 		return;
// 	}
// 	for(int i = 0; i < linkedList[node].size(); i++) {
// 		int edge = linkedList[node][i].first;
// 		if(check[edge] == 0) {
// 			check[edge] = 1;
// 			sum += linkedList[node][i].second;
// 			dfs(edge);
// 			sum -= linkedList[node][i].second;
// 			check[edge] = 0;			
// 		}
// 	}
// }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int node1, node2;
		cin >> node1 >> node2 >> weight;
		linkedList[node1].push_back({node2, weight});
	}
	
	check[1] = 1;
	dfs(1, 0);
	cout << minVal;

	return 0;
}
