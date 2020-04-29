#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	int tc = 0;
	scanf("%d", &tc);
	while(tc)
	{
		stack <char> s;
		int i = 0;
		
		while(1)
		{
			char c;
			scanf("%c", &c);
			s.push(c);
			i++;
			if(c == '\n')
				break;
		}
		
		vector<char> password;
		
		for(int i = 0; i < s.size(); i++)
		{
			while(1)
			{
				switch(s.top())
				{
					case '-' :
					{
						s.pop(); //remove '-'
						if(s.top() != '<' && s.top() != '>')
						{ 
							s.pop(); //remove one character				
						}
						break;
					}
					case '<' :
					{
						
						break;
					}
					case '>' :
					{
						s.pop(); //remove '>'
//						v.push();
						
						break;
					}
					
					default:
					{
						password.push_back(s.top());
						s.pop();
						break;
					}
				}
			
				if(s.empty())
					break;
			}
		}
		
		for(auto p : password)
		{
			printf("%c", p);
		}
		--tc;
	}
	
	return 0;
}
