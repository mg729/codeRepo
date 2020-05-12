# BOJ  

### Chapter 01. 기본 자료구조

#### [01] [기초 문제풀이]
* [음계](https://www.acmicpc.net/problem/2920): ([C++ 답안](2920.cpp))
* [블랙잭](https://www.acmicpc.net/problem/2798): ([C++ 답안](2798.cpp))

#### [02] [핵심 유형 문제풀이]
> 벡터, 큐, 스택을 활용한 문제풀이


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
        * `stable_sort` : 정렬을 하되 원소들 간의 순서를 보존합니다. 만약에 벡터에 [a, b] 순으로 있었는데, a 와 b 가 크기가 같다면 정렬을 [a,b] 혹은 [b,a] 로 할 수 있습니다. **sort** 의 경우 그 순서가 랜덤으로 정해집니다. 하지만 **stable_sort** 의 경우 그 순서를 반드시 보존합니다. 즉 컨테이너 상에서 [a,b] 순으로 있엇다면 정렬 시에도 (크기가 같다면) [a,b] 순으로 나오게 됩니다. 이 때문에 sort 보다 좀 더 느립니다.  
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
* [0 만들기](https://www.acmicpc.net/problem/7490): ([C++ 답안]())  

