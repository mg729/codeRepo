#include <bits/stdc++.h>
using namespace std;
int num[10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int roomNum;
	cin >> roomNum;
	
	if(roomNum == 0){
		cout << 1;
		return 0;
	}
	
	while(true) {
		num[roomNum % 10]++;
		if (roomNum/10 ==0)
			break;
		roomNum /= 10;
	}
	
	int sum = 0;
	for(int i = 0; i < 10 ; i++) {
		if(i != 6 && i != 9)
			sum = max(sum, num[i]);
	}

	cout << max(sum, (num[6] + num[9] +1)/2 );
	return 0;	
}

// ####-------------- my solution
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	
//	string room;
//	cin>> room;
//	
//	if(stoi(room) == 0){
//		cout << room.length();
//		return 0;
//	}
//	
//	int roomNum = stoi(room);
//	while(roomNum > 0) {
//		num[roomNum % 10]++;
//		roomNum /= 10;
//	}
//	
//	int sum = 0;
//	for(int i = 0; i < 10 ; i++) {
//		if(i == 6 || i == 9)
//			continue;
//		sum = num[i] > sum ? num[i] : sum;
//	}
//
//	int set = 0;
//	if(num[6] != 0 || num[9] != 0) {
//		if((num[6] + num[9]) % 2 == 0)
//			set += (num[6] + num[9])/2;
//		else
// 			set += ( (num[6] + num[9])/2 )+ 1;
//
// 		sum = set > sum ? set : sum;
//    }
//
//	cout << sum;
//	return 0;	
//}
