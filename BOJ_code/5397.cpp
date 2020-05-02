#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
/**
���ڿ��� ũ�Ⱑ �ִ� �鸸 1,000,000 �̹Ƿ� �ùķ��̼� ������δ� ������ �ذ��� �� ����

1) ������ �ΰ� �����, ���� �� ���� �߰� ������ Ŀ���� ����
2) �����Է�: ���� ���ÿ� ���Ҹ� ����
3) -�Է� : ���� ���ÿ��� ���Ҹ� ����
4) < �Է�: ���� ���ÿ��� ������ �������� ���Ҹ� �̵�
5) > �Է� : ������ ���ÿ��� ���� �������� ���Ҹ� �̵�
6) ���� ���� ���
7) ������ ���� ��� 
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
