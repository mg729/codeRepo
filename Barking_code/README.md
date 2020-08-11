# Barking Dog Algorithm Study

> Chapther
[0x01 시간, 공간복잡도](0x01시간,공간복잡도)
[0x02 기초코드 작성요령](0x02기초코드작성요령)
[0x03 배열](0x03배열)


## 0x01시간,공간복잡도
- **시간 복잡도**  
    - 이진 탐색 시간복잡도
        - log n
        - 이진 탐색은 남은 데이터의 개수가 1이 될 때까지 반 씩 쪼개는 작업을 계속해야합니다.
        - n : 1
        - n/2 : 2 
        - n/4 : 3
        - 1 : x
        - 연산의 횟수를 x라고 가정했을 때 n  이 1일 경우 x를 구하려면 1에서 2를 n번 곱해야 n 이 되므로 
        - n = 1 * 2^x
        - log n = x

    - [quize4](ch01_quiz4.cpp) 
- **공간 복잡도** 
    - 입력의 크기와 문제를 해결하는데 필요한 공간의 상관관계
    - 512 MB = 1.2 억개의 int  
    - 

- **정수 자료형**  
    - char 자료형은 1byte = 8 bit  
    - short (2 byte)   
    - int (4 byte)  
    - long long (8 byte)  
    - Integer Overflow

- 실수 자료형
    - float (4byte)
    - *double* (8byte)
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
