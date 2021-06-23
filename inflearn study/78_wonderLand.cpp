#include<bits/stdc++.h>
using namespace std;

int v, e, a, b, c, sum;
int unf[102];

struct land {
	int x , y, z;
	land(int val1, int val2, int val3) {
		x = val1;
		y = val2;
		z = val3;
	}
	bool operator < (const land& cmpLand) const {
		return z < cmpLand.z;
	}
};

int Find(int val) {
	if(val != unf[val]) return unf[val] = Find(unf[val]);
	else return val;
}

void Union(int x, int y, int cost) {
	int node1 = Find(x);
	int node2 = Find(y);
	if(node1 != node2) {
		unf[node1] = node2;
		sum += cost;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//	freopen("input.txt", "rt", stdin);
	
	cin >> v >> e;
	
	for(int i = 1; i <= v; i++) {
		unf[i] = i;
	}
	
	vector<land> v;
	for(int i = 0 ; i < e ; i++) {
		cin >> a >> b >> c;
		v.push_back({a, b, c});
	}
	
	sort(v.begin(), v.end());
//	for(int i = 0; i < v.size(); i++) {
//		cout << v[i].x  << " "<< v[i].y << " "<< v[i].z <<"\n";
//	}

	for(int i = 0; i < e ; i++) {
		Union(v[i].x, v[i].y, v[i].z);
	}
	
	cout << sum;	
	
 	return 0;
}

/*
-- Union Find Algorithm --

int Find(int val) {
	if(val == unf[val]) return val;
	else unf[val] = Find(unf[val]);
}

void Union(int node1, int node2, int cost) {
	int x = Find(node1);
	int y = Find(node2);
	if(x != y) return unf[node1] = node2;
}
*/
