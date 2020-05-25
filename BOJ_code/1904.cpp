#include <iostream>
#include <cstdio>
#include <vector>

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
