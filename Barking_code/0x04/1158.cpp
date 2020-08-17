#include <bits/stdc++.h>
using namespace std;

list<int> L;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	
	for(int i = 1; i <= n; i++) 
		L.push_back(i);
	
	auto cursor = L.begin();
	
	for (int i = 0; i < k - 1; i++)
		++cursor;
	
		
	cout << "<";
	
	for(int i = 0; i < n-1; i++) {
		
		cout << *cursor << ", ";
		
		cursor = L.erase(cursor);
		if(cursor == L.end())
			cursor = L.begin();

		for (int j = 0; j < k-1; j++) {
			auto endCursor = cursor;
			++endCursor;
			if(endCursor != L.end())
				++cursor;
			else {
				cursor = L.begin();
			}
		}
	}
	
	cout << *cursor << ">";
	
	return 0;
}
