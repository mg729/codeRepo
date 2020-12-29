#include<bits/stdc++.h>

using namespace std;
int n, sum;
vector<int> v;

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	cin >> n;
	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;
		v.push_back(val);
	}
	int maxVal = -1;
	for(int i = 1; i < n; i++) {
		if(v[i-1] > v[i]) {
			sum = 0;
			continue;
		}
		sum++;
		if(maxVal < sum) maxVal = sum;
	}
	cout << maxVal+1;
	return 0;
}