// 진약수는 모두 1 부터 시작하므로 cout << 1 먼저 해주고 for문돌리기 
#include<bits/stdc++.h>

using namespace std;
int n;
int sum = 1;

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	int size = 0;
	cout << "1";
	
	for(int i = 2; i < n;i++) {
		if(n % i == 0) {
			cout << " + " << i;
			sum += i;
		}
	}
	cout << " = " << sum;
	
	return 0;
}

/**
#include<bits/stdc++.h>

using namespace std;
int n;
int sum;
vector <int> v;

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	int size = 0;
	for(int i = 1; i < n;i++) {
		if(n % i == 0) {
			v.push_back(i);
			size++;
		}
	}
	
	
	for(auto x : v) {
		if(x == v[size-1]) 
			break;
		cout << x << " + ";
		sum += x;
	}
	cout << v[size-1] << " = " << sum + v[size-1];
	
	return 0;
}
**/