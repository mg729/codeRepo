#include<bits/stdc++.h>
using namespace std;

int n;
int check[12];

void dfs(int level) {
	if(level > n) return;
	
	check[level] = 1;
	dfs(level + 1);
	if(level==n) {
		for(int i = 1; i <= n; i++) 
			if(check[i]) cout << i << " ";
		cout << "\n";
	}

	check[level] = 0;
	dfs(level + 1);
	if(level==n) {
		for(int i = 1; i <= n; i++) 
			if(check[i]) cout << i << " ";
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//	freopen("input.txt", "rt", stdin);
	cin >> n;
	dfs(1);

	return 0;
}