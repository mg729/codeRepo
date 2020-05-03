#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	set <int> s;
	
	for(int i = 0; i < n; ++i)
	{
		int val;
		scanf("%d", &val);
		s.insert(val);
	}
	
	int m;
	scanf("%d", &m);
	vector <int> v;
	
	for(int i = 0; i < m; ++i)
	{
		int val;
		scanf("%d", &val);
		v.push_back(val);
	}
	
	for(auto x : v)
		printf("%d\n", s.count(x));

	
	return 0;
}
