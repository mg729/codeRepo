#include<bits/stdc++.h>
using namespace std;

int n;
int res1 , res2;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	cin >> n;

	for(int i = 2; i <= n; i++) {
		int j = 2;
		int tmp = i;
		while(1) {
			if(tmp % j == 0) {
				if(j == 2) res1++;
				else if(j == 5) res2++;
				tmp /= j;
			}
			else {
				j++;
			}			
			if(tmp == 1) break;
		}
	}
	
	if(res1 > res2) cout << res2;
	else cout << res1;
	
	return 0;
}