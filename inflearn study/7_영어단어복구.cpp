#include<bits/stdc++.h>

using namespace std;
string input;
vector<char> v;

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "rt", stdin);
	
	getline(cin, input);
	
	for(int i = 0 ; i< input.length(); i++) {
		if(input[i] >= 97 && input[i] <= 122) {
			v.push_back(input[i]);
		}
		else if(input[i] >= 65 && input[i] <= 90) {
			v.push_back(input[i] + 32);
		}
	}
	for(auto x : v) {
		cout << x;
	}
	
	return 0;
}