#include<bits/stdc++.h>
using namespace std;

int n, m, h, w, sum;
int arr[702][702];
int board[702][702];

int maxVal;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//	freopen("input.txt", "rt", stdin);
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m ; j++) {
			int val;
			cin >> val;
			arr[i][j] = val;
		}
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m ; j++) {
			board[i][j] = board[i][j-1] + board[i-1][j] - board[i-1][j-1] + arr[i][j]; 
		}
	}
	
	cin >> h >> w;
	for(int i = h; i <= n; i++) { // *** i is start with h
		for(int j = w; j <= m; j++) { // *** j is start with w
			int tmp = 0;
			tmp = board[i][j] - board[i][j-w] - board[i-h][j] + board[i-h][j-w];
			
			if(tmp > maxVal) maxVal = tmp;
		}
	}
	
	cout << maxVal;
	
	return 0;
}