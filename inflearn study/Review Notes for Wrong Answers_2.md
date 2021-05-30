## Review Notes 2
- **2021.04.10 ~ 2021.05.12(문제 풀이)**
    - 56번부터 ~ 75번까지

- **2021.05.13 ~ 2021.05.00(오답 풀이)**
    - quiz 26 : 병합정렬
    - quiz 30 : 구글인터뷰
	- [quiz 26](#quiz26)
	- [quiz 35](#quiz35) 
	- [quiz 37](#quiz37)
    - [quiz 40 : 교집합을 구하는 투포인트 알고리즘 풀이](#quiz40) 
    - [quiz 41 : 연속된 합을 구하는 단순 수리 풀이법](#quiz41) 
    - [quiz 43](#quiz43)
	- [quiz 44](#quiz44)
    - [quiz 45](#quiz45)
    - [quiz 51](#quiz51)
    - [quiz 52](#quiz52)
    - [quiz 53](#quiz53)
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

### quiz43


```c++
#include<bits/stdc++.h>
using namespace std;

int n, m, val, lt, rt, mid, res;
vector<int> v;

int numberOfDvd(int time) {
	int cnt = 1, sum = 0;
	for(int i = 0; i < n; i++) {
		if(sum + v[i] > time) {
			cnt++;
			sum = v[i];
		}
		else sum += v[i];
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);
	
	cin >> n >> m;
	lt = 1;
	int maxVal = -2147000000;
	for(int i = 0; i < n; i++) {
		cin >> val;
		v.push_back(val);
		rt += val;
		if(val > maxVal) maxVal = val;
	}
	
	while(lt <= rt) {
		mid = (lt+rt)/2;
		if(mid >= maxVal && numberOfDvd(mid) <= m) {
			res = mid;
			rt = mid - 1;
		}
		else {
			lt = mid + 1;
		}
	}
	cout << res;
	
	return 0;
}
```

### quiz44

```c++
#include<bits/stdc++.h>
using namespace std;

int n, c, val;
vector<int> v;

int count (int x) {
	int cnt = 1;
	int a = v[0];
	for(int i = 1; i < n; i++) {
		if(v[i] - a >= x) {
			cnt++;
			a = v[i];
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	
	cin >> n >> c;
	for(int i = 0 ; i < n ;  i++) {
		cin >> val;
		v.push_back(val);                    
	}
	sort(v.begin(), v.end());
	
	int maxDist = -2147000000;
	int lt = v[0];
	int rt = v[n-1];
	int mid = 0;
	while(lt <= rt) {
		mid = (lt + rt) / 2;
		if(count(mid) >= c) {
			if(maxDist < mid) maxDist = mid;
			lt = mid + 1;			
		}
		else {
			rt = mid - 1;
		}
	}
	
	cout << maxDist;

	return 0;
}
```

### quiz45


```c++
#include<bits/stdc++.h>
using namespace std;

int n, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	
	cin >> n >> k;
	
	queue<int> q;
	for(int i = 1; i <= n; i++) {
		q.push(i);
	}
	
	int idx = 1;
	while(!q.empty()) {
		
		if(idx == k) {
			idx = 1;			
		}
		else {
			q.push(q.front());
			idx++;
		}
		if(q.size() == 1) cout << q.front();
		q.pop();
	}

	return 0;
}
```

## quiz51

```c++
#include<bits/stdc++.h>
using namespace std;

int h, w, val, x, y;
int res[702][702];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	
	cin >> h >> w;
	
	for(int i = 1; i <= h; i++) {
		for(int j = 1; j <= w ; j++) {
			cin >> val;			
			res[i][j] = res[i-1][j] + res[i][j-1] - res[i-1][j-1] + val;
		}
	}

	cin >> x >> y;
	int maxTree = -2147000000;
	for(int i = x ; i <= h; i++) {
		for(int j = y; j <= w; j++) {
			int tree = res[i][j] - res[i-x][j] - res[i][j-y] + res[i-x][j-y];
			if(maxTree < tree) maxTree = tree;
		}
	}
	
	cout << maxTree;
	
	
	return 0;
}
```


## quiz52

- FAIL (TIME_LIMIT)

```c++
#include<bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);
	
	cin >> n;
	int cnt = 2;
	vector<int> v;
	v.push_back(1);
	while(v.size() < n) {
		int tmp = cnt;
		if(tmp % 2 == 0 ||
		   tmp % 3 == 0 ||
		   tmp % 5 == 0) {
		   while(1) {
			   	if(tmp % 2 == 0) tmp /= 2;	
				if(tmp % 3 == 0) tmp /= 3;
				if(tmp % 5 == 0) tmp /= 5;
				
				if(tmp % 2 == 0 ||
			   	   tmp % 3 == 0 ||
			   	   tmp % 5 == 0) {
			   	   	continue;
				}
				else break;		   	
		   }
		}
		
		if(tmp == 1) v.push_back(cnt);
		cnt++;
	}
	
	cout << v.back();
	
		
	return 0;
}
```
- PASS (REMOVE FOR LOOP DUPLICATION)

```c++

```



## quiz53

```c++

```

