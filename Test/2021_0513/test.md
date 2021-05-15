# 프로그래밍1

- [해설](https://www.geeksforgeeks.org/count-divisors-n-on13/)

## 제출코드

```c++
//sqrt()조건 왜안보지..? 
#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    for(int i = left; i <= right; i++) {
        //calculate divisor
        int cntDivisor = 1;
        for(int j = 2; j <= i; j++) {
            if(i % j == 0) {
                cntDivisor++;
            }
        }
        if(cntDivisor % 2 == 0) { //even
            answer += i;
        }
        else { //odd
            answer -= i;
        }

    }
    
    return answer;
}
```
## 문제 해설
> 약수의 개수를 구하는 방법을 구현 할 수 있는지

- 1부터 n까지의 합 **x(x+1) / 2**

- **sqrt()** : 소수 prime number 판별 알고리즘에서 활용


# 프로그래밍2

## 제출코드

```c++
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// step1 : 입력된 10진수 2진수로 바꾸기
// step2 : 입력된 수보다 큰 숫자를 2진수로 바꾸면서 diffBit세주기
// step3 : diffBit가 2보다 작거나 같거나 0보다 큰 경우 value return; 
int main() {
	vector<long long> numbers;
	numbers.push_back(2);
    numbers.push_back(7);
	vector<long long> input[numbers.size()];
//	vector<vector<long long> > input(numbers.size(), 0);

//    for(auto x : numbers) cout << x << endl; 
    
    for(int i = 0; i < numbers.size(); i++) {
    	long long tmp = numbers[i];
		while(tmp != 1) {
    		if(tmp % 2 == 0) {
    			input[i].push_back(0);
			}
			else {
				input[i].push_back(1);
			}
			tmp /= 2;
		}
		input[i].push_back(1);
	}
	
	vector<long long> answer; 
	vector<long long> cmpBit[numbers.size()];
	for(long long i = 0; i < numbers.size(); i++) {
		long long val = numbers[i];
		bool isFound = true;
		val++;
		long long numOfBits = 0;
		// handle push_back data
		int diffBit = 0;
		long long tmp = val;
		while(tmp != 1) {
			numOfBits++;
			if(tmp % 2 == 0) {
				cmpBit[i].push_back(0);
			}
			else {
				cmpBit[i].push_back(1);
			}
			tmp /= 2;
		}
		numOfBits++;
		cmpBit[i].push_back(1);	
		cout <<__LINE__ <<  numOfBits << endl;
		for(long long j = 0; j < numOfBits; j++) {
			if(input[i][j] != cmpBit[i][j]) {			
				diffBit++;
			}
		}
		if(diffBit <= 2 && diffBit > 0) {
			isFound = false;
			answer.push_back(val);
		}
		// access as index
		if(isFound) {
			for(long long k = 0; ; k++) {
				val++;
				
				diffBit = 0;
				tmp = val;
				while(tmp != 1) {
					if(tmp % 2 == 0) {
						cmpBit[i][k] = 0;
					}
					else {
						cmpBit[i][k] = 1;
					}
					tmp /= 2;
				}
				cmpBit[i][k] = 1;
				
				cout <<__LINE__ << val <<": ";
				for(long long j = 0; j < numOfBits; j++) {
					cout << cmpBit[i][j] << " ";
				}
				cout << "\n";
				if(numOfBits != input[i].size()) {
					if(0 != cmpBit[i][0]) diffBit++;	
					for(long long j = 1; j < numOfBits; j++) {
						if(input[i][j] != cmpBit[i][j+1]) {			
							diffBit++;
						}
					}
				}
				else {
					for(long long j = 0; j < numOfBits; j++) {
						if(input[i][j] != cmpBit[i][j]) {			
							diffBit++;
						}
					}
				}	
				if(diffBit <= 2 && diffBit > 0) {
					answer.push_back(val);
					break;
				}
			}
		}
	}
    
    for(auto x : answer) {
    	cout << x << " ";
	}
	
    return 0;
}
```
## 문제해설