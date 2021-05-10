#include<bits/stdc++.h>
using namespace std;

struct Loc {
	int x, y, z;
	Loc(int a, int b, int c) {
		x = a;
		y = b;
		z = c;
	}
	bool operator < (const Loc& cmpLoc) const {
		if(x != cmpLoc.x) return x < cmpLoc.x;
		if(y != cmpLoc.y) return y < cmpLoc.y;
		if(z != cmpLoc.z) return z < cmpLoc.z;
	}
};
int main() {
	vector<Loc> locV;
	locV.push_back({1,3,5});
	locV.push_back({1,4,9});
	locV.push_back({3,6,8});
	locV.push_back({7,6,7});
	locV.push_back({3,6,2});
	
	sort(locV.begin(), locV.end());
	for(auto lv : locV) {
		cout << lv.x << " " << lv.y << " " << lv.z <<"\n";
	}
	
	return 0;
}