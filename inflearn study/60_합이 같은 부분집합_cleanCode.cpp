#include<bits/stdc++.h>
using namespace std;

int n, val, total;
int idx[12]; 
bool isEqualSum; // false

void dfs(int level, int sum) {
	if(isEqualSum) return;
	if(sum > (total/2) ) return;
	if(level > n) {
		if(sum == (total - sum)){
			isEqualSum = true;
			return;
		}
	}
	dfs(level+1, sum+idx[level]);
	dfs(level+1, sum);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);
	
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> val;
		idx[i] = val;
		total += val;
	}
	
	dfs(1, 0);
	
	if(isEqualSum) cout << "YES";
	else cout << "NO";
	
	return 0;
}
