#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
/**
문자열의 크기가 최대 백만 1,000,000 이므로 시뮬레이션 방식으로는 문제를 해결할 수 없습니다.
스택을 활용하여 선형 시간 문제를 해결할 수 있는 알고리즘을 설계합니다.

1) 스택을 두개 만들고, 스택 두 개의 중간 지점을 커서로 간주
2) 문자입력: 왼쪽 스택에 원소를 삽입
3) -입력 : 왼쪽 스택에서 원소를 삭제
4) < 입력: 왼쪽 스택에서 오른쪽 스택으로 원소를 이동
5) > 입력 : 오른쪽 스택에서 왼쪽 스택으로 원소를 이동 
6) 왼쪽 스택 출력
7) 오른쪽 스택 출력 
*/
using namespace std;

int main()
{
	int tc = 0;
	scanf("%d", &tc);
	while(tc)
	{
		
		--tc;
	}
	
	return 0;
}
