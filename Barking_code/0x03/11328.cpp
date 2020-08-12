#include <bits/stdc++.h>
using namespace std;
int freq1[26];
int freq2[26];
int tc;	
/**
Below test case will pass only when
two strings' length are equal
*/
int main() {

	cin >> tc;
	
	for(int i = 0; i <tc; i++) {
		ios::sync_with_stdio(0);
		cin.tie(0);
		
		// should intialize all data again for each test cases
		// std::fill
		fill(freq1, freq1+26, 0);
		fill(freq2, freq2+26, 0);
		
		string s1, s2;
		cin >> s1 >> s2;
		
		if(s1.length() != s2.length())
        {
            cout << "Impossible\n";
            continue;
        }
        
		for(auto c : s1) {
			freq1[c-'a']++;
		}
		
		for(auto c : s2) {
			freq2[c-'a']++;
		}
		bool validateStrfry = true;
//		for(int i = 0, j = 0 ; i<26 && j<26; i++, j++) {
		for(int i = 0; i<26 ; i++) {
			if(freq1[i] != freq2[i]){
				validateStrfry = false;
				break;
			}
		}
		if(validateStrfry)
			cout << "Possible\n" ;
		else
			cout << "Impossible\n";

	}
	return 0;	
}
/**
The code will pass for all below cases
case 1: a aaaaa
case 2: aaaaa a
case 3 : a a
https://www.geeksforgeeks.org/given-two-strings-find-first-string-subsequence-second/
*/
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	
//	int tc;	
//	cin >> tc;
//	
//	for(int i = 0; i <tc; i++) {
//		// fill
//		fill(freq1, freq1+26, 0);
//		
//		string s1;
//		string s2;
//		cin >> s1 >> s2;
//		
//		if(s1.length() < s2.length())
//			s1.swap(s2);
//			
//		for(auto c : s1)
//			freq1[c-'a']++;
//		
//	
//		bool validateStrfry = true;
//		for(auto c : s2) {
//			
//			if(freq1[c - 'a'] == 0)
//			{
//				validateStrfry = false;
//				break;
//			}
//			freq1[c-'a']--;
//		}
//		
//		if(validateStrfry)
//			cout << "Possible\n" ;
//		else
//			cout << "Impossible\n";
//
//	}
//	return 0;	
//}
