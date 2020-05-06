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
	set내부의 데이터는 이미 정렬되어 저장된다
	오름차순이아닌 내림차순 정렬으로 출력을 원한다면
	set의 멤버함수 rbegin 과 rend를 활용  
	*/
<<<<<<< HEAD

	for(auto x: s)
		cout << x <<endl; 
		
=======
>>>>>>> b7f20e7962851bbfd208c7c50cd81da17c1ca7c6
	return 0;
}
