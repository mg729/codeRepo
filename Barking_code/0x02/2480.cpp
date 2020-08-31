#include<bits/stdc++.h>

using namespace std;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	for(int i = 0; i <3; i++) {
		int val;
		cin >> val;
		v.push_back(val);
	}
	int prize = 0;
	if(v[0] == v[1] &&
	   v[1] == v[2] &&
	   v[0] == v[2]) {
	   	prize = 10000 + v[0] * 1000;
	}
	else if(v[0] == v[1]) {
		prize = 1000 + v[0] * 100;	 	
	}
	else if(v[1] == v[2]) {
		prize = 1000 + v[1] * 100;	 
	} 
	else if(v[0] == v[2]) {
		prize = 1000 + v[2] * 100;	 
	}
	else {
		sort(v.begin(), v.end());
		prize = v[2] * 100;
	}

	cout << prize;
	return 0;
}
