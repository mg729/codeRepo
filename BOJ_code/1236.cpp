#include <iostream>
#include <cstdio>

using namespace std;

char c;
int row[50];
int col[50];
int rowCount, colCount;

int main()
{
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin >> c;
			if(c == 'X')
			{
				row[i] = 1;
				col[j] = 1;
			}
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		if(!row[i])
		{
			++rowCount;
		}	
	}
	
	for(int j = 0; j < m; j++)
	{
		if(!col[j])
		{
			++colCount;
		}	
	}
	
	printf("%d", max(colCount, rowCount));
	
	return 0;
}
