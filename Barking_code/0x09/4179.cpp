#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
string board[1002];

int dist[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int r,c;
	cin >> r >> c;
	
	queue <pair<int, int> > q;
	
	for(int i = 0; i < r; i++) {
		cin >> board[i];
	}
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			if(board[i][j] == 'J') 
				q.push({i,j});
		}
	}
	int min = 0;
	while(!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		
		for(int dir = 0; dir < 4; dir++) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			
			if(board[nx][ny] == 'F') {
				min = dist[cur.x][cur.y];
				break;
			}
			if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;  // ** >= r , >= c  do not forget equal condition
			if(board[nx][ny] == '#' || dist[nx][ny] ) continue;
			
			dist[nx][ny] = dist[cur.x][cur.y] + 1;
			q.push({nx,ny});
		}
	}
	if()
	
	return 0;
}
