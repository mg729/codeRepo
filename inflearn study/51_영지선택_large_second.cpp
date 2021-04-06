#include<bits/stdc++.h>
using namespace std;

int n, m, val;
int x, y;
int arr[702][702];
int res[702][702];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//	freopen("input.txt", "rt", stdin);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> val;
			arr[i][j] = val;
		}
	}
	cin >> x >> y;
	int maxVal = -1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m ; j++) {
			res[i][j] = res[i-1][j]
					  + res[i][j-1]
					  - res[i-1][j-1]
					  + arr[i][j];
					  
			if(i >= x && j >= y) {
				maxVal = max(maxVal, res[i][j] - res[i-x][j] - res[i][j-y] + res[i-x][j-y]);
			}
		}
	}
	
	cout << maxVal;
	return 0;
}
