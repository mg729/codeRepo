#include <bits/stdc++.h>

using namespace std;

deque<int> dq;
queue<int> key;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n>> m;
	for(int i= 0; i < n; i++) {
		dq.push_back(i);
	}
	for(int i = 0; i < m; i++) {
		int val;
		cin>> val;
		key.push(val-1);
	}
	
	int sum = 0;
	int keyDat;
	int newDat;
	while(!key.empty()) {
		keyDat = key.front();
		int keyIndex = 0;
		
		for(int i = 0; i < dq.size(); i++) 
			if(keyDat == dq[i])
				keyIndex = i;
		
		if(dq.front() == keyDat) {
			dq.pop_front();
			key.pop();
		}
		else {
			if(keyIndex < dq.size() - keyIndex) {
				//Second rule
				newDat = dq.front();
				dq.pop_front();
				dq.push_back(newDat);
			}
			else {
				//Third rule
				newDat = dq.back();
				dq.pop_back();
				dq.push_front(newDat);		
			}
			++sum;
		}
	}
	
	cout << sum;
		
	return 0;
	
}
