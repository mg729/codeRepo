#include<bits/stdc++.h>
using namespace std;

int n, cur, rt, res;
int lt = 1;
int k = 1;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	cin >> n;
	
	while(lt != 0) {
		lt = n/(k*10);
		cur = (n/k) % 10;
		rt = n%k;
		if (cur > 3) res += (lt+1) * k;
		else if (cur < 3) res += lt * k;
		else if (cur == 3) res += (lt*k) + (rt+1);
		
		k *= 10;		
	}
	cout << res;

	return 0;
}
