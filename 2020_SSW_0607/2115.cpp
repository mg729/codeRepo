#include <iostream>
#include <cstdio>

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
int honey[10][10];
int maxOutcome;
int main() 
{
	int tc;
	cin >> tc;
	
	for(int i = 0; i < tc; i++)
	{
		int n, m, c;
		cin >> n >> m >> c;
		
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < n; k++)
			{
				cin >> honey[j][k];
			}
		}
		
		int maxOutcome = 0;
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k <n; k++)
			{
				
			}
		} 
		
		
		//print out max outcome
		cout << "#" << i << " " << maxOutcome << endl;
			
	}	
	
	return 0;
}
