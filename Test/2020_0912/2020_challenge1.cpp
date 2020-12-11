/**
1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
     만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string id;
	cin >> id;
	//step 1
	for(int i = 0; id[i]; i++) {
		if(id[i] >= 'A' && id[i] <= 'Z' ) {
			id[i] = id[i] + 32;
		}
	}
	cout << __LINE__ << id <<endl;
	//step 2
	for(auto it = id.begin(); it < id.end(); it++) {
		if(*it >= 'a' && *it <= 'z' ||
		   *it >= '0' && *it <= '9' ||
		   *it == '-' ||
		   *it == '_' ||
		   *it == '.') {
		   continue;
		}
		else {
			id.erase(it);
			it--;
		}
	}
	cout << __LINE__ << id <<endl;
	//step 3
	for(auto it = id.begin(); it < id.end(); it++) {
		if(*it == '.') {
		   if(*(it+1) == '.') {
				id.erase(it);
		   		it--;
		   }
		}
	}
	cout << __LINE__ << id <<endl;
	//step 4
	while(true) {
		if(id[0] != '.')
			break;
		id.erase(id.begin());
	}
	while(true) {
		if(id[id.size()-1] != '.')
			break;
		id.erase(id.end()-1);
	}
	cout << __LINE__ << id <<endl;
	//step 5
	if(id == "")
		id.push_back('a');
	cout << __LINE__ << id <<endl;
	//step 6
	auto endSize = id.size();
	if(id.size() > 15) {
		id.erase(15, --endSize);
	}
	while(true) {
		if(id[id.size()-1] != '.')
			break;
		id.erase(id.end()-1);
	}
	cout << __LINE__ << id <<endl;
	//step 7
	char c = id.back();
	while(true) {
		if(id.size() > 2) 
			break;
		id.push_back(c);
	}
	cout << __LINE__ << id <<endl;
	return 0;	
}

