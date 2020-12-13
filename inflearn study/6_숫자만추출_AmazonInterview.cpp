#include<bits/stdc++.h>

using namespace std;
string input;
vector <string> v;
int numVal;
int sumFactor;

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "rt", stdin);
	
	cin >> input;
	for(int i = 0; i < input.lenth(); i++) {
		if(input[i] >= 48 && input[i] <= 57){
			if(v.empty() && input[i] == 48)
				continue;
		    v.push_back(input.substr(i,1));
		}
	}

    string number = "";
	for(int x = 0; x < v.size(); x++) {
		cout << v[x];
		number += v[x];
	}

	if(number.length() != 0) {
	    numVal = stoi(number);
	}

	for(int i = 1; i <= stoi(number) ; i++) {
		if(numVal % i == 0)
			++sumFactor;
	}
	cout << "\n" << sumFactor;
	return 0;
}
