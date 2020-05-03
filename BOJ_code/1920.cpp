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
		s.insert(val);   //set container insert data by using "insert" member function
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
		printf("%d\n", s.count(x));  //count member function returns only 1 or 0
	
	return 0;
}
