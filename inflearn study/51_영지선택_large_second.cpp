#include<bits/stdc++.h>
using namespace std;

int n, m, val;
int x, y;
int arr[702][702];
int res[702][702];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("input.txt", "rt", stdin);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> val;
			arr[i][j] = val;
		}
	}
	cin >> x >> y;
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j<=m ; j++) {
			cout << arr[i][j] <<" ";
		}
		cout << endl;
	}
	int maxVal = -1;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m ; j++) {
			res[i][j] = res[i-1][j]
					  + res[i][j-1]
					  - res[i-1][j-1]
					  + arr[i][j];
			maxVal = max(maxVal, res[i][j]);
		}
	}
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j<=m ; j++) {
			cout << res[i][j] <<" ";
		}
		cout << endl;
	}
	cout << maxVal;
	return 0;
}
