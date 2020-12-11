#include <iostream>
#include <cstdio>

using namespace std;

int month[13]; // �̿� ��ȹ
int pay[4]; // 0: 1�ϱ� 1:�Ѵޱ� 2:���ޱ� 3:�ϳ��

int minMonth[13]; //�� ���� �̿��ϴµ� �ʿ��� �ּ� �̿� �ݾ�
int d[13]; //d[N]=N��° ���� ������ �ּҰ�

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
		// Step 1. min( 1��, �Ѵ� )
		for(int i = 1; i < 13 ; i++)
		{
			minMonth[i] = min(pay[0] * month[i], pay[1]);
		}
		
		// Step 2. d[N]=N��° ���� ������ �ּҰ�
		/**
		�� �������� �Ѵ� ������ �������ϴ� ���
		F(n) = F(n-1) + 1��
		�� �������� ���� ������ �������ϴ� ���
		F(n) = F(n-3) + 3��
		*/
		for(int i = 1; i < 13 ; i++)
		{
			d[i] = d[i-1] + minMonth[i]; //F(n) = F(n-1) + 1��
			if( i-3 >= 0) //F(n) = F(n-3) + 3��
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
