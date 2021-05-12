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
	freopen("input.txt", "rt", stdin);
	
	cin >> n;
	
	vector<income> iv;
	for(int i = 0; i < n; i++) {
		cin >> m >> d;
		iv.push_back({m,d});
	}
	sort(iv.begin(), iv.end());
//	for(auto x : iv) {
//		cout << x.money << " " << x.day <<"\n";
//	}
	
	int res = 0;
	int prevDay = iv[0].day;
	priority_queue<int> pq;
	for(int i = 0; i < n; i++) {
		if(prevDay == iv[i].day) {
			pq.push(iv[i].money);
			if(i+1 < n && iv[i+1].day != prevDay) {
				res += pq.top();
				pq.pop();
				prevDay = iv[i+1].day;
			}
		}
	}
	res += pq.top();
	cout << res;
	
	return 0;
}

/*
150
6
50 2
20 1
40 2
60 3
30 3
30 1

130
6
50 1
20 1
40 2
60 1
30 3
30 1
*/