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

/**
// # Using C++ two dimension vector 
   ## Be cautious with initialization!!

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
//solve By VECTOR
vector< vector<int> > v (101,  vector<int>(100001,0));  --> if you don't intilize then, you can't insert data in vector like "v[i][j] = value;"

int main(void) {
	int n, k;
	cin >> n >> k;
	
	for(int i = 1; i <= n; i++)
	{
		int weight;
		int value;
		cin >> weight >> value;
		for(int j = 1; j <= k; j++)
		{
			if(i == 0 || j == 0)
			{
				v[i][j] = 0;
			}
			else if( j < weight )
			{
				v[i][j] = v[i-1][j];
			}
			else //j >= w
			{
				v[i][j] = max( v[i-1][j] , v[i-1][j-weight]+value);
			}
		}
	}

	cout << v[n][k];
	
	return 0;
}

*/
