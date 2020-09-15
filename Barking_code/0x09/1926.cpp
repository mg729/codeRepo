#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
int board[502][502]; // 1이 색칠된부분,  0이 색칠안 된 부분 
bool vis[502][502];
int n;
int m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

queue<pair<int,int> > q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m ; j++) {
			cin >> board[i][j];
		}
	}
	int picNum = 0;
	int maxCount = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m ; j++) {
			if(!board[i][j]) continue;
			if(board[i][j] && !vis[i][j]) {
				q.push({i,j});
				picNum++;
			}
			int picCount = 0;
			while(!q.empty()) {
				pair<int,int> cur = q.front();
				q.pop();
				for(int dir = 0; dir <4; dir++) {
					int nx = cur.x + dx[dir];
					int ny = cur.y + dy[dir];
					if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
					if(vis[nx][ny] || !board[nx][ny]) continue;
					picCount++;
					vis[nx][ny] = 1;
					q.push({nx,ny});
				}
				
			}
			
			maxCount = max(maxCount, picCount);
			picCount = 0;
		}
	}
	
	cout << picNum << '\n' << maxCount;
	
	return 0;
}
