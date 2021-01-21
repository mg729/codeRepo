#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);
	cin >> n;
	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;
		v.push_back(val);
	}
	
	for(int i = 0; i < n-1; i++) {
		for(int j = 0; j < n-i-1 ; j++) { // **j < n-i-1** 
			if(v[j] > v[j+1]) {
				int tmp = v[j];
				v[j] = v[j+1];
				v[j+1] = tmp;	
			}
		}
	}
	
	for(auto x : v) cout << x <<" ";

	return 0;
}


/*
n-i-1
-i 을 하는 이유는 한 번의 턴을 거칠 때마다 뒤에 있는 데이터는 정렬이 되기때문에 정렬되지 않은 데이터에대해서만 조건체크를 하기 위함
-1 을 하는 이유는 if문내에서 j+1 까지 값을 미리 비교하니까 해당데이터의 +1값까지는 탐색이 될 것이므로 전체 for문에서 -1 해줌
*/