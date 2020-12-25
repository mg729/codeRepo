#include<bits/stdc++.h>

using namespace std;
int n;
int s[102]; //student
int ans;

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;
		s[i] = val;
	}
	bool isTall = true;
	for(int i = 0; i < n-1; i++) {
		isTall = true;
		for(int j = i+1; j < n; j++) {
			if(s[i] < s[j]) {
				i = j -1;
				isTall = false;
				break;
			}
		}
		if(isTall) ans++;
	}
	
	cout << ans;
	return 0;
}
