#include <iostream>
#include <cstdio>
#include <vector>
/**
  타일을 왼쪽에서 오른쪽으로 이어서 붙이는 경우 길이가 i 인 수열을 형성하는 방법은 두가지 
  (      )(1) or (    )(0)(0)
  └i-1 ┘       └i-2 ┘
*/
using namespace std;

vector<int> v;

int main(void) {
	int n;
	cin >> n;
	
	v.push_back(1);
	v.push_back(2);
	
	for(int i = 2; i < n; ++i)
	{
		v.push_back((v[i-1] + v[i-2]) % 15746);
	}
	cout << v[n-1];
	return 0;
}

/**

int main(void) {
	int n;
	cin >> n;
	
	v[0] = 1;  //check why not working????
	v[1] = 2;  //vector는 동적 리스트를의미하는데 현재 v 컨테이너에 데이터가 없는데인덱스 0과 1을 가지고 접근하려하니까 에러남 
	
	for(int i = 2; i < n; ++i)
	{
		v.push_back((v[i-1] + v[i-2]) % 15746);
	}
	for(auto x : v)
	{
		cout << x;
	}
	return 0;
}
*/
