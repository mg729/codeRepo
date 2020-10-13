#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int fj[100002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	
	fill(fj, fj+100001, -1);
    	
	queue<int> q;
	q.push(n);
	fj[n] = 0;
	
	while(fj[k] == -1) {
		int cur = q.front();
		q.pop();
		
		for(int nxt : {cur-1, cur+1, cur*2}) {
			if(nxt < 0 || nxt > 100000) continue;
			if(fj[nxt] != -1) continue;
			fj[nxt] = fj[cur] + 1;
			q.push(nxt);
		}
	}
	
//	while(!q.empty()) {
//		auto cur = q.front();
//		q.pop();
//		
//		for(int dir = 0; dir <3; dir++) {
//			int pos;
//			switch(dir) {
//				case 0 : {
//					pos = cur + 1;
//					break;
//				}
//				case 1 : {
//					pos = cur - 1;
//					break;
//				}
//				case 2 : {
//					pos = cur * 2;
//					break;
//				}
//			}
//
//			if( pos < 0  || pos > 100000) continue;
//			if( fj[pos] != -1 ) continue;
//			fj[pos] = fj[cur] +1;
//			q.push(pos);
//			
//		}
//	}
	
	cout << fj[k];
	return 0;
}
