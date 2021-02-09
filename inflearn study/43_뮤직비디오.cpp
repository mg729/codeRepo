#include<bits/stdc++.h>
using namespace std;

int n, m, limit, sum;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;
		v.push_back(val);
		sum += val;
	}
	sort(v.begin(), v.end());
	int lt = 1;
	int rt = sum;
	while(lt < rt) {
		limit = (lt + rt) / 2;
		
		int sumOfDvd = 0;
		int cnt = 1;
		int i;
		bool isValid = true;
		for(i = 0; i <n; i++) {
			if(cnt == m) break;
			sumOfDvd += v[i];
			if(sumOfDvd >= limit) {
				cnt++;
				sumOfDvd = 0;
				i--;
			}
		}
		int sumOfLeft = 0;
		for(int j = i-1; j < n; j++){
			if(sumOfLeft > limit) {
				isValid = false;
			}
			sumOfLeft += v[j];
		}
		
		if(isValid) {
			sum = limit;
			rt = limit - 1;
		}
		else {
			lt = limit + 1;
		}
	}
	
	cout << sum;

	
	return 0;
}