#include<bits/stdc++.h>
using namespace std;

int n,m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("input.txt", "rt", stdin);
	
	cin >> n; 
	vector<int> v1(n);
	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;
		v1[i] = val;
	}
	cin >> m;
	vector<int> v2(m);
	for(int i = 0; i < m; i++) {
		int val;
		cin >> val;
		v2[i] = val;
	}
	
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	
	int i = 0;
	int j = 0;
	while(i < v1.size() && j <v2.size()) {		
		if(v1[i] == v2[j]) {
			cout << v1[i] <<" ";
			i++;
			j++;
		}
		else if(v1[i] > v2[j]) j++;
		else i++;
	}
	
	return 0;
}