# Inflearn

<!--it 취업을 위한 알고리즘 문제 풀이-->

<details><summary>다시 풀어볼 문제</summary>
<p>
- 2021.00.00<br>
    - quiz 26 (병합정렬풀이)<br>
    - quiz 30 (large)<br>
    - quiz 41 (연속된 자연수의 합 풀이 방법 --> 암기)<br>
    - quiz 43 : 결정알고리즘 --> backjoon (Binary Search)<br>
    - quiz 52 : 기업인터뷰로 자주출제되는 문제<br><!--아래019설명참고-->
    - quiz 53 : 스택 자료구조--> string 응용<br>
    - quiz 60 : 59번이랑 다른방식으로 풀이할 것<!--강의 다시 보기, 강의처럼 면접 대비 멘트 연습해 볼 것, check[]배열없이--><br>
    - quiz 62 : <br>    <!--병합정렬 강의듣고 100프로 이해한적 오늘이 레알 처음... 명강의다 강의 또듣자!! 무조건 복습 && : 병합정렬 Point **1. 후위순회방식 2. tmp 배열 & point 변수(p1,p2,p3)**-->
    - quiz 64, 66<br>    <!--맞추긴 맞추었으나..풀이시간이 너무오래걸렸음 다시 풀이하쟈..그리고 내 풀이보다 정답풀이가 더 깔끔햇음.. 특히 탈출조건관련해서 나는 탈출조건따로 안달았는데..탈출조건 있는게 더 깔끔..그리고 강의 내용도 너무 좋다 강의 반복수강할 것-->
    - quiz 69<br>    <!--문제에 hint로 ~~~이라고 써 있는데 문제조건이 지워져있어도 해당 문제 풀이 가능해야, 그리고 cleanCode 가 더 깔끔-->
    - quiz 71<br>    <!--이문제를 읽자마자 아! 이건 BFS 문제다!하는 느낌이 들어야함, 아 그리고 방향배열..도 설정하자(강의참고) cleanCode 꼭 확인-->
    - quiz 75<br>    <!--구조체를 이용한 STL vector 정렬 공부 확실히 하기, 강의꼭다시수강할 것-->
    <!--Please memorize above quiz solutions && 다시 풀이하기-->
    <!--76번부터~90번까지 :) -->
    - quiz 76<br>
    - quiz 77<br>
    - quiz 78<br>
    - quiz 79<br>
- 면접대비<!--오답정리때 답은 맞추었음, 그래도 문제읽어보고 정답풀이 확인하고 풀이 암기권장및 강의 반복수강--><br>
    - quiz 56 (강의 : *56.재귀함수 분석 보충* - 스택프레임/스택오버플로우 개념)<br>
    - quiz 56, 57 : 나 재귀함수짤 때 탈출조건 1에 집착하는데 x == 0으로도 받아보고 다양하게 생각해보자 : 탈출조건 x==1 아니고 x==0<br>
    - quiz 59 : 부분집합 check[] 배열<br>
    - quiz 70<br>    <!--queue front 데이터를 배열 인덱스로 활용하기-->
    - quiz 72<br>    <!--pop하는 데이터를배열 뒤로 다시 push하는 원형데이터를 다룰때 queue 자료구조를 활용합시다-->
    - quiz 74<br>
