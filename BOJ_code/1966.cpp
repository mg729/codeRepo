#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	int tc; 
	cin >> tc;
	
	for(int i = 0; i < tc; ++i)
	{
		int n,m;
		cin >> n;
		cin >> m;
		queue<pair<bool, int>> q;
		priority_queue<int> pq;
		
		int key;
		for(int index = 0; index < n; ++index)
		{
			int importance;
			cin >> importance;
			if(index == m)
			{
				key = importance;
				q.push({true, importance});
				pq.push(importance);
			}
			q.push({false, importance});
			pq.push(importance);
		}
		
		int print = 1;
		
		while(1)
		{			
			if(q.front().second != pq.top())
			{
				q.push(q.front());
				q.pop();
			}
			else if(q.front().second == pq.top())
			{
				pq.pop();
				if(q.front().second == key && q.front().first == true)
				{
					cout << print <<endl;
					break;
				}
				else
				{
					q.pop();
					print++;
				}
			}
		}
	}
	return 0;
}
