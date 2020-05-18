#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
// substr() �Լ� Ȱ��
// npos�� -1 �ΰ�
// while���� s.find() �ϸ� 0�� ������ ������� �迭 s�� ù��°��Ҹ� ã�Ƴ� ���
// �׷��� string::npos���°�..
// �׸��� �ݺ��������� found ��� �����ϴ� �� ����
// ��.. ���ܻ�Ȳ üũ�� �κ��� �ſ� ���׿� 
int main()
{
	string s;
	getline(cin, s);
	
	string cmp_s;
	getline(cin, cmp_s);
	
	int count = 0;
	
	size_t found = s.find(cmp_s);
	
	while(found != string::npos)
	{
		s.substr(found, cmp_s.size());
		
		++count;
		found = s.find(cmp_s);  // �̺κ��� ��� ���Ծ���..! �������� üũ �ʼ�... 
	}
	
	cout << count;
	
	return 0;
}
