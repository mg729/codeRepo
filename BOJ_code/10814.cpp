#include <iostream>
#include <vector>
#include <algorithm>  //std::stable_sort

using namespace std;

string name;
int tc;
int age;

bool cmp (pair<int, string> a, pair<int, string> b)
{
	return a.first < b.first;
}

int main() {
	
	cin >> tc;
	
	vector<pair<int, string>> v;
	
	while(tc)
	{
		
		cin >> age >> name;
		v.push_back({age, name});
		
		tc--;
	}
	
	stable_sort(v.begin(), v.end(), cmp);
	for(auto x: v)
		cout << x.first << " " << x.second << '\n';
	

}

//** NOTICE : cin cout  
//https://www.acmicpc.net/board/view/22716
// In case of using endl in this code, the error will occur due to Timeout ERROR
