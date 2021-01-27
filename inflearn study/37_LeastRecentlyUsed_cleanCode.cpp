#include<bits/stdc++.h>
using namespace std;

int s, n;
int cache[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	cin >> s >> n;
	
	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;
		int pos = -1;
		for(int j = 0; j < s; j++) {
			if(cache[j] == val) {
				pos = j;
				break;
			}
		}
		
		if(pos >= 0) {
			for(int j = pos; j > 0; j--) cache[j] = cache[j-1];
		}
		else {
			for(int j = s-1; j > 0; j--) cache[j] = cache[j-1];
		}
		cache[0] = val;
		
	}
	for(int i = 0; i < s; i++) {
		cout << cache[i] << " ";
	}
	
	return 0;
}