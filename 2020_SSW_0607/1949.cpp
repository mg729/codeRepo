#include <iostream>
#include <algorithm>
using namespace std;

//dx[] dy[] 는 delta x, y라고해서 상하 좌우 원소이동을 의미
// 0    1   : 오른쪽으로 한칸
// 0   -1   : 왼쪽으로 한 칸
// 1    0   : 위로 한 칸
//-1    0   : 아래로 한 칸
int dx[] = { 0,0,1,-1 };  
int dy[] = { 1,-1,0,0 };

int t, n, k, res;
int input[9][9];
bool visit[9][9];

// cnt : 현재 몇 개 까지의 노드를 지나쳤는지
// flag : 이미 공사를 진행했는지 아닌지에대한 여부
void dfs(int x, int y, int cnt, int flag) {
	visit[x][y] = true;
	if (res < cnt) res = cnt;  //res 현재까지 방문한 최도 노드 개수

	for (int i = 0; i < 4; i++) {
		int ax = x + dx[i];
		int ay = y + dy[i];

		//방문했거나 범위 벗어나면 continue
		if (ax == 0 || ay == 0 || ax == n + 1 || ay == n + 1 || visit[ax][ay]) continue;

		//내리막길인 경우
		if (input[x][y] > input[ax][ay]) {
			dfs(ax, ay, cnt + 1, flag);  //방문횟수를 하나 증가 cnt+1
		}
		//내리막길이 아닌 경우
		else {
			if (input[x][y] > input[ax][ay] - k && flag) {  // k 만큼 공사 && flag 아직 공사안한 경우

				int temp = input[ax][ay];

				input[ax][ay] = input[x][y] - 1;
				dfs(ax, ay, cnt + 1, 0);  //flag 값을 0으로 
				input[ax][ay] = temp; // 원상 복귀
			}
		}
	}
	visit[x][y] = false;  //원상 복귀
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> t;

	for (int tc = 1; tc <= t; tc++) {

		cin >> n >> k;
		res = 0;
		int maxCnt = 0;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> input[i][j];
				maxCnt = max(input[i][j], maxCnt);
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (input[i][j] == maxCnt) {
					//탐색
					dfs(i, j, 1, 1);
				}
			}
		}

		cout << "#" << tc << " " << res << endl;

	}
}
