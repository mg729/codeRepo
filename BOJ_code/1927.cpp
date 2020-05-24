#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main()
{
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; ++i)
	{
		int val;
		scanf("%d", &val);
		if(val != 0)
			v.push_back(val);
		else
		{
			if(v.empty())
			{
				printf("%d\n", 0);
			}
			else
			{
				sort(v.begin(), v.end());
				printf("%d\n", v.front());
				v.erase(v.begin());		
			}
		}
	}
	return 0;
}
