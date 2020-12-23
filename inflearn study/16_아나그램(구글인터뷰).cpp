#include<bits/stdc++.h>

using namespace std;

int capLetter[25];
int smallLetter[25];

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	
	string str1,str2;
	cin >> str1 >> str2;
	
	if(str1.length() != str2.length()) {
		cout << "NO";
		return 0;
	}
	
	for(auto x : str1) {
		if(x >=65 && x <=90) smallLetter[x-65]++;
		else capLetter[x-97]++;
	}
	
	for(auto x : str2) {
		if(x >=65 && x <=90) {
			smallLetter[x-65]--;
			if(smallLetter[x-65] < 0) {
				cout << "NO";
				return 0;
			}
		}
		else {
			capLetter[x-97]--;
			if(capLetter[x-97] < 0) {
				cout << "NO";
				return 0;
			}
		}
	}
	
	cout << "YES";

	
	return 0;
}