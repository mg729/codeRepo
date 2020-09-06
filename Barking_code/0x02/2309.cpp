#include<bits/stdc++.h>

using namespace std;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	for(int i = 0; i < 9; i++) {
		int val;
		cin >> val;
		v.push_back(val);
	}
	
	int sum = 0;
	for(auto x : v) {
		sum += x;
	}
	
	int temp = sum;
	sort(v.begin(), v.end());
	
	int one = 0;
	int two = 0;
	
	for(int i = 0; i < 8; i++) {
		temp -= v[i];
		for(int j = 1; j<9;j++) {
			temp -= v[j];
			if(temp == 100) {
				one = i;
				two = j;
				break;
			}
			temp += v[j];
		}
		if(temp == 0)
			break;
		temp+= v[i];
	
	}
	
	for(int i = 0; i <9 ; i++) {
		if(i == one || i == two)
			continue;
		cout << v[i] << '\n';
	}
	
	
	return 0;	
}

