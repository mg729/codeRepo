#include <bits/stdc++.h>
using namespace std;

int data[26];

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin >> s;
	
	for(auto c : s) 
		data[c-'a']++;  // c-'a'�� �������μ� c�� 'a'���ٸ� 0, 'b'���ٸ� 1, ������,  'z'���ٸ� 25
	for(int i = 0; i < 26; i++) {
		cout << data[i] << ' ';
	}
}
//----- my solution
//int main() {
//  string s = "abcdefghijklmnopqrstuvwxyz";
//  string str;
//  cin >> str;
//  for(int i = 0; i < s.size(); i++) {
//  	int count = 0;
//  	for(int j = 0; j <str.size(); j++) {
//	  if(s[i] == str[j]) {
//  	  	count++;
//	  }
//	}
//	cout << count << " ";
//  }
//}
