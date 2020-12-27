#include<bits/stdc++.h>

using namespace std;
int a[10];
int b[10];
int aCnt;
int bCnt;
int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);

	for(int i = 0; i < 10; i++) {
		int val;
		cin >> val;
		a[i] = val;
	}
	for(int i = 0; i < 10; i++) {
		int val;
		cin >> val;
		b[i] = val;
	}
	bool isD = true;
	char isLast = 'd';
	for(int i = 0; i < 10; i++) {	
		if(a[i] != b[i]) {
			isD = false;
			if(a[i] > b[i]) {
				aCnt += 3;
				isLast = 'a';
			}
			else {
				bCnt += 3;
				isLast = 'b';
			}
		}
		else {
			aCnt++;
			bCnt++;
		}
	}
	
	if(isD) {
		cout << aCnt << " " << bCnt << "\n" << "D";
	}
	else {
		cout << aCnt << " " << bCnt << "\n";
		if(aCnt > bCnt)	cout << "A";
		else if(aCnt < bCnt) cout << "B";
		else {
			if(isLast == 'a') cout << "A";
			else cout << "B";
		}
	}

	return 0;
}