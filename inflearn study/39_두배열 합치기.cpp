#include<bits/stdc++.h>
using namespace std;

int n , m;
vector<int> v1;
vector<int> v2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	cin >> n;
	for(int i =0; i < n; i++) {
		int val;
		cin >> val;
		v1.push_back(val);
	}
	cin >> m;
	for(int i =0; i < m; i++) {
		int val;
		cin >> val;
		v2.push_back(val);
	}
	
	int pos1 = 0;
	int pos2 = 0;
	for(int i = 0; i<n+m; i++) {
		if(v1[pos1] < v2[pos2]) {
			cout << v1[pos1] << " ";
			pos1++;
		}
		else if(v1[pos1] >= v2[pos2]){
			cout << v2[pos2] << " ";
			pos2++;
		}
		if(pos1 >= v1.size()) {
			for(int j = pos2 ; j < m; j++) cout << v2[j] << " ";
			break;
		}
		if(pos2 >= v2.size()) {
			for(int j = pos1 ; j < n; j++) cout << v1[j] << " ";
			break;
		}
	}

	return 0;
}