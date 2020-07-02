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

/**

#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int maxLength[1001];

int main()
{
	int n;
	cin >> n;
	if(n == 1)
	{
		cout << 1;
		return 0;
	}
	
	for(int i = 0; i < n; i++)
	{
		int val;
		cin >> val;
		v.push_back(val);
	}
	int count = 0;
	int cmp = v[0];
	for(int i = 0; i < n; i++)
	{
		if(cmp < v[i+1])
		{
			maxLength[i+1] = ++count;
			cmp = v[i+1];
		}
	}
	
	int answer = 0;  //never be 0
	for(int i = 1; i <= n; i++)
	{
		answer = answer > maxLength[i] ? answer : maxLength[i];
	}
	
	cout << answer;
	
	return 0;
}
*/
