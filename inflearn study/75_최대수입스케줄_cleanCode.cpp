#include<bits/stdc++.h>
using namespace std;

int n, m, d;

struct income {
	int money, day;
	income(int a, int b) {
		money = a;
		day = b;
	}
	
	bool operator < (const income& i) const {
		return day > i.day;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	
	cin >> n;
	
	vector<income> iv;
	int maxDay = 0;
	for(int i = 0; i < n; i++) {
		cin >> m >> d;
//		iv.push_back({m,d});
		iv.push_back(income(m,d));
		if(maxDay < d) maxDay = d;
	}
	sort(iv.begin(), iv.end());
//	for(auto x : iv) {
//		cout << x.day << " " << x.money <<"\n";
//	}
	
	int res = 0;
	priority_queue<int> pq;
	int j = 0;
	for(int i = maxDay; i >= 1; i--) {
		for( ; j <n; j++) {
			if(iv[j].day != i) break;
			pq.push(iv[j].money);
		}
		if(!pq.empty()) {
			res += pq.top();
			pq.pop();
		}		
	}

	cout << res;

	return 0;
}

