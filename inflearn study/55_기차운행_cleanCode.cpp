#include<bits/stdc++.h>
using namespace std;

int n, val;
vector<char> str;
stack<int> num;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//	freopen("input.txt", "rt", stdin);
	cin >> n;
	int j = 1;
	for(int i = 1; i <= n; i++) {
		cin >> val;
		num.push(val);
		str.push_back('P');
		while(1) {
			if(num.empty()) break;
			if(j == num.top()) {
				num.pop();
				j++;
				str.push_back('O');
			}
			else break;
		}
	}
	
	if(!num.empty()) {
		cout << "impossible";
	}
	else {
		for(auto x : str) {
			cout << x;
		}
	}
	

	return 0;
}