#include <bits/stdc++.h>
using namespace std;
int freq1[26];
int freq2[26];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s1,s2;
	cin >> s1 >> s2;
	
	for(auto c : s1) {
		freq1[c - 'a']++;
	}
	
	for(auto c : s2) {
		freq2[c - 'a']++;
	}
	
	int eraseData = 0;
	for(int i = 0; i <26; i++) {
		int s1Data = freq1[i];
		int s2Data = freq2[i];
		if(s1Data  == s2Data) {
			continue;
		}
		else {
			if(s1Data > s2Data)
				eraseData += (s1Data - s2Data);
			else
				eraseData += (s2Data - s1Data);
		}
	}
	
	cout << eraseData;
	return 0;	
}
