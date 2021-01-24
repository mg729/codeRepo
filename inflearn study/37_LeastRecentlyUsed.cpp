#include<bits/stdc++.h>
using namespace std;

int s, n;
vector<int> v;
int arr[101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);
	cin >> s >> n;
	
	int sRound = 0;	
	for(int i = 0; i < n; i++) {
		sRound++;
		int val;
		cin >> val;
		if(sRound == s && arr[val] == 0 && !v.empty()) {
			sRound = 0;
			v.erase(v.begin());	
			v.push_back(val);
			arr[val]++;
			continue;
		}
		
		if(arr[val] == 0) {
			v.push_back(val);
		}
		else {
			auto it = v.begin();
			for(int j = 0; j < v.size(); j++){
				if(v[j] == val){
					v.erase(it);
					break;
				}
				it++;
			}
			v.push_back(val);
		}
		arr[val]++;
	}
	
	for(int i = v.size()-1; i > -1; i--) {
		cout << v[i] <<" ";
	}

	return 0;
}