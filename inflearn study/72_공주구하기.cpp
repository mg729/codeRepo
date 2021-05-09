#include<bits/stdc++.h>
using namespace std;

int n, k, val;
int prince[1002];
int arr[1002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	cin >> n >> k;
	for(int i = 1; i<=n; i++) {
		prince[i] = i;
	}
	
	int pos = 1;
	while(1) {
		int tmp = k;
		while(tmp) {
			if(pos > n) pos = 1;
			if(arr[pos] == 0) {
				tmp--;
			}
			pos++;
		}
		arr[--pos] = 1;
		
		int count = 0;
		int idx = 0;
		for(int i = 1; i <=n ; i++) {
			if(arr[i] == 0) {
				count++;
				idx = i;
			}
		}
		if(count == 1) {
			cout << prince[idx];
			break;
		}
	}

	return 0;
}