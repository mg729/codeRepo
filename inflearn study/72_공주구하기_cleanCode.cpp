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

	while(!q.empty()) {
		for(int i = 1; i < k ; i++) {
			q.push(q.front());
			q.pop();
		}
		q.pop();
		if(q.size()==1) cout << q.front();		
	}
	
	return 0;
}