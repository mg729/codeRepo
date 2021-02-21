#include<bits/stdc++.h>
using namespace std;

int n, cnt;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("input.txt", "rt", stdin);
	cin >> n;
	vector<vector<int> > map(n+2, vector<int>(n+2)); 
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			int val;
			cin >> val;
			map[i][j] = val;
		}
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			bool isTop = true;
			for(int dir= 0; dir < 4; dir++) {
				if(map[i+dx[dir]][j+dy[dir]] > map[i][j]) {
					isTop = false;
					break;
				}
			}
			if(isTop) cnt++;
		}
	}

	cout << cnt;
	
	return 0;
}

