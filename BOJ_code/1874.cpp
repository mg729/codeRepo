#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
using namespace std;

stack<int> s;
vector<char> vc;
 
int main()
{
	int n;
	scanf("%d", &n);
	
	int num = 1;
	for(int i = 0; i < n ; ++i)
	{
		int val;
		scanf("%d", &val);
		
		while(num <= val)
		{
			s.push(num);
			++num;
			vc.push_back('+');
		}
		if(s.top()==val)
		{
			s.pop();
			vc.push_back('-');
		}
		else
		{
			printf("NO");
			return 0;
		}
	}
	for(auto result: vc)
	{
		printf("%c\n", result);
	}
	
	return 0;
}

//https://www.acmicpc.net/problem/1874
