# Barking Dog Algorithm Study

> Chapther  
[0x01 시간, 공간복잡도](#0x01시간,공간복잡도)   
[0x02 기초코드 작성요령](#0x02기초코드작성요령)  
[0x03 배열](#0x03배열)  
[0x04 연결리스트](#0x04연결리스트)  
[0x05 스택](#0x05스택)  
[0x06 큐](#0x06큐)  
[0x07 덱](#0x07덱)  
[0x08 스택의활용](#0x08스택의활용(수식의괄호쌍))  

<details><summary>PS - should Memorize</summary>
<p>

### stack
- [stack pair<index, height>- 레이저를 수신하는 하나의 탑](0x05/2493.cpp)
- **size() 활용** 
    - [stack size() - 옥상에서 볼 수 있는 모든 탑](0x05/6918.cpp)  
    - [레이저를 쏠 때 몇개의 막대가 잘려나가는지는 그 순간의 stack의 size와 연관](0x08/10799.cpp)  
    
### deque
- [reverse data , string utilization](0x07/5430.cpp)
    - R 명령이 들어온다고 진짜로 배열의 모든 원소를 뒤집으면 절대로 안 됩니다. N개의 원소의 순서를 정말로 바꾸면 당연히 그 원소 수만큼 시간이 걸리고, 그걸 최대 10만 번 수행해야 하니 테스트 케이스 1개만으로도 100억번의 연산이 수행됩니다.    
        - **R 명령의 핵심은 실제로 원소를 뒤집지 않고도 뒤집힌 것과 같은 효과를 내도록 구현하는 것입니다.** --> deque 컨테이너와 isReverse flag 활용 
    - 테스트 케이스마다 초기화가 잘 됐는지 확인하세요. 
        - **every end of the test case, container sholud be cleared**
</p>
</details>

## 0x01시간,공간복잡도
- **시간 복잡도**  
    - 이진 탐색 시간복잡도
        - log n
        - 이진 탐색은 남은 데이터의 개수가 1이 될 때까지 반 씩 쪼개는 작업을 계속해야합니다.
        - n : 1
        - n/2 : 2 
        - n/4 : 6
        - 1 : x
        - 연산의 횟수를 x라고 가정했을 때 n  이 1일 경우 x를 구하려면 1에서 2를 n번 곱해야 n 이 되므로 
        - n = 1 * 2^x
        - log n = x

    - [quize4](ch01_quiz4.cpp) 
- **공간 복잡도** 
    - 입력의 크기와 문제를 해결하는데 필요한 공간의 상관관계
    - 512 MB = 1.2 억개의 int  

- **정수 자료형**  
    - char 자료형은 1byte = 8 bit  
    - short (2 byte) : 2^15 -1 (=32767)   
    - **int** (4 byte) : 2^31 -1 **(= 2.1 * 10^9)**  
    - **long long** (8 byte) : 2^63 -1 **(= 9.2*10^18)**  
    - Integer Overflow

- 실수 자료형
    - float (4byte) - 유효숫자6자리
    - **double** (8byte) - 유효숫자15자리
    - (1) 실수의 저장/연산 과정에서 반드시 오차가 발생할 수 밖에 없다.
    - (2) double 에 long long long 범위의 정수를 함부로 담으면 안된다.
    - (3) 실수를 비교할 때는 등호를 사용하면 안된다.

## 0x02기초코드작성요령
- **원본의 값**
- 수의 인자로 int / int 배열 / 구조체를 실어보내서 값을 바꿨을 때 원본의 값이 바뀌는지  
    - int (x)
    - int 배열 (o)
    - 구조체 (x)
    ```cpp
    struct pt {
        int x, y;
    };
    void func(pt a) {
        a.x = 10;
    }
    int main() {
        pt tmp = {0,0};
        func(tmp);
        cout << tmp.x; // 0
    }
    ```
    - 구조체의 경우에는 int랑 비슷하게 그냥 값이 다 복사되기 때문에 func 함수에서 값을 바꿔도 원본에는 영향을 주지 않습니다.

- **참조자**
```cpp
void swap (int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
} //c

void swap2 (int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
} // c++
```
-  swap 함수처럼 포인터를 보내서 두 변수의 값을 바꿀 수가 있습니다. 그런데 C++에서는 해결법이 한 개 더 있는데, 바로 참조자(*reference*)입니다. swap2 함수를 보면 함수 인자인 a와 b의 type이 int가 아니고, int 뒤에 &가 붙어있는 것을 볼 수 있습니다. 그러니까 a와 b는 int reference인 것입니다.

- **STL - vector**
```cpp
vector <int> v(100);
```
> type이 int이고 0으로 초기화된 100칸짜리 가변배열 v가 선언

- **STL과 함수인자**
```cpp
void func1(vector<int> v) {
    v[10] = 7;
}
int main() {
    vector<int> v (100);
    func1(v);
    cout << v[10];  // not 7, print 0
}
```
>  STL도 구조체랑 비슷하게 함수 인자로 실어 보내면 복사본을 만들어서 보내기 때문에 func1 함수에서 바꾼건 원본에 영향을 주지 않습니다.  

```cpp
void func1(vector<int>& v) {
    v[10] = 7;
}
int main() {
    vector<int> v (100);
    func1(v);
    cout << v[10];  // print 7
}
```

- **표준 입출력**
    - 공백을 포함한 문자열 입력
        - *string s;*
        - *getline(cin, s);*  

    - ios::sync_with_stdio(0);
        - sync : C++ stream과 C stream을 동기화
        - `ios::sync_with_stdio(0);` : 동기화를 끊어버려서 C++ stream만 사용하거나 C stream 만 사용  
        - 동기화를 끊었으면 절대 cout과 printf를 섞어쓰면 안됩니다
    - cin.tie(0)
        - This unties `cin` from `cout`. Tied streams ensure that one stream is flushed automatically before each I/O operation on the other stream.
        - 그런데 온라인 저지 사이트에서는 채점을 할 때 그냥 출력 글자만 확인을 합니다. 그렇기 때문에 콘솔 창에서 입력 글자와 출력 글자 사이에 순서가 설령 꼬인다고 해도 채점에 아무런 영향을 주지 않고 두 경우 모두 다 정답 처리가 됩니다.
        - 그러면 굳이 cin 명령을 수행하기 전에 cout 버퍼를 비울 필요가 없겠죠. 그래서 cin 명령을 수행하기 전에 cout 버퍼를 비우지 않도록 하는 코드가 cin.tie(nullptr)인것
    - never use **endl**

## 0x03배열

- **배열의 특징**
    - O(1)에 k번째 원소를 확인/변경 가능
    - 추가적으로 소모되는 메모리의 양overhead이 거의 없음
    - Cache hit rate 가 높음
    - 메모리 상에 연속한 구간을 잡아야해서 할당에 제약이 걸림

- [insert, erase code](ch03_quiz1.cpp)
- [BOJ 10808번 O(n) 풀이](10808.cpp)

- 배열 내의 합이 100인 서로 다른 위치의 두 원소가 존재하는지 체크하는 코드
```cpp
#include <bits/stdc++.h>
using namespace std;
int arr[101];
int data[101];
int main() {
	int n;
	cin >> n;
	 
	for(int idx = 0; idx < n; idx++) {
		cin >> arr[idx];
	}
	
	for(int idx = 0; idx < n; idx++) {
		
		if(data[100 - arr[idx]])
		{
			cout << "1 "<<endl;
			return 0;
		}
		else
			data[arr[idx]] = 1;
		
	}
	cout << "0" <<endl;
	
}
```
    - O(n)의 풀이를 생각해내는게 관건
    - for 루프하나만으로 문제풀이해야
    - 수를 차례로 하나씩 읽으면서 **이전에 등장한 수** 중에서 지금 보고 있는 수와 더해 100이 되는 수가 있는지를 체크  


- 배열요소 채우기
    - `fill` : fill(arr, arr+arraySize, 0);
    - arr이름의 배열을 arrSize만큼 모두 0으로 초기화
    - **fill(void fill (ForwardIterator first, ForwardIterator last, const T& val);)**  
        - first : start point of iterator
        - last : end point of iterator
        - val : value to fill

## 0x04연결리스트
- **연결리스트**
    - 원소들을 저장할 때 그 다음 원소가 있는 위치를 포함시키는 방식으로 저장하는 자료구조  
- 연결리스트 종류
    - 단일연결리스트
    - 이중연결리스트 (__std::list__)
    - 원형연결리스트
- 연결리스트 활용 예시
    - 메모장, editor (커서 관리시 용이 - *텍스트의 삽입과 삭제 관리*)

- 배열과 연결리스트의 비교   

    |  | 배열 | 연결리스트 |  
    | :--- | :---: | ---: |  
    | k번째 원소에 접근 | O(1) | O(k) |  
    | 임의 위치에 원소 추가/제거 | O(n) | O(1) |  
    | 메모리상의 배치 | 연속 | 불연속 |  
    | 추가적으로 필요한 공간 (Overhead) | - | O(n) |    


> **연결리스트**
> *임의의 위치*에 있는 원소를 확인하거나 변경하는건 O(N)  
> *해당 위치*의 주소를 같이 넘겨줄 때 임의의 위치에 원소를 추가하거나 임의 위치의 원소를 제거하는건 O(1)  


- 연결리스트 구현  
```cpp
const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

fill(pre, pre+MX, -1);
fill(nxt, nxt+MX, -1);
```

- [insert_erase 함수 구현](ch04_quiz1.cpp)

- **STL List**
```cpp
list<int> L = {1,2};
list<int>::iterator t = L.begin();
cout << *t << '\n'; // t가 가리키는 값 = 1 을 출력

L.push_front(10); //10 1 2
L.push_back(5); //10 1 2 5

L.insert(t, 6); // 10 6 1 2 5
t++; // t를 한 칸 앞으로 전진, 현재 t가 가리키는 값은 2
t = L.erase(t); // t가 가리키는 값을 제거, 그 다음 원소인 5를 반환

cout << *t << '\n'; // 5

for(auto i : L)
    cout << i << ' '; //10 6 1 5

for(list<int>::iterator it = L.begin(); it != L.end(); it++)
    cout << *it << ' '; //10 6 1 5
```
- push_front()  
- push_back()  
- insert()  
- erase()  

- [BOJ 1406](1406.cpp)  


>  연결 리스트가 쓰이는 문제는 크게 응용해서 낼만한게 없고  원소들을 돌아다니면서 이동하다가 삭제나 삽입이 필요한 문제들입니다. 그런데 만약 N이 5000 정도로 작다면 그냥 O(N^2)으로 짜도 통과되니 익숙한 vector로 구현을 하면 됩니다. 하지만 N이 굉장히 큰 경우는 연결 리스트를 이용해 구현을 해야 합니다.


## 0x05스택

- **스택**  
    - 스택은 먼저 들어간 원소가 제일 나중에 나오게 되는 자료구조  
    - FILO
    - *참고로 큐나 덱도 스택처럼 특정 위치에서만 원소를 넣거나 뺄 수 있는 제한이 걸려있습니다. 그래서 스택, 큐, 덱을 묶어서 Restricted Structure라고 부르기도 합니다.*

- **스택의 성질** 
    - 원소의 추가가 O(1)
    - 원소의 제거가 O(1)
    - 제일 상단의 원소 확인이 O(1)
    - 제일 상단이 아닌 나머지 원소들의 확인/변경이 원칙적으로는 불가능  
        - 스택을 활용하는 예시들을 보면 애초에 제일 상단이 아닌 나머지 원소들의 확인/변경이 필요하지 않습니다. 하지만 배열을 이용해 스택을 구현하면 기본적인 스택의 기능 이외에도 제일 상단이 아닌 나머지 원소들의 확인/변경을 가능하도록 만들 수는 있습니다.

- [push_pop 함수 구현](ch05_quiz1.cpp)

- **STL stack**
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.size(); //3

    if(s.empty())
        cout << "stack is empty" ;
    else {
        s.pop(); //10 20
        s.pop(); // 10
        cout << s.top();//10
    }
    s.pop();
    cout << s.top(); // runtime error
}
```

## 0x06큐
- **큐**
    - **FIFO(First In First Out)**
    - 원소의 추가 O(1)
    - 원소의 제거 O(1)
    - 제일 앞/뒤의 원소 확인 O(1)
    - 제일 앞/뒤가 아닌 나머지 원소들의 확인/변경이 원칙적으로 불가 (STL에서도 불가능)  

    ```cpp
    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        queue<int> q;
        q.push(10);
        q.push(20);
        q.push(30);

        cout << q.size(); //3

        if(q.empty())
            cout <<"Queue is empty";
        
        q.pop(); // 20 30
        q.front(); //20
        q.back(); // 30

    }
    ```

   - 보통 큐는 BFS랑 Flood Fill를 할 때 쓰게 되는데 둘 다 코딩테스트 단골 문제여서 문제를 풀 때 STL queue를 쓸 일이 아주 많을 것입니다. 

## 0x07덱
- **deque**(Double Ended Queue)
    - 양쪽 끝에서 삽입과 삭제가 전부 가능한 자료구조
    - 원소의 추가가 O(1)
    - 원소의 제거가 O(1)
    - 제일 상단의 원소 확인이 O(1)
    - 제일 상단이 아닌 나머지 원소들의 확인/변경이 원칙적으로는 불가능
        - **STL deque에서는 인덱스로 원소에 접근 가능** 
        - STL stack, queue에서는 인덱스로 원소 접근 불가능

- **STL dequeue**
```cpp
#include <bits/stdc++.h>
using namespace std;

deque<int> dq;

int main() {
    dq.push_front(10); //10
    dq.push_back(50); //10 50
    dq.push_front(24); //24 10 50

    for(auto x : dq) {
        cout << x;
    }

    cout << dq.size(); //3
    dq[2] = 17; //24 10 17 50
    dq.insert(dq.begin() + 1, 33); //24 33 10 17 50
    dq.erase(dq.begin()+3); //24 33 10 50

    dq.clear(); // dq.size == 0; 모든 원소 제거

}
```
- STL vector에서 제공되는 기능을 STL deque에서도 다 제공해주고 심지어 deque은 front에서도 O(1)에 추가와 제거가 가능하니 deque이 vector보다 상위호환이 아닌가 하는 생각이 들 수 있겠지만, __vector와 달리 deque은 모든 원소들이 메모리 상에 연속하게 배치되어 있지 않습니다.__ 


## 0x08스택의활용(수식의괄호쌍)
- 수식의 괄호 쌍이란, 주어진 괄호 문자열이 올바른지 판단하는 문제
    - 문자열을 앞에서부터 읽어나갈 때, 닫는 괄호는 남아있는 괄호 중에서 가장 최근에 들어온 여는 괄호와 짝을 지어 없애버리는 명령이라고 생각해도 된다
    - FILO **STACK**

- 문제 해결 방법
    1. 여는 괄호가 나오면 스택에 추가
    2. 닫는 괄호가 나오는 경우 
        - 2-1) 스택이 비어있으면 올바르지 않은 괄호쌍
        - 2-2) 스택의 top이 짝이 맞지 않는 괄호일 경우 올바르지 않은 괄호쌍
        - 2-3) 스택의 top이 짝이 맞는 괄호일 경우 pop
    3. 모든 과정을 끝낸 후 스택에 괄호가 남아있으면 올바르지 않은 괄호쌍, 남아 있지 않으면 올바른 괄호쌍

