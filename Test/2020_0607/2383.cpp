/*
******이문제는 반드시 풀어볼 것
******시간내에 못풀수있음
******하루정도고민해볼 것

각 계단(s)의 수용인원 3명
내려가는 시간 10초

- 사람을 어떻게 배정하는가? 
	- Greedy로는 해결이안남
	- 이 문제는 완전탐색 해결법
- 사람 10명에 대해 두개의 계단이있다면 2의 10승(2*2*2*...)만큼 선택지가 있음
- 각 사람별로 두개의 선택지가 있고 모든 케이스는 곱하기로 연결됨
- 이 2의 10승의 케이스의 종료조건은 10명이 다 매칭이된 경우
- 즉 하나의 케이스마다 시간 t를 구해내는 것

- 여러가지 방법으로 구현이 가능
- "시간"조건자체가 정해져있음
- int t = 1 로 두고 while문을 돌리면서 t를 계속증가시킴
	- p1 (Q1 계단에 할당된 사람이 담긴 배열)
	- p2 (Q2 계단에 할당된 사람이 담긴 배열)
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<pair<int, int>> people;
vector<pair<int, int>> stair;

int N;
int board[10][10] = { 0, };

int mappingTable[10]; //사람(0~9)과 계단 1, 계단2 매핑관계
int answer; //최단 시간
int peopleCnt;

int getTime() { //총 걸린 시간을 계산하는 함수 
	int t = 0;
	int chk = 0;
	int d[10];
	queue<int> c[2]; //계단 queue

	for (int i = 0; i < peopleCnt; i++) {
		d[i] = abs(people[i].first - stair[mappingTable[i]].first) + abs(people[i].second - stair[mappingTable[i]].second);
	}

	while (true) {
		if (t >= answer) return t; //시간을 계속증가시키면서 반복하는데 최단시간보다 길게나오면 종료

		if (chk == peopleCnt) return t; //사람이 모두 계단을타고 나가야되는데 그 cnt가 peopleCnt가되면 종료

		// 계단에 들어간 경우 사람들에 대한 처리
		// 계단에 내려가는시간 계산
		for (int i = 0; i < 2; i++) {
			int cs = c[i].size();
			for (int j = 0; j < cs; j++) { //이 계단에서 나갈 수 있는지 없는지에대한 체크
				int top = c[i].front();
				c[i].pop();
				top--;
				if (top != 0)
					c[i].push(top);
				else {
					chk++;
				}
			}
		}

		// 입구에 도착한 경우
		for (int i = 0; i < peopleCnt; i++) {
			if (t == d[i]) {
				if (c[mappingTable[i]].size()<3)//계단 입구 도착시 사람이 아무도 없다면
					c[mappingTable[i]].push(board[stair[mappingTable[i]].first][stair[mappingTable[i]].second]);
				else {
					c[mappingTable[i]].push(board[stair[mappingTable[i]].first][stair[mappingTable[i]].second] + c[mappingTable[i]].front());
				}
			}
		}
		t++; // 시간 증가

	}

}

void recursive(int cnt) {  

	// 종료부
	//people.size 사람수만큼 매핑이 된 순간 종료
	if (cnt == people.size()) {
		int tmp = getTime();
		if (answer > tmp) answer = tmp;
		return;
	}

	// 분할부
	// cnt 현재 사람의 index
	mappingTable[cnt] = 0; recursive(cnt + 1);
	mappingTable[cnt] = 1; recursive(cnt + 1);

}

int main() {

	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> N;
		people.clear();
		stair.clear();
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) people.push_back({ i,j });
			else if (board[i][j] > 1) stair.push_back({ i,j });
		}
		peopleCnt = people.size();
		answer = 99999999;
		recursive(0);
		cout << "#" << test_case << ' ' << answer << '\n';

	}
	return 0;