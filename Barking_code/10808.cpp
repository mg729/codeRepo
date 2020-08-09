#include <bits/stdc++.h>
using namespace std;

int main() {
  string s = "abcdefghijklmnopqrstuvwxyz";
  string str;
  cin >> str;
  for(int i = 0; i < s.size(); i++) {
  	int count = 0;
  	for(int j = 0; j <str.size(); j++) {
	  if(s[i] == str[j]) {
  	  	count++;
	  }
	}
	cout << count << " ";
  }
}
