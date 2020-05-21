# Today I Learned  
## 규칙
* 기억에 남는 내용 기록
* 1일 2개의 알고리즘 문제 해결

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
//Process P₁			//Process P₂
flag[1] = true;			flag[2] = true;
turn = 1;				turn = 0;
while (flag[2] && (turn == 1));	while (flag[1] && (turn == 0));
	critical section			critical section
flag[1] = false;			flag[2] = false;
	remainder section			remainder section
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