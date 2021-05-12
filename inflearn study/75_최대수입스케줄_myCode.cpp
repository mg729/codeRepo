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
	int maxDay = 0;
	for(int i = 0; i < n; i++) {
		cin >> m >> d;
//		iv.push_back({m,d});
		iv.push_back(income(m,d));
		if(maxDay < d) maxDay = d;
	}
	sort(iv.begin(), iv.end());
	for(auto x : iv) {
		cout << x.day << " " << x.money <<"\n";
	}
	
	int res = 0;
	priority_queue<int> pq;
	for(int i = 0; i < n; i++) {
		if(maxDay == iv[i].day)
			pq.push(iv[i].money);
		else {			
			int interval = maxDay - iv[i].day;
			for(int j = 0; j < interval; j++) {
				if(!pq.empty()){
					cout << i << " " << j << " " << pq.top() << "\n";
					res += pq.top();
					pq.pop();
				}
			}
			pq.push(iv[i].money);
			maxDay = iv[i].day;
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
60 1
50 1
40 1
50 3
20 3
10 3
*/

/*
#include<bits/stdc++.h>
using namespace std;

struct Loc {
	int x, y, z;
	Loc(int a, int b, int c) {
		x = a;
		y = b;
		z = c;
	}
	bool operator < (const Loc& cmpLoc) {
		if(x != cmpLoc.x) return x < cmpLoc.x;
		if(y != cmpLoc.y) return y < cmpLoc.y;
		if(z != cmpLoc.z) return z < cmpLoc.z;
	}
};

int main() {
	vector<Loc> locV;
	locV.push_back(Loc(1,3,5));
	locV.push_back(Loc(1,4,9));
	locV.push_back({3,6,8});
	locV.push_back({7,6,7});
	locV.push_back({3,6,2});
	
	sort(locV.begin(), locV.end());
	for(auto lv : locV) {
		cout << lv.x << " " << lv.y << " " << lv.z <<"\n";
	}
	
	return 0;
}
*/