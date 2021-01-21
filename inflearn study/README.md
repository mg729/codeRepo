# Inflearn

<!--it 취업을 위한 알고리즘 문제 풀이-->
- 2020.12.11~
- 다시 풀어볼 문제
    - quiz26 (병합정렬), quiz30, quiz35 

> Quiz    
[001 max, min 값 초기화](#max,min_Initialization)  
[002 ASCII](#Necessary_ascii_code)  
[003 string Type](#stringType)  
[004 how to convert string to int](#Convert_String_To_Int)  
[005 how to convert int to string](#Convert_Int_To_String)  
[006 getline()](#When_To_Use_getline)  
[007 TIME_LIMIT_EXCEED](#Example_of_TIME_LIMIT_EXCEED)  
[008 소수](#Prime_Number)  
[009 소인수분해](#Prime_factorial)  
[010 최대 최소값 구하기](#Max_Min_Value)  
[011 1차원 배열 구간합](#Partial_sum_of_Array)  
[012 vector n개만큼 할당하기](#Vector_n)  
[013 C++ STL - 정렬되는 컨테이너](#STL_Container)  
[014 C++ iterator 활용하기](#Iterator)  
[015 정렬 시간복잡도](#TimeComplexity_Sorting)  



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

- stoi()
- stof()
- stod()
```cpp
string str1 = "45";
int myint1 = std::stoi(str1);
```


## Convert_Int_To_String
> quiz29

- __to_string()__ 
```cpp
double f = 23.43;
string f_str = std::to_string(f);

int i = 24;
string i_str = std::to_string(i);
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
> quiz 9 - nested for loop  
> quiz 22 (1) - access index which is out of scope of the array 


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

## Prime_factorial
> quiz27


- factorial 
    - N! 
    - int 범위 초과할 수 있으니 N! 값을 저장할때는 unsigned long long
- **prime factorial**
    - 소인수분해
    - **prime factorization, integer factorization**


    ```cpp
    int tmp = i;
    int j = 2;
    while(1) {
        if(tmp % j == 0) {
            tmp /= j;
            v[j]++;
        }
        else {
            j++;
        }
        if(tmp == 1) break;
    }
    ```

## Max_Min_Value
> quiz19


- 56 46 55 76 65 53 52 53 55 50
    - 위 수에서 맨 앞의 숫자를 max로 하고 맨앞자리 수를 제외한 부분집합의 수 중에서 값들을 비교해서 기존의 max값보다 크지않다면 가장 키가 큰 학생이므로 res++;
    - 근데 위 풀이 처럼하면 for 이중으로 쓰게됨
    - 그냥 **뒤에서부터** 접근
    - 뒤에서부터 맨 처음 숫자를 max로 설정하고 하나씩 앞으로 이동하면서 기존 max보다 큰 수가 있다면 키가 더 큰 학생이므로 res++; 하고 max값을 업데이트


## Partial_sum_of_Array  
> quiz22  
> 1차원 배열 구간합 (**제한시간 1초**)  


- 시간복잡도 O(n)으로 풀이하기  
    - 0부터 k까지의 부분합을 미리 구하기
    - k부터 n-1까지 부분합 for루프하나로 구하기
        - 이때 배열의 요소를 sum 값에 더해주면서 i-k값인 k구간의 이전요소를 빼주면서 sum 값 업데이트


## Vector_n
> quiz24


```cpp
int n;
cin >> n;
vector<int> v(n);
```


## STL_Container
- 컨테이너에 원소가 삽입될때 자동으로 순차적으로 정렬되는 컨테이너
    - `std::set`, `std::multiset`, `std::map`, and `std::multimap` are all **sorted using std::less** as the default comparison operation. 

## Iterator
- How to access data using iterator
    - `*it`

```cpp
set<int>:: iterator it;
for( it = s.begin(); it!=s.end(); ++it){
   int ans = *it;
  cout << ans << endl;
}
```

## TimeComplexity_Sorting
- 선택정렬, 버블정렬, 삽입정렬 : O(n^2)  
- 병합정렬 : O(nLogn)
- 퀵정렬 : O(nLogn), O(n^2)  