#include<bits/stdc++.h>

using namespace std;
int n;
string number;

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
    //freopen("input.txt", "rt", stdin);
	
	cin >> number;

    // substr(pos, size())
    // if using number[0] + number [1] --> WRONG
    // because char type has no operator + ()
	string year = number.substr(0,1) + number.substr(1,1);

	int age = 0;
	bool isWoman = true;
	
	switch(number[7]) {
        // case 1 --> WRONG
        // case '1' --> should consider char type
		case '1': {
			isWoman = false;
			string sYear = "19" + year;
			age = 2019 - stoi(sYear) + 1;		
			break;
		}
		case '2':{
            string sYear = "19" + year;
            age = 2019 - stoi(sYear) + 1;	
			break;
		}
		case '3': {
			isWoman = false;
			string sYear = "20" + year;
			age = 2019 - stoi(sYear) + 1;	
			break;
		}
		case '4':{
            string sYear = "20" + year;
            age = 2019 - stoi(sYear) + 1;
			break;
		}
	}
	cout << age;
	if(isWoman)
		cout << " W";
	else 
		cout << " M";
	
	
	return 0;
}