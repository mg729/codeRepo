#include<bits/stdc++.h>

using namespace std;

int tc;
int num[1002];

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	cin >> tc;
	
	for(int i = 1; i < 1001; i++) {
		num[i] = i + num[i-1] ;
	}
	
	for(int i = 0; i < tc; i++) {
		int guess, res;
		cin>> guess >> res;
		if(num[guess] == res) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}