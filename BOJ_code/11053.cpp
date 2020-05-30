#include <iostream>
#include <cstdio>

using namespace std;

int dp[1001]; //length of the data
int num[1001]; //data
int n, val;

int main()
{
	cin >> n;
	dp[0] = 1;
	cin >> num[0];
	//dp[i] i를 포함하는 가장 긴 LIS의 길이 
	for(int i = 1; i < n ; i++)
	{
		int max = 0; 
		cin >> num[i];
		for(int j = 0; j < i ; j++)
		{
			if(num[j] < num[i] && dp[j] > max)
				max = dp[j];
		}
		dp[i] = max+1;
	}
		
	int max = dp[0]; 
	for(int i = 1; i <n; i++)
		if(dp[i] > max) max = dp[i];
	cout << max;
	
	return 0;
}
