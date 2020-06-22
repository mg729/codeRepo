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
		
		
		
		//print out max outcome
		cout << "#" << i << " " << maxOutcome << endl;
			
	}	
	
	return 0;
}
