#include<bits/stdc++.h>
using namespace std;

int val;
priority_queue <int, vector<int>, greater<int>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);
	
	while(1) {
		cin >> val;
		switch(val) {
			case 0 : {
				if(pq.empty()) {
					cout << "-1" << "\n";
					break;
				}
				cout << pq.top() << "\n";
				pq.pop();
				break;
			}
			case -1 : {
				exit(0);
				break;
			}
			default : {
				pq.push(val);
				break;
			}
		}
	}

	return 0;
}