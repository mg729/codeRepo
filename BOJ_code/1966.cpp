#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int tc; 
	cin >> tc;
	
	for(int i = 0; i < tc; ++i)
	{
		int n,m;
		cin >> n;
		cin >> m;
		vector<pair<bool, int>> v;
		
		int key;
		for(int index = 0; index < n; ++index)
		{
			int importance;
			cin >> importance;
			if(index == m)
			{
				key = importance;
				v.push_back(pair<bool, int>(true, importance));
			}
			v.push_back(pair<bool, int>(false, importance));
		}
		
		int print = 1;
		
		while(1)
		{
			int maxval = 0;
			for(int i = 0; i < v.size(); i++)
			{
				maxval = max(maxval, v[i].second);
			}
			
			if(v[0].second != maxval)
			{
				int value = v[0].second;
				v.erase(v.begin());
				v.push_back(pair<bool, int>(false, value));
			}
			else if(v[0].second == maxval)
			{
				if(v[0].second == key && v[0].first == true)
				{
					cout << print <<endl;
					break;
				}
				else
				{
					v.erase(v.begin());
					print++;
				}
			}
		}
	}
	return 0;
}
