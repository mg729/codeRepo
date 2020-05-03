#include <iostream>
#include <vector>

using namespace std;

/**
��Dynamic Programming 
- ������, �Ǻ���ġ ���� : ���Ϲ��������� �ش��� Ȱ���ϴ� Ǯ�̹�
 
array[n] = array[n] + array[n-1] 
n�� ° ���� �հ� n��° ���� ���ϸ� n ��°������ ���� ���� 
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
