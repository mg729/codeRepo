# Review Notes for Wrong Answers

<details><summary>다시 풀어볼 문제</summary>
<p>
- 2020.12.11~2021.04.10 <br>
    - quiz 26 (병합정렬)<br>    
    - quiz 30(large)<br>
    - quiz 35 : 하나의 벡터만 선언하고  데이터 정렬<br>
    - quiz 36 삽입정렬 : 기업 손 코딩 문제 (강의 참고)<br>
    - quiz 37<br>
    - quiz 40 : MS_interview<br>
    - quiz 41 : 연속된 숫자 합 구하기 - 수리 센스<br>
    - quiz 43,44 : 또 !! 접근자체를 잘못했었음 - 결정알고리즘 - 생각의 전환 pleaz...<br>
    - quiz 45 : v.erase 를 쓰지 말고 풀이할 것<br>
    - quiz 51 : Dynamic Programming<br>
    - quiz 52 : 투포인트 알고리즘 - 외국기업에서 많이 면접에서 출제되는 문제<br>
    - quiz 53 : Time limit 에러 없이 풀이하는 법<br>
    - quiz 55 : 스택 <br>
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
while(idxA < n && idxB < m)
```


## 41
- 이건 그냥 풀이법 외우자
- **연속된 자연수의 합 구하는 방법**

## 43, 44
> **이건 그냥 이분 검색 응용 문제다..**  
> 결정알고리즘을 요구하는 문제가 출제되면 이분 검색 풀이 법으로 접근  
> 정해진 범주의 데이터가 많이 나오고 데이터를 나눠서 최적의 답을 찾아야 한다..는 조건들이 나온다면 **이분 검색**알고리즘을 생각하자..!!!  
> 이분검색 알고리즘으로 문제를 해결할때는 **mid** 값이 return 값이 될 텐데 이 mid값을 어떻게 설정할 것인지 코드짜기전에 확실히 하고 문제 풀 것  
> 이분 검색 응용문제 나오면 데이터가 모두 1 인 경우의 수를 예시로 알고리즘 돌려볼 것

- quiz 43

```
input
5 4 
1 1 1 1 1
```
- 아래 코드에서 sum = v[i] 하면서 i 부터 새로운 sum을 계산하는 부분 집중
- 평소에 저런 코드있으면 sum = 0; 으로 초기화하고 i--; 해서 다시 sum += v[i]; 를 거치게 하는데
- 아예 초기화를 sum = 0; 이 아닌 sum = v[i]; 로 해주면 덜 번거로움...!

```c++
int count(int s) {
	int cnt = 1, sum = 0;
	for(int i = 0; i < n; i++) {
		if(sum + v[i] > s) {
			cnt++; // dvd하나를 추가해 
			sum = v[i]; //이곡부터 새로운 sum을 계산하자 (새롭게 초기화) 
		}
		else sum += v[i]; // 녹화하는 dvd에 누적 
	}
	return cnt; 
}
```

- 결정알고리즘 : 데이터를 좁혀나가면서 정답을 찾아나갈 때 
- `lt < rt` 하면 에러!
- `lt <= rt` equal 기호 잊지 말 것!

```c++
while(lt <= rt) { // lt < rt 하면 예외케이스 있음
```

## 45
> **v.erase() 를 쓰지말고 알고리즘 풀이하는 연습을 해야**   
> 해당 문제는 배열을 0으로 초기화하고 k값이 되는 순간 0 -> 1로 변경시키는 코드로 구현  

## 52
- 소인수분해
- three point algorithm
    - need to make three pointer

## 53
- K진수 로 변환하면 첫번째 value가 무조건 1인 것은 아님
- 예 ) 512 16 (**200**)
