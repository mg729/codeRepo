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
	
	int maxVal = s[n-1];
	
	for(int i = n-2; i > -1; i--) {
		if(maxVal < s[i]) {
			ans++;
			maxVal = s[i];
		}
	}
	
	cout << ans;
	return 0;
}
