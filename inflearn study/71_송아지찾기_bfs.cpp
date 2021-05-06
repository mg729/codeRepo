#include<bits/stdc++.h>
using namespace std;
// *** my solution :: check 배열이 없음 --> check 배열 구현해서 같은 노드에 대해 중복탐색방지
int s, e, cnt;
queue<int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	
	cin >> s >> e;
	int tmp = s;
	if(s > e) {
		while(1) {
			if(tmp == e) break;
			cnt++;
			tmp -= 1;
		}
	}
	else if(s == e) {
		cnt = 0;
	}
	else { // s < e
		q.push(tmp);
		while(q.front() != e) {
			tmp = q.front();
			int a = tmp + 1;
			int b = tmp - 1;
			int c = tmp + 5;
			q.pop();
			
			int minVal = a;
			if(abs(a-e) > abs(b-e)) minVal = b;
			else if(abs(b-e) > abs(c-e)) minVal = c;
			
			q.push(minVal);
			cnt++;
		}
	}
	
	cout << cnt;
	
	return 0;
}