</p>
</details>


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
[016 이분탐색](#Binary_Search)  
[017 소수점 첫째자리에서 반올림](#Round_up_to_first_decimal_place)  
[018 배열 index 설정](#How_to_handle_array_index)  
[019 투포인트 알고리즘](#Two_Point_algorithm)  
[020 K진수 변환](#Decimal_converter)  
[021 스택프레임, 스택오버플로우](#Stack_concept)  
[022 다익스트라](#Dijkstra)  
[023 dfs,bfs](#DFS_BFS)  
[024 priority queue](#priority_queue)  
[025 memoization](#memoization)  
[026 UnionFind](#UnionFind)  
[027 Kruskal Algorithm](#Kruskal)  
[027 Prim MST](#Prim)  


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
> quiz24, quiz47


```cpp
int n;
cin >> n;
vector<int> v(n);

// two dimension vector initialization
vector<vector<int> > map(n, vector<int>(n, 0));
```
- 2차원 벡터를 0으로 초기화
- vector<vector<int> > map(n, vector<int>(n));
- vector<vector<int> > map(n, vector<int>(n, **0**));
    - 0은 생략가능 / 다른 수로 초기하할 경우 다른 자연수 입력


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

## Binary_Search
- **lt, rt, mid**
- quiz 42,43

> **결정 알고리즘**  
> 알고리즘 대회의 문제에서 결정알고리즘 유형이 출제되면 이분탐색법으로 해결  
> **답을 결정해두고 이 답이 가능한지 아닌지를 따지며 답을 찾아가는 것**

## Round_up_to_first_decimal_place
> quiz 48


- 소수점 첫째자리에서 반올림 : round up to first decimal place
- 소수점 셋째자리에서 반올림 : round up to third decimal places
- 소수점 : **decimal point**

```c++
int avg = (sum / 9.0) + 0.5;
```
- double 타입의 실수변수값에 0.5를 더해줘서 int 타입으로 강제형변환하면 첫째자리에서 반올림됨  


## How_to_handle_array_index
> quiz 51


- 이중 for문을 돌 때 `int i` 와 `int j` 값의 초기값을 1로 설정하는 것 권장
- array 배열은 어차피 0으로 초기화 된 경우라면 아래 코드에서 board[i-1][j-1] 에서 i 와 j 가 1인 경우 0값이 있으므로 이슈상황 발생 안할 것

```c++
for(int i = 0; i < n; i++) {
    for(int j = 0; j < m ; j++) {
        board[i][j] = board[i][j-1] + board[i-1][j] - board[i-1][j-1] + arr[i][j]; 
    }
}
```


## Two_Point_algorithm
> quiz52  
> **미국기업에서도 인터뷰로 자주나오는 유형**


- 투포인트 알고리즘

## Decimal_converter
> quiz53  


- 2진수 : Binary
- 8진수 : Octal
- 10진수 : decimal 
- 16진수 : hexadecimal
    - 16진수 (10 : A, 11: B, 12:C, 13:D, 14:E, 15:F)


## Stack_concept
> quiz 56  


- 스택프레임 : main() 함수부터 보관, 호출되는 함수들을 스택에 쌓아두는 프레임, 각각의 프로세스마다 스택프레임을 갖게되는데 이때 스택내부적으로 매개변수, 지역변수, **복귀주소**를 보관한다.

- 호출된 함수의 스택프레임이 자기의 복귀주소를 갖고 스택프레임을 생성시킨다.

- 스택이 꽉차서 최상단의 스택프레임을 넘어가게 스택프레임을 생성시키려면 **스택 오버플로우**

## Dijkstra
- 다익스트라 알고리즘은 다이나믹 프로그래밍을 활용한 대표적인 최단 경로 탐색알고리즘  
- 흔히 인공위성 GPS 소프트웨어등에서 가장 많이 사용
- 하나의 최단거리를 구할 때 그 이전까지 구했던 최단거리 정보를 그대로 사용

- **다익스트라**
    - 출발노드를 설정
    - 출발노드를 기준으로 각 노드의 최소비용을 저장
    - 방문하지 않은 노드 중에서 가장 적은 비용의 노드를 선택
    - 해당노드를 거쳐서 특정한 노드로 가는 경우를 고려하여 최소 비용을 갱신

- 2차원 배열 행렬활용

## DFS_BFS
> DSF BFS 문제보고 구분하기

- **DFS** : 경로탐색, 경로탐색 후 최소비용구하기 
    - 재귀, stack
- **BFS** : 최단 거리 (어떤 출발점에서 도착점을 향해서 갈 때 최소 횟수로 가는 횟수/최단거리 --> 큐 자료구조)
    - queue

- **최단거리 문제를 푼다면 BFS**
    - 특히 가중치 없는 그래프의 최단경로문제는 only BFS
- **이동할때마다 가중치가 붙어서 이동하거나 이동 과정에서 여러 제약이 있는 경우 DFS**

## priority_queue
> quiz 73
- 우선순위 큐 **priority_queue**
    - 부모노드가 왼쪽자식과 오른쪽 자식값보다 크도록 트리가 구성
    - 레벨 별로 노드에 데이터가 삽입되고 삽입된 이후 부모노드와 계속 값을 비교하여 트리내부데이터를 재구성
    - 데이터 *pop()*하는 경우 : 가장 말단의 제일 오른쪽 데이터가 루트노드로 삽입되고 다시 트리 내부적으로 값을 비교하여 트리 재구성
    - 데이터 *top()*하는 경우 : max heap 구조라서 가장 최댓값인 루트노드값을 반환

- 최대값 구하기

- **최소값 구하기**
> quiz74

```c++
template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
> class priority_queue;

priority_queue <int, vector<int>, greater<int>> pq;
```

## memoization
> quiz 76 - 이항계수(메모이제이션 풀이)  


-  **메모이제이션(memoization)** 은 컴퓨터 프로그램이 동일한 계산을 반복해야 할 때, 이전에 계산한 값을 메모리에 저장함으로써 동일한 계산의 중복 수행을 제거하여 프로그램 실행 속도를 빠르게 하는 기술이다.

- 대표 예제 
    - **이항계수**
    - **nCr = n-1Cr + n-1Cr-1**
    - **nCn == nC0** : **1**
        - *n개 중 n개 모두를 선택하는 경우의수*와 *n개 중 아무것도 고르지 않는 경우의 수* 모두 1가지씩있으므로 nCn과 nC0은 1의 값을 가짐
    - 이미 계산된 조합의 결과는 중복계산하지 않도록 코딩

## UnionFind  
> **UnionFind**  : *A disjoint-set* data strsubsetsucture is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) . A union-find algorithm is an algorithm that performs two useful operations on such a data structure


- Union Find 알고리즘 : Disjoint Set을 표현할 때 사용하는 알고리즘
    - Disjoint Set 서로소 집합 
    - **tree**로 구현합니다.
    
## Kruskal

- **Kruskal's Algorithm 크루스칼 알고리즘** 
    - **MST** (*Minimun Spanning Tree*) : 최소비용신장트리
    - 그래프에서 최소비용 트리 만드는 것
    - 크루스칼 알고리즘이란, 그래프 내의 모든 정점들을 가장 적은 비용으로 연결하기 위해 사용, 그래프 내의 모든 정점을 포함하고 **사이클이 없는 연결 선**을 그렸을 때, 가중치의 합이 최소가 되는 상황을 구하고 싶을 때 크루스칼 알고리즘을 사용

    - SOLUTION : **UnionFind** (quiz78)
        - *Point* : 우선 간선의 가중치를 기준으로 작은순으로 오름차순 정렬해서 정점이 서로소집합을 만족하는 경우에만 정점을 포함
    
## Prim

- **Prim Algorithm** : 정점을 추가하는 방식
    - MST 최소비용신장트리를 만드는데 간선을 선택하는 것이 아니라 임의의 정점을 하나 선택
    - 거기서부터 계속 그래프의 연결관계를 보면서 정점을 하나씩추가
    - 정점을 추가하면서 트리를 확장
    - 정점이 N개가 완성되면 트리가 완성되는 것

    - SOLUTION : **priority_queue** - 최소힙활용 (quiz79)

- **prim & kruskal 차이**
    - 프림 알고리즘은 꼭지점(정점)을 선택하고 그것과 연결된 가장 적은 비용의 **정점을 선택**
    - 크루스칼 알고리즘은 모든 비용을 순차적으로 나열하여 가장 적은 비용이 드는 **간선(신장)들을 선택**
