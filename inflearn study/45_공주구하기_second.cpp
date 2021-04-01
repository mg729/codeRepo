#include<bits/stdc++.h>
using namespace std;

// simulation quizz
int n, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//	freopen("input.txt", "rt", stdin);
	cin >> n >> k;
	
	vector<int> v(n);
	
	int isLimitSize = 0;
	int cnt = 0;
	int pos = 0;
	while(true) {
		if(v[pos] == 0) {
			cnt++;
			if(cnt == k && v[pos] == 0) {
				isLimitSize++;
				v[pos] = 1;
				cnt = 0;
			}
		}		
		pos++;
		if(pos == n) pos = 0;
		if(isLimitSize == n-1) break;
	}
	
	for(int i = 0; i < n; i++) {
		if(v[i] == 0) {
			cout << i+1;
		}
	}

	return 0;
}
