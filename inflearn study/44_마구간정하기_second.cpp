#include<bits/stdc++.h>
using namespace std;

int n, c, val;
vector<int> v;

int getHorse(int len) {
	int cnt = 1;
	int pos = v[0];
	for(int i = 1; i < n; i++) {
		if(v[i] - pos >= len) {
			cnt++;
			pos = v[i];
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("input.txt", "rt", stdin);
	cin >> n >> c;
	
	for(int i = 0; i < n; i++) {
		cin >> val;
		v.push_back(val);
	}
	
	sort(v.begin(), v.end());
	int lt = 1;
	int rt = v[n-1];
	int mid;
	int cnt = 2;
	while(lt <= rt) {
		mid = (lt+rt) / 2;
		if(getHorse(mid) >= c) {
			lt = mid + 1;
			cnt = mid;
		}
		else {
			rt = mid - 1;			
		}
	}
	cout << cnt;

	return 0;
}
