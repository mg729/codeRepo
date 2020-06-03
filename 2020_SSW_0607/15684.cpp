#include <iostream>
#include <cstdio>

using namespace std;

int n,m,h;
int a[31];
int b[11];

int main()
{
	scanf("%d", &n);
	scanf("%d", &m);
	scanf("%d", &h);
	
	int extraLine = -1;
	
	for(int i = 1 ; i <= m; i++)
	{
		scanf("%d", &a[i]);
		scanf("%d", &b[i]);
		
	}
	
	printf("%d", extraLine);
	
	return 0;
}
