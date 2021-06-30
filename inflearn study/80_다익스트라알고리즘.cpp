#include<bits/stdc++.h>

using namespace std;

int n, m, a, b, e, minCost, node;
vector<pair<int, int> > v[22];
int cost[22];
int ch[22];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("input.txt", "rt", stdin);
	
	cin >> n >> m;
	
	for(int i = 0; i < m; i++) {
		cin >> a >> b >> e;
		v[a].push_back({b,e});
	}
	
	for(int i = 1; i <= n; i++) {
		cost[i] = 2147000000;
	}
	
	cost[1] = 0;
	while(1) {
		bool isChecked = false;
		// select minVal among cost array
		for(int i = 1; i <= n; i++) {
			minCost = 2147000000;
			if(ch[i] == 0 && cost[i] < minCost) {
				minCost = cost[i];
				isChecked = true;
				node = i;
			}				
		}
		if(isChecked){
			ch[node] = 1;
			for(int i = 0; i < v[node].size(); i++) {
				int connectedNode = v[node][i].first; // node
				if(ch[connectedNode] == 0) {
					if(cost[node] + v[node][i].second < cost[connectedNode]) {
						cost[connectedNode] = cost[node] + v[node][i].second; // cost
//						cout << "Updated Node" << connectedNode << " : " << cost[connectedNode] << endl;
					}
				}
			}
		}
		else break;	
	}
	
	for(int i = 2 ; i <= n; i++) {
		if(cost[i] == 2147000000) cout <<"impossible";
		else cout << i << " : " << cost[i] << "\n";
	}


 	return 0;
}