#include<bits/stdc++.h>

using namespace std;
int n, sum;
vector<pair<int,int> > v1;
vector<int> v2;

bool cmp(pair<int,int> a, pair<int,int> b) {
	return a.first > b.first;	
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		int val;
		cin >> val;
		v1.push_back({val,0});
		v2.push_back(val);
	}
	sort(v1.begin(), v1.end(), cmp);
	
	int order = 0;
	int prev = 0;
	for(int i = 0; i < n; i++) {
		if(v1[i].first != prev) order++;
		v1[i].second = order;
		if(v1[i].first == prev) order++;
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(v2[i] == v1[j].first) {
				cout << v1[j].second <<" ";
				break;
			}
		}
	}


	return 0;
}