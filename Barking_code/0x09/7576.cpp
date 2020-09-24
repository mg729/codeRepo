#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
int board[1002][1002]; // ***bool is 1 byte data type
int n, m;
int dist[1002][1002];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> m >> n;
	
	queue<pair<int,int> > q;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> board[i][j];
			if(board[i][j] == 1) 
				q.push({i,j});
			if(board[i][j] == 0)  // if
				dist[i][j] = -1;
		}
	}

	while(!q.empty()) {
		pair<int,int> cur = q.front();
		q.pop();
		
		for(int dir = 0 ; dir < 4; dir++) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			if(nx < 0 || nx >=n || ny < 0 || ny >= m) continue;
			if(dist[nx][ny] >= 0|| board[nx][ny] == -1) continue;
			dist[nx][ny] = dist[cur.x][cur.y] + 1;					
			q.push({nx,ny});
		}
	}

	int days = 0; //int days = -1 : error	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(dist[i][j] == -1) {
				cout << -1;
				return 0;
			}
			days = max(dist[i][j], days);
		}
	}
	
	cout << days;
	return 0;
}



/*#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
int board[1002][1002]; // ***bool is 1 byte data type
int n, m;
int dist[1002][1002];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> m >> n;
	
	queue<pair<int,int> > q;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> board[i][j];
			if(board[i][j] == 1) {
				q.push({i,j});
				dist[i][j] = 0;
			}
			if(board[i][j] == -1)
				dist[i][j] = -1;
		}
	}

	while(!q.empty()) {
		pair<int,int> cur = q.front();
		q.pop();
		
		for(int dir = 0 ; dir < 4; dir++) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			if(nx < 0 || nx >=n || ny < 0 || ny >= m) continue;
			if(dist[nx][ny] >= 1|| board[nx][ny] == -1) continue;
			dist[nx][ny] = dist[cur.x][cur.y] + 1;					
			q.push({nx,ny});
		}
	}

	int days = 0; //int days = -1 : error	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(dist[i][j] == -2) {
				cout << "-1";
				return 0;
			}
			days = max(dist[i][j], days);
		}
	}
	
	cout << days;
	return 0;
}
**/
/**
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
*/

