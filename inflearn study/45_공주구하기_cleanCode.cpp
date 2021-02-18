#include<bits/stdc++.h>
using namespace std;

int n, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//	freopen("input.txt", "rt", stdin);
	
	cin >> n >> k;
	vector<int> v(n+1); // n+1 만큼 0으로 vector 값 할당하기 
	
	int bp = 0; // breakpoint
	int cnt = 0; // need to be compared with k
	int pos = 1;
	while(1) {
		if(bp == n-1) break;
		if(pos == n+1) pos = 1;
		if(v[pos] == 0) {
			cnt++;
			if(cnt == k) {
				v[pos] = 1;
				bp++;
				cnt = 0;
			}
		}
		pos++;
		
	}
	
	for(int i = 1; i <= n; i++) {
		if(v[i] == 0) {
			cout << i;
			break;
		}
	}
	
	return 0;
}