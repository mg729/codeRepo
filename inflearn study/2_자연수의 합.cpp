#include<bits/stdc++.h>

using namespace std;
int a,b;
int sum;
int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> a >> b;
	
	while(true) {
		if(a == b) 	break;
		cout << a << " + ";
		sum += a++;
	}

	cout << b << " = " << sum + b;
	return 0;
}