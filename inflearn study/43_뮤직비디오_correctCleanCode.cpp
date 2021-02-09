#include<bits/stdc++.h>
using namespace std;

int n, m, mid, res;
vector<int> v;

int count(int s) {
	int cnt = 1, sum = 0;
	for(int i = 0; i < n; i++) {
		if(sum + v[i] > s) {
			cnt++; // dvd하나를 추가해 
			sum = v[i]; //이곡부터 새로운 sum을 계산하자 (새롭게 초기화) 
		}
		else sum += v[i]; // 녹화하는 dvd에 누적 
	}
	return cnt; 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);
	cin >> n >> m;
	int lt = 1;
	int rt = 0;
	int max = -1;
	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;
		v.push_back(val);
		rt += val;
		if(v[i] > max) max = v[i];
	}
	
	while(lt < rt) {
		mid = (lt + rt) / 2;
		if(mid >= max && count(mid) <= m) { // mid should at least larger than input data
			res = mid;
			rt = mid - 1;
		}
		else lt = mid + 1;
	}
	
	cout << res;

	
	return 0;
}