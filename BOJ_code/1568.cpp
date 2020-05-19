#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	
	int i = 1;
	int sec = 0;
	while(n != 0)
	{
		if(n < i)
			i =1;
		
		n -= i;
		i++;
		sec += 1;	
	}
	
	printf("%d", sec);
	
	return 0;
}
