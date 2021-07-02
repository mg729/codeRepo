#include<bits/stdc++.h>

using namespace std;

int n, m, a, b, e;

struct Graph{
	int vertex;
	int edge;
	Graph(int ve, int ed) {
		vertex = ve;
		edge = ed;
	}
	bool operator < (const Graph& cmpGraph) const {
		return edge > cmpGraph.edge;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("input.txt", "rt", stdin);
	
	cin >> n >> m;
	vector<Graph> v[22];
	for(int i = 0; i < m; i++) {
		cin >> a >> b >> e;
		v[a].push_back({b,e});
	}

	vector<int> cost(22, 2147000000); // need to initialize all the data as 2147000000 by vector
	
	priority_queue<Graph> pq;
	pq.push({1, 0});
	cost[1] = 0;
	
	// below while code is Dijkstra algorithm
	while(!pq.empty()){
		int curNode = pq.top().vertex;
		int curCost = pq.top().edge;
		pq.pop();
		if(cost[curNode] < curCost) continue;
		for(int i = 0; i < v[curNode].size(); i++) {
			int nextNode = v[curNode][i].vertex;
			int nextCost = curCost + v[curNode][i].edge;
			if(nextCost < cost[nextNode]) {
				cost[nextNode] = nextCost;
				pq.push({nextNode, nextCost});
			}
		}
	}
	
	for(int i = 2 ; i <= n; i++) {
		if(cost[i] == 2147000000) cout <<"impossible";
		else cout << i << " : " << cost[i] << "\n";
	}

 	return 0;
}
