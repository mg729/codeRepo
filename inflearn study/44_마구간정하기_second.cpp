#include<bits/stdc++.h>
using namespace std;

int n, c, val;
vector<int> v;
vector<int> res;

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
	int lt, mid, rt;
	lt = 0;
	rt = n-1;
	
	res.push_back(v[0]);
	
	int cnt = 0;
	while(lt <= rt && c > 2) {
		if(cnt >= c-2) break;
		mid = (lt + rt) / 2;
		if(v[mid] - v[lt] < v[rt]- v[mid]) {
			lt = mid + 1;
		}
		else {
			rt = mid - 1;
		}
		res.push_back(v[mid]);
		cnt++;
	}
	
	res.push_back(v[n-1]);
	sort(res.begin(), res.end());
	int distance = res[1] - res[0];
	for(int i = 2; i < c; i++) {
		int tmp = res[i] - res[i-1];
		distance = min(tmp, distance);		
	}
	cout << distance;

	return 0;
}
