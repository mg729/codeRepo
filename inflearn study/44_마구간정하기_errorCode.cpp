/*
데이터의 연속적인 최대/최소 거리를 구할때 이분 검색법을 사용합시다.
아래 코드는 distance함수내부적으로 계속 접근하면 안되는 vector값에 접근하게 되서 if(idx+a)문에 걸림;;
*/

#include<bits/stdc++.h>
using namespace std;

int n, c, minVal, res;
vector<int> v;

int distance(int a, int cNum, int size) {
	int dist = a;
	int idx = 0;
	cout << "cNum: " << cNum << endl;
	int temp = 2147000000;
	for(int i = 0; i < cNum; i++) { // 말을 배치하는 최대거리는 cNum 
		if(idx + a > size) { // idx + a 가 벡터의 제한을 벗어난 경우 error
			dist = -1;
			cout << idx << "cNUM: "<<cNum << "i:  " << i << " size " << size<< endl;
			return dist;
		}
		idx += a;
		temp = min(v[idx] - v[idx-a], temp); // a 를 기준으로 말을 배치했을 때 가장 가까운 두 말의 거리 
	}
	minVal = temp;
	return minVal;
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
	sort(v.begin(), v.end()); // 우선 정렬 

	int cnt = 1;
	int limit = c-1;
	while(true) {
		if(distance(cnt, limit, n-1) != -1) { //cnt : 마구간 사이 거리, c-1: 최대 배치 제한, size : vector 배열 제한   
			res = minVal;
			cout << "cnt: "<< cnt << endl;
			cnt++;
			limit -= 1;
		}
		else {
			cout << cnt << endl;
			break;
		}
	}
	cout << res;
	
	return 0;
}