# Review Notes for Wrong Answers

<details><summary>다시 풀어볼 문제</summary>
<p>
- 2020.12.11~ <br>
    - quiz 26 (병합정렬)<br>    
    - quiz 30(large)<br>
    - quiz 35 : 하나의 벡터만 선언하고  데이터 정렬<br>
    - quiz 36 삽입정렬 : 기업 손 코딩 문제 (강의 참고)<br>
    - quiz 37<br>
    - quiz 40 : MS_interview<br>
    - quiz 41 : 연속된 숫자 합 구하기 - 수리 센스<br>
    - quiz 43,44 : 또 !! 접근자체를 잘못했었음 - 결정알고리즘 - 생각의 전환 pleaz...<br>
    - quiz 45 : 원형데이터를 관리하는 최적의 컨테이너 // 아니고 시뮬레이션 문제<br>
    - quiz 51 : Dynamic Programming<br>
    - quiz 52 : 투포인트 알고리즘<br>
    - quiz 53 : 16진수 변환 처리<br>
    - quiz 55 : 스택 <br>
- 2021.03~ <br>
</p>
</details>

## 30
- 30_large_구글인터뷰

## 35
- 이웃된 두 수를 정렬하는 Bubble sort
```c++
if(v[j] > 0 && v[j+1] < 0) { // j번째는 양수고 j+1 이 음수인 경우 즉 뒤에 음수의 데이터가 있는경우 
    // 이웃된 두 수를 swap 정렬하는 bubble 정렬
}
```

## 37
- 데이터 하나를 삭제하고 데이터를 뒤로 밀어 넣기
- **vector.erase(it);** 하는 것보다 array로 하는게 더 시간이 덜 걸릴듯

```c++
cache[i] = cache[i-1];
```

## 40
- 마지막에 while 범위 잡는데 실수했음!! 주의할 것

```c++
while(idxA < n && idxB < m)**
```


## 41
- 이건 그냥 풀이법 외우자
- **연속된 자연수의 합 구하는 방법**

## 43, 44
> **이건 그냥 이분 검색 응용 문제다..**  
> 데이터가 많이 나오고 데이터를 동일한 분량으로 나눠야한다..는 조건들이 나온다면 **이분 검색**알고리즘을 생각하자..!!!


- 결정알고리즘 : 데이터를 좁혀나가면서 정답을 찾아나갈 때 

