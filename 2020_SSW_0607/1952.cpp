#include <iostream>
#indlude <cstdio>

using namespace std;

int month[12];
int pay[4];

int main()
{
	int tc;
	scanf("%d", &tc);
	
	for(int i = 0; i < tc; i++)
	{
		for(int j = 0; j < 4; ++j)
		{
			scanf("%d", &pay[j]);
		}
		for(int k = 0; k < 12; ++k)
		{
			scanf("%d", &month[k]);
		}
		
		int money = 0;
		
		
		
		printf("#%d %d", i, money);
	}
	
	 
	return 0;
}
