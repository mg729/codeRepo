#include <iostream>

using namespace std;

int data[10001];

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		int val;
		scanf("%d", &val); //cin ���� �Է¹����� �ð��ʰ� ���� 
							/**
							for ���� �������� scanf, printf��� ����  
							*/
		data[val]++;
	}
	for(int i = 0; i < 10001; i++)
	{
		int count = data[i];
		if(data[i] != 0)
	    	while(count--)
	    	{
				printf("%d\n", i);
			}
	}
	return 0;
}
