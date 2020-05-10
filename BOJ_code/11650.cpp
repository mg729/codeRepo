#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp (pair<int, int> a, pair<int, int> b)
{
	if(a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

int main()
{
	int tc;
	cin >> tc;
	
	vector <pair<int, int>> v;
	
	for (int i = 0; i < tc; ++i)
	{
		int x;
		int y;
		cin >> x >> y;
		v.push_back({x,y});
	}
	
	sort(v.begin(),v.end(), cmp);
	
	for(auto x:v)
		cout << x.first << " " << x.second << '\n';
		
	return 0;
}
