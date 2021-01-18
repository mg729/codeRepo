#include<bits/stdc++.h>
using namespace std;

string cVal, hVal;
string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);

	cin >> str;
	int i = 0;
	while(1) {
		i++;
		if(str[i] == 'H') break;
		string s = to_string(str[i] - 48);
		cVal += s;
	}
	i++;
	while(1) {
		if(!str[i]) break;
		string s = to_string(str[i] - 48);
		hVal += s;
		i++;
	}
	if(cVal == "") cVal += '1';
	if(hVal == "") hVal += '1';
	cout << stoi(cVal) * 12 + stoi(hVal) ;

	return 0;
}