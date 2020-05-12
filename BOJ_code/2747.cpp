#include <iostream>
#include <cstdio>
using namespace std; 

int data[44];

int main()
{
	int n;
	scanf("%d", &n);
	data[0] = 0;
	data[1] = 1;
	for(int i = 2; i <= n; ++i)
	{
		data[i] = data[i-1] + data [i-2];
	}
	
	printf("%d", data[n]);
	return 0;
}
