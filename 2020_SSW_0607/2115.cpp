#include <iostream>
#include <cstdio>

using namespace std;
/**
@input : 
	������ ũ�� n
	���뿡 ���� ���� �翡���� ����
	������ �� �ִ� ������ ���� M
	���� ä���� �� �ִ� �ִ� �� C
@output : 
	�ִ� ������ �� 
*/

/*
Point1 : �� ���� ����� �����ϴ� ���̽������� ������ ����� ��
ù��° ����� �����ϰ��� �ι� ° ����� ������ �� �ִ� ����� ���� �����̵˴ϴ�.
���� ������ ������
���� : ù��°����� �׻� ���� �������ϰ� �ι�° ����� �׻� �� �ڿ� ������ �����մϴ�.

Point2 : ������ �ִ� ���� �����ϴ� ����Ǽ� -> ����Լ�

*/
int honey[10][10];
int maxOutcome;
int main() 
{
	int tc;
	cin >> tc;
	
	for(int i = 0; i < tc; i++)
	{
		int n, m, c;
		cin >> n >> m >> c;
		
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < n; k++)
			{
				cin >> honey[j][k];
			}
		}
		
		int maxOutcome = 0;
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k <n; k++)
			{
				
			}
		} 
		
		
		//print out max outcome
		cout << "#" << i << " " << maxOutcome << endl;
			
	}	
	
	return 0;
}
