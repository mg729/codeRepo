#include<bits/stdc++.h>
using namespace std;

int n, val;
int sumArr[58];
int check[12];  // n : 1 ~ 10
vector<int> v;
bool isEqualSum; // false

void dfs(int x) {
	if(x > n){
		int localSum = 0;
		for(int i = 0; i < n; i++) {
			if(check[i]) localSum += v[i];
		}
		if(sumArr[localSum]) {
			isEqualSum = true;
			return;
		}
		sumArr[localSum]++;
		return;
	}
	check[x] = 1;
	dfs(x+1);
	check[x] = 0;
	dfs(x+1);	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);
	
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> val;
		v.push_back(val);
	}
	
	dfs(1);
	
	if(isEqualSum) cout << "YES";
	else cout << "NO";
	
	return 0;
}