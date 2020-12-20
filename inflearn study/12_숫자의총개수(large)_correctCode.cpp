#include<bits/stdc++.h>

using namespace std;
int n;
int cnt;
int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	
	cin >> n;

	int i = 1;
	int val = 1;

	while(val * 10 <= n) {
		cnt += (9 * val) * i;
		val *= 10;
		i++;
	}

	cout << cnt + (( n - (val) + 1 ) * i);
	
	return 0;
}