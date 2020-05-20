#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> v;

int main()
{
	int n;
	scanf("%d", &n);
	
	for(int i = 0 ; i < n; ++i)
	{
		int val;
		scanf("%d", &val);
		v.push_back(val); 
	}

	int rcount = 0;
	int cmp = 0;
	for(int i = 0; i < n; ++i)
	{
		if(v[i] > cmp)
		{
			rcount++;
		}
		cmp = max(cmp, v[i]);
	}
	printf("%d\n", rcount);
	
	
	int lcount = 0;
	cmp = 0;
	for(int i = n-1; i >= 0; --i)
	{
		if(v[i] > cmp)
		{
			lcount++;
		}
		cmp = max(cmp, v[i]);
	}
	printf("%d", lcount);
	
	return 0;
}
