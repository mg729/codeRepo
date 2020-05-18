#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
// substr() 함수 활용
// npos가 -1 인것
// while문에 s.find() 하면 0이 나오는 경우있음 배열 s의 첫번째요소를 찾아낸 경우
// 그래서 string::npos쓰는거..
// 그리고 반복문내에서 found 계속 갱신하는 것 유의
// 와.. 예외상황 체크할 부분이 매우 많네요 
int main()
{
	string s;
	getline(cin, s);
	
	string cmp_s;
	getline(cin, cmp_s);
	
	int count = 0;
	
	size_t found = s.find(cmp_s);
	
	while(found != string::npos)
	{
		s.substr(found, cmp_s.size());
		
		++count;
		found = s.find(cmp_s);  // 이부분을 계속 빼먹었네..! 예외조건 체크 필수... 
	}
	
	cout << count;
	
	return 0;
}
