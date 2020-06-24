#include <stdio.h>
#include <memory.h>

using namespace std;
/**
@input : 
	벌통의 크기 n
	벌통에 담기는 꿀의 양에대한 정보
	선택할 수 있는 벌통의 개수 M
	꿀을 채취할 수 있는 최대 양 C
@output : 
	최대 수익의 합 
*/

/*
Point1 : 두 명의 사람이 선택하는 케이스에대해 기준을 세우는 것
첫번째 사람이 선택하고나면 두번 째 사람이 선택할 수 있는 경우의 수는 제한이됩니다.
따라서 기준을 세워야
기준 : 첫번째사람이 항상 먼저 선택을하고 두번째 사람은 항상 그 뒤에 벌통을 설정합니다.

Point2 : 이익의 최대 값을 선택하는 경우의수 -> 재귀함수

*/

int input[10][10];
int n, m, c, res;

int max(int a, int b) {
	return (a > b) ? a : b;
}

// (x,y) 좌표부터 m개의 꿀통을 선택해서 얻을 수 있는 최대 가격을 구하는 재귀 함수
// sum : 현재까지의 합
// cnt : 꿀통의 개수
// res : 지금까지의 최고이익
// price : 현재의 이익
void getMaxPrice(int x, int y, int cnt, int sum, int price) {
	if (sum > c) 
		return;
	res = max(res, price);
	if (cnt == m)   
		return;
	//아래 두가지경우를 모두 고려해줌 --> 조건을 만족못하면 함수를 타고들어가서 if문에서 종료될 것
	//현재 x,y 좌표값을 선택하는 경우
	getMaxPrice(x, y + 1, cnt + 1, sum + input[x][y], price + input[x][y] * input[x][y]);
	//현재 x,y 좌표값을 선택하지 않는 경우
	getMaxPrice(x, y + 1, cnt + 1, sum, price);
}

int solve(int x, int y) {

	res = 0;
	getMaxPrice(x, y, 0, 0, 0);
	int priceA = res;  //첫번째 사람의 이익

	// 두번째 사람이 고른 벌통 M개의 비용구하기
	int priceB = 0;
	int j = y + m;  //첫번 째 사람이 y부터 m개의 벌통을 채취
	for (int i = x; i < n; i++, j = 0) {
		for (; j < n - m + 1; j++) { // n-m+1 : 만약 첫번째사람이 차지한칸과 같은 행에서 자리가 없다면 다음열로 넘겨주는 것
			res = 0;
			getMaxPrice(i, j, 0, 0, 0);
			priceB = max(priceB, res);
		}
	}

	return priceA + priceB;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d %d %d", &n, &m, &c);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &input[i][j]);
			}
		}

		int maxPrice = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - m + 1; j++) {
				maxPrice = max(maxPrice, solve(i, j));  //x,y에 대한 모든 경우의 수를 고려하려면 solve함수는 for문을 돌려야합니다.
			}
		}
		printf("#%d %d\n", tc, maxPrice);
	}
}

