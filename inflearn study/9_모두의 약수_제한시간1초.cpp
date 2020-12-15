#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> v;
 
int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "rt", stdin);
	
	scanf("%d", &n);
	for(int i = 0; i <= n; i++) {
		v.push_back(0);
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j = j + i) {
			v[j]++;
		}
	}
	
	for(int i = 1; i <= n; i++) {
		cout << v[i] << " ";
	}
	
	
//  n^2 의 시간복잡도 --> 제한시간 1초를 초과  
//	for(int i = 1; i <= n; i++) {
//		int divisor = 0;
//		for(int j =1; j <= i; j++) {
//			if(i % j == 0)
//				divisor++;
//		}
//		cout << divisor <<" ";
//	}
	return 0;
}