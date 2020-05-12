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
		scanf("%d", &val); //cin 으로 입력받으면 시간초과 에러 
							/**
							for 루프 내에서는 scanf, printf사용 권장  
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
