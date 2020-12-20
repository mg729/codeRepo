#include<bits/stdc++.h>

using namespace std;
int n;
int cnt;

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	
	cin >> n;
	
	if(n >= 3 && n <= 9) {
		cnt +=  n;
	}
	else if (n >= 10 && n <= 99) {
		cnt += 9;
		cnt += (n - 10 + 1) * 2;
	}
	else if (n >= 100 && n <= 999) {
		cnt += 9;
		cnt += (90) * 2;
		cnt += (n - 100 + 1) * 3;
	}
	else if (n >= 1000 && n <= 9999) {
		cnt += 9;
		cnt += (90) * 2;
		cnt += (900) * 3;
		cnt += (n - 1000 + 1) * 4;
	}
	else if (n >= 10000 && n <= 99999) {
		cnt += 9;
		cnt += (90) * 2;
		cnt += (900) * 3;
		cnt += (9000) * 4;	
		cnt += (n - 10000 + 1) * 5;
	}
	else if (n >= 100000 && n <= 999999) {
		cnt += 9;
		cnt += (90) * 2;
		cnt += (900) * 3;
		cnt += (9000) * 4;
		cnt += (90000) * 5;
		cnt += (n - 100000 + 1) * 6;
	}
	else if (n >= 1000000 && n <= 9,999,999) {
		cnt += 9;
		cnt += (90) * 2;
		cnt += (900) * 3;
		cnt += (9000) * 4;
		cnt += (90000) * 5;
		cnt += (900000) * 6;
		cnt += (n - 1000000 + 1) * 7;
	}
	else if (n >= 10000000 && n <= 99,999,999) {
		cnt += 9;
		cnt += (90) * 2;
		cnt += (900) * 3;
		cnt += (9000) * 4;
		cnt += (90000) * 5;
		cnt += (900000) * 6;
		cnt += (9000000) * 7;
		cnt += (n - 10000000 + 1) * 8;
	}
	else {
		cnt += 9;
		cnt += (90) * 2;
		cnt += (900) * 3;
		cnt += (9000) * 4;
		cnt += (90000) * 5;
		cnt += (900000) * 6;
		cnt += (9000000) * 7;
		cnt += (90000000) * 8;
		cnt += 	9;
	}

	cout << cnt;
	
	return 0;
}