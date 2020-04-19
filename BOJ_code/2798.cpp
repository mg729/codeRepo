#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n, m; 
int arr[100];

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
    }
    
    int sum = 0;
	for(int i = 0; i <n;++i)
		for(int j = i+1; j <n; ++j)
			for(int k = j+1; k<n; ++k)
				if(arr[i]+arr[j]+arr[k] <= m)
					sum = max(sum, arr[i]+arr[j]+arr[k]);
				
	printf("%d", sum);
	return 0;
}
//Contest > Croatian Open Competition in Informatics > COCI 2011/2012 > Contest #6  No.1

/*
�� ������ ��� ����� ���� �����ϰ� �������� ���� �ǵ��� �����Դϴ�. 
1. ���� �ð��� ���̱� ���� ����� ���� �ʿ����� �ʽ��ϴ�. 
���� ������ �ð� ���⵵�� �����ϴ� ���� �Ұ����� ���� �ƴϳ�, ������ ������ N <= 100�� ��� ������ �� ī���� ������ 1�� ���� �̾ƺ��� ���� ���� ������ ���� �����̱� ������ ���� �غ��Ƶ� �ǰ�, �ݸ鿡 ������ �� ���� ������� Ž���� �ߵ��� �����ϵ��� �ϴ� ���� �ſ� �����մϴ�.
n(n-1)(n-2)
----------    : ��ü ����� ���� ��, C(n,3) �ִ� 1,000,000 ��( �鸸�� ��ǻ�Ͱ� ����� ����� �� �����Ƿ� ����Ž��������� ���� Ǯ��) 
3!

2. ���� ���, ���� ī�带 ������ �ʿ䰡 �����ϴ�. 
   ������ ��� ����� ���� ������ ���̱� �����Դϴ�.

3. ���� �߰��� break�� �� �ʿ䵵 �����ϴ�.
   �װ� ������ �������� ���ϴ� ��찡 ����ϴ�.
*/

/* Wrong implementation
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int n, m; 
vector<int> v;

bool compare(int a, int b)
{
	return a > b;
}

int main()
{
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i)
	{
		int num;
		scanf("%d", &num);
		v.push_back(num);
    } 
	sort(v.begin(), v.end(), compare);
	
	int sum = 0;
	int three = 3;
	while(1)
	{
		for(int i = 0; i < v.size(); ++i)
		{
			if(sum + v[i] <= m)
			{
				sum += v[i];
				--three;
			}
		}
		if(three)
			v.erase(v.begin());
		else
		{
			printf("%d", sum);
			break;
		}
	}

	
	return 0;
}
*/
