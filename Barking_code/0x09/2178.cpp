#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second

int board[102][102];
bool vis[102][102];
int dist[102][102];
int n;
int m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	//*** need to check input data format
	/**
	- whether there are space between input data
	*/ 
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m ; j++) {
			char c;
			cin >> c;
			int val = c - '0';
			board[i][j] = val;
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(!board[i][j] || vis[i][j]) continue;
			queue <pair<int,int> > q;
			q.push({i,j});
			vis[i][j] = 1;
			
			while(!q.empty()) {
				pair<int,int> cur = q.front();
				q.pop();
				
				for(int dir = 0; dir < 4; dir++) {
					int nx = cur.x + dx[dir];
					int ny = cur.y + dy[dir];
					
					if(nx < 0 || nx >= n || ny < 0 || ny >=m) continue;
					if(vis[nx][ny] || !board[nx][ny]) continue;
					vis[nx][ny] = 1;
					dist[nx][ny] = dist[cur.x][cur.y] + 1;
					
					q.push({nx,ny});
				}
				
			}
		}
	}
	
	cout << dist[n-1][m-1] + 1;
	
	return 0;
}
