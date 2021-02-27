#include<bits/stdc++.h>
using namespace std;

int n, m, h, w, sum;
int arr[52][52];

int maxVal = -1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//	freopen("input.txt", "rt", stdin);
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m ; j++) {
			int val;
			cin >> val;
			arr[i][j] = val;
		}
	}
	
	cin >> h >> w;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			sum = 0;
			int idx1 = i;
			int idx2 = j;
			if((idx1 + h) <= n && (idx2 + w) <= m) {
				for(int index1 = 0; index1 < h; index1++) {
					idx2 = j;
					for(int index2 = 0; index2 < w; index2++) {
						sum += arr[idx1][idx2];
						idx2++;
					}
					idx1++;
				}
			}
			maxVal = max(maxVal, sum);
		}
	}
	
	cout << maxVal;

	return 0;
}