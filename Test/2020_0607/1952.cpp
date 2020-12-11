#include <iostream>
#include <cstdio>

using namespace std;

int month[13]; // 이용 계획
int pay[4]; // 0: 1일권 1:한달권 2:세달권 3:일년권

int minMonth[13]; //각 달을 이용하는데 필요한 최소 이용 금액
int d[13]; //d[N]=N번째 날의 누적된 최소값

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
		for(int k = 1; k < 13; ++k)
		{
			scanf("%d", &month[k]);
		}
		
		int money = 0;
		// Step 1. min( 1일, 한달 )
		for(int i = 1; i < 13 ; i++)
		{
			minMonth[i] = min(pay[0] * month[i], pay[1]);
		}
		
		// Step 2. d[N]=N번째 날의 누적된 최소값
		/**
		맨 마지막에 한달 권으로 마무리하는 경우
		F(n) = F(n-1) + 1달
		맨 마지막에 세달 권으로 마무리하는 경우
		F(n) = F(n-3) + 3달
		*/
		for(int i = 1; i < 13 ; i++)
		{
			d[i] = d[i-1] + minMonth[i]; //F(n) = F(n-1) + 1달
			if( i-3 >= 0) //F(n) = F(n-3) + 3달
			{
				if( d[i] > d[i-3] + pay[2] )  
				{
					d[i] = d[i-3] + pay[2];
				}	
			} 
		} 
		
		money = min( d[12] , pay[3]);
		
		printf("#%d %d", i, money);
	}
	
	 
	return 0;
}
