#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<int> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	cin >> n >> k;
	
	for(int i = 1; i <= n; i++) {
		v.push_back(i);
	}
	
	int cnt = 1;
	while(v.size() != 1) {
		auto it = v.begin(); 
//		cout << __LINE__ << " " << *it << endl;

		if(cnt == 3) {
//			cout <<"#: "<< *it <<" "<< v.size() << endl;
			v.erase(it);
			cnt = 1;
		}
		else {			
			v.push_back(*it);
			v.erase(it);
			cnt++;
		}
	}
	cout << *(v.begin());
	
	return 0;
}