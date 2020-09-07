#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc = 0;
	
	while(true) {
		string str;
		getline(cin, str);
		
		if(str[0] == '-') break;
		
		int num = 0;
		int res = 0;
		for(auto c : str) {
			if(c == '{')
				num++;
			else { //c == '}'
				num--;
				if(num < 0) {
					num = 1;
					res++;
				}
			}
		}
		
		res += num/2;
		cout << ++tc << ". " << res << "\n";
	}
	
	return 0;
}


//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	
//	int tc = 0;
//	
//	while(true) {
//		stack<char> st;
//		stack<char> r_st;
//		
//		int num = 0;
//		
//		string str;
//		getline(cin, str);
//		
//		if(str.empty()) {
//			cout << ++tc << ". " << num << "\n";
//			continue;
//		}
//		
//		if(str[0] == '-') break;
//	
//		for(int i = 0; i < str[i]; i++) {
//			if(str[i] == '{')
//				st.push(str[i]);
//			else if(str[i] == '}') {
//				if(st.empty()) {
//					r_st.push(str[i]);
//				}
//				else
//					st.pop();
//			}
//		}
//		
//		if(st.empty()) {
//			num = 0;
//		}
//		else if(st.size() > 0 && r_st.size() == 0) {
//			num += (st.size() / 2);
//		}
//		else if(st.size() == r_st.size()){
//			int val = 0;
//			if(r_st.size() % 2 == 0)
//				val = r_st.size() / 2;
//			else
//				val =  r_st.size() / 2 + 1;
//			
//			num += val*2;
//		}
//		else { //r_st.size() > st.size()
//			num+= r_st.size();
//		}
//		cout << ++tc << ". " << num << "\n";
//	}
//	
//	return 0;
//}
