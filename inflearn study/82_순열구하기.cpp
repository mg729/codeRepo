#include<bits/stdc++.h>

using namespace std;

int n, r, a, cnt;
int arr[17];
int res[17];
int ch[17];

void dfs(int level) {
	if(level == r) {
		for(int i = 0; i < level; i++) {
			cout << res[i] << " ";
		}
		cout << "\n";
		cnt++;
		return;
	}
	
	for(int i = 1; i <= n ; i++) {
		if(ch[i] == 0) {
			res[level] = arr[i];
			ch[i] = 1;
			dfs(level+1);
			ch[i] = 0;
		}
	}	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("input.txt", "rt", stdin);
	cin >> n >> r;
	for(int i = 1; i <=n ; i++) {
		cin >> a;
		arr[i] = a;
	}
	
	dfs(0);
	cout << cnt;
	
	return 0;
}
