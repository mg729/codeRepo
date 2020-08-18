#include <bits/stdc++.h>
using namespace std;

list<int> L;
vector<int> V;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	
	for(int i = 1; i <= n; i++) 
		L.push_back(i);
	
	auto cursor = L.begin();
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <k-1; j++) {
			if(cursor == L.end()) cursor = L.begin();
			cursor++;
			if(cursor == L.end()) cursor = L.begin();
		}
		V.push_back(*cursor);
		cursor = L.erase(cursor);
	}
	
	cout << "<";
	for(int i = 0; i < V.size() - 1; i++)
		cout << V[i] << ", ";
	
	cout << V[V.size()-1] << ">";
	
	return 0;
}
