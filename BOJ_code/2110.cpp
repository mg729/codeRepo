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
	
	int start = v.front();
	int mid = v.back();  // do not declare as 0 

	while(c > 2)
	{
		if(n % 2 == 0)
			n = n/2 - 1;
		else
			n = n/2;
			
		mid = v[n];
		cout << mid <<endl;
		v.erase(v.begin());
		v.pop_back();

		c -= 2;
	}
	cout << mid - start;	
	
	return 0;
}
