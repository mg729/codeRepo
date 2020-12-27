#include<bits/stdc++.h>

using namespace std;
int tc;
int a[102];
int b[102];

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	
	cin >> tc;
	for(int i = 0; i < tc; i++) {
		int val;
		cin >> val;
		a[i] = val;		
	}
	for(int i = 0; i < tc; i++) {
		int val;
		cin >> val;
		b[i] = val;		
	}
	for(int i = 0 ; i < tc; i++) {
		if(a[i] == b[i]) cout << "D\n";
		else if (a[i] == 1 && b[i] ==3||
		         a[i] == 2 && b[i] ==1||
			     a[i] == 3 && b[i] ==2) {
			  	   cout << "A\n";
			     }
		else cout << "B\n";	
	}	
	
	
	return 0;
}