#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	
	int i = 0;
	int sec = 0;
	while(1)
	{
		if(n < i)
		{
			sec += (i-1);
			i=0;
			continue;
		}
		
		n -= i;
		if(n == 0)
			break;
		i++;	
	}
	
	printf("%d", sec + (i));
	
	return 0;
}
