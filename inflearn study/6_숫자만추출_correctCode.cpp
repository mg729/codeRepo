#include<bits/stdc++.h>

using namespace std;
string input;
int result;
int num;
int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "rt", stdin);
	
	cin >> input;
	for(int i = 0; i < input.length(); i++) {
		if(input[i] >= 48 && input[i] <= 57){
			result = result * 10 + (input[i] - 48);
		}
	}

	for(int i = 1; i <= result; i++) {
		if(result % i == 0)
			num++;
	}
	cout << result << "\n" << num;

	return 0;
}
