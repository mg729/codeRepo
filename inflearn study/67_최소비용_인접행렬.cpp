#include<bits/stdc++.h>
using namespace std;

int n, m, weight;
int arr[22][22];
int check[22];
int minVal = 2147000000; //need to check the minimum value of the int type
int sum;

void dfs(int node, int sum) {
	// if(node == n) {
	// 	minVal = min(minVal, sum);
	// 	return;
	// }
	if(node == n) {
		if(sum < minVal) minVal = sum;
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(arr[node][i] && check[i] == 0) {
			check[i] = 1;
			dfs(i, sum + arr[node][i]);
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
		int node1, node2;
		cin >> node1 >> node2 >> weight;
		arr[node1][node2] = weight;
	}
	
	check[1] = 1;
	dfs(1, 0);
	cout << minVal;

	return 0;
}

// #include<bits/stdc++.h>
// using namespace std;

// int n, m, weight;
// int arr[22][22];
// int check[22];
// int minVal = 2147000000; //need to check the minimum value of the int type
// int sum;

// void dfs(int node) {
// 	if(node == n) {
// 		minVal = min(minVal, sum);
// 		return;
// 	}
// 	for(int i = 1; i <= n; i++) {
// 		if(arr[node][i] && check[i] == 0) {
// 			check[i] = 1;
// 			sum += arr[node][i];
// 			dfs(i);
// 			sum -= arr[node][i];
// 			check[i] = 0;			
// 		}
// 	}
// }

// int main() {
// 	ios::sync_with_stdio(false);
// 	cin.tie(nullptr);
// //	freopen("input.txt", "rt", stdin);
	
// 	cin >> n >> m;
// 	for(int i = 1; i <= m; i++) {
// 		int node1, node2;
// 		cin >> node1 >> node2 >> weight;
// 		arr[node1][node2] = weight;
// 	}
	
// 	check[1] = 1;
// 	dfs(1);
// 	cout << minVal;

// 	return 0;
// }