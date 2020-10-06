# BFS
> **다차원 배열에서의 탐색**  
>   
> - 첫번째 vis[][] = 1 초기화 잊지말 것  
> - 입력값이 붙어져있는지 떨어져있는지 체크    


> **each move one square per minute, vertically or horizontally (not diagonally).**  
> 매 분마다 한칸씩 수평또는 수직으로(비스듬하게 이동하지 않는다)  이동  `diagonal - 사선의, 대각선의`


## 1926 그림  

[BOJ 1926](1926.cpp)  


## 2178 미로탐색
[BOJ 2178](2178.cpp)
- **다차원 배열에서의 거리측정**  
    - _example 1_  

    |||||||
    | :--: | :--: | :--: | :--: | :--: | :--: |  
    | 0 | - | 8 | 9 | 10 | 11| 
    |1 |-|7|-|11|-|
    |2|-|6|-|12|13|
    |3|4|5|-|13|14|  

    - _example 2_  

    |||||||
    | :--: | :--: | :--: | :--: | :--: | :--: |  
    |0|-|6|7|8|-|
    |1|-|5|6|7|-|
    |2|3|4|5|6|7|
    |3|4|5|6|-|8|

- 이전 데이터
    - cur.x
    - cur.y
    ```cpp
    dist[nx][ny] = dist[cur.x][cur.y] + 1;
    ```  
- *std::fill*  
    - `std::fill(v.begin(), v.end(), -1);`

- 띄어쓰기가 없는 입력 데이터
    ```cpp
    string board[102];
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> board[i];
    for(int i = 0; i < n; i++)
        fill(dist[i], dist[i]+m, -1);
        
    if(board[nx][ny] != '1' ) continue;// *** board  is string type but can be accessed by 2 dimension char type 
    ```

## 7576 토마토
[BOJ 7576](7576.cpp)  
> **BFS 하면서 큐에 쌓이는 순서는 반드시 거리순으로 되어있다**  


- 익은 토마토의 개수가 1개라면 익은 토마토의 해당위치를 시작점으로 BFS
- 근데 문제에서는 익은 토마토의 개수가 1개 이상인 경우도 있다  
- **시작점이 여러개인 BFS**  
    - *모든 시작점을 큐에 넣고 BFS*  


## 7569 토마토
[BOJ 7569](7569.cpp)

- Hint > 3차원이라고 해서 크게 다를건 없고, 단지 배열이 3차원이고 6개의 인접한 칸을 처리하기 위해 dx, dy, dz가 필요하게 됩니다. 구현할 때 STL tuple이라고 하는 것을 이용하면 좋습니다.  

- *STL tuple*
