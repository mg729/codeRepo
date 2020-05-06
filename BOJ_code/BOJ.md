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
> 'sort() function is defined in <algorithm>'  

#### [04] [기초 문제풀이]  
* [수 정렬하기](https://www.acmicpc.net/problem/2750): ([C++ 답안](2750.cpp))
    * std::set is an associative container that contains a **sorted set** of **unique** objects of type Key  
    * set 컨테이너는 중복을 허용하지 않는 정렬된 컨테이너  
* [소트인사이드](https://www.acmicpc.net/problem/1427): ([C++ 답안]())  

#### [05] [핵심 유형 문제풀이]  
* [나이순 정렬](https://www.acmicpc.net/problem/10814): ([C++ 답안]())  
* [좌표 정렬하기](https://www.acmicpc.net/problem/11650): ([C++ 답안]())  
* [수 정렬하기 3](https://www.acmicpc.net/problem/10989): ([C++ 답안]())  
