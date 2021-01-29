#include<bits/stdc++.h>
using namespace std;

int n;
int arr[101];
int res[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;
		arr[i] = val;
	}
	int round = 0;
	for(int i = n-1; i >= 0; i--) {
		int pos = arr[i];
		if(res[pos] != 0) {
			int tmp = pos;
			for(int j = round; j>= tmp; j--) {
				res[j+1] = res[j];
			}
		}
		res[pos] = i+1;
		round++;
	}
	
	for(int i = 0; i < n; i++) {
		cout << res[i] << " " ;
	}
	


	return 0;
}