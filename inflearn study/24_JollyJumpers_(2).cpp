#include<bits/stdc++.h>

using namespace std;
int n, sum;
vector<int> v;
int adj[102];

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		int val;
		cin>> val;
		v.push_back(val);
	}

	for(int i = 1; i < n; i++) {
		adj[abs(v[i] - v[i-1])]++;
	}

	bool isJollyJumpers = true;
	for(int i = 1; i < n; i++) {
		if(!adj[i]) {
			isJollyJumpers = false;
			break;
		}
	}
	if(isJollyJumpers) cout << "YES";
	else cout << "NO";

	return 0;
}