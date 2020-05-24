#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;

int main()
{
	int n, c;
	cin >> n >> c;
	
	for(int i = 0; i < n; ++i)
	{
		int val;
		cin >> val;
		v.push_back(val);
	}
	
	sort(v.begin(), v.end());
	
	int start = v[1] - v[0];     // minimum gap
	int end = v[n-1] - v[0];   // maximum gap
	int result = 0;
	
	while(start <= end)
	{
		int mid = (start + end) / 2;
		
		int value = v[0];
		
		int cnt = 1;
		
		for(int i = 1; i < n; ++i) //starts from i as 1
		{
			if(v[i] >= value + mid)  // mid means gap
			{
				value = v[i];
				cnt += 1;
			}
		}
		
		if(cnt >= c)
		{
			start = mid + 1; //update start value for minimize search datas' range
			result = mid;
		}
		else
			end = mid - 1;  //update end value 
	}
	cout << result;	
	
	return 0;
}
