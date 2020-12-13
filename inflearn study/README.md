# Inflearn

<!--it 취업을 위한 알고리즘 문제 풀이-->
- 2020.12.11~

> Quiz    
[001 max, min 값 초기화](#max,min_Initialization)  
[002 ASCII](#Necessary_ascii_code)  
[003 string Type](#stringType)  
[004 how to convert string to int](#Convert_String_To_Int)
[004 getline()](#When_To_Use_getline)

## max,min_Initialization
`signed int` type: 값의 범위 `–2,147,483,648 ~ 2,147,483,647`  
- max 값 초기화 : __-2,147,000,000__  
- min 값 초기화 : __2,147,000,000__  

## Necessary_ascii_code
> quiz 6  


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