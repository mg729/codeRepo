#include <bits/stdc++.h>
using namespace std;

list<char> str;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string memo;
	cin >> memo;
	
	for(auto i : memo)
		str.push_back(i);
	
	int tc;
	cin >> tc;
	
	auto cursor = str.end();
	
	while(tc){
		char input;
		cin >> input;
		switch(input) {
			case 'L' : {
				if(cursor != str.begin())
					cursor--;
				break;
			}
			case 'D' : {
				if(cursor != str.end())
					cursor++;
				break;
			}
			case 'B' : {
				if(cursor != str.begin()) {
					--cursor;
//					str.erase(cursor); --> error
					cursor = str.erase(cursor);	
				}
				break;
			}
			case 'P': {
				char alphabet;
				cin>> alphabet;
				
				str.insert(cursor,alphabet);
				
				break;
			}
		}
	
		tc--;
	}
	
	for(auto i : str) {
		cout << i;
	}
	
	return 0;
}

