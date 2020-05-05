#include <iostream>
#include <set>

/**
Below solution has error problem

4
Ann Ben 2
Carl David 2
Evan Fred 2
Betty Fred 7 --> not 7 but should be 3 
*/
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
			char a[21] = {0,};
			char b[21] = {0,};
			scanf("%s %s", &a, &b);
			
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
			for(auto x : vfs)
				cout << x << " ";
			cout << endl;
		}	
	}
	return 0;
}
