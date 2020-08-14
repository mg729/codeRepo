#include <bits/stdc++.h>
using namespace std;

int girls[7];
int boys[7];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n; // number of all students 
	int k; //max number of student of each room
	
	cin >> n >> k;
	
	int gender;
	int grade;
	
	for (int i = 0; i < n; i++) {
		cin >> gender >> grade;
		if(gender == 0) {
			girls[grade]++;
		}
		else {
			boys[grade]++;
		}
	}
	
	int gRoom = 0;
	for(int i = 1; i < 7; i++) {
		if(girls[i] == 0)
			continue;
		
		while(girls[i] > k) {
			girls[i] -= k;
			gRoom++;
		}
		gRoom++;
	}
	
	int bRoom = 0;
	for(int i = 1; i < 7; i++) {
		if(boys[i] == 0)
			continue;
		
		while(boys[i] > k) {
			boys[i] -= k;
			bRoom++;
		}
		bRoom++;
	}
	
	cout << gRoom + bRoom;
}
