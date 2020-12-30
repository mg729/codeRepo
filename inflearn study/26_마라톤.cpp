#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> v;
int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;
		v.push_back(val);
		if(i == 0) {
			cout << "1 ";
			continue;
		}
		int grade = 1;
		for(int j = 0; j < i; j++) {
			if(v[i] <= v[j]) grade++;
		}
		cout << grade <<" ";
	}
	return 0;
}