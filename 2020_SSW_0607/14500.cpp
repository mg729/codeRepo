#include<iostream>
#include<cstdio>
#include<stack>

using namespace std;

int T, N, M;
int input[501][501];
int visit[501][501] = { 0, };
int answer = 0;

stack<pair<int,int>> s;

// 상하좌우 dx, dy 접근을 위한 방식
int dArr[][4] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 } };

// 재귀함수
void dfs(int n, int m, int sum, int depth) {

	sum += input[n][m];

	// 종료조건: 테트로미노는 정사각형 네개가되면 종료
	if (depth == 1) {
		if (sum > answer)
			answer = sum;
		return;
	}

	// stack에 추가함
	s.push({n, m});
	visit[n][m] = 1;

	//현재 stack에서 push되지않은 경우가 있다면 dfs를 실행
	for (int k = 0; k <= s.size(); k++) { // STACK에 담긴 모든 원소들을 하나씩 탐색
		for (int a = 0; a < 4; a++) {  // 각 각의 STACK 원소의 상하좌우 좌표 : (newX, newY) - 스택에 있는 하나의 원소에 인접한 좌표를 검사

			int newX = s.top().first + dArr[a][0];
			int newY = s.top().second + dArr[a][1];

			// 좌표 범위 검사
			if (newX >= N || newY >= M || newX < 0 || newY < 0)
				continue;
			//stack에 없는 경우에대해서만 dfs를 호출
			if (visit[newX][newY] == 0)  
				dfs(newX, newY, sum, depth - 1);
		}
	}

	// stack에서 삭제함
	visit[n][m] = 0;
	s.pop();

	return;
}

int main() {

	int temp;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {

			scanf("%d", &temp);
			input[i][j] = temp;
		}


	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {

			dfs(i, j, 0, 4);
		}

	printf("%d", answer);
}
