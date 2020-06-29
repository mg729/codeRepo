/*
실제 문제 출제와 난이도 비슷한 문제
두시간을 잡아두고 문제 풀이진행
바이러스가 퍼지는 모양이 BFS (상하좌우로 바이러스가 퍼지는 경우 BFS)
- 바이러스가 존재하는 칸을 큐에 insert
- 그 칸과 상하좌우 인접한 칸을 2로 바꾸면서 큐에 insert
- 반복

*/

#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

//상하 좌우를 위한 dx,dy
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };

int inputMap[8][8];
int tempMap[8][8];
int n, m;
int ans = 0;



//지도 복사 
// 두개의 map을 input으로 받아서 a에 복사하는 것
void copyMap(int a[8][8], int b[8][8]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = b[i][j];
		}
	}
}

//바이러스 퍼트리기(BFS)
void BFSforVirus() {
	//AfterSpreadMap은 3개의 벽을 세운 후 바이러스가 퍼졌을 때의 연구소의 상황을 저장하는곳.
	int AfterSpreadMap[8][8];
	copyMap(AfterSpreadMap, tempMap);
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (AfterSpreadMap[i][j] == 2)
				q.push(make_pair(i, j));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int newX = x + dx[i];
			int newY = y + dy[i];
			// 감염되지 않은 영역만 선택
			if (0 <= newX && newX<n && 0 <= newY && newY<m) {
				if (AfterSpreadMap[newX][newY] == 0) {
					AfterSpreadMap[newX][newY] = 2;
					q.push(make_pair(newX, newY));
				}
			}
		}
	}
	//연구소에 오염되지 않은 부분 체크.
	//2로바뀌지않고 0으로 남아있는부분 개수 체크
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (AfterSpreadMap[i][j] == 0)
				cnt++;
		}
	}
	ans = max(ans, cnt);
}

// 벽을 세우는 재귀 함수 
void recursiveWall(int cnt) {
	// 종료 부, 바이러스를 퍼트려서 오염되지 않은 부분의 갯수를 확인한다.
	if (cnt == 3) { //벽의 개수가 3일때 종료
		BFSforVirus();
		return;
	}
	//벽 세우는 부분.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tempMap[i][j] == 0) {
				tempMap[i][j] = 1; // 해결 부, 실제로 벽을 세우는 부분
				recursiveWall(cnt + 1); // 분할 부, cnt를 ++ 시켜 벽을 세워야하는 갯수를 -1 시키면서 문제를 분할. -> 재귀함수 호출		 		
				tempMap[i][j] = 0;
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &inputMap[i][j]);
		}
	}
	//연구소에서 0인 부분을 모두 벽을 세워야 하므로 다음과 같이 진행.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (inputMap[i][j] == 0) {
				copyMap(tempMap, inputMap); //input 데이터가 바뀌면안되니까 tempMap을 만들어놓음
				tempMap[i][j] = 1;
				recursiveWall(1);
				tempMap[i][j] = 0;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}