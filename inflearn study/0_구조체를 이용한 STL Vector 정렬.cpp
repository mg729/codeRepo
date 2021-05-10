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
		return x < cmpLoc.x; //오름차순
        //return x >  cmpLoc.x; // 내림차순
	}
};
int main() {
	vector<Loc> locV;
	locV.push_back({1,3,5});
	locV.push_back({1,4,9});
	locV.push_back({3,6,2});
	locV.push_back({5,6,7});
	locV.push_back({3,4,2});
	
	sort(locV.begin(), locV.end());
	for(auto lv : locV) {
		cout << lv.x << " " << lv.y << " " << lv.z <<"\n";
	}
	
	return 0;
}