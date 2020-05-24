#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

priority_queue <int, vector<int>, greater<int> > pq;
priority_queue <int, vector<int>, greater<int> > pq2;

int main()
{
	int n;
	scanf("%d", &n);
	
	for(int i =0; i <n; ++i)
	{
		int val;
		scanf("%d", &val);
		pq.push(val);
	}
	
	int cmp = 0;
	int sum = 0;
	while(pq.size() != 1)
	{
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		
		cmp = a + b;
		pq.push(cmp);
		pq2.push(cmp);
		
		sum += cmp;
	}
	
	cout << sum;
	return 0;
}
