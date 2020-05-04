#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	int tc;
	scanf("%d", &tc);
	for(int i = 0; i < tc; ++i)
	{
		int numberVf;
		scanf("%d", &numberVf);
		
		set <string> vfs;
		for(int i = 0; i <numberVf; ++i)
		{
			set <string> s;
			
			cin.clear();
			fflush(stdin);
			
			string friendship;
			getline(cin, friendship);
			
			string a;
			string b;
			int idx;
			for(idx = 0; idx < friendship.size(); ++idx)
			{
				if(friendship[idx] == ' ')
				{
					++idx;
					break;	
				}
				a.append(1,friendship[idx]);
			}
			for( ; idx <friendship.size(); ++idx)
			{
				b.append(1,friendship[idx]);
			}
			
			s.insert(a);
			s.insert(b);
			
			if(!vfs.count(a) && !vfs.count(b))
			{
				vfs.insert(a);
				vfs.insert(b);
				printf("%d\n", 2);
			}
			else
			{
				vfs.insert(a);
				vfs.insert(b);
				printf("%d\n", vfs.size());
			}
		}	
	}
	return 0;
}
