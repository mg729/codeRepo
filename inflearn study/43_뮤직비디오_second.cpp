#include<bits/stdc++.h>
using namespace std;

int n, m, val, lt, mid, rt, res;
vector<int> v;

int calculateSize(int size) {
	int cnt = 1;
	int sum = 0;
	for(int i = 0; i <n; i++) {
		if(sum + v[i] > size) {
			cnt++;
			sum = v[i];
		}
		else sum += v[i];
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//	freopen("input.txt", "rt", stdin);
	cin >> n >> m;
	int minRes = -1;
	for(int i = 0; i < n; i++) {
		cin >> val;
		v.push_back(val);
		rt += val;
		minRes = max(val, minRes);
	}
	
	lt = 1;
	while(lt <= rt) {	
		mid = (lt+rt) / 2; // mid value will be set as minimum dvd size
		if(mid >= minRes && calculateSize(mid) <= m) {
			res = mid;
			rt = mid - 1;
		}
		else lt = mid + 1;
	}
	
	cout << res;
	return 0;
}
