# 📙 Today I Learned  
## 규칙
* 기억에 남는 내용 기록
* 1일 2개의 알고리즘 문제 해결
* markdown으로 작성

---

## 5월  
* 18日  
이항 계수 (페르마 소정리 이용)
[SWEA](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXGKdbqczEDFAUo&categoryId=AWXGKdbqczEDFAUo&categoryType=CODE)
[BOJ](https://www.acmicpc.net/problem/11401)  

이항 계수란 n개의 원소에서 r개의 원소를 뽑아내는 경우의 수  
즉, 조합. 수식으로는 n!/(r!(n-r)!)  
다른 문제에서는 nCr = (n-1)Cr + (n-1)C(r-1) 이걸로 해결 가능하였으나, 이번 문제는 시간초과로 실패 검색 결과 페르마의 소정리 이용해야함.  
페르마의 소정리란 p가 소수, a가 정수 일때,  ![페르마 소정리](https://wikimedia.org/api/rest_v1/media/math/render/svg/7ff656f721894b9a50a2b1d18538463a6a4ec15f)  
**(대수학에서의 합동(≡)이란 mod p 연산시에 값이 동일한 경우)**  
양쪽에 a로 나눠주게 되면 ![페르마 소정리](https://wikimedia.org/api/rest_v1/media/math/render/svg/2149302899fcbf99c1b46c536549f7ed7b0a6b2b)  
한번 더 a로 나눠주게 되면 a의 역수가 a^(p-2)란 걸 증명할 수 있다.  
문제의 식인 nCr = n!/(r!(n-r)!) % p  
-> A = n!, B = (r!(n-r)!)  
-> (A*B^(-1)) % p  
-> ((A % p)*(B^(-1) % p)) % p  
-> B^(-1)은 B의 역수  
-> (A*B^(p-2)) % p  
따라서 factorial을 구하고 factorial의 역을 구해서 원하는 값을 집어넣어 답을 구한다.  
**거듭 제곱시에 분할 정복을 사용하면**
```
long long power(ll x, ll y) {  
	long long result = 1;  
	while(y) {  
		if (y%2) {  
			result *= x;
			result %= P;
		}
		x *= x;
		x %= P;
		y /= 2;
	}
	return result;
}  
```

---

* 19日  
PL시간에서 배운 가변 인자 [참고](https://dojang.io/mod/page/view.php?id=577)  

가변 인자란 함수의 매개변수가 정해지지 않은 경우다.  
대표적으로 C언어의 **printf**를 알아보았다.  
```
int printf(const char* format, ...)
```
printf의 원형은 이렇게 생겨서 format 이후의 인자는 ...으로 취급한다.  
printf의 원형 같이 가변인자 사용하는 경우에 반환값자료형 함수이름(**자료형 고정매개변수**, ...) {}  
```
#include <stdio.h>
#include <stdarg.h>    // va_list, va_start, va_arg, va_end가 정의된 헤더 파일

void printNumbers(int args, ...)    // 가변 인자의 개수를 받음, ...로 가변 인자 설정
{
    va_list ap;    // 가변 인자 목록 포인터

    va_start(ap, args);    // 가변 인자 목록 포인터 설정
    for (int i = 0; i < args; i++)    // 가변 인자 개수만큼 반복
    {
        int num = va_arg(ap, int);    // int 크기만큼 가변 인자 목록 포인터에서 값을 가져옴
                                      // ap를 int 크기만큼 순방향으로 이동
        printf("%d ", num);           // 가변 인자 값 출력
    }
    va_end(ap);    // 가변 인자 목록 포인터를 NULL로 초기화

    printf("\n");    // 줄바꿈
}
```
va_list: 가변 인자 목록. 가변 인자의 메모리 주소를 저장하는 포인터   
va_start: 가변 인자를 가져올 수 있도록 포인터를 설정  
va_arg: 가변 인자 포인터에서 특정 자료형 크기만큼 값을 가져옴  
va_end: 가변 인자 처리가 끝났을 때 포인터를 NULL로 초기화  

---

* 20日  
compiler과제로 LR Parser를 c++로 구현해야한다.  

FIRST와 FOLLOW에 대해 공부하였다.  
먼저 FIRST를 구하는 알고리즘은  
```
① 만약 X가 하나의 터미널 기호이면 {X}는 FIRST(X)에 포함된다.  
② 만약 X가 하나의 논터미널 기호이고 X → aβ의 생성 규칙이 존재하면 터미널 기호인 {a}는 FIRST(X)에 속한다.
③ 만약 X → ε의 생성 규칙이 존재하면 {ε}도 FIRST(X)에 속한다.
④ 만약 X → Y₁Y₂···Yk의 생성 규칙이 존재하면 FIRST(X) = FIRST(X) ∪ FIRST(Y₁Y₂···Yk)이다.
```
FOLLOW를 구하는 알고리즘은  
```
① 만약 A가 시작 기호이면 $는 FOLLOW(A)에 속한다.
② 만약 B → αAβ, β≠ε인 생성 규칙이 존재하면 A의 FOLLOW에 ε을 제외한 FIRST(β)를 첨가한다.
③ 만약 B → αA이거나 B → αAβ에서 β⇒* ε이면 B의 FOLLOW 전체를 A의 FOLLOW에 첨가한다.
```
FIRST는 바로 직관적으로 이해되었으나 FOLLOW에서 꽤 긴 시간이 필요했다.  
FIRST의 경우에는 생성 규칙 중 첫번째 심볼을 선택하면 되었다.  
하지만 FOLLOW에서는 헷갈리는 부분이 많았다. [참고](https://gutte.tistory.com/129?category=1050871)를 통해 이해를 붙여갔다.

---

* 21日  
Operating System수업에서 CPU Synchronization에 대해 배웠다.  
CPU 동기화하는데에 있어 **Race Condition** 문제점이 있는데
```
//count = 5일때 counter++, counter-- 연산
S0: producer execute register1 = counter {register1 = 5}  
S1: producer execute register1 = register1 + 1 {register1 = 6}  
S2: consumer execute register2 = counter{register2 = 5}  
S3: consumer execute register2 = register2 –1 {register2 = 4}  
S4: producer execute counter = register1 {counter = 6 }  
S5: consumer execute counter = register2 {counter = 4}
```  
이런식으로 실행할 때마다 답이 달라지는 경우를 Race Condition이라고 한다.  
프로세스끼리 변수를 공유하여 만들어진 시스템에 있어서 같은 변수를 사용하거나 table을 업데이트하거나 file을 쓰는 코드가 쓰인 부분을 **Critical Section**이라고 한다.  
Critical Section은 Entry Section과 Exit Section으로 나누어지는데 나머지를 Remainder Section이라 부른다.  
![Critical Section](https://www.geeksforgeeks.org/wp-content/uploads/gq/2015/06/critical-section-problem.png)  
Critical Section은 3가지 필요조건을 만족해야한다.  
*1. Mutual Exclusion* - 한 프로세스가 C-S을 수행중이라면 다른 프로세스들은 C-S을 수행할 수 없다.  
*2. Progress* - C-S을 수행하는 프로세스가 없고 C-S을 수행하고자하는 프로세스가 있을 때 반드시 수행되어야 한다.  
*3. Bounded Waiting* - C-S을 요청한 프로세스는 무한히 대기하면 안된다.  
이 세가지 조건을 다 만족한 Peterson's Solution을 봐보자  
```
// int turn = 0; bool flag[3]; flag[1] = flag[2] = false;
//Process P₁			|	//Process P₂
flag[1] = true;			|	flag[2] = true;
turn = 1;			|	turn = 0;
while (flag[2] && (turn == 1));	|	while (flag[1] && (turn == 0));
	critical section	|		critical section
flag[1] = false;		|	flag[2] = false;
	remainder section	|		remainder section
```
이러한 3가지 조건을 만족하는 해결법은 크게 소프트웨어적, 하드웨어적 해결법으로 나뉜다.  
소프트웨어적 해결법은 test_and_set과 compare_and_swap 등이 있다.  
```
boolean test_and_set (boolean * target) {
	boolean * rv = * target;
	*target = TRUE;
	return rv;
}
// 인자 값을 그대로 반환하되, 인자를 TRUE로 변경한다.
do{
	while (test_and_set(&lock)); /* do nothing */
		/* critical section */
	lock = false;
		/* remainder section */
	} while (true);
// lock이 false로 초기화되어있으므로 처음엔 바로 C-S을 수행하지만 lock이 true가 되어 다른 프로세스들은 수행하지 못한다. 이후 lock을 바꾸면서 수행하여 Mutual Exclusion 조건을 해결하였다.

do {
	waiting[i] = true;
	key = true;
	while (waiting[i] && key)
		key = test_and_set(&lock);
	waiting[i] = false;
	/* critical sectioin */
	next = (i+1) % n;
	while ((next != i) && !waiting[next])
		next = (next + 1) % n;
	if (next == i)
		lock = false;
	else
		waiting[next] = false;
	/*remainder section */
} while (true);
이 코드는 Bounded Waiting도 해결한 코드이다.
```

```
int compare_and_swap(int *value, int expected, int new_value) {
	int temp = *value;
	if (*value == expected)
		*value = new_value;
	return temp;
}
do {
	while (compare_and_swap(&lock, 0, 1) != 0);
			/* do nothing */
		/* ciritcal section */
	lock = 0;
		/* remainder section */
	} while (true);
이 방법 또한 Mutual exlusion 을 해결했다. 차이점은 반환형이 다르다는 점이다.
```
하드웨어적 해결법은 3가지가 있다.  
*1. Mutex lock (spinlock)* - 가장 기본적인 형태의 방법이다. acquire()와 release()로 잠금과 잠금해제를 한다. 잠그면 CS에 접근할 수 없다.  
*2. Semaphore* - Binary와 Counting으로 나뉘어서 spinlock과 비슷하게 P()와 V()을 사용한다.  
*3. Monitor* - 가장 high-level부분으로 가장 사용하기 편한 방법이라고 하나 크게 다루지 않았다.  
추가적으로 Deadlock과 Starvation이 있는데  
먼저 Deadlock은 여러 프로세스들이 수행될 때 프로세스 전부 wait상태에 빠진 경우다.  
Starvation은 특정 프로세스의 우선순위가 낮아서 자원 할당을 받지 못하는 경우이다.  
각각 코드와 내용은 이어서 공부할 것이다.  

---

* 22日  
연속합을 복습하였다. 예전에 스터디에서 최대 부분 배열 합이라는 이름으로 CSES에서 문제를 풀었는데 SWEA와 BOJ에 비슷한 문제가 있어서 다시 풀어보았다.  
[CSES](https://cses.fi/problemset/task/1643) [BOJ](https://www.acmicpc.net/problem/1912) [SWEA](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXQm2SqdxkDFAUo&categoryId=AWXQm2SqdxkDFAUo&categoryType=CODE&&&)  
기본적으로 비슷한 문제로 처음에 떠올린 방법은 시간 복잡도 O(n)을 가졌다. 하지만 시간초과로 제대로 해결하지 못하였는데 이 부분은 O(1)로 구현해야했다. 그래서 밑과 같은 방식으로 복습하여 구현하였다.
```
int best = v[0], sum = 0; // best인 값은 초기에 첫번째 배열로 설정하고 합은 0으로 설정한다.
for (int i=0; i<n; i++) {
	if(sum + v[i] < v[i]) sum = v[i]; // if(sum < 0)과 동일 sum이 0보다 작으면 v[i]로 새롭게 초기화시켜준다.
	else sum += v[i]; // sum이 양수거나 0과 같다면 sum에 현재 인덱스부분을 더해준다.
	best = max(best,sum); // best는 best와 sum중 큰 값으로 갱신해준다.
}
```
와 같은 알고리즘으로 구현하게 되면 연속적인 값들의 합을 구할 때 시간복잡도 O(1)로 구할 수 있다.

---

* 23日  
Algorithm 과제로 내준 그래프 이론에 대해 공부하였다.  
1. [BFS](https://github.com/lee20h/Algoritm/blob/master/graph/BFS.cpp)  
2. [DFS](https://github.com/lee20h/Algoritm/blob/master/graph/DFS.cpp)  
3. [Prim](https://github.com/lee20h/Algoritm/blob/master/graph/Prim.cpp)
4. [Kruskal](https://github.com/lee20h/Algoritm/blob/master/graph/Kruskal.cpp)  
BFS와 DFS는 평소 알고리즘 문제를 풀어오니까 빠르게 해결할 수 있었다. 그와 반해 Prim과 Kruskal은 겉핥기식으로 가볍게 보고 넘어갔다보니 이번에 다시 문제를 받고 풀어볼려고 하니 당혹스러웠다.  
작년에 자료구조 수업에서 그래프를 배울 때 제대로 배워뒀어야 했다.  
Prim 알고리즘은 MST 즉 최소 비용 신장 트리를 구현할 때 사용하는 알고리즘으로,  
임의의 점에서 시작해서 간선을 추가하면서 트리를 점점 키워간다.  
1) 트리를 키워갈 때는 간선중 가장 작은 것을 선택  
2) 사이클이 이뤄지면 안됨  
![prim](https://t1.daumcdn.net/cfile/tistory/232ACE3F570B903F30)  
(출처 : http://cbb1225.tistory.com/entry/%EC%B5%9C%EC%86%8C-%EC%8B%A0%EC%9E%A5-%ED%8A%B8%EB%A6%ACMinimum-Cost-Spanning-Trees)  
Kruskal 알고리즘 또한 Prim 알고리즘과 같이 MST를 만드는 알고리즘이다.  
Kruskal 알고리즘은 Greedy algorithm과 같이 매번 최선의 선택을 하여 모든 정점을 최소 비용으로 연결하는 트리를 구하는 것이다.  
원래 Greedy algorithm으로 구한 답은 최적의 해답이라고 보장 할 수 없어서 검증이 필요하지만 Kruskal 알고리즘은 최적의 해답을 주는 것으로 증명이 되어있다.  
![kruskal](https://gmlwjd9405.github.io/images/algorithm-mst/kruskal-example2.png)  
(출처 : https://gmlwjd9405.github.io/2018/08/29/algorithm-kruskal-mst.html)  
이 알고리즘 또한 사이클을 형성하면 안된다. union-find 알고리즘을 이용하여 사이클이 형성되나 확인한다.  

--- 

* 24日  
Compiler 과제를 만들기 앞서 공부를 진행하였다.  
오늘은 SLR파싱에 대해 공부하고, 테이블을 공부했다. [참고](http://courses.washington.edu/css448/zander/Notes/SLRtable.pdf) [참고2](http://blog.naver.com/PostView.nhn?blogId=moonsoo5522&logNo=220726316745&categoryNo=31&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=postView)  
**SLR Parsing**은 Simple Left-to-right scan of input Rightmost derivation in reverse의 준말로 bottom-up 파싱 방법의 일종이다.  
단말노드로부터 생성규칙을 적용하면서 올라가는 방식이다. LL parsing에 비해 파싱 테이블을 얻기 어렵지만 효율적이고 에러 발견이 빠르다.  
먼저 LR(0)방식으로 상태를 구하고 테이블을 구성할 때에 SLR(1)방식을 사용한다.  
```
(1) E -> E + T
(2) E -> T
(3) T -> T * F
(4) T -> F
(5) F -> ( E )
(6) F -> a
```  
이러한 문법이 있다고 가정한다. LR parsing에는 dot이라는 기호가 있는데 dot 뒤에 있는 symbol이 *Mark Symbol*이다.  
1) Mark Symbol이 non-terminal symbol인 경우는 closure한 모든 생성 규칙을 구한 뒤 dot을 한칸 옮겨 Mark Symbol을 옮긴다.  
2) Mark Symbol이 terminal symbol인 경우는 바로 dot을 한칸 뒤로 옮겨 Mark symbol을 바꾼다.  
3) dot 뒤에 아무것도 없는 경우는 해당 생성 규칙의 좌항 non-terminal symbol의 FOLLOW을 구한다.  
![생성규칙으로 만든 그림](http://postfiles12.naver.net/20160602_123/moonsoo5522_1464875245472voI5t_JPEG/%C1%A6%B8%F1_%BE%F8%C0%BD.jpg?type=w2)  
위의 규칙에 따라 dot을 옮겨가며 만들어진 그림이다. 이 그림을 통해서 파싱 테이블을 구성하면 된다. start symbol에서의 FOLLOW는 $을 주면 된다.  

|q / symbol | E | T | F | ( | ) | + | * | a | $ |
|:--------|:--------:|--------:|:--------|:--------:|--------:|:--------:|:--------:|:--------:|:--------:|
| q0 | q1 | q2 | q3 | sq4 |  |  |  | sq5 |  |
| q1 |  |  |  |  |  | sq6 |  |  | accept |
| q2 |  |  |  |  | r2 | r2 | sq7 |  | r2 |
| q3 |  |  |  |  | r4 | r4 | r4 |  | r4 |
| q4 | q8 | q9 |  | sq4 |  |  |  | sq5 |  |
| q5 |  |  |  |  | r6 | r6 | r6 |  | r6 |
| q6 |  | q10 | q7 | sq4 |  |  |  | sq5 |  |
| q7 |  |  | q11 | sq4 |  |  |  | sq5 |  |
| q8 |  |  |  |  | sq12 | sq6 |  |  |  |
| q9 |  |  |  |  | r2 | r2 | sq7 |  | r2 |
| q10 |  |  |  |  | r1 | r1 | sq7 |  | r1 |
| q11 |  |  |  |  | r3 | r3 | r3 |  | r3 |
| q12 |  |  |  |  | r5 | r5 | r5 |  | r5 |
  
non-terminal symbol을 보고갈 때 -> 상태 전이  
terminal symbol을 보고갈 때 -> 시프트 및 상태전이  
모든 symbol을 다 봤을 때 -> FOLLOW set을 보고 reduce (reduce 번호는 production rule에 매겼던 번호.)  
reduce 번호가 E' -> E 같은 시작 심볼일 경우에는 accpet 처리를 한다.  

(출처 : http://blog.naver.com/PostView.nhn?blogId=moonsoo5522&logNo=220726316745&categoryNo=31&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=postView)

---

* 25日  
회문 [SWEA](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14QpAaAAwCFAYi&categoryId=AV14QpAaAAwCFAYi&categoryType=CODE) 회문2 [SWEA](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14Rq5aABUCFAYi&categoryId=AV14Rq5aABUCFAYi&categoryType=CODE)  
회문이란 앞으로 읽어도 뒤로 읽어도 같은 단어이다. 회문1 같은 경우에는 8x8 단어판와 길이가 주어지면 그 단어판에서 길이만큼의 회문 갯수를 세면 된다.  
```
string temp;
for (int i=n; i<n+len; i++) {
	temp += v[i][m];
}
string temp2 = temp;
reverse(temp.begin(),temp.end());
if(temp == temp2)
	ans++;
```
와 같이 뒤집은 문자와 문자가 같으면 회문으로 처리했다.  
회문2의 경우에는 회문1에서 단어판을 100x100으로 키우고 최대의 길이의 회문을 찾으면 된다.  
```
for (int k=1; k<100; k++) {
	for (int i=0; i<=100-k; i++) {
		for (int j=0; j<100; j++) {
			temp = y(k,i,j);
			len = max(len,temp);
		}
	}
	for (int i=0; i<100; i++) {
		for (int j=0; j<=100-k; j++) {
			temp = x(k,i,j);
			len = max(len,temp);
		}
	}
}
```
k가 길이, i가 열, j가 행으로 잡고 길이가 k일때 (i,j)에서 시작하는 회문을 찾고 있으면 길이를 반환해서 len값과 비교해서 큰 값을 len에 넣는다.  

---

* 26日  
다익스트라, 벨만포드, 플루이드 워셜 알고리즘에 대해 공부해보았다.  
먼저 **다익스트라** 알고리즘은 프림의 알고리즘와 같이 주어진 시작점을 루트로 한다. 그리고 루트로부터 최단 길이 트리(SPT)를 만든다. 알고리즘이 진행되면서 가장 짧고 포함되어지지 않은 정점을 찾아서 포함시킨다.  
1) SPT에 포함되는 정점을 추적하기 위한 sptSet을 만든다. 즉 그 정점의 최단거리는 계산되어 결정되었다. 처음에 이 set은 비었다.  
2) 그래프의 모든 정점에 거리(가중치) 값을 준다. 모든 거리는 처음에 무한대로 설정한다. 그리고 source 정점에는 0 값을 주어 처음에 선택되도록 한다.  
3) 모든 정점이 sptSet에 포함될 때 까지 반복한다.  
	a) 아직 sptSet에 포함되지 않았고 가장 짧은 길이를 갖진 정점 u를 선택한다.  
	b) 이를 sptSet에 포함한다.  
	c) 정점 u에 인접한 모든 정점의 거리를 업데이트한다. 정점의 거리를 업데이트하기 위해, 모든 정점을 반복한다. 모든 정점 v에 대해서, 정점 u의 값과 u-v 간선의 가중치의 합이 정점 v의 값보다 작다면 정점 v의 거리 값을 갱신한다.  
![Dijsktra1](https://www.geeksforgeeks.org/wp-content/uploads/Fig-11.jpg)  
처음 시작할 때 sptSet은 비어있고 시작점 은 0, 그외 모든 정점은 무한대 값으로 할당한다. 그 후 가장 작은 거리값을 가진 정점을 선택한다. 처음에는 0으로 할당된 시작 점을 sptSet에 포함 시킨 후 인접한 정점들의 거리를 갱신한다.  
![Dijsktra2](https://www.geeksforgeeks.org/wp-content/uploads/MST1.jpg)  
초록색은 sptSet에 포함된 경우, 빨간색은 인접한 정점 중 sptSet에 포함되지 않은 경우이다.  
계속 3번 방법을 반복하면
![Dijsktra3](https://www.geeksforgeeks.org/wp-content/uploads/DIJ2.jpg)  
![Dijsktra4](https://www.geeksforgeeks.org/wp-content/uploads/DIJ3.jpg)  
![Dijsktra5](https://www.geeksforgeeks.org/wp-content/uploads/DIJ4.jpg)  
![Dijsktra6](https://www.geeksforgeeks.org/wp-content/uploads/DIJ5.jpg)  
이런식으로 다익스트라 알고리즘으로 SPT을 찾을 수 있다.  
특징으로는 모든 정점을 들려야하며 다 돈다면 O(V²)의 시간복잡도를 가지며 구현시에는 우선순위 큐를 사용하면 쉽게 구현이 가능하다. 그리드 알고리즘에 속하며 음의 값을 가지면 안된다.  

**벨만포드** 알고리즘 또한 모든 정점의 최단거리를 구하는 알고리즘이다. 하지만 다익스트라 알고리즘과의 차이점은 음의 값을 가질 수 있다는 점이 다르다. 그리고 시간 복잡도 또한 O(VE)로 다익스트라보다 긴 시간 복잡도를 가졌다.  
1) 첫번째로 src로 부터 모든 정점의 거리를 무한대로 초기화 한다. 그리고 src의 거리는 0으로 초기화 한다. 정점의 개수만큼의 dist[] 배열을 만든다.  
2) 다음으로 최단거리를 계산한다. |V|-1 번 만큼 아래 단계를 반복한다.  
	a) dist[v] > dist[u] + 간선 uv의 가중치 라면 dist[v]를 dist[u]+ 간선 uv의 가중치로 갱신한다.  
![Bellman-Ford1](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/bellmanford1.png)  
시작 정점은 0, 그외 모든 정점은 무한대로 초기화시킨다.  
![Bellman-Ford2](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/bellmanford2.png)  
이후엔 방법대로 반복한다.  
![Bellman-Ford3](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/bellmanford3.png)  

**플루이드 와샬** 알고리즘은 다익스트라와 벨만포드 알고리즘은 처음에 시작하는 정점을 정하는거와 달리 모든 정점들의 최단 거리를 구하는 알고리즘이다. 플루이드 와샬 알고리즘은 처음 배우고 아직도 기억에 남는 알고리즘이다.  
첫번째로 그래프 메트릭스와 같은 솔루션 메트릭스를 초기화 한다. 그 다음 모든 정점을 중간 정점으로 고려하면서 솔루션 메트릭스를 갱신할 것이다. 이 알고리즘의 아이디어는 모든 정점을 하나하나 선택하여 모든 최단거리를 갱신하는 것인데, 선택된 정점을 중간 정점으로 포함하는 것이다. 정점 K를 중간 정점으로 선택한다면, 이미 {1,2,3, ... k-1}의 정점들은 중간 정점으로 구려된 후이다. 모든 정점의 쌍 (i, j)을 시작점과 끝점으로 여긴다면, 두가지 가능성이 있다.  
1) K는 최단거리 (i, j)의 중간 정점이 아니기 때문에 d[i][j]를 그대로 유지한다.  
2) K가 최단거리 (i, j)의 중간 정점에 포함된다. 때문에 만약 d[i][j]의 값이 d[i][k] + d[k][j] 값보다 크다면 d[i][j]의 값을 d[i][k] + d[k][j] 로 갱신해야한다.  
![Floyd-Warshall](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/dpFloyd-Warshall-.jpg)  
내가 문제를 풀이하면서 이해한 소스이다.  
```
k = 거쳐가는 노드 i = 출발 노드 j = 도착노드 
for (int k = 0; k< number; k++) {
	for (int i=0; i < number; i++) {
		for (int j=0; j < number; j++) {
			if(d[i][k] + d[k][j] < d[i][j]) {
				d[i][j] = d[i][k] + d[k][j];
			}
		}
	}
}
```  

(출처 : [다익스트라](https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/) [벨만포드](https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/) [플루이드-와샬](https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/)  

---

* 27日  
오늘은 Compiler 과제를 진행하는 도중 아무리 생각해도 이전 내용을 잘 이해한거 같지 않아서 다시 복습을 진행했다.  
[블로그](https://talkingaboutme.tistory.com/category/About%20Study/Compiler)에서 복습을 해보니 정말 정리를 잘하셨고 예제를 통해서 이해가 쏙쏙되었다. 모르고 놓치고 온 개념이 있을까봐 포스팅 처음부터 읽어보았는데 수업에서는 넘어갔던 부분도 있어서 LR Parser 구현에 도움이 되었다. 이 블로그에서 포스팅한 Top-Down, Bottom-Up parsing을 내가 이해한 방식대로 적어볼려 한다.  
**Top-Down Parsing**은 Tree의 위에서부터 차례대로 Parsing을 한다는 의미로, 보기 쉽게 Tree 형식으로 만들어놓고 실제로 Parsing될 때는 왼쪽에서부터 오른쪽으로 String을 검색한다. 이러한 방식을 Left Recursive라고 하며, Top-Down Parsing을 Recursive Descent Parsing이라고 한다.  
Parsing Tree를 그릴 때 결과물을 하나의 node로 표현한다. Terminal은 leaf node로, Nonterminal은 Derivation을 거친다. 알고리즘에서 흔히 말하는 백트래킹과 같이 탐색하면서 원하는 답을 구한다. 따라서 시간이 많이 걸린다.  
백트래킹이 가진 약점을 보완하기 위해 **Predictive Parsing**이 있다. 한 단계 이후의 결과를 미리 예상하고 경로를 정하기 때문에 결과가 틀려서 백트래킹을 할 필요가 없어진다. 이러한 개념이 Lookahead이며, LR(k)로 k단계 앞을 본다고 표기한다.  
**Bottom-up** parsing은 leave에서 root를 찾아가는 방식으로 Top-down에서 overhead가 많았던 점 때문에 대부분의 컴파일러는 Bottom-up 방식을 택한다. 주어진 입력부터 Reduction과 Shift을 통해서 최종 Root와 비교하는 방법이다. Reduction을 언제 할지 정해주는게 Handle이다. 이것은 Parsing할 때 초점을 맞춰주는 substring이라고 한다. Top-down에서는 production 된게 handdle이라면 Bottom-up에서는 reduction한게 handdle이라고 한다. Top-down에서 하는 방식대로 leftmost을 준수 할 필요 없이 grammar중에서 input과 일치하는게 있으면 reduction 하는 방식대로 이루어지는데 이것을 *Handle Pruning*이라고 한다.  
LR Parser을 만들기 위해 복습을 철저히 하고 빨리 개발에 들어가야겠다.  

---  

* 28日  
운영체제 수업에서 CPU동기화에 신경써야할 문제에 대해 배웠다.  
1) Bounded-Buffer Problem  
2) Readers-Writers Problem  
3) Dining-Philosophers Problem  
Bounded-Buffer Problem은  
![Bounded-Buffer](./img/Bounded-Buffer.JPG)  
이러한 그림으로 생산자와 소비자가 같은 버퍼를 점유할 때 일어나는 문제이다.  
*Bounded-Buffer Problem Solution*  
Empty : 버퍼 내에 저장할 공간이 있음을 표시, 생산자의 진입을 관리  
Full : 버퍼 내에 소비할 아이템이 있음을 표시, 소비자의 진입을 관리  
Mutex : 버퍼에 대한 접근을 관리, 생산자와 소비자가 empty, full 세마포어에 진입한 경우 버퍼의 상태 값을 변경하기위한 세마포어  
세마포어 value의 초기값은 full = 0, empty = n, mutex = 1로 생산자와 소비자의 프로세스을 정리한다.  
```
생산자 프로세스					|소비자 프로세스
Do {						|Do {
	...					|	wait(full);
	/* produce an item in next_produced */	|	wait(mutex);
	...					|	...
	wait(empty);				|	/* remove an item from buffe to next_consumed */
	wait(mutex);				|	...
	...					|	signal(mutex);
	/* add next produced to the buffer */		|	signal(empty);
	...					|	...
	signal(mutex);				|	/* consume the item in next consumed */
	siganl(full);				|	...
} while(true);					|} while(true);
```  

*Readers-Writers Problem*은  
![Readers-Writers](./img/Readers-Writers.JPG)  
- Readers : 공유 데이터를 읽는다.
	+ 여러 Reader는 동시에 데이터를 접근할 수 있다.  
- Writers : 공유 데이터에 쓴다.
	+ Writer가 데이터를 수정할 때는 reader나 다른 writer가 접근하면 안된다.  
```
/* do while 생략 */
1)  
Writer						Reader
wait(wrt);		//entry section			wait(mutex);
		...				readcount++;
writing is performed // critical section			if (readcount == 1)
		...					wait(wrt);		//어떤 writer도 수행X
signal(wrt);	//exit section			signal(mutex);
							... reading is performed... // critical section
						wait(mutex);
						readcount--;
						if (readcount == 0)	
							signal(wrt);
						signal(mutex);
```  
이때 Writer의 Starvation이 일어난다. 그 이유는 계속 Reader들이 진입하게되면 Writer는 Critical section에 진입할 수 없기 때문이다.  

```
2)
Writer					|	Reader
wait(wmutex); // Writer Process entry section	|	wait(read); // Reader Process entry section
writedcount++;				|	signal(read);
if (writecount == 1)			|	wait(rmutex);
	wait(read);			|	readcount++;
signal(wmutex);				|	if (readcount == 1)
wait(wrt);					|		wait(wrt);
...writing is performed... // critical section	|	signal(rmutex);
signal(wrt); // Writer Process exit section	|	...reading is performed... // critical section
wait(wmutex);				|	wait(rmutex); // Reader Process exit sectioin
writecount--;				|	readcount--;
if (writecount == 0)			|	if (readcount == 0)
	signal(read);			|		signal(wrt);
signal(wmutex);				|	signal(rmutex);
```  
`1)`의 Writer의 starvation을 해결하기 위해 짜여졌으나 `2)`에서는 Reader들이 오히려 starvation에 빠지게 된다.  
Reader가 초기값으로 진입했다면 Reader들이 계속 진입하다가 Writer가 진입하게되면 진입한 Reader이 모두 수행하면 Writer가 수행된다. 이 때 Reader가 더 이상 진입하지 못하여 Starvation이 일어난다.  
또, Writer가 초기값으로 진입해서 계속 Writer만 진입한다면 Reader가 Starvation에 빠지게 된다.  
```
3)
Writer					|	Reader
wait(mutex); // Writer Process entry section	|	wait(mutex); // Reader Process entry section
if(rc>0 || wc>0 || rwc>0 || wwc>0) {		|	if(wc>0 || wwc>0) {
	wwc++;				|		rwc++;
	signal(mutex);			|		signal(mutex);
	wait(wrt);				|		wait(read);
	wait(mutex);			|		wait(mutex);
	wwc--;				|		rwc--;
}					|	}
wc++;					|	rc++;
signal(mutex);				|	signal(mutex);
...writing is performed // critical section	|	...reading is performed // critical section
wait(mutex); // Writer Process exit section	|	wait(mutex); // Reader Process exit section
wc--;					|	rc--;
if(rwc>0) {				|	if(rc == 0 && wwc>0)
	for (i=0; i<rwc; i++)		|		signal(wrt);
		signal(read);		|	signal(mutex);
}					|
else					|
	if (wwc>0) signal(wrt);		|
signal(mutex);				|
```
`3)`의 경우에는 모든 문제가 해결되어 동기화가 잘 이루어진다.  
Writer는 작업이 수행되거나 대기중인 다른 reader, writer가 있다면 대기한다. 그리고 수행 후 대기중인 reader들을 모두 수행한다.  
Reader는 writer가 기다리거나 작업중이라면 대기한다. Reader가 다 수행되면 대기 중인 writer을 수행한다.  

*Dining-Philosophers Problem*은  
![Dining-Philosopher](./img/Dining-Philosophers.JPG)  
그림과 같이 젓가락이 5개가 있을 때 자신과 이웃한 젓가락만 들 수 있으며 젓가락을 2개 들었을 때 식사가 가능하다.  
```
1)
do {
		...
		think
		...
	wait(chopstick[i])
	wait(chopstick[(i+1) % 5])
		...
		eat
		...
	signal(chopstick[i])
	signal(chopstick[(i+1) % 5])
		...
} while(1);
```
동시에 젓가락을 집으면 deadlock이 발생한다.
```
2)
do {
		...
		think
		...
	take_chopsticks(i);
		...
		eat
		...
	put_chopsticks(i)
		...
} while(1);

take_chopstics(int i) {		|		put_chopsticks(int i) {
	wait(mutex);		|			wait(mutex);
	state[i] = HUNGRY;		|			state[i] = THINK;
	test(i);			|			test(LEFT);
	signal(mutex);		|			test(RIGHT);
	signal(self[i]);		|			signal(mutex);
}				|		}

test(int i) {
	if (state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
		state[i] = EATING;
		signal(self[i]);
	}
}
```  
`2)`의 전략은 철학자들이 좌우 젓가락이 사용 가능할 때 critical section에 진입하여 deadlock과 starvation을 해결하였다.  

오늘은 CPU 동기화 문제를 일으키는 부분을 3가지로 케이스로 나눠서 솔루션까지 공부해보았다.

---

* 29日  
오늘은 이전에 하던 컴파일러 공부를 이어서 하였다. LR Parser을 구현하기 위해서 필요한 Shift연산과 Reduce연산에 대해 제대로 공부했다. [참조](https://talkingaboutme.tistory.com/entry/Compiler-Shift-Reduce-Parsing?category=484576)  
Reduce 동작은 Top-down에서 했던 Product을 반대로 행한다고 생각하면 된다.  
```
cD -> Z 문법이 있을 때 |은 구분자다.
ABcD|efg ⇒ ABZ|efg (reduce)	ABZ|efg ⇒ ABZe|fg (shift)  
```  
이러한 동작이 왼쪽부터 오른쪽까지 left to right로 하게되면 LR Parsing이 되게 된다.  
이것은 stack 자료구조의 push pop을 이용해서 보여줄 수 있는데 구분자가 현재 stack의 top이고 shift가 일어나면 stack에 push, reduction이 일어나면 stack에서 pop을 하는 것으로 보게되면 stack으로 이해할 수 있다. [참조](http://cons.mit.edu/sp13/ocw/L03.pdf)  
하지만 문제점이 존재하는데 문법이 중복되어 A -> a, B -> a로 Reduction을 선택해야하는 문제, Shift를 할지 Reduction을 할지 골라야하는 문제 두 가지가 있다. 각각 **Reduce-Reduce Conflict**, **Shift-Reduce Conflict**라고 한다. 문제를 해결하기 위해 대부분에 책들이 선택하는 방법이 Lookahead을 사용한 방법이다. 이 방법은 LALR로 컴파일러 과제에서도 구현해야하는 방법 중 하나이다.  

이어서 LR(0)에 대해 알아보았다. LR(0)은 LR Parser로 k가 0으로 즉, lookahead가 0으로 선행을 인식하지 않고 현재 상태에서 모든 item들을 뽑아 낼 수 있다.  
```
T -> T + E | (E)는
T -> ㆍT + E
T -> Tㆍ + E
T -> T +ㆍ E
T -> T + E ㆍ
T -> ㆍ( E )
T -> (ㆍ E )
T -> ( E ㆍ)
T -> ( E ) ㆍ
```

ㆍ이전까지 LR(0)로 인식했다고 볼 수 있다. 위의 구분자와 비슷하게 작동한다. T의 production이자 item이다.  
`X -> ε 이면 X -> ㆍ` 라는 조건까지 붙이면 LR(0)에 대한 모든 item이 되며 Grammar라고 할 수 있다.  
또 다른 예시를 보여주었는데, 
```
입력 : ( int * int )
S` -> E // augmented Grammar
E -> T + E | T
T -> int * T | int | ( E )
```
stack내의 push와 pop으로 볼 때 stack 안에 들어있는 item으로 그 다음 item을 판단하고 shift나 reduce가 일어나게 된다.  
```
items on stack	meaning
T -> (ㆍE)	seen "(" of T -> (E)  // T -> "(" E )
E -> ㆍT		seen nothing of E -> T // E -> T
T -> int * ㆍT	seen int * of T -> int * T // T -> int * T
```
이러한 방법을 모든 터미널 노드에 대해 시도하면 이러한 그림처럼 된다.  
![LR(0)](./img/LR(0).JPG)  

---

* 30日  
Parser을 구현하기 위해 First와 Follow을 구하는 부분을 공부해보았다.
```
void findfirst(char c, int q1, int q2) 
{ 
    // The case where we
    // encounter a Terminal
    if(!(isupper(c))) {
        first[n++] = c;
    } 
    for(int j = 0; j < count; j++) {
        if(production[j][0] == c) {
            if(production[j][3] == '_') {
                if(production[q1][q2] == '\0') 
                    first[n++] = '_'; 
                else if(production[q1][q2] != '\0'  && (q1 != 0 || q2 != 0)) {
                    // Recursion to calculate First of New
                    // Non-Terminal we encounter after epsilon
                    findfirst(production[q1][q2], q1, (q2+1));
                } 
                else
                    first[n++] = '_';
            }
            else if(!isupper(production[j][3])) {
                first[n++] = production[j][3];
            }
            else {
                // Recursion to calculate First of
                // New Non-Terminal we encounter
                // at the beginning
                findfirst(production[j][3], j, 3);
            } 
        } 
    }  
}
```
First을 구하는 함수로 `_`을 Epsilon으로 뒀다. input grammar가 "E->TR" 일때 0번 인덱스를 1,2번째 인덱스를 사용하지 않고 인덱스 3부터 사용하며 논터미널이 나오게되면 재귀시켰다.
```
void follow(char c) {
    // Adding "$" to the follow
    // set of the start symbol
    if(production[0][0] == c) {
        f[m++] = '$';
    } 
    for(int i = 0; i < 10; i++) {
        for(int j = 3; j < 10; j++) {
            if(production[i][j] == c) {
                if(production[i][j+1] != '\0') {
                    // Calculate the first of the next
                    // Non-Terminal in the production 
                    followfirst(production[i][j+1], i, (j+2)); 
                } 
                  
                if(production[i][j+1]=='\0' && c!=production[i][0]) { 
                    // Calculate the follow of the Non-Terminal 
                    // in the L.H.S. of the production 
                    follow(production[i][0]); 
                } 
            }  
        } 
    } 
} 

void followfirst(char c, int c1, int c2) {       
    // The case where we encounter 
    // a Terminal 
    if(!(isupper(c))) 
        f[m++] = c; 
    else{ 
        int i = 0, j = 1;
        for(i = 0; i < count; i++) { 
            if(calc_first[i][0] == c) 
                break; 
        }
        
        //Including the First set of the 
        // Non-Terminal in the Follow of 
        // the original query 
        while(calc_first[i][j] != '!') {
            if(calc_first[i][j] != '_')  { 
                f[m++] = calc_first[i][j]; 
            } 
            else { 
                if(production[c1][c2] == '\0') 
                { 
                    // Case where we reach the 
                    // end of a production 
                    follow(production[c1][0]);
                } 
                else
                {
                    // Recursion to the next symbol
                    // in case we encounter a "_"
                    followfirst(production[c1][c2], c1, c2+1);
                } 
            } 
            j++; 
        } 
    } 
}
```
Follow는 start symbol로는 `$`으로 잡고 파라미터로 넘어온 c와 비교해서 inputgrammar을 null문자 전까지 재귀시켜서 찾는다.  
FollowFirst에서는 calc_first 배열에 전부 !을 넣어 놓고 !이 아닌 즉, 문자가 다른게 들어간 배열을 follow에 넣어준다.  

소스에 대해 가볍게 알아보았는데 이제 이걸 적용시켜서 LR Parser을 구현하는 데까지가 목표이다.  

---
