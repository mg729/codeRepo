# 프로그래밍1

- [해설](https://www.geeksforgeeks.org/count-divisors-n-on13/)

## 제출코드 (PASS)


```c++ 
#include <st ring>
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
> **약수의 개수를 구하는 방법을 구현 할 수 있는지**


- 1부터 n까지의 합 **x(x+1) / 2**
- **sqrt()** : 소수 prime number 판별 알고리즘에서 활용


```c++ 
#include <bits/stdc++.h>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    for(int i = left; i <= right; i++) {
        //calculate divisor
        int cntDivisor = 0;
        for(int j = 1; j <= sqrt(i); j++) {
			if(i % j == 0) {
				if(i / j == j) {
					cntDivisor++;
				}
				else cntDivisor += 2;
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



# 프로그래밍2

## 제출코드 (FAIL)

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
- 문제
	- 양의 정수 x에 대한 함수 f(x)를 다음과 같이 정의합니다.
	- x보다 크고 x와 비트가 1~2개 다른 수들 중에서 제일 작은 수

> **비트연산을 적절히 응용할 수 있는지**  
> 시뮬레이션 문제가 아닙니다

- 해설
	- **x가 짝수인 경우**
		- 만약 x의 비트를 하나만 바꾸는 경우, x는 커져야하기 때문에 x의 어떤 0을 1로 바꿔야하는데, 그렇다면 x가 가진 0중에서 가장 낮은위치에 있는 0을 1로 바꾸는 것이 이상적

	- **x가 홀수인 경우**
		- 만약 x의 비트를 두 개 바꿀 경우, 일단 하나의 0을 1로 바꿔야하는데, 다른 하나는 그보다 더 낮으면서 제일 높은 자리의 1을 0으로 바꾸는 것이 이상적


## myCode(PASS)


```c++
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    long long val;
    for(long long i = 0; i < numbers.size(); i++) {
    	val = numbers[i];  
  		string bitStr = "";
		while(val > 0) {
			if(val % 2 == 0) {
				bitStr.insert(0, 1, '0');
			}
			else {
				bitStr.insert(0, 1, '1');
			}
			val /= 2;
		}
		
    	if(numbers[i] % 2 == 0) { // even
            answer.push_back(numbers[i] + 1);
		}
		else { //odd
			// if odd bit has no 0 value --> add 0
			bool isContainZero = false; 
    		for(long long j = bitStr.size() - 1; j >= 0; j--) {
    			if(bitStr[j] == '0') {
    				isContainZero = true;
    				break;
				}
			}
			
			if(!isContainZero) {
				bitStr.insert(0, 1, '0');
				bitStr.replace(bitStr.begin(), bitStr.begin() + 2, "10");
			}
			else {
				long long idx = 0;
				for(long long j = bitStr.size(); j >= 0 ; j--) {
	    			if(bitStr[j] == '0') {
	    				bitStr.replace(j, 1, "1");
	    				idx = j;
	    				break;
					}
				}
				
				for(long long j = idx + 1; j < bitStr.size(); j++) {
	    			if(bitStr[j] == '1') {
	    				bitStr.replace(j, 1, "0");
	    				idx = j;
	    				break;
					}
				}
			}
            long long res = 0;
            long long two = 1;
            for(long long j = bitStr.size() - 1; j >= 0; j--) {			
                if(bitStr[j] == '1') {
                    res += two;
                }
                two *= 2;
            }		
            answer.push_back(res);
		}
	}
    
    return answer;
}
```

## string 과 char 에 대하여
- string 타입의 원소를 배열 인덱스로 접근시 char 타입으로 전환됩니다.

```c++
string str1 = "hello";
str1[0] = 'H';
cout << str1; // Hello
```

- **operator+=**, **append()** 처럼 뒤에 char 데이터 추가가 아닌 앞에 char 데이터 추가 **insert()**


```c++
std::string s = "xmplr";

// insert(size_type index, size_type count, char ch)
s.insert(0, 1, 'E');
assert("Exmplr" == s);

// insert(size_type index, const char* s)
s.insert(2, "e");
assert("Exemplr" == s);
```

## bitmask c++ 연산
- **비트마스크 (BitMask)란?**
	- 비트마스크는 이진수를 사용하는 컴퓨터의 연산 방식을 이용하여, 정수의 이진수 표현을 자료구조로 쓰는 기법
- **비트연산자**
	- AND : (**&**) 두 정수를 한 bit씩 비교하면서 해당 bit가 둘다 1인경우에 1
	- OR : (**|**) 두 정수를 한 bit씩 비교하면서 하나의 bit라도 1인 경우에 1
	- XOR : (**^**) 두 정수를 한 bit씩 비교하면서 하나의 bit만 1인경우에 1
	- NOT : (**~**) 정수하나를 입력받아서 한 비트씩 탐색하며 1인 bit는 0으로, 0인 bit는 1로 
	- Shit : (**<<**)/(**>>**) 비트들을 왼쪽 또는 오른쪽으로 원하는 만큼 움직이고 움직이고 나서 빈 자리는 0으로 채워진다.
	
	```c++
	// 13 - 00001101
	int bitmask1 = (13 << 1); // 00011010
    int bitmask2 = (13 >> 1); // 00000110
	cout << bitmask1 << endl; // 26
	cout << bitmask2 << endl; // 6
	```

## bitmask C++ 연산 응용 해답

- 이진수에서 홀수가 나오려면 무조건 마지막의 1의 자리수인 1이 있어야함
- 왜냐하면 이진수의 각 자리수는 2의 지수승으로 치환되므로 홀수가 구해지려면 무조건 마지막 1의 자리수인 1이 1이어야함


```c++
#include <vector>
std::vector<long long> solution(std::vector<long long> numbers) {
    std::vector<long long> answer;
    for (long long number : numbers) {
        long long bit = 1; // l의 자리수
        while ((number & bit) > 0) { 
			bit <<= 1; // bit = (bit << 1);
		}
        answer.push_back(number + bit - (bit >> 1));
    }
    return answer;
}
```
