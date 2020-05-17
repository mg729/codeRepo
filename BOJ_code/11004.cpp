#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i < n; ++i)
	{
		int val;
		scanf("%d", &val);
		v.push_back(val);
	}
	sort(v.begin(), v.end());
	
	printf("%d", v[k-1]);
	
	return 0;
}
