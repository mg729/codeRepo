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
		cin >> n >> m ;
		vector<int> v;
		
		for(int index = 0; index < n; ++index)
		{
			int importance;
			cin >> importance;
			v.push_back(importance);
		}
		
		int key = v[m];
		int print = 1;
		
		while(1)
		{
			int maxval = 0;
			for(int i = 0; i <v.size(); i++)
			{
				maxval = max(maxval, v[i]);
			}
			
			if(v.front() != maxval)
			{
				int value = v.front();
				v.erase(v.begin());
				v.push_back(value);
			}
			else if(v.front() == maxval)
			{
				if(v.front() == key)
				{
					cout <<print <<endl;
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
