#include<bits/stdc++.h>
using namespace std;

int s, n, val;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//	freopen("input.txt", "rt", stdin);
	cin >> s >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> val;
		int idx = 0;		
		for(auto it = v.begin(); it != v.end(); it++) {
			if(v[idx] == val) {
				v.erase(it);
				break;
			}
			idx++;
		}
		v.push_back(val);
	}
	
	int i  = v.size() - 1;
	int end = v.size() - s - 1;
	while(true) {
		if(i == end) break;
		cout << v[i] << " ";
		i--;
	}

}