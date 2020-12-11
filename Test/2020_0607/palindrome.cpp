#include <iostream>
using namespace std;
/*
1. 회문검사하려면 길이변수가 있어야함
* 최적화의 기준은 탈출!조건
* 길이가 긴것부터 회문인지를 판단하고
* 회문을 만족하면 그보다 작은 경우는 고려할 필요가 없으므로 바로 탈출
* 그리고나서 현재까지 탐색에서 최고 회문 길이를 변수에 저장해둠
* 그리고 나서 max보다 작은 경우의수에 대해서는 탐색을하지 않는다
*/
char ary[100][100];

// 위치 p부터 len 만큼의 길이의 문자열이 회문인지 판단하는 함수
bool isPalindrome(char * p, int len) //p : 시작점
{
	for (int i = 0; i < (len + 1) / 2; i++)
		if (*(p + i) != *(p + len - 1 - i))
			return false;

	return true;
}


int getMaxPalindrome(char ary[][100])
{
	int max = 0; //현재까지 나온 최대 회문의 길이를 저장함.

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			for (int k = 100 - j; k > max; k--)  //가능한한 최대 길이의 문자열부터 회문인지를 검사  --> k는 length값을 의미 ( length 값을 줄여나가면서 조건 검사 ), k>max 일때까지만 탐색
				if (isPalindrome(&ary[i][j], k))
				{
					if (max < k) max = k;
					break;
				}

	return max;
}

void main()
{
	int ans = 0;
	//freopen("input.txt", "r", stdin); // 리소스 파일 input.txt 파일로부터 input을 읽어오도록 설정 -> 불필요시 주석처리 필요

	for (int tc = 1; tc <= 10; tc++)
	{
		int n;
		cin >> n;

		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				cin >> ary[i][j];

		ans = getMaxPalindrome(ary);  //가로행에대한 최대 회문길이파악할 수 있음

		// (x,y) <-> (y,x) swap  =>  행과 열이 swap 됨.
		// 와 이렇게 가로 세로행을 모두 고려하는 문제 많이 출제되는데 이렇게 행과 열을 바꿔주면 되겠다..!
		for (int i = 0; i < 100; i++)
			for (int j = 0; j < 100; j++)
				if (i < j)
				{
					char t = ary[i][j];
					ary[i][j] = ary[j][i];
					ary[j][i] = t;
				}

		ans = getMaxPalindrome(ary) < ans ? ans : getMaxPalindrome(ary);

		cout << "#" << tc << " " << ans << endl;
		ans = 0;
	}
}
