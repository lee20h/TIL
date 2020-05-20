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

