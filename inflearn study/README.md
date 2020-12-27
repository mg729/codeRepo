# Inflearn

<!--it 취업을 위한 알고리즘 문제 풀이-->
- 2020.12.11~

> Quiz    
[001 max, min 값 초기화](#max,min_Initialization)  
[002 ASCII](#Necessary_ascii_code)  
[003 string Type](#stringType)  
[004 how to convert string to int](#Convert_String_To_Int)  
[005 getline()](#When_To_Use_getline)  
[006 TIME_LIMIT_EXCEED](#Example_of_TIME_LIMIT_EXCEED)  
[007 소수](#Prime_Number)  
[008 최대 최소값 구하기](#Max_Min_Value)  


## max,min_Initialization
`signed int` type: 값의 범위 `–2,147,483,648 ~ 2,147,483,647`  
- max 값 초기화 : __-2,147,000,000__  
- min 값 초기화 : __2,147,000,000__  

## Necessary_ascii_code
> quiz 6, quiz 13   


| ascii | 10진법 |   
| :---: | :---: |   
| 0 | 48 |  
| 9 | 57 |  
| A | 65 |  
| Z | 90 |  
| a | 97 |  
| z | 122 |  

## stringType  
- __substr()__ : returns a substring
    - _substr_(position of the first character to include, length of the substring)
- __append()__ : appends string type characters to the end
    - str1._append_(str2); //str1str2
- __+()__ : concatenates two strings or a string and a char
- __atoi()__ : converts a byte string to an integer value
- __stoi()__ : converts a string to a signed integer  

## Convert_String_To_Int
> quiz 6


- utilize __ascii code__ for converting String to Int type value
```cpp
string input;
cin >> input;
for(int i = 0; i < input.length(); i++) {
    if(input[i] >= 48 && input[i] <= 57){
        result = result * 10 + (input[i] - 48);
    }
}
```

## When_To_Use_getline
> quiz 7


- __getline()__
    - 공백, 띄어쓰기를 무시하고 ‘\n’까지의 string데이터를 input으로 받음
```cpp
std::string name1;
std::getline(std::cin, name1);
```


## Example_of_TIME_LIMIT_EXCEED
> quiz 9


- __cin__ 말고 __scanf__ 쓰니까 시간 초과 문제 해결
    - `ios::sync_with_stdio(false);`
    - `cin.tie(nullptr);`

- n제곱 시간복잡도 주의 (이중 for문)
    - timeout
    
    ```cpp
	for(int i = 1; i <= n; i++) {
		int divisor = 0;
		for(int j =1; j <= i; j++) {
			if(i % j == 0)
				divisor++;
		}
		cout << divisor <<" ";
	}
    ```


    - fix timeout

    ```cpp
 	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j = j + i) {
			v[j]++;
		}
	}   
    ```

## Prime_Number
> quiz14, quiz15   


- **1 is not prime Number**  
- Need to consider TIME_OUT 
    - 36의 약수  

        | | |   
        | :---: | :---: |    
        | 1 | 36 |    
        | 2 | 18 |    
        | 3 | 12 |    
        | 4 | 9 |    
        | 6 | 6 |    

    - range of checking prime number should be filtered by **sqrt()**;

    ```cpp
    int limit = sqrt(x);  
	for(int i = 2; i <= limit ; i++) {
		if(x % i == 0) {
			return false;
		}
	}
    ```


    ```cpp 
	for(int i = 2; i *i <= n ; i++) {
		if(x % i == 0) {
			return false;
		}
	}
    ```

## Max_Min_Value
> quiz19


- 56 46 55 76 65 53 52 53 55 50
    - 위 수에서 맨 앞의 숫자를 max로 하고 맨앞자리 수를 제외한 부분집합의 수 중에서 값들을 비교해서 기존의 max값보다 크지않다면 가장 키가 큰 학생이므로 res++;
    - 근데 위 풀이 처럼하면 for 이중으로 쓰게됨
    - 그냥 **뒤에서부터** 접근
    - 뒤에서부터 맨 처음 숫자를 max로 설정하고 하나씩 앞으로 이동하면서 기존 max보다 큰 수가 있다면 키가 더 큰 학생이므로 res++; 하고 max값을 업데이트

