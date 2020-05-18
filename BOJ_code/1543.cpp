#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	
	string cmp_s;
	getline(cin, s);
	
	int count = 0;
	
	while(s.find(cmp_s))
	{
		for(auto x : cmp_s)
			s.erase(find(s.begin(),s.end(),x));
		
		++count;
	}
	
	cout << count;
	
	return 0;
}
