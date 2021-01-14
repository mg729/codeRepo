#include<bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	cin >> n;
	
	string str = "";
	for(int i = 1; i <=n ; i++) {
		str += to_string(i);
	}
	
	int numberOfThree = 0;
	for(int i = 0; i <= str.length(); i++) {
		if(str[i] -'0' == 3) numberOfThree++;
	}

	cout << numberOfThree;

	return 0;
}