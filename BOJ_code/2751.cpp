#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

int main()
{
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; ++i)
	{
		int val;
		scanf("%d", &val);
		v.push_back(val);
	}
	sort(v.begin(), v.end());
	
	for(auto x : v)
		printf("%d\n", x);
	
	return 0;
}
