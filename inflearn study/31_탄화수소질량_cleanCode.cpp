#include<bits/stdc++.h>
using namespace std;
int c, h, i , pos;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);
	char a[10];
	
	cin >> a;
	if(a[1] == 'H') {
		c = 1;
		pos = 1;
	}
	else {
		for(i = 1; a[i] != 'H' ; i++) {
			c = c*10 + (a[i] - 48);
		}
		pos = i;
	}

	if(a[pos+1] == '\0') h=1;
	else {
		for(i = pos +1 ; a[i] != '\0'; i++) {
			h = h*10 + (a[i] - 48);
		}
	}
    cout << c*12 + h;
    
	return 0;
}
