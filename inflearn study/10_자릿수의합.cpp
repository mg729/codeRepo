#include<bits/stdc++.h>

using namespace std;
int n, sumVal;
vector<int> number;
vector<pair<int, int> > v;
vector<int> result;

int digit_sum(int x) {
	int sum = 0;
	while(x != 0) {
		sum += x % 10;
		x /= 10;
	}
	return sum;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
    cin >> n;
    for (int i = 0; i < n ; i++) {
    	int val;
   		cin >> val;
		number.push_back(val);
	}
	
	for (int i = 0; i < n ; i++) {
		sumVal = digit_sum(number[i]);
		v.push_back({number[i],sumVal});
	}
	
	int maxVal = -1;
	for(auto x : v) {
		maxVal = max(maxVal, x.second);
	}
	int size = 0;
	for(auto x : v) {
		if(x.second == maxVal) {
			result.push_back(x.first);
			size++;
		}
	}
	// need to check sort()
	sort(result.begin(), result.end());
	cout << result[size-1];
	
	
	
	return 0;
}