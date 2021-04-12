#include<bits/stdc++.h>
using namespace std;

int n;

void preOrder(int v) {
	if(v>7) return;
	else { // 이진트리 함수 호출 
		cout << v << " ";
		preOrder(v*2);
		preOrder(v*2 + 1);
	}
}

void inOrder(int v) {
	if(v>7) return;
	else { // 이진트리 함수 호출 
		inOrder(v*2);
		cout << v << " ";
		inOrder(v*2 + 1);
	}
}

void postOrder(int v) {
	if(v>7) return;
	else { // 이진트리 함수 호출 
		postOrder(v*2);
		postOrder(v*2 + 1);
		cout << v << " ";
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("input.txt", "rt", stdin);
	cin >> n;
	preOrder(1);
	cout << "\n";
	inOrder(1);
	cout << "\n";
	postOrder(1);
	
	return 0;
}