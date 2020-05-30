#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string a,b;
int adp[1001] = {};
int bdp[1001] = {};

int main()
{
	cin >> a >> b;
	int n = max(a.size(), b.size());
	
	for(int i = 0; i < a.size(); i++)
	{
		int maxLength = 0;
		int index = i;
		int j = 0;
		while(index != a.size())
		{
			if(a[index] == b[j])
			{
				++maxLength;
				index++;
			}
			
			if(j == b.size()-1)
				index++;
			else
				j++;
		}
		adp[i] = maxLength;
	}
	
	int aMaxVal = 0;
	for(int i = 0; i < n; i++)
	{
		aMaxVal = max(aMaxVal, adp[i]);
	}
	
	for(int i = 0; i < b.size(); i++)
	{
		int maxLength = 0;
		int index = i;
		int j = 0;
		while(index != b.size())
		{			
			if(b[index] == a[j])
			{
				++maxLength;
				index++;
			}
			
			if(j == a.size()-1)
				index++;
			else
				j++;
		}
		bdp[i] = maxLength;
	}
	
	int bMaxVal = 0;
	for(int i = 0; i < n; i++)
	{
		bMaxVal = max(bMaxVal, bdp[i]);
	}
	
	cout << max(aMaxVal,bMaxVal);
	
	return 0;
}
