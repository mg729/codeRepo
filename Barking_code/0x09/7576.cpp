#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second
int board[1002][1002]; // ***bool is 1 byte data type
int n, m;
int vis[1002][1002];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> m >> n;
	int days = -1;
	
	queue<pair<int,int> > q;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> board[i][j];
			if(board[i][j] == 1) {
				q.push({i,j});
				vis[i][j] = 1;
			}
		}
	}
		
	while(!q.empty()) {
		pair<int,int> cur = q.front();
		q.pop();
		days++;
		cout << "#:  " << cur.x << " " << cur.y << endl;
		for(int dir = 0 ; dir < 4; dir++) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			if(nx < 0 || nx >=n || ny < 0 || ny >= m) continue;
			if(vis[nx][ny] == 1|| board[nx][ny] == -1) continue;
			cout << nx << " " << ny << endl;
			vis[nx][ny] = 1;					
			
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(vis[i][j] == 0){
				cout << "!!!-1!!!";
				return 0;
			}
			
		}
	}
	int maxdays= 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			maxdays = (maxdays, vis[i][j]);
		}
	}
	cout << maxdays;
	return 0;
}

