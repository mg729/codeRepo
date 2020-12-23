#include<bits/stdc++.h>

using namespace std;

int n,m;

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	
	cin >> n >> m;
	
	int maxAlarm = -1;
	int house = 0;
	for(int i = 0 ; i < n ; i++) {
		int val;
		cin >> val;
		
		if(val > m) maxAlarm = max(maxAlarm, ++house);
		else house = 0;
	}
	
	cout << maxAlarm;

	
	return 0;
}