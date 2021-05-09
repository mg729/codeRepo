#include<bits/stdc++.h>
using namespace std;

int n, k, val;
queue <int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	cin >> n >> k;
	for(int i = 1; i<=n; i++) {
		q.push(i);
	}
	
	while(q.size() != 1) {
		int tmp = k-1;
		int qFront = q.front();
		while(1) {
			if(tmp == 0) {
				q.pop();
				break;
			}
			qFront = q.front();
			q.pop();
			q.push(qFront);
			
			tmp--;
		}		
	}
	cout << q.front();

	return 0;
}