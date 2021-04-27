#include<bits/stdc++.h>
using namespace std;

int val, cnt;
int arr[9][9];
int check[9][9];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void dfs(int x, int y) {
	if(x == 7 && y == 7) {
		cnt++;
	}
	else {
		for(int i = 0; i< 4; i++) {
			int curX = x + dx[i];
			int curY = y + dy[i];
			if(curX < 1 || curX > 7 || curY < 1 || curY > 7) continue;
			if(arr[curX][curY] == 0 && check[curX][curY] == 0) {
				check[curX][curY] = 1;
				dfs(curX, curY);
				check[curX][curY] = 0;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			arr[i][j] = 1;	
		}
	}

	for(int i = 1; i <= 7; i++) {
		for(int j = 1; j <=7; j++) {
			cin >> val;
			arr[i][j] = val;
		}
	}
	
	check[1][1] = 1;
	dfs(1, 1);
	cout << cnt;

	return 0;
}