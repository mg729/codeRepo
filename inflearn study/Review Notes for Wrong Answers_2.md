## Review Notes 2
- **2021.04.10 ~ 2021.05.12(문제 풀이)**
    - 56번부터 ~ 75번까지

- **2021.05.13 ~ 2021.05.00(오답 풀이)**
    - quiz 26 : 병합정렬
    - quiz 30 : 구글인터뷰
    - quiz 40 
    - quiz 41 
    - quiz 43,44
    - quiz 45 : v.erase 를 쓰지말고 풀이할 것
    - quiz 51
    - quiz 52
    - quiz 53
    - quiz 56 : 스택 보충영상 (면접대비) --> 스택프레임/스택오버플로우 개념
    - quiz 57
    - quiz 58
    - quiz 59 
    - quiz 60 : 59번이랑 다른방식으로 풀이할 것<!--강의 다시 보기, 강의처럼 면접 대비 멘트 연습해 볼 것-->
    - quiz 61 : 문제에서 발전 - 특정수를 만드는 요소들을 출력할 것<!--예를들어 6+8-2=12 인 경우, -2 0 6 8 이렇게 출력할 것 -->
    - quiz 62 : <!--병합정렬 강의듣고 100프로 이해한적 오늘이 레알 처음... 명강의다 강의 또듣자-->
    - quiz 64, 66
    - quiz 67, 68
    - quiz 69
    - quiz 70
    - quiz 71
    - quiz 72
    - quiz 74
    - quiz 75


### quiz26
```c++
#include<bits/stdc++.h>
using namespace std;

int n, val, cnt;
int a; //ability
int arr[10002];
int ranking[10002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> val;
		arr[i] = val;		
	}
	
	ranking[0] = 1;
	for(int i = 1; i < n; i++) {
		cnt = 1;
		for(int j = 0; j < i; j++) {
			if(arr[j] >= arr[i]) {
				cnt++;
			}
		}
		ranking[i] = cnt;
	}
	
	for(int i = 0; i < n; i++) {
		cout << ranking[i] << " ";
	}
	
	return 0;
}
```

### quiz35
```c++
#include<bits/stdc++.h>
using namespace std;

int n, val, tmp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) {
		cin >> val;
		
		v[i] = val;
		int j = i;
		while(j > 0 && v[j] < 0) {
			if(v[j-1] < 0) break;
			tmp = v[j-1];
			v[j-1] = v[j];
			v[j] = tmp;
			j--;
		}
	}
	
	for (auto x : v) {
		cout << x << " ";
	}
	
	return 0;
}
```

## quiz37

```c++
#include<bits/stdc++.h>
using namespace std;

int s, n, mem, maxIdx, k;
int arr[1002];
int check[1002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	
	cin >> s >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> mem;
		arr[maxIdx] = mem;
		if(check[mem]) { //Cache Hit
			int idx = 0;
			int j = 0;
			while(1) {
				// find idx 
				if(arr[j] == mem) {
					idx = j;
					break;
				}
				j++;
			}
			for(j = idx; j < i-1; j++) {
				// swapping
				int tmp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = tmp;
			}	
		}
		else {
			maxIdx++;
		}
		
		check[mem] = 1;		
	}
	
	for(int i = 0; i < s; i++) {
		cout << arr[maxIdx-1] << " ";
		maxIdx--;
	}

	return 0;
}
```

