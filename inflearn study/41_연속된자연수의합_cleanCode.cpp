#include<bits/stdc++.h>
using namespace std;

int n,cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);
	cin >> n;
	int tmp = n; // store n value in tmp variable to print out 
	
	int i = 1;
	n--;
	while(n>0) {
		i++;
		n = n - i;
		if(n % i == 0) {
			int j;
			for(j= 1; j < i; j++) {
				cout << (n/i)+j <<" + ";
			}
			cout << (n/i)+j <<" = "<<tmp << "\n";
			cnt++;
		}
	}
	cout << cnt;
	
	return 0;
}