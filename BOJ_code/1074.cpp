#include <iostream>
#include <cstdio>

using namespace std;

int  v [10000][10000] = {};
int count = 0;

void z_recursive(int x, int y, int size)
{
	if(size == 4)
	{
		v[x][y] = count++;
		v[x][y+1] = (count++);
		v[x+1][y] = (count++);
		v[x+1][y+1] = (count++);
		
		return;
	}
	
	int val = size/4;
	int index = val/4;
	
	z_recursive(x, y, val);
	z_recursive(x, y+(index), val);
	z_recursive(x+(index), y, val);
	z_recursive(x+(index), y+(index), val);
	
}

int main()
{
	int n;
	scanf("%d", &n);
	
	int z_size = 1;
	for(int i = 0; i < n; ++i)
	{
		z_size *= 2;
		z_size = z_size * z_size;	
	}
	
	int r, c;
	scanf("%d %d", &r, &c);
	
	z_recursive(0, 0, z_size);
		
	printf("%d", v[r][c]);
	
	return 0;
}
