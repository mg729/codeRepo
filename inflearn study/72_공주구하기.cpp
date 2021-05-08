#include<bits/stdc++.h>
using namespace std;

int n, k;
int arr[1002];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);
	cin >> n >> k;
	
	int pos = 1;
	int size = n;
	while(1) {
		for(int i = 1; i <= k; i++) {
			if(pos > n) pos = 1; /// 여기 어캐바꾸지... 
			if(i == k)  {
				cout << pos << endl;
				arr[pos] = 1;
			}
			pos++;
		}
		
		int count = 0;
		int lastVal;
		for(int i = 1; i <=n ; i++) {
			if(arr[i] == 0) {
				count++;
				lastVal = i;
			}
		}
		if(count == 1) {
			cout << lastVal;
			break;
		}
	}
	
	return 0;
}