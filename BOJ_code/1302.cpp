#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<string, int>> sales;

int main()
{
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		
		bool isExist = false;
		
		for(auto x : sales)
		{
			if(x.first == s)
			{
				isExist = true;
				int val = x.second;
				sales.erase(find(sales.begin(), sales.end(), x));
				sales.push_back({s,++val});
				break;
			}
		}
		if(!isExist)
			sales.push_back({s, 1});
			
	}
	
	sort(sales.begin(), sales.end());
	
	int maxval = 0;
	for(auto x: sales) 
		maxval = max(maxval, x.second);
	
	for(auto x : sales)
	{
		if(x.second == maxval)
		{
			cout << x.first;
			break;
		}
	}	

	
	return 0;
}
