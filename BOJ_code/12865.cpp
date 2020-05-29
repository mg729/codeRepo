#include <iostream>
#include <cstdio>
using namespace std;

int n, k, weight, value;
int dp[101][100001];

int main(void) {
	cin >> n >> k;
		
	for(int i = 1; i <= n; i++)
	{
		cin >> weight >> value;
		for(int j = 1; j <= k; j++)
		{
			if(i == 0 || j == 0)
			{
				dp[i][j] = 0;
			}
			else if( j < weight )
			{
				dp[i][j] = dp[i-1][j];
			}
			else //j >= w
			{
				dp[i][j] = max( dp[i-1][j] , dp[i-1][j-weight]+value);
			}
		}
	}

	cout << dp[n][k];
	
	return 0;
}
