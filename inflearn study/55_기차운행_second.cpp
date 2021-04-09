#include<bits/stdc++.h>
using namespace std;

int n, val;
vector<int> v;
string str;
stack<int> sNum;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//	freopen("input.txt", "rt", stdin);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> val;
		v.push_back(val);
	}

	int order = 1;
	for(int i = 0, j = 0; i < n * 2; i++) {
		if(!sNum.empty() && sNum.top() == order) {
			sNum.pop();
			str.append("O");
			order++;
			continue;
		}
		if(j < n) {
			str.append("P");
			sNum.push(v[j]);
			j++;
		}
	}
	
	if(!sNum.empty()) cout << "impossible";
	else cout << str;
		
	return 0;
}
