#include<bits/stdc++.h>
using namespace std;

int unf[1002];

int Find(int v) {
	if(v == unf[v]) return v;
	else return unf[v] = Find(unf[v]); //경로 압축  
}

void Union (int a, int b){
	a = Find(a);
	b = Find(b);
	if(a != b) unf[a] = b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, x, y;
	freopen("input.txt", "rt", stdin);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		unf[i] = i;
	}
	
	for(int i = 1; i <= m; i++) {
		cin >> x >> y;
		Union(x ,y); 
	}
	
	cin >> x >> y;
	x = Find(x);
	y = Find(y);
	if(x == y) cout << "YES";
	else cout << "NO";
	

 	return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;

int unf[1002];

int Find(int v) {
	if(v == unf[v]) return v;
	else return Find(unf[v]);
}

void Union (int a, int b){
	a = Find(a);
	b = Find(b);
	if(a != b) unf[a] = b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, x, y;
	freopen("input.txt", "rt", stdin);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		unf[i] = i;
	}
	
	for(int i = 1; i <= m; i++) {
		cin >> x >> y;
		Union(x ,y); 
	}
	
	cin >> x >> y;
	x = Find(x);
	y = Find(y);
	if(x == y) cout << "YES";
	else cout << "NO";
	

 	return 0;
}
*/