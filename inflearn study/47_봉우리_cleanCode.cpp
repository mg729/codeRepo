#include<bits/stdc++.h>
using namespace std;

int n, cnt;
int arr[52][52]; // 51 은 오류 --> 가장자리를 0으로 세팅해 놓을 것이므로  
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("input.txt", "rt", stdin);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			int val;
			cin >> val;
			arr[i][j] = val;
		}
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			bool isTop = true;
			for(int dir= 0; dir < 4; dir++) {
				if(arr[i+dx[dir]][j+dy[dir]] > arr[i][j]) {
                    isTop = false;
                    break;
                }
			}
			if(isTop) cnt++;
		}
	}

	cout << cnt;
	
	return 0;
}

