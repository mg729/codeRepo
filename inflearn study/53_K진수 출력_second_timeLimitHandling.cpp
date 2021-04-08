#include<bits/stdc++.h>
using namespace std;

int n, k;
stack<int> s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//	freopen("input.txt", "rt", stdin);
	cin >> n >> k;
	char str[20] = "0123456789ABCDEF";
    // Below is the Error Code
    /*
	while(true) {
		s.push(n%k);
		n /= k;
		if(n==1)  {
			s.push(1);
			break;
		}
	}
	*/
    while(n>0) {
		s.push(n%k);
		n /= k;
	}
	
	
	while(!s.empty()){
		cout << str[s.top()];
		s.pop();
	}
	
	return 0;
}
