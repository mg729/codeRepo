#include<bits/stdc++.h>
using namespace std;

int ch[10];
queue<int> q;
vector<int> v[10];
int x;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);
	
	for(int i = 1; i <=6; i++) {
		int n1, n2; // node1, node2
		cin>> n1 >> n2;
		v[n1].push_back(n2);
//		v[n2].push_back(n1);
	}
	
	q.push(1);
	ch[1] = 1;
	while(!q.empty()) {
		x = q.front();
		cout << x << " ";
		for(int i = 0; i < v[x].size(); i++) {
			if(ch[v[x][i]] == 0) {
				ch[v[x][i]] = 1;
				q.push(v[x][i]);
			}
		}
		q.pop();
	}
	return 0;
}

//Solution 2--------------
/*
#include<bits/stdc++.h>
using namespace std;

int Queue[100];
int front = -1;
int back = -1;
int ch[10];
vector<int> v[10];
int x;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);
	
	for(int i = 1; i <=6; i++) {
		int n1, n2; // node1, node2
		cin>> n1 >> n2;
		v[n1].push_back(n2);
//		v[n2].push_back(n1);
	}
	
	Queue[++back] = 1;
	ch[1] = 1;
	while(front < back) {
		x = Queue[++front];
		cout << x << " ";
		for(int i = 0; i <v[x].size(); i++) {
			if(ch[v[x][i]] == 0) {
				ch[v[x][i]] = 1;
				Queue[++back] = v[x][i];
			}
		}
	}
	return 0;
}
*/

//Solution 3--------------
/*
#include<bits/stdc++.h>
using namespace std;

vector<int> v[10]; 
queue<int> q; //front, back, push, pop

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);
	// vector 인접리스트 활용 
	for(int i = 1; i <= 6; i++) {
		int n1,n2;
		cin >> n1 >> n2;
		v[n1].push_back(n2);
	}
	
	// vector 인접리스트를 탐색하면서 queue로 데이터 출력 
	for(int i = 1; i <= 6; i++) {
		for(int j = 0; j < v[i].size(); j++) {
			q.push(v[i][j]);
		}
	}
	
	cout << "1 ";
	while(!q.empty()) {
		cout << q.front() << " ";
		q.pop();		
	}
	
	return 0;
}
*/