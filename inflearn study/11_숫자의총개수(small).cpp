#include<bits/stdc++.h>

using namespace std;
int n;
int cnt;

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	
	cin >> n;
	
	for(int i = 1; i <= n; i++) {
		int tmp = i;
		while (tmp > 0) {
			tmp /= 10;
			cnt++;
		}
	}
	cout << cnt;
	
	return 0;
}