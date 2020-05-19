#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

map<string, int> sales;

int main()
{
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		
		sales[s]++;
	}
	
	int maxval = 0;
	for(auto it = sales.begin(); it != sales.end(); it++)
	{
		maxval = max(maxval, it->second);
	}
	
	for(auto it = sales.begin(); it != sales.end(); it++)
	{
		if(maxval == it->second)
		{
			cout << it->first;
			break;
		}
	}

	
	return 0;
}
