#include <stdio.h>
#include <memory.h>

using namespace std;
/**
@input : 
	������ ũ�� n
	���뿡 ���� ���� �翡���� ����
	������ �� �ִ� ������ ���� M
	���� ä���� �� �ִ� �ִ� �� C
@output : 
	�ִ� ������ �� 
*/

/*
Point1 : �� ���� ����� �����ϴ� ���̽������� ������ ����� ��
ù��° ����� �����ϰ��� �ι� ° ����� ������ �� �ִ� ����� ���� �����̵˴ϴ�.
���� ������ ������
���� : ù��°����� �׻� ���� �������ϰ� �ι�° ����� �׻� �� �ڿ� ������ �����մϴ�.

Point2 : ������ �ִ� ���� �����ϴ� ����Ǽ� -> ����Լ�

*/

int input[10][10];
int n, m, c, res;

int max(int a, int b) {
	return (a > b) ? a : b;
}

// (x,y) ��ǥ���� m���� ������ �����ؼ� ���� �� �ִ� �ִ� ������ ���ϴ� ��� �Լ�
// sum : ��������� ��
// cnt : ������ ����
// res : ���ݱ����� �ְ�����
// price : ������ ����
void getMaxPrice(int x, int y, int cnt, int sum, int price) {
	if (sum > c) 
		return;
	res = max(res, price);
	if (cnt == m)   
		return;
	//�Ʒ� �ΰ�����츦 ��� ������� --> ������ �������ϸ� �Լ��� Ÿ����� if������ ����� ��
	//���� x,y ��ǥ���� �����ϴ� ���
	getMaxPrice(x, y + 1, cnt + 1, sum + input[x][y], price + input[x][y] * input[x][y]);
	//���� x,y ��ǥ���� �������� �ʴ� ���
	getMaxPrice(x, y + 1, cnt + 1, sum, price);
}

int solve(int x, int y) {

	res = 0;
	getMaxPrice(x, y, 0, 0, 0);
	int priceA = res;  //ù��° ����� ����

	// �ι�° ����� �� ���� M���� ��뱸�ϱ�
	int priceB = 0;
	int j = y + m;  //ù�� ° ����� y���� m���� ������ ä��
	for (int i = x; i < n; i++, j = 0) {
		for (; j < n - m + 1; j++) { // n-m+1 : ���� ù��°����� ������ĭ�� ���� �࿡�� �ڸ��� ���ٸ� �������� �Ѱ��ִ� ��
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
				maxPrice = max(maxPrice, solve(i, j));  //x,y�� ���� ��� ����� ���� ����Ϸ��� solve�Լ��� for���� �������մϴ�.
			}
		}
		printf("#%d %d\n", tc, maxPrice);
	}
}

