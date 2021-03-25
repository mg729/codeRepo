#include<bits/stdc++.h>
using namespace std;

int n, val, grade;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//	freopen("input.txt", "rt", stdin);
	cin >> n;
	cin >> val;
	
	vector<int> v(n);
	v[0]  = val;

	vector<int>res(n);
	res[0] = 1;
	for(int i = 1; i < n; i++) {
		cin >> val;
		v[i] = val;
		
		grade = 1;
		for(int j = 0; j < i; j++) {
			if(val <= v[j]) {
				grade++;
			}
		}
		res[i] = grade;
	}
	
	for(auto x : res) {
		cout << x << " ";
	}
}