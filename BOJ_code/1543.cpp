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
	getline(cin, cmp_s);
	
	int count = 0;
	
	size_t found = s.find(cmp_s);
	
	while(s.length() >= cmp_s.length() && found != string::npos)
	{
		string sub = s.substr(found, cmp_s.length());
		for(auto x : sub)
			s.erase(find(s.begin(), s.end(), x));
		
		++count;
		found = s.find(cmp_s);
	}
	
	cout << count;
	
	return 0;
}
