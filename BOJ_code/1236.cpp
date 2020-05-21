#include <iostream>
#include <cstdio>
using namespace std;

char castle[50][50];

int main()
{
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
//			char c;
//			scanf("%c", &c);
//			castle[i][j] = c;
			cin >> castle[i][j];
		}
//		getchar(); //clear buffer
	}

	int col = 0;
	bool isExist = false;
	
	for(int i = 0; i < n; i++)
	{
		isExist = false;
		for(int j = 0; j < m; j++)
		{
			if(castle[i][j] == 'X')
			{
				isExist = true;
				break;
			}
		}
		if(!isExist)
			col++;
		
	}

	
	int row = 0;
	isExist = false;
	for(int i = 0; i < n; i++)
	{
		isExist = false;
		for(int j = 0; j < m; j++)
		{
			if(castle[j][i] == 'X')
			{
				isExist = true;
				break;
			}
		}
		if(!isExist)
			row++;
	}
	
	printf("%d", max(col, row));
	
	return 0;
}
