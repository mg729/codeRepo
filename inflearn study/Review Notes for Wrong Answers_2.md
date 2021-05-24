## Review Notes 2
- **2021.04.10 ~ 2021.05.12(문제 풀이)**
    - 56번부터 ~ 75번까지

- **2021.05.13 ~ 2021.05.00(오답 풀이)**
    - quiz 26 : 병합정렬
    - quiz 30 : 구글인터뷰
	- [quiz 26](#quiz26)
	- [quiz 35](#quiz35) 
	- [quiz 37](#quiz37)
    - [quiz 40](#quiz40) 
    - [quiz 41](#quiz41) 
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

### quiz37

```c++
#include<bits/stdc++.h>
using namespace std;

int s, n, mem, maxIdx, k;
int arr[1002];
int check[1002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);
	
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
			for(j = idx; j < maxIdx; j++) {
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
### quiz40

- FAIL


```c++
#include<bits/stdc++.h>
using namespace std;

int n, m, val;
int arr[30002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> val;
		arr[val] = 1;
	}
	cin >> m;
	vector<int> v;
	for(int i = 0; i < m; i++) {
		cin >> val;
		if(arr[val]) {
			v.push_back(val);
		}
	}
	
	sort(v.begin(), v.end());
	
	for(auto x : v) {
		cout << x << " ";
	}

	return 0;
}
```

- **PASS**

```c++
#include<bits/stdc++.h>
using namespace std;

int n, m, val;
int arr1[30002];
int arr2[30002];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> val;
		arr1[i] = val;
	}
	sort(arr1, arr1 + n);

	cin >> m;
	for(int i = 0; i < m; i++) {
		cin >> val;
		arr2[i] = val;
	}
	sort(arr2, arr2 + m);

	int p1 = 0;
	int p2 = 0;
	vector<int> v3;
	while(p1<n && p2<m) {
		if(arr1[p1] > arr2[p2]) {
			p2++;
		}
		else if(arr1[p1] < arr2[p2]) {
			p1++;
		}
		else { // arr1[p1] == arr2[p2]
			v3.push_back(arr1[p1]);
			p1++;
			p2++;
		}
	}
	
	for(auto x : v3) {
		cout << x << " ";
	}
	
	return 0;
}
```


### quiz41

```c++
#include<bits/stdc++.h>
using namespace std;

int a, cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);
	
	cin >> a;
	int tmp = a; // store a value to print out
	
	a--; // 맨 처음에 1을 빼주고 그 다음에 b를 빼주고..하는거라서..우선 a는 1빼주고 시작	
	int b = 1;
	while(a > 0) {
		b++; // b 가 15 - 3 할때 3을 의미 즉, n만큼 뺐다 라는 의미
		a = a - b;
		if(a%b == 0) {
			for(int i = 1; i < b; i++) {
				cout << i+(a/b) << " + ";
			}
			cout << b + (a/b) << " = " << tmp <<"\n";
			cnt++;
		}
	}

	cout << cnt;	
	return 0;
}
```