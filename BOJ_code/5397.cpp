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
		
		vector<pair<int, char>> password;
		int cursor = 0;
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
						s.pop(); //remoce '<'
						if( password.begin() == password[cursor] )
							break;
						else
						{
							--cursor;
							password.insert(password[cursor], {})
						}
						break;
					}
					case '>' :
					{
						s.pop(); //remove '>'
						if( password.end() == password[cursor] ) //마지막 데이터와 커서 위치가 같으면 
							break; 
						else  //change cursor position;
						{
							++cursor;
						}
						
						break;
					}
					
					default:
					{
						password.push_back({ cursor, s.top() });
						s.pop();
						++cursor;
						break;
					}
				}
			
				if(s.empty())
					break;
			}
		}
		
		for(auto p : password)
		{
			printf("%c", p.second);
		}
		--tc;
	}
	
	return 0;
}
