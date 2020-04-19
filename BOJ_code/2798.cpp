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
이 문제는 모든 경우의 수를 정직하게 따져보는 것이 의도인 문제입니다. 
1. 수행 시간을 줄이기 위한 묘기는 따로 필요하지 않습니다. 
물론 실제로 시간 복잡도를 개선하는 것이 불가능한 것은 아니나, 문제의 제한인 N <= 100은 모든 가능한 세 카드의 조합을 1초 내에 뽑아보는 데에 전혀 무리가 없는 제한이기 때문에 전부 해보아도 되고, 반면에 증명할 수 없는 방법으로 탐색을 중도에 종료하도록 하는 것은 매우 위험합니다.
n(n-1)(n-2)
----------    : 전체 경우의 수는 약, C(n,3) 최대 1,000,000 임( 백만은 컴퓨터가 충분히 계산할 수 있으므로 완전탐색방법으로 문제 풀이) 
3!

2. 예를 들어, 굳이 카드를 정렬할 필요가 없습니다. 
   어차피 모든 경우의 수를 따져볼 것이기 때문입니다.

3. 루프 중간에 break를 할 필요도 없습니다.
   그것 때문에 따져보지 못하는 경우가 생깁니다.
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
