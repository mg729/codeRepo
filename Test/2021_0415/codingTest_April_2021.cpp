/*Quiz1*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    for(int i = 0; i < absolutes.size(); i++) {
        int val = absolutes[i];
        if(!signs[i]) val = -val; 
        answer += (val);
    }
    return answer;
}


/*Quiz2*/

#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<string> st;

int solution(string s) {
    int answer = 0;
    int size = s.length();
    
    for(int i = 0; i < size; i++) {
    	if(s[0] == '(')  s.append("(");
		else if(s[0] == ')')  s.append(")");
		else if(s[0] == '[')  s.append("[");
		else if(s[0] == ']')  s.append("]");
		else if(s[0] == '{')  s.append("{");
		else if(s[0] == '}')  s.append("}");
		
        s.erase(0,1);
        bool isOnlyRight = false;
        for(int j = 0; j <  size; j++) {
            if(s[j] == '[' || s[j] == '(' || s[j] == '{') {
                isOnlyRight = true;
                if(s[j] == '(')  st.push("(");
				else if(s[j] == '[')  st.push("[");
				else if(s[j] == '{')  st.push("{");
            }
            else if(s[j] == ']') {
                if(!st.empty() && st.top() == "[") st.pop();
                
            }     
            else if(s[j] == '}') {
                if(!st.empty() &&st.top() == "{") st.pop();
            }
            else if(s[j] == ')') {
                if(!st.empty() && st.top() == "(") st.pop();
            }
        }
        
        if(isOnlyRight && st.empty()) answer++;
        while(!st.empty()) st.pop();
    }
    
    return answer;
}