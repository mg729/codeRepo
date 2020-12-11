#include<iostream>
using namespace std;
#define MAX 51

int N, M;
int input[MAX][MAX];
int x, y;
int result;
int direction;

//북, 동, 남, 서  --> 서쪽 옆에 왼쪽으로 돌리면 남쪽, 남쪽기준으로 왼쪽으로 돌리면 동쪽
//즉, 왼쪽으로 갈수록 왼쪽으로 회전하는 것
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main() {

	cin >> N >> M;
	cin >> x >> y >> direction;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> input[i][j];

	while (1) {

		// 현재위치 청소
		if (input[x][y] == 0) {
			input[x][y] = 2;
			result++; //청소한 result counter
		}

		int nextStep = 0;
		for (int i = 0; i < 4; i++) { //청소이후 상하좌우를 탐색하며 청소가능한부분을 찾음

			// direction의 값이 dx, dy의 index값이 됩니다.
			// +3 % 4 : ex - 북쪽 0 에 3을 더하면 3, 4로 나눠도 3
			//        : 왼쪽방향으로 전환
			direction = (direction + 3) % 4;
			int newX = x + dx[direction];
			int newY = y + dy[direction];

			if (input[newX][newY] == 0) {
				x = newX;
				y = newY;
				nextStep = 1;  //다음단계로 나아갈수있는지 (청소할 수 있는영역이 있는지)
				break;
			}
		}

		if (nextStep == 1)
			continue;

		// 후진
		// +2 %4 : 서(3) +2 = 5,  5%4 = 1--> 1(동)
		// 180 도 바뀐 방향
		int newDirection = (direction + 2) % 4;
		x = x + dx[newDirection];
		y = y + dy[newDirection];

		// 후진했을 때 1 이면 즉, 벽이면 --> break
		if (input[x][y] == 1)
			break;
		// 1이 아니면 새로운 후진하고 while문 다시 반복
	}
	//후진했을 때 벽을 만났을 때 result값 출력
	cout << result;
}