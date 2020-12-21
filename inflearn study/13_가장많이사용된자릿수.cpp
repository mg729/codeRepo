#include<bits/stdc++.h>

using namespace std;
string str;
int num[10] = {0,};
int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	
	cin >> str;
	for(int i = 0; i < str.length(); i++) {
		num[str[i]-48]++;
	}

	int maxVal = -1;
	int res = -1;
	for(int i = 0; i < 10; i++) {
		if(num[i] >= maxVal) {
			maxVal = num[i];
			res = i;
		}
	}
	cout << res;

	return 0;
}