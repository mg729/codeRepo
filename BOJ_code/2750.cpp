#include <iostream>
#include <set>
//#include <algorithm>  --> for sort algorithm 
using namespace std;

int main()
{
	set<int> s;
	int n; 
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		
		s.insert(num);
	}
	
//	sort(s.begin(),s.end()); --> ERROR 
  	/**
	set������ �����ʹ� �̹� ���ĵǾ� ����ȴ�
	���������̾ƴ� �������� �������� ����� ���Ѵٸ�
	set�� ����Լ� rbegin �� rend�� Ȱ��  
	*/

	for(auto x: s)
		cout << x <<endl; 
		
	return 0;
}
