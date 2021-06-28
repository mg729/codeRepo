#include<bits/stdc++.h>
using namespace std;

int v, e, node1, node2, cost, sum;
int ch[102];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//	freopen("input.txt", "rt", stdin);
	
	cin >> v >> e;
	vector <pair<int, int> > vertex[102];
	for(int i = 1; i <= e; i++) {
		cin >> node1 >> node2 >> cost;
		vertex[node1].push_back({cost, node2});
		vertex[node2].push_back({cost, node1});
	}
	
	priority_queue<pair<int, int> > pq;
	pq.push({0,1});
	while(!pq.empty()) {
		int x = pq.top().second;
		cost = -pq.top().first;
		pq.pop();
//		cout << __LINE__ <<"***** "<<x << " : " << cost << endl;
		if(ch[x] == 0) {
			ch[x] = 1;
			sum += cost;
			for(int j = 0; j < vertex[x].size(); j++) {
				int a = -vertex[x][j].first;
				int b = vertex[x][j].second;
				pq.push({a,b});
//				cout << __LINE__ <<" "<<a << " : " << b << endl;
			}
		}
	}
	
	cout << sum;
	
 	return 0;
}