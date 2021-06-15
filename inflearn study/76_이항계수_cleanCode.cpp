#include<bits/stdc++.h>
using namespace std;

int memoi[22][22];

int dfs(int n, int r) {
	if(memoi[n][r]) return memoi[n][r];
	if(n == r || r == 0) return 1;
	else return memoi[n][r] = dfs(n-1, r) + dfs(n-1, r-1); // dfs(n-1, r) + dfs(n-1, r-1) 계산한 결과를 memoi[n][r] 에 대입하고  memoi[n][r] 을 return 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("input.txt", "rt", stdin);
	
	int n, r;
	cin >> n >> r;
	
	// nCr = n-1Cr + n-1Cr-1
	cout << dfs(n, r);	

 	return 0;
}