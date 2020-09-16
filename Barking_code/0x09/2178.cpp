#include<bits/stdc++.h>

using namespace std;

#define x first
#define y second

//int board[102][102];
string board[102];
int dist[102][102];
int n;
int m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//*** need to check input data format
	/**
	- whether there are space between input data
	*/ 
//	for(int i = 0; i < n; i++) {
//		for(int j = 0; j < m ; j++) {
//			char c;
//			cin >> c;
//			int val = c - '0';
//			board[i][j] = val;
//		}
//	}
	
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		cin >> board[i];
	for(int i = 0; i < n; i++)
		fill(dist[i], dist[i]+m, -1);

	queue <pair<int,int> > q;
	q.push({0,0});
	dist[0][0] = 0;
	while(!q.empty()) {
		pair<int,int> cur = q.front();
		q.pop();
		
		for(int dir = 0; dir < 4; dir++) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			
			if(nx < 0 || nx >= n || ny < 0 || ny >=m) continue;
			if(dist[nx][ny] >=0 || board[nx][ny] != '1' ) continue;  // ***board  is string type but can accessed by 2 dimension char type 
			dist[nx][ny] = dist[cur.x][cur.y] + 1;
			
			q.push({nx,ny});
		}
		
	}
	cout << dist[n-1][m-1] + 1;
	
	return 0;
}
