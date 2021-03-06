# BOJ  

# 항상 코드 제출 전에 반례가 될만한 예시 케이스들을 다양하게 테스트 후 제출  

### Chapter 01. 기본 자료구조

#### [01] [기초 문제풀이]
* [음계](https://www.acmicpc.net/problem/2920): ([C++ 답안](2920.cpp))
* [블랙잭](https://www.acmicpc.net/problem/2798): ([C++ 답안](2798.cpp))

#### [02] [핵심 유형 문제풀이]  
> 벡터, 큐, 스택을 활용한 문제풀이  
> queue<pair<int,int>> 이런 식으로 >>가 두개 붙어 있으면 비트 연산자 처리 되서 > > 띄어서 써야함  


* [스택 수열](https://www.acmicpc.net/problem/1874): ([C++ 답안](1874.cpp))  
* [프린터 큐](https://www.acmicpc.net/problem/1966): ([C++ 답안](1966.cpp))  
    * [우선순위 큐에대한 이해](https://en.cppreference.com/w/cpp/container/priority_queue)
* [키로거](https://www.acmicpc.net/problem/5397): ([C++ 답안](5397.cpp))
    * [std::reverse](https://en.cppreference.com/w/cpp/algorithm/reverse) - `defined in header <algorithm>`  

### Chapter 02. 고급 자료구조

> 해시, 집합을 활용한 문제풀이


#### [03] [핵심 유형 문제풀이]
* [수 찾기](https://www.acmicpc.net/problem/1920): ([C++ 답안](1920.cpp))
    * [std::find](https://en.cppreference.com/w/cpp/algorithm/find) - `defined in header <algorithm>`  
    * [중복을 허용하지 않는 데이터 컨테이너 set](https://en.cppreference.com/w/cpp/container/set)  
    * [count function : member function of set](https://en.cppreference.com/w/cpp/container/set/count)  
* [친구 네트워크](https://www.acmicpc.net/problem/4195): ([C++ 답안](4195.cpp))  
    * **Union-Find 알고리즘**  <!--TIL Blog concept update is needed and need to solve the problem again in the future-->
    * [C++ 문자열](https://mg729.github.io/c++/2019/10/09/C++_String/)  
        * do not use **cin, cout** for string type data  
        * scanf("%s", string data) is not working (scanf does not reads **string** but reads **char** type data)   

### Chapter 03. 기본 정렬 알고리즘

> 정렬 라이브러리, 키(Key) 기반 정렬, 계수 정렬을 활용한 문제풀이  
> [C++ 정렬 기초 컨셉](https://mg729.github.io/c++/2020/03/30/C++_sort/)  
> `sort() function is defined in <algorithm>`  
> sort의 매개변수 compare는 **bool 타입**이다. `bool cmp(const Type1 &a, const Type2 &b);`  

#### [04] [기초 문제풀이]  
* [수 정렬하기](https://www.acmicpc.net/problem/2750): ([C++ 답안](2750.cpp))
    * std::set is an associative container that contains a **sorted set** of **unique** objects of type Key  
    * set 컨테이너는 중복을 허용하지 않는 정렬된 컨테이너  
* [소트인사이드](https://www.acmicpc.net/problem/1427): ([C++ 답안](1427.cpp))  
    * **Notice** : In *char* type array and *string* type, a null character ('\0') has been added in order to indicate the end of the sequence.  
        * '0' refers to the character zero, which has an ASCII value of 48  
        * '\0' refers to the null character (ASCII value 0), or a number of value 0  

#### [05] [핵심 유형 문제풀이]  
* [나이순 정렬](https://www.acmicpc.net/problem/10814): ([C++ 답안](10814.cpp))  
    * `sort()`: *sorts the elements*  
    * `stable_sort()`: *sorts a range of elements while preserving order between equal elements*  
        * `stable_sort` : 정렬을 하되 원소들 간의 순서를 보존합니다. 만약에 벡터에 [a, b] 순으로 있었는데, a 와 b 가 크기가 같다면 정렬을 [a,b] 혹은 [b,a] 로 할 수 있습니다. **sort** 의 경우 그 순서가 랜덤으로 정해집니다. 하지만 **stable_sort** 의 경우 그 순서를 반드시 보존합니다. 즉 컨테이너 상에서 [a,b] 순으로 있었다면 정렬 시에도 (크기가 같다면) [a,b] 순으로 나오게 됩니다. 이 때문에 sort 보다 좀 더 느립니다.  
* [좌표 정렬하기](https://www.acmicpc.net/problem/11650): ([C++ 답안](11650.cpp))  
    * sort() : comparison function object which returns ​true if the first argument is less than the second.  
        * C++ 기본 정렬 라이브러리는 기본적으로 인덱스 순서대로 오름차순으로 정렬  
* [수 정렬하기 3](https://www.acmicpc.net/problem/10989): ([C++ 답안](10989.cpp))  
    * **계수정렬 알고리즘 (Counting Sort)**  
    > 데이터의 개수가 많은 대신 데이터의 범위가 좁은 경우 계수정렬 알고리즘을 활용
    > 배열의 인덱스를 특정한 데이터의 값으로 여기는 정렬 방법  
    > 배열의 크기는 데이터의 범위를 포함할 수 있도록 설정  
    > 데이터가 등장한 횟수를 카운팅  
     

    * for 루프 내에서는 scanf, printf사용 권장  
    * for 루프 내에서 cin, cout 쓰는 것은 시간 초과 에러 원인일 수 있음  

### Chapter 04. 재귀 호출

> 기본적인 재귀 함수 구현을 활용한 문제풀이

#### [06] [핵심 유형 문제풀이]
* [피보나치 수](https://www.acmicpc.net/problem/2747): ([C++ 답안](2747.cpp))  
    * 문제의 취지 : 재귀함수의 느린 연산 속도(시간)를 해결하기 위해서 **동적계획법**을 활용  
    > 재귀함수의 한계 : 동일 문제를 반복적으로 호출  
    > 동적계획법 : 하나의 문제는 단 한번만 풀도록 하는 알고리즘 (이미 푼 것을 다시 푸는 비효율적인 알고리즘 개선)  
    

* [Z](https://www.acmicpc.net/problem/1074): ([C++ 답안](1074.cpp))  
    * __std::pow__  `defined in header <cmath>`  
    * pow(2, 10) = 1024  
    * __std::sqrt__  `defined in header <cmath>`   
    * sqrt(100) = 10  
    * *global 변수를 재귀함수 내에서 바로 print out*    
    * *입력 좌표 (r, c)도 global 변수로 지정*  
* [0 만들기](https://www.acmicpc.net/problem/7490)
    * python : *eval()* 함수 활용  


### Chapter 05. 고급 정렬 알고리즘

> 병합 정렬을 활용한 문제풀이

#### [07] [핵심 유형 문제풀이]  
* [수 정렬하기 2](https://www.acmicpc.net/problem/2751):([C++ 답안](2751.cpp))  
* [K 번째 수](https://www.acmicpc.net/problem/11004): ([C++ 답안](11004.cpp))  

### Chapter 06. 기본 탐색 알고리즘

> 순차 탐색, 이진 탐색을 활용한 문제풀이

#### [08] [기초 문제풀이]
* [문서 검색](https://www.acmicpc.net/problem/1543): ([C++ 답안](1543.cpp))  
    * [substr()](https://en.cppreference.com/w/cpp/string/basic_string/substr) :  __substr__( size_type pos = 0, size_type count = npos )  
        * __pos__ -	position of the first character to include  
        * __count__	- length of the substring  
        * 실제로 string에서 데이터를 삭제하지는않고 substr한 결과를 show 하는 역할  
    * npos 는 -1을 의미  
    * string::__find()__ 는 0이나오는 경우가 있음 - string의 첫번째 요소를 찾아낸 경우 0을 반환  
    * 예외상황 체크!!주의  

* [새](https://www.acmicpc.net/problem/1568): ([C++ 답안](1568.cpp))  
* [베스트셀러](https://www.acmicpc.net/problem/1302): ([C++ 답안](1302.cpp))  
    * __map__ container : 등장 횟수를 계산할 때 활용하는 컨테이너  
    * `map <key, value>` : key는 정렬될 값, value는 key를 기준으로 저장될 값을 의미  
        * 중복된 key값을 허용 안함  

    * std::map is a __sorted__ associative container that contains key-value pairs with __unique keys.__   
        * map 정렬  
        * `map <key, value>` : __key를__ default로 `std::less<key>`를 활용하여 __오름차순으로 정렬__    
        * `map <key, value, std::greater<key>>` : 내림차순 정렬  
    * __iterator__ 활용한 for 루프 순회  
    ```c++
    for(auto it = sales.begin(); it != sales.end(); it++)
	{
		maxval = max(maxval, it->second); //it->second : value of the corresponding key of the map
	}
    for(auto it = sales.begin(); it != sales.end(); it++)
	{
		if(maxval == it->second)
		{
			cout << it->first; // it->first : key of the map
			break;
		}
	}
    ```
    
* [트로피 진열](https://www.acmicpc.net/problem/1668): ([C++ 답안](1668.cpp))  
* [성 지키기](https://www.acmicpc.net/problem/1236): ([C++ 답안](1236.cpp))  
    * __getchar()__ : clear the buffer  
    * 2차원 배열의 데이터 입력받기  
    ```c++
    cin >> array[i][j];
    ```
    * 2차원 배열 데이터 관리 : 행과 열에대한 배열을 각각 개별적으로 선언해서 관리  



#### [09] [핵심 유형 문제풀이]
* [공유기 설치](https://www.acmicpc.net/problem/2110): ([C++ 답안](2110.cpp))  
    > 탐색해야할 데이터의 수가 10억처럼 큰 경우 이진탐색으로 풀이할 것을 시도해야 합니다.  
    > 이진탐색 시간복잡도 : __O(log n)__


    * __Binary Search__ (이진탐색)  
        * 이미 데이터가 **정렬이 되어있는 상태**에서 범위를 반씩 좁혀가며 데이터를 빠르게 탐색하는 알고리즘  
        * min, max 혹은 start, end를 설정한 다음에 그 중간값 mid 를 반복적으로 찾고 min, max 값을 갱신하며 mid값을 찾는 것을 반복하는 알고리즘   
    * *이진 탐색시에 __mid__ 값 선언할 때 초기화 값을 잘 설정해야(무조건 0 이런값으로하지말고 container의 값 중 일부를 선택)*  

### Chapter 07. 고급 탐색 알고리즘

> 트리 순회, 힙 (**우선순위 큐**), 위상 정렬을 활용한 문제풀이

#### [10] [핵심 유형 문제풀이]
* [최소 힙](https://www.acmicpc.net/problem/1927): ([C++ 답안](1927.cpp))  
    * __TLE__ 주의 : *Time Limit Exceeded* 시간초과  
    * C++에서는 기본적으로 __우선순위 큐__ 가 최대힙(Max Heap)  
    * 우선순위 큐는 기본적으로 내림차순으로 정렬 - __최대힙__  
    * 정렬 기준 변경(__최소힙__)  
        * `priority_queue <[Data Type], [Container Type], [정렬 기준]>`  
        * `priority_queue <int, vector<int> , greater<int>> pq;`  
    * __최소힙__ 아예 음수로 push(-x) 입력하고 컨테이너 내부의 데이터용 벡터를 별도로 선언  
        ```c++
        priority_queue <int> pq;
        vector<int> v;
        
        pq.push(-x);
        v.push_back(-pq.top());
        ```
* [카드 정렬하기](https://www.acmicpc.net/problem/1715): ([C++ 답안](1715.cpp))  


### Chapter 08. 동적 프로그래밍

> 잘 알려진 동적 프로그래밍 개념 (타일링, Knapsack, LCS, LIS 등)을 활용한 문제풀이

#### [11] [기초 문제풀이]
* [01타일](https://www.acmicpc.net/problem/1904): ([C++ 답안](1904.cpp))  
    > 사용할 수 있는 타일의 종류는 2개  
    > 두가지 종류의 타일을 이용하여, N 길이의 수열을 만드는 모든 경우의 수를 구해야  
    > N이 최대 1,000,000이므로 시간복잡도 O(n)으로 해결해야함  


    * 한번 계산한 값은 다시 구하지 않는다  
    * 길이가 짧을 때 만들수있는 경우의수를 앞에서부터 차례로 계산해준다음에 나중에 길이가 커졌을 때 이미 구한 값들을 활용  
    * __메모이제이션__ : 이미 구한 값을 특정 list 배열, vector에 저장  

    * **동적프로그래밍 문제를 풀기 위해서는 점화식을 세워야합니다.**  
    * __점화식__ : 인접한 항들 사이의 관계식  

* [평범한 배낭](https://www.acmicpc.net/problem/12865): ([C++ 답안](12865.cpp))  

    > 12865번 풀이는 그냥 __암기!!!!!__  
    > __배낭문제(Knapsack Problem)__  으로도 알려져있는, 전형적인 동적프로그래밍 문제  
    > 물품의 수가 N, 배낭에 담을 수 있는 무게가 K  
    > 동적프로그래밍을 이용하여 시간복잡도 __O(NK)__ 로 문제 해결    
    

    - n * m 의 2차원 벡터 선언 및 초기화  
        - `vector< vector<int> > arr(6, vector<int>(5,0));`    
        - int arr[6][5] 배열을 선언하고 0으로 초기화  


* [가장 긴 증가하는 부분 수열](https://www.acmicpc.net/problem/11053): ([C++ 답안](11053.cpp))  
    * __LIS__ : _Longest Increasing Subsequence_  
 

#### [12] [핵심 유형 문제풀이]
* [LCS](https://www.acmicpc.net/problem/9251): ([C++ 답안](9251.cpp))  
    * __LCS__ : _Longest Common Subsequence_  
* [기타리스트](https://www.acmicpc.net/problem/1495): ([C++ 답안]())  


### Chapter 09. 그래프 기본 탐색 알고리즘

> DFS와 BFS를 활용한 문제풀이

#### [13] [기초 문제풀이]
* [DFS와 BFS](https://www.acmicpc.net/problem/1260): ([C++ 답안]())  
* [숨바꼭질](https://www.acmicpc.net/problem/1697): ([C++ 답안]())  

#### [14] [핵심 유형 문제풀이]
* [바이러스](https://www.acmicpc.net/problem/2606): ([C++ 답안]())  
* [유기농 배추](https://www.acmicpc.net/problem/1012): ([C++ 답안]())  
* [효율적인 해킹](https://www.acmicpc.net/problem/1325): ([C++ 답안]())  

### Chapter 10. 그래프 고급 탐색 알고리즘

> 다익스트라 최단 경로 알고리즘, 최소 신장 트리 알고리즘을 활용한 문제풀이

#### [15] [핵심 유형 문제풀이]
* [해킹](https://www.acmicpc.net/problem/10282): ([C++ 답안]())  
* [거의 최단 경로](https://www.acmicpc.net/problem/5719): ([C++ 답안]())  
* [우주신과의 교감](https://www.acmicpc.net/problem/1774): ([C++ 답안]())  

### Chapter 11. 탐욕 알고리즘

> 그리디(Greedy) 알고리즘의 원리를 활용한 문제풀이

#### [16] [기초 문제풀이]
* [거스름돈](https://www.acmicpc.net/problem/5585): ([C++ 답안]())  
* [뒤집기](https://www.acmicpc.net/problem/1439): ([C++ 답안]())  
* [등수 매기기](https://www.acmicpc.net/problem/2012): ([C++ 답안]())  
* [배](https://www.acmicpc.net/problem/1092): ([C++ 답안]())  

#### [17] [핵심 유형 문제풀이]
* [센서](https://www.acmicpc.net/problem/2212): ([C++ 답안]())  
* [도서관](https://www.acmicpc.net/problem/1461): ([C++ 답안]())  
* [컵라면](https://www.acmicpc.net/problem/1781): ([C++ 답안]())  

### Chapter 12. 백 트래킹

> DFS 혹은 조합(Combinations)을 활용한 문제풀이

#### [18] [핵심 유형 문제풀이]
* [N-Queen](https://www.acmicpc.net/problem/9663):  ([C++ 답안]())  
