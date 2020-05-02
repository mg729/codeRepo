#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
/**
문자열의 크기가 최대 백만 1,000,000 이므로 시뮬레이션 방식으로는 문제를 해결할 수 없음

1) 스택을 두개 만들고, 스택 두 개의 중간 지점을 커서로 간주
2) 문자입력: 왼쪽 스택에 원소를 삽입
3) -입력 : 왼쪽 스택에서 원소를 삭제
4) < 입력: 왼쪽 스택에서 오른쪽 스택으로 원소를 이동
5) > 입력 : 오른쪽 스택에서 왼쪽 스택으로 원소를 이동
6) 왼쪽 스택 출력
7) 오른쪽 스택 출력 
*/

using namespace std;

int main()
{
	int tc = 0;
	scanf("%d", &tc);
	while(tc)
	{
		stack <char> left_s;
		stack <char> right_s;
		
		string s;
		cin >> s;
		
		for(int i = 0; s[i] ; ++i)
		{
			if(s[i] == '-')
			{
				if(!left_s.empty())
					left_s.pop();
			}
			else if(s[i] == '<')
			{
				if(!left_s.empty())
				{
					right_s.push(left_s.top());
					left_s.pop();
				}
			}
			else if(s[i] == '>')
			{
				if(!right_s.empty())
				{
					left_s.push(right_s.top());
					right_s.pop();
				}
			}
			else
				left_s.push(s[i]);
		}
		
		vector<char> password;

		while(!right_s.empty())
		{
			left_s.push(right_s.top());
			right_s.pop();
		}
		while(!left_s.empty())
		{
			password.push_back(left_s.top());
			left_s.pop();
		}
		
		reverse(password.begin(), password.end()); //defined in header <algorithm>
		
		for(auto x: password)
			printf("%c", x);
		printf("\n");
		
		--tc;
	}
	
	return 0;
}
