#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int n;
	cin >> n;
	
	vector <int> v;
	
	while(n)
	{
		v.push_back(n%10);
		n -= (n%10);
		n /= 10;
	}
	
	sort(v.begin(), v.end(), cmp);
	
	for(auto x: v)
		cout << x;
		
	return 0;
} 
