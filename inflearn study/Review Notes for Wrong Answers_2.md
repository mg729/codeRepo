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
    - [quiz 56 : 스택 보충영상 (면접대비) --> 스택프레임/스택오버플로우 개념](#quiz56)
    - [quiz 57](#quiz57)
    - [quiz 58](#quiz58)
    - [quiz 59](#quiz59)
    - [quiz 60](#quiz60) : void dfs(int level, int sum) - 부분집합의 합을 함수파라미터로 관리
    - [quiz 61](#quiz61) : 문제에서 발전 - 특정수를 만드는 요소들을 출력할 것<!--예를들어 6+8-2=12 인 경우, -2 0 6 8 이렇게 출력할 것 -->
    - [quiz 62](#quiz62) : 병합정렬 Point **1. 후위순회방식 2. tmp 배열 & point 변수(p1,p2,p3)**
    - [quiz 64](#quiz64) : 인접행렬
	- [quiz 66](#quiz66) : vector 인접리스트
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
- **PASS (REMOVE FOR LOOP DUPLICATION) : 투포인트알고리즘응용**
- **Three point Algorithm**

```c++
#include<bits/stdc++.h>
using namespace std;

int n, p2, p3, p5;
int arr[1502];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	cin >> n;
	p2 = p3 = p5 = 1;
	int minVal = 2147000000;
	int idx = 1;
	arr[1] = 1;
	while(idx <= n) {
		int tmp2 = arr[p2]*2;
		int tmp3 = arr[p3]*3;
		int tmp5 = arr[p5]*5;
		
		if(tmp2 < tmp3) minVal = tmp2;
		else minVal = tmp3;
		
		if(tmp5 < minVal) minVal = tmp5;
		
		if(tmp2 == minVal) p2++;
		if(tmp3 == minVal) p3++;
		if(tmp5 == minVal) p5++;
		
		arr[++idx] = minVal;		
	}
	cout << arr[idx-1];
	return 0;
}
```



## quiz53


```c++
#include<bits/stdc++.h>
using namespace std;

int n,k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	
	cin >> n >> k;
	
	stack<string> s;
	
	while(n > 0) {
		
		if(n % k != 0) {
			int val = n % k;
			if(val > 9) {
				if(val == 10) s.push("A"); 
				else if(val == 11) s.push("B");
				else if(val == 12) s.push("C");
				else if(val == 13) s.push("D"); 
				else if(val == 14) s.push("E");
				else s.push("F");
			}
			else  {
				s.push(to_string(val));
			}
		}
		else {
			s.push("0");
		}
		n /= k;
	}

	while(!s.empty()) {
		cout << s.top();
		s.pop();
	}
	
	return 0;
}
```

- cleanCode

```c++
#include<bits/stdc++.h>
using namespace std;

int n,k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	
	cin >> n >> k;
	
	stack<int> s;
	string str = "0123456789ABCDEF";
	while(n > 0) {
		s.push(n%k);
		n /= k;
	}

	while(!s.empty()) {
		cout << str[s.top()];
		s.pop();
	}
	
	return 0;
}
```

## quiz56

```c++
#include<bits/stdc++.h>
using namespace std;

int n;

void recursiveFunc(int x) {
	if(x == 0) {
		return;
	}
	recursiveFunc(x-1);
	cout << x  << " ";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);
	
	cin >> n;
	recursiveFunc(n);

	return 0;
}
```

## quiz57

```c++
#include<bits/stdc++.h>
using namespace std;

int n;

void recur(int x) {
	if(x == 0) {
		return;
	}
	recur(x/2);
	cout << x%2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	
	cin >> n;
	recur(n);

	return 0;
}
```
## quiz58

```c++
#include<bits/stdc++.h>
using namespace std;

void preOrder(int x) {
	if(x > 7) return;
	cout << x << " ";
	preOrder(x*2);
	preOrder(x*2 + 1);	
}

void inOrder(int x) {
	if(x > 7) return;
	inOrder(x*2);
	cout << x << " ";
	inOrder(x*2 + 1);	
	
}

void postOrder(int x) {
	if(x > 7) return;
	postOrder(x*2);
	postOrder(x*2 + 1);	
	cout << x << " ";
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	preOrder(1); // root left right
	cout << "\n";
	inOrder(1); // left root right
	cout << "\n";
	postOrder(1); // left right root
	cout << "\n";
	
	return 0;
}
```

## quiz59

```c++
#include<bits/stdc++.h>
using namespace std;

int n;

int ch[12];

void func(int level) {
	if(level > n) {
		for(int i = 1; i <= n; i++) {
			if(ch[i]) {
				cout << i << " ";
			}
		}
		cout << "\n";
		return;
	}
	else {
		ch[level] = 1;
		func(level+1);
		ch[level] = 0;
		func(level+1);		
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	
	cin >> n;
	func(1);
	
	return 0;
}
```


## quiz60

- PASS 1

```c++
#include<bits/stdc++.h>
using namespace std;

int n, val, a, b;
int arr[12];
int ch[12];
bool isSame;

void dfs(int level) {
	if(level > n) {
		a = b = 0;
		for(int i = 1; i <=n; i++) {
			if(ch[i]) a += arr[i];
			else b += arr[i];
		}
		if(a == b) {
			isSame = true;
			cout << "YES";6
			exit(0);
		}
		
		return;
	}
	ch[level] = 1;
	dfs(level+1);
	ch[level] = 0;
	dfs(level+1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);
	
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> val;
		arr[i] = val;
	}
	
	dfs(1);
	
	if(isSame) cout << "YES";
	else cout << "NO";
	
	return 0;
}
```

- PASS 2 **(cleanCode)**
>  **부분집합의 합을 두번째 파라미터로 관리**



```c++
#include<bits/stdc++.h>
using namespace std;

int n, val, a, b, total;
int arr[12];
bool isSame;

void dfs(int level, int sum) {
	if(sum > (total/2)) return;
	if(isSame) return; 
	if(level > n) {
		if(sum == total - sum) 
			isSame = true;
	}
	else {
		dfs(level+1, sum+arr[level]);
		dfs(level+1, sum);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);
	
	
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> val;
		arr[i] = val;
		total += val;
	}
	
	dfs(1, 0); // 부분집합의 합을 두번째 파라미터로 관리	 
	
	if(isSame) cout << "YES";
	else cout << "NO";
	
	return 0;
}
```

## quiz61

```c++
#include<bits/stdc++.h>
using namespace std;

int n,m,val,cnt;
int arr[12];
int ch[12]; // 1 : (+) , 2 : (-) , 3 : ()

int dfs(int level, int res) {
	if(level > n) {
		if(res == m) {
			cnt++;
			for(int i = 1; i < n ; i++) {
				if(ch[i] == 1) 
					cout << arr[i] << " + ";
				else if(ch[i] == 3)
					cout << "-" << arr[i]<< " + ";
				else continue;
			}
			if(ch[n] == 1) cout << arr[n];
			else if(ch[n] == 3) cout << "-" <<arr[n];
			
			cout << " = " << m << "\n";
		}
	}
	else {
		ch[level] = 1;
		dfs(level+1, res + arr[level]);
		ch[level] = 2;
		dfs(level+1, res);
		ch[level] = 3;
		dfs(level+1, res - arr[level]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);

	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> val;
		arr[i] = val;
	}
	
	dfs(1,0);
	cout << cnt;
	
	return 0;
}
```

## quiz62

```c++
#include<bits/stdc++.h>
using namespace std;

int n, val;
int arr[102];
int tmp[102];

void mergeSort(int lt, int rt) {
	int mid;
	int p1, p2, p3;
	
	if(lt < rt) {
		mid = (lt+rt) / 2;
		mergeSort(lt, mid);
		mergeSort(mid+1, rt);
		
		p1 = lt;
		p2 = mid+1;
		p3 = lt;
		
		while(p1 <= mid && p2 <=rt) {
			if(arr[p1] < arr[p2]) tmp[p3++] = arr[p1++];
			else tmp[p3++] = arr[p2++];
		}
		
		while(p1 <= mid) tmp[p3++] = arr[p1++];
		while(p2 <= rt) tmp[p3++] = arr[p2++];
		
		for(int i = lt ; i <= rt; i++) 
			arr[i] = tmp[i];	
	}	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> val;
		arr[i] = val;
	}
	
	mergeSort(1, n);
	for(int i = 1; i <= n; i++) {
		cout << arr[i] <<" ";
	}
	
	return 0;
}
```

## quiz64

- 인접행렬 _myCode

```c++
#include<bits/stdc++.h>
using namespace std;

int n, m, a, b, cnt; 
int ch[22];
int arr[22][22];

void dfs(int level) {
	for(int i = 1; i <= n; i++) {
		if(arr[level][i] == 1 && i == n) {
			cnt++;
		}
		if(arr[level][i] && ch[i] == 0) {
			ch[i] = 1;
			dfs(i);
			ch[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	cin >> n >> m;
	
	for(int i = 1; i <= m ; i++) {
		cin >> a >> b;
		arr[a][b] = 1;
	}
	ch[1] = 1;
	dfs(1);	
	cout << cnt;
	
	return 0;
}
```

- **cleanCode**

```c++
#include<bits/stdc++.h>
using namespace std;

int n, m, a, b, cnt; 
int ch[22];
int arr[22][22];

void dfs(int level) {
	if(level == n) {
		cnt++;
		return; // 재귀 함수에서 탈출조건 코딩해주기
	}
	for(int i = 1; i <= n; i++) {
		if(arr[level][i] && ch[i] == 0) {
			ch[i] = 1;
			dfs(i);
			ch[i] = 0; // 여기서 check를 풀어주는 이유 : 경로의 가짓수가 여러 경우의 수가 나올 수 있으므로 다른 경우의 수를 위해서..
			// 즉 예를들어 level 5를 방문하고 해당 경우의수를 찾아주고 ch[5] = 0으로 다시 초기화해줘야함. 다른 경우의 수에서 ch배열을 체크하고 새로운 경로를 탐색해야하니까.
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	cin >> n >> m;
	
	for(int i = 1; i <= m ; i++) {
		cin >> a >> b;
		arr[a][b] = 1;
	}
	ch[1] = 1;
	dfs(1);	
	cout << cnt;
	
	return 0;
}
```

## quiz66

- 인접리스트

```c++
#include<bits/stdc++.h>
using namespace std;

int n, m, a, b, cnt; 
int ch[22];
vector<int> v[22];

void dfs(int level) {
	for(int i = 0; i < v[level].size(); i++) {
		int x = v[level][i];
		if(x == n) {
			cnt++;
		}
		if(ch[x] == 0) {
			ch[x] = 1;
			dfs(x);
			ch[x] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
//	freopen("input.txt", "rt", stdin);
	cin >> n >> m;
	
	for(int i = 1; i <= m ; i++) {
		cin >> a >> b;
		v[a].push_back(b);
	}
	
	ch[1] = 1;
	dfs(1);

	cout << cnt;
	
	return 0;
}
```

- **cleanCode**

```c++
#include<bits/stdc++.h>
using namespace std;

int n, m, a, b, cnt; 
int ch[22];
vector<int> v[22];

void dfs(int level) {
	if(level == n) {
		cnt++;
		return;	
	}	
	for(int i = 0; i < v[level].size(); i++) {
		int x = v[level][i];
		if(ch[x] == 0) {
			ch[x] = 1;
			dfs(x);
			ch[x] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("input.txt", "rt", stdin);
	cin >> n >> m;
	
	for(int i = 1; i <= m ; i++) {
		cin >> a >> b;
		v[a].push_back(b);
	}
	
	ch[1] = 1;
	dfs(1);

	cout << cnt;
	
	return 0;
}
```

