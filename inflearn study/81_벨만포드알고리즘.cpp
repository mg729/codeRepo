
#include<bits/stdc++.h>

using namespace std;

int n, m, a, b, c;
int dist[101];
struct Edge{
	int s;
	int e;
	int val;
	Edge(int a, int b, int c){
		s=a;
		e=b;
		val=c;
	}
};

int main(){
	freopen("input.txt", "rt", stdin);
	vector<Edge> Ed;
	int i, n, m, a, b, c, j;
	scanf("%d %d", &n, &m);
	for(i=1; i<=m; i++){
		cin >> a >> b >> c;
		Ed.push_back(Edge(a, b, c));	
	}
	for(i=1; i<=n; i++){
		dist[i]=2147000000;
	}
	int s, e;
	cin >> s >> e;
	dist[s]=0;
	for(i=1; i<n; i++){  
		for(j=0; j<Ed.size(); j++){ // n-1 개의 간선으로 이동하는 최단 거리 비용 구하기 
			int s=Ed[j].s; // start 출발노드 
			int e=Ed[j].e; // end 도착노드 
			int w=Ed[j].val; // 간선 cost 
			if(dist[s]!=2147000000 && dist[s]+w<dist[e]){ 
				// dist[s]!=2147000000 : 출발이 무한대면 무한대 값에 뭐 가중치 더한다고 갱신될 일 없죠 
				// dist[s]+w<dist[e] : 출발 노드의 비용에 가중치를 더한 값이 기존 값보다 작더 라  
				dist[e]=dist[s]+w;
			}
		}
	}
	for(j=0; j<Ed.size(); j++){ // N-1 까지 line44에서 끝냈는데 이부분은 이제 N개의 간선까지 테스트
	// N 개의 간선을 점검하는데 최단 경로가 갱신되면 음의사이클이 나오는 것을 의미 
		int u=Ed[j].s;
		int v=Ed[j].e;
		int w=Ed[j].val;
		if(dist[u]!=2147000000 && dist[u]+w<dist[v]){
			cout << "-1\n";
			exit(0);
		}
	}
	cout << dist[e];
	return 0;
}
