#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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
	
	sort(v.begin(),v.end());
	
	for(auto x:v)
		cout << x.first << " " << x.second << '\n';
		
	return 0;
}
