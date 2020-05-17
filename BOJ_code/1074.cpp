#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int count = 0;
int r, c;

void z_recursive(int x, int y, int size)
{
	if(size == 2)
	{
		if(x == r && y == c)
		{
			printf("%d", count);
			return;
		}
		count++;
		if(x == r && y+1 == c)
		{
			printf("%d", count);
			return;
		}
		count++;
		if(x+1 == r && y == c)
		{
			printf("%d", count);
			return;
		}
		count++;
		if(x+1 == r && y+1 == c)
		{
			printf("%d", count);
			return;
		}
		count++;
		return;
	}
	
	z_recursive(x, y, size/2);
	z_recursive(x, y+(size/2), size/2);
	z_recursive(x+(size/2), y, size/2);
	z_recursive(x+(size/2), y+(size/2), size/2);
	
}

int main()
{
	int n;
	scanf("%d", &n);

	scanf("%d %d", &r, &c);
	
	z_recursive(0, 0, pow(2, n));

	return 0;
}
