#include <iostream>
#include <cstdio>
#include <vector>
/**
  Ÿ���� ���ʿ��� ���������� �̾ ���̴� ��� ���̰� i �� ������ �����ϴ� ����� �ΰ��� 
  (      )(1) or (    )(0)(0)
  ��i-1 ��       ��i-2 ��
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
	v[1] = 2;  //vector�� ���� ����Ʈ���ǹ��ϴµ� ���� v �����̳ʿ� �����Ͱ� ���µ��ε��� 0�� 1�� ������ �����Ϸ��ϴϱ� ������ 
	
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
