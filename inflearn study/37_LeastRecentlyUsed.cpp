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
		
		if(pos >= 0) { //pos is the index of the same data --> insert pos data at the front
			int tmp = cache[pos];
			for(int j = pos-1 ; j >= 0; j--) {
				cache[j+1] = cache[j];
			}
			cache[0] = tmp;
		}
		else { //have not found same data --> insert new data at the front
			for(int j = s ; j >= 0; j--) {
				cache[j+1] = cache[j];
			}
			cache[0] = val;
		}
	}
	for(int i = 0; i < s; i++) {
		cout << cache[i] << " ";
	}


	
	
	return 0;
}
