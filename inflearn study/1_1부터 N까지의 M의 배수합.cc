#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int n,m;
int sum;
int main(int argc, char** argv) {
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++) {
		if(i % m == 0) 
			sum += i;		
	}
	cout << sum;
	
	return 0;
}