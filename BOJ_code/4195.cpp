#include <iostream>
#include <cstdio>
#include <map>
/**
Union-Find 알고리즘
- 원소들의 연결여부를 확인하는 알고리즘
*/
int parent[200001];
int number[200001];
char one[21];
char two[21];

using namespace std;

int findParent(int p)
{
	if(p == parent[p])
		return p;
	return parent[p] = findParent(parent[p]);
}

void unionParent(int x, int y)
{
	x = findParent(x);
	y = findParent(y);
	
	if(x!=y)
	{
		parent[y] = x;
		number[x] += number[y];
	}
} 
int main()
{
	int tc;
	scanf("%d", &tc);
	for(int i = 0; i < tc; ++i)
	{
		map <string, int> data;
		int cnt = 1;
		int numberOfVf;
		scanf("%d", &numberOfVf);
		
		for(int i = 0 ; i < 2*numberOfVf; ++i)
		{
			parent[i] = i;
			number[i] = 1;
		}
		for(int i = 0; i < numberOfVf; ++i)
		{
			scanf("%s %s", &one, &two);
			
			if(data.count(one) == 0)
				data[one] = cnt++;
			if(data.count(two) == 0)
				data[two] = cnt++;
			
			unionParent(data[one], data[two]);
			printf("%d\n", number[findParent(data[one])]);
		}
	}
	return 0;
}
