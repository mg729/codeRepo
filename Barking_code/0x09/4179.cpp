#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second

string board[1002];

int fire[1002][1002];
int steps[1002][1002]; 
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int r,c;
	cin >> r >> c;
	
	queue <pair<int, int> > q_fire;
	queue <pair<int, int> > q_steps;
	
	for(int i = 0; i < r; i++) {
		cin >> board[i];
	}
	for(int i = 0;i < r; i++) {
		fill(fire[i],fire[i]+c, -1);
		fill(steps[i],steps[i]+c, -1);
	}
	
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			if(board[i][j] == 'F') { // string board one dimension can be accessed two dimension char[][] type
				q_fire.push({i,j});
				fire[i][j] = 0;
			}
			else if(board[i][j] == 'J') {
				q_steps.push({i,j});
				steps[i][j] = 0;
			}
		}
	}
	
	// BFS - fire
	while(!q_fire.empty()) {
		pair<int, int> cur = q_fire.front();
		q_fire.pop();
		
		for(int dir = 0; dir < 4; dir++) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];

			if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;  // ** >= r , >= c  do not forget equal condition
			if(board[nx][ny] == '#' || fire[nx][ny] >= 0 ) continue;
			
			fire[nx][ny] = fire[cur.x][cur.y] + 1;
			q_fire.push({nx,ny});
		}
	}
	
	// BFS - move steps
	while(!q_steps.empty()) {
		auto cur = q_steps.front();
		q_steps.pop();
		
		for(int dir = 0; dir < 4; dir++) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];

			if(nx < 0 || nx >= r || ny < 0 || ny >= c) { // if out of range -> succeded to escape
				cout << steps[cur.x][cur.y] + 1;
				return 0;
			}
			if(board[nx][ny] == '#' || steps[nx][ny] >= 0 ) continue;
//			if(steps[nx][ny] >= fire[nx][ny] && fire[nx][ny] != -1) continue;  ***!!! 
			if(steps[cur.x][cur.y] + 1 >= fire[nx][ny] && fire[nx][ny] != -1) continue;
			steps[nx][ny] = steps[cur.x][cur.y] + 1;
			q_steps.push({nx,ny});
		}
	}

	cout << "IMPOSSIBLE";

	return 0;
}
