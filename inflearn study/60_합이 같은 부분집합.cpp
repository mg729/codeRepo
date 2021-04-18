#include<bits/stdc++.h>
using namespace std;

int n, val;
int check[12];  // n : 1 ~ 10
int idx[12]; // it was error when idx array was declared vector --> be careful to access vector factor
bool isEqualSum; // false

void dfs(int x) {
	if(isEqualSum) return;
	if(x > n){
		int leftSum = 0;
		int rightSum = 0;
		for(int i = 1; i <= n; i++) {
			if(check[i]) leftSum += idx[i];
			else rightSum += idx[i];
		}
		if(leftSum == rightSum) {
			isEqualSum = true;
			return;
		}
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
//	freopen("input.txt", "rt", stdin);
	
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> val;
		idx[i] = val;
	}
	
	dfs(1);
	
	if(isEqualSum) cout << "YES";
	else cout << "NO";
	
	return 0;
}