#include<bits/stdc++.h>

using namespace std;
int n, sum;
vector<int> v;

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
	vector<int> adj(n);
	for(int i = 1; i < n; i++) {
		if(abs(v[i] - v[i-1]) > n) continue; // without this code time limit error will happen
		// Because "adj" vector can only access from 0 to n-1
		// But without line 20 code, "abs(v[i] - v[i-1])" can be out of scope of from 0 to n-1
		// So TIME_LIMIT_ERROR will occur
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