/**
1�ܰ� new_id�� ��� �빮�ڸ� �����Ǵ� �ҹ��ڷ� ġȯ�մϴ�.
2�ܰ� new_id���� ���ĺ� �ҹ���, ����, ����(-), ����(_), ��ħǥ(.)�� ������ ��� ���ڸ� �����մϴ�.
3�ܰ� new_id���� ��ħǥ(.)�� 2�� �̻� ���ӵ� �κ��� �ϳ��� ��ħǥ(.)�� ġȯ�մϴ�.
4�ܰ� new_id���� ��ħǥ(.)�� ó���̳� ���� ��ġ�Ѵٸ� �����մϴ�.
5�ܰ� new_id�� �� ���ڿ��̶��, new_id�� "a"�� �����մϴ�.
6�ܰ� new_id�� ���̰� 16�� �̻��̸�, new_id�� ù 15���� ���ڸ� ������ ������ ���ڵ��� ��� �����մϴ�.
     ���� ���� �� ��ħǥ(.)�� new_id�� ���� ��ġ�Ѵٸ� ���� ��ġ�� ��ħǥ(.) ���ڸ� �����մϴ�.
7�ܰ� new_id�� ���̰� 2�� ���϶��, new_id�� ������ ���ڸ� new_id�� ���̰� 3�� �� ������ �ݺ��ؼ� ���� ���Դϴ�.
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

