#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector <int> vn;
	
	for(int i = 0; i < n; ++i)
	{
		int val;
		scanf("%d", &val);
		vn.push_back(val);
	}
	
	int m;
	scanf("%d", &m);
	vector <int> vm;
	
	for(int i = 0; i < m; ++i)
	{
		int val;
		scanf("%d", &val);
		vm.push_back(val);
	}
	
	vector <int> answer;

	for(int j = 0; j < vm.size(); ++j)
	{
		if(find(vn.begin(), vn.end(), vm[j]) != vn.end())
			answer.push_back(1);
		else
			answer.push_back(0);
	}
	
	for(auto x : answer)
		printf("%d\n", x);
	
	
	return 0;
}
