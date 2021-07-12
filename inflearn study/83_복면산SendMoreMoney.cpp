#include<bits/stdc++.h>

using namespace std;

int arr[10];
int ch[10];

int send() {
	return arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
}

int more() {
	return  arr[4] * 1000 + arr[5] * 100 + arr[6] * 10 + arr[1];
}

int money() {
	return  arr[4] * 10000 + arr[5] * 1000 + arr[2] * 100 + arr[1] * 10 + arr[7];
}

void dfs(int level) {
	if(level == 8) {
		if(arr[0] == 0 || arr[4] == 0) return;
		if(send() + more() == money()) {
			cout <<"   "<< arr[0] <<" "<< arr[1] <<" "<< arr[2] <<" "<< arr[3] <<"\n";
			cout <<" + "<< arr[4] <<" "<< arr[5] <<" "<< arr[6] <<" "<< arr[1] <<"\n";
			cout << "-----------\n";
			cout <<" "  << arr[4] <<" "<< arr[5] <<" "<< arr[2] <<" "<< arr[1] <<" " << arr[7]<<"\n";
		}
		return;
	}
	for(int i = 0; i < 10; i++) {
		if(ch[i] == 0) {
			arr[level] = i;
			ch[i] = 1;
			dfs(level+1);
			ch[i] = 0;	
		}
	}
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

//	freopen("input.txt", "rt", stdin);

	dfs(0);	
	return 0;
}
