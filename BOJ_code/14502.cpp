#include<bits/stdc++.h>

using namespace std;
int board[8][8];
int temp[8][8];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n, m ,area;

void make_wall (int wall);
void bfs();

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> board[i][j];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m ; j++) {
			if(board[i][j] == 0) {
				for(int i = 0; i < n; i++)
					for(int j = 0; j < m; j++)
						temp[i][j] = board[i][j];
						
				temp[i][j] = 1;
				make_wall(1);
				temp[i][j] = 0;
			}
		}
	}
	cout << area;
	return 0;
}

void make_wall(int wall) {
	if(wall == 3) {
		bfs();
		return;
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m ; j++) {	
			if(temp[i][j] == 0)
			{
				temp[i][j] = 1;
				make_wall(wall+1);
				temp[i][j] = 0;
			}
		} 
	}	
}

void bfs() {
	int virus[8][8];
	
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < m ; j++) 
			virus[i][j] = temp[i][j];
	
	queue <pair<int,int> > q;
	
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < m ; j++) 
			if (virus[i][j] == 2)
				q.push({i,j});
	
	while(!q.empty()) {
		auto cur = q.front();
		q.pop();
		for(int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if(virus[nx][ny] == 0)  {
				virus[nx][ny] = 2;
				q.push({nx,ny}); 
			}			
		}
	}
	
	int cnt = 0;
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < m ; j++) 
			if(virus[i][j] == 0)
				cnt++;
	
	area = max(area, cnt);
	 
}





