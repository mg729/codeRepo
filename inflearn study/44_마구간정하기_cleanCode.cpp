#include<bits/stdc++.h>
using namespace std;

int n, c, lt, rt, mid, val, res;
vector<int> v;

int Count(int mid) {
	int cnt = 1;
	int pos = v[0];
	for(int i = 1; i < n; i++) {
		if(v[i] - pos >= mid) {
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
	
	for(int i = 0 ; i < n; i++) {
		int val;
		cin >> val;
		v.push_back(val);
	}
	sort(v.begin(), v.end());
	
	lt = v[0];
	rt = v[n-1];
	
	while(lt <= rt) {
		mid = (lt + rt) / 2;
		if(Count(mid) >= c) {
			res = mid;
			lt = mid + 1;
		}
		else {
			rt = mid - 1;
		}
	}
	cout << res;
	return 0;
}