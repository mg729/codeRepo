#include <iostream>
#include <string>
using namespace std;

string s, cmp_s;
int idx;
int count;

int main()
{

	getline(cin, s);
	getline(cin, cmp_s);
	
	while(s.length() - idx >= cmp_s.length())
	{
		if(s.substr(idx, cmp_s.length()) == cmp_s)
		{
			idx += cmp_s.length();
			++count;
		}
		else
			idx++;
	}
	
	cout << count;
	
	return 0;
}
