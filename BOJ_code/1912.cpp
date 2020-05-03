#include <iostream>
#include <vector>

using namespace std;

/**
※Dynamic Programming 
- 연속합, 피보나치 수열 : 동일문제에대한 해답을 활용하는 풀이법
 
array[n] = array[n] + array[n-1] 
n번 째 이전 합과 n번째 수를 더하면 n 번째까지의 합이 나옴 
*/
int main()
{
	int n;
	cin >> n;
	
	vector <int> v;
	for(int i = 0; i < n; ++i)
	{
		int val;
		cin >> val;
		v.push_back(val);
	}
	
	int maxSum = v.front();
		
	for(int i = 1; i < n; ++i)
	{
		v[i] = max(v[i], v[i] + v[i-1]);
		maxSum = max(maxSum, v[i]);
	}
	
	cout << maxSum;
	
	return 0;
}
