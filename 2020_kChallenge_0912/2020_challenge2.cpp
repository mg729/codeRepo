#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<char> s_intersection;
    vector<string> str_intersection;
    for(auto iit = orders.begin(); iit < orders.end(); iit++) {
        vector<char> v1;
        for(auto c : *iit) {
        	v1.push_back(c);
		}

        for(auto jit = ++iit; jit < orders.end(); jit++) {
            vector<char> v2;
	        for(auto c : *jit) {
	        	v2.push_back(c);
			}
            
            std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(s_intersection));
            if(!s_intersection.empty()) {
            	string str;
	            for(auto s : s_intersection) {            	
	            	str += s;
				}
				str_intersection.push_back(str);
	            s_intersection.clear();
			}
            v2.clear();
        }
        v1.clear();
    }
    
    for(auto x : str_intersection)
    	cout << __LINE__ << x << endl;
    	
    set<string> str;
    for(auto i : str_intersection) {
        str.insert(i);
    }
    
    for(auto idx : course) {
        for(auto s : str) {
            if(idx == (s).size()) {
                answer.push_back(s);
            }
        }
    }
    sort(answer.begin(), answer.end());
    
    for(auto x : answer)
    	cout << __LINE__ << x << endl;
    return answer;
}

int main() {
	vector<string> orders = {"ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"};
	vector<int> course = {2,3,5};
	
	solution(orders, course);
	return 0;
}
