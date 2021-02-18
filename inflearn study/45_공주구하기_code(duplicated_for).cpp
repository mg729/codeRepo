#include<bits/stdc++.h>
using namespace std;

int n, k;
int arr[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//	freopen("input.txt", "rt", stdin);
	
	cin >> n >> k;
	
	int cnt = 1;
	while(1) {
		int isSaved = 0;
		for(int i = 1; i <= n; i++) {
			if(arr[i] == 0)	isSaved++;
			if(arr[i] == 1) continue;
			if(cnt == k) {
				cnt = 1;
				if(arr[i] == 0)	arr[i]  = 1;
				continue;
			}
			cnt++;
		}
		if(isSaved == 1) break;	
	}
	
	for(int i = 1; i <= n; i++) {
		if(arr[i] == 0) {
			cout << i;
			break;
		}
	}
	
	return 0;
}