#include <bits/stdc++.h>

using namespace std;

queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	for(int i = 1; i <=n; i++) {
		q.push(i);
	}
	
	while(true) {
		if(q.size() == 1)
			break;
		q.pop();
		
		q.push(q.front());
		q.pop();	
			
	}
	
	cout << q.front();
	return 0;
}
