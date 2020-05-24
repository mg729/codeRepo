#include <iostream>
#include <queue>
using namespace std;

priority_queue <int, vector<int> , greater<int>> pq;

int main()
{
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; ++i)
	{
		int val;
		scanf("%d", &val);
		if(val != 0)
			pq.push(val);
		else
		{
			if(pq.empty())
			{
				printf("%d\n", 0);
			}
			else
			{
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
	}
	return 0;
}
