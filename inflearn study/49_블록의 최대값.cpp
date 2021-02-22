#include<bits/stdc++.h>
using namespace std;

int n;
int block[12][12];
int frontBlock[12];
int rightBlock[12];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//	freopen("input.txt", "rt", stdin);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		int val;
		cin >> val;
		frontBlock[i] = val;
	}
	for(int i = 1; i <= n; i++) {
		int val;
		cin >> val;
		rightBlock[i] = val;
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			block[j][i] = frontBlock[i];			
		}
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(rightBlock[i] < block[i][j]) block[i][j] = rightBlock[i];		
		}
	}
	
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(block[i][j] > 0) sum += block[i][j];
		}
	}
	cout << sum;
	
	return 0;
}