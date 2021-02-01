#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> v1;
vector<int> v2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;
		v1.push_back(val);
	}
	cin >> m;
	for(int i = 0; i < m; i++) {
		int val;
		cin >> val;
		v2.push_back(val);
	}
	
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	
	int size = v1.size() > v2.size() ? v1.size() : v2.size();
	int i = 0;
	int j = 0;
	while(true) {
		if(v1[i] == 0 || v2[j] == 0) break;
		
		if(v1[i] == v2[j]) {
			cout << v1[i] <<" ";
			i++;
			j++;
		}
		else if(v1[i] > v2[j]) {
			j++;
		}
		else {
			i++;
		}
		
	}
	
	return 0;
}