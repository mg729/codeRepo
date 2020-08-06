# Barking Dog Algorithm Study

> Chapther
[0x00 시간, 공간복잡도](0x00시간,공간복잡도)
[0x02 기초코드 작성요령](0x02기초코드작성요령)

## 0x00시간,공간복잡도
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