#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

vector<int> v;
vector<char> vc;
 
int main()
{
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n ; ++i)
	{
		int val;
		scanf("%d", &val);
		v.push_back(val);
	}
	
	int sum = n*2;
	int cmp = 0;
	for(int i = 0; i < n-1 ; ++i)
	{
		if(v[i] > v[i+1])
		{
			int num = v[i] - cmp;
			while(num)
			{
				vc.push_back('+');
				cmp = num;
				--sum;
				--num;
			}
		}
		else
		{
			vc.push_back('-');
			--sum;
		}
	}
	if(sum)
		printf("NO");
	else
	{
		for(int i = 0; i < n; i++)
		{
			printf("%c", vc[i]);
		}
	}
	return 0;
}

//https://www.acmicpc.net/problem/1874
