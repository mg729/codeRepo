#include<bits/stdc++.h>
using namespace std;

// Solution 2 :: clean Code
int s, e, qFront, pos;
int check[10002];
int dir[3] = {1, -1, 5};
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);
	
	cin >> s >> e;
	q.push(s);
	check[s] = 1;
	while(1) {
		qFront = q.front();
		q.pop();
		
		for(int i = 0; i < 3; i++) {
			pos = qFront + dir[i];
			if(pos <= 0 || pos > 100000) continue;
			if(pos == e) {
				cout << check[qFront]; // not check[pos] --> line17 starts from 1 
				exit(0);
			} 
			else if(check[pos] == 0) {
				check[pos] = check[qFront] + 1; // pos지점까지가는데 걸린 최단 거리 횟수 
				q.push(pos);
			}
		}
	}
	return 0;
}
