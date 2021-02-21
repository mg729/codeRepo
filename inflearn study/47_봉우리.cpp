#include<bits/stdc++.h>
using namespace std;

int n;
int arr[51][51];
int top[51][51];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//	freopen("input.txt", "rt", stdin);
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int val;
			cin >> val;
			arr[i][j] = val;
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i-1 < 0 && j-1 < 0) {
				if(arr[i][j] > arr[i+1][j] &&
				   arr[i][j] > arr[i][j+1]) {
				   	top[i][j] = 1;
				}	
			}
			else if(i-1 < 0) {
				if(arr[i][j] > arr[i+1][j] &&
				   arr[i][j] > arr[i][j-1] &&
				   arr[i][j] > arr[i][j+1]) {
				   	top[i][j] = 1;
				}		
			}
			if(j-1 < 0) {
				if(arr[i][j] > arr[i-1][j] &&
				   arr[i][j] > arr[i+1][j] &&
				   arr[i][j] > arr[i][j+1]) {
				   	top[i][j] = 1;
				}		
			}
			else {
				if(arr[i][j] > arr[i-1][j] &&
				   arr[i][j] > arr[i+1][j] &&
				   arr[i][j] > arr[i][j-1] &&
				   arr[i][j] > arr[i][j+1]) {
				   	top[i][j] = 1;
				}	
			}
		}
	}
	
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(top[i][j] == 1) cnt++;
		}
	}
	cout << cnt;
	
	return 0;
}

