---
sidebar: auto
---
# Expressions and Assignment Statements

들어가기 앞서, 명령형 언어는 assignment가 제일 중요하다. 하지만 이로인해 Side effect가 발생한다.  

## Side Effect
**Side effect**란 함수가 자신이 선언된 범위 밖의 변수의 값을 변경시키는 것.  
ex)  
```
int gCount;
int square(int a) {
	gCount++;
	return a*a;
}
```
함수형 언어는 Side effect가 없다. 왜냐 **assignment**가 없기 때문이다.  

## Arithmetic Expression  

산술이 프로그래밍 언어 개발의 첫번째 동기라고 할 수 있다.  
연산자는 피연산자의 갯수로 분류할 수 있다.  
1) Unary : -a
2) Binary : a+b
3) Ternary : a>b?a:b  
	
위치에 따라 분류할 수도 있다.  
1) Prefix : 괄호 없이 산술이 가능하다.  
2) Infix : 대부분 프로그래밍언어에서는 사람이 코딩하므로 infix을 주로 사용한다.
3) Postfix : stack이용하면 편하다.  


## Arithmetic Operator Evalation Order  

1) 연산자 우선순위
2) associativity rule

전형적인 우선순위는 
괄호 -> unary operator -> 제곱 -> *,/ -> +,-이다.  
보통 왼쪽에서 오른쪽으로 진행되나 제곱은 오른쪽에서 왼쪽으로 진행하면 된다.  
우선순위를 잘 모르겠으면 괄호로 묶으면 된다.  

조건연산은 C나 C++의 경우에는 삼항연산을 이용한다.  

피연산자 순서  
변수나 상수는 순서가 크게 상관이 없다.  
괄호가 있거나 함수호출이 있는 경우에는 결과 값을 피연산자로 들어가야하기 때문에 먼저 결과 값을 얻어야한다.  

만약에, a*b에 side effect가 존재한다면 순서가 달라진다.  
Functional side effect는 함수 안에서 전역 변수나 매개변수의 값을 바꿀 때 side effect가 있다고 한다.  
a = 10; b = a + func(a);  
왼쪽을 먼저하면 변수 b에 20이 할당되지만, 오른쪽을 먼저하면 변수 b에 30이 할당된다. 
```
int a = 5;
itn fun1() {
	a = 17;
	return 3;
}
void main() {
	a = a + fun1();
}
```
 
C언어의 경우에는 정의되어 있지 않다. 따라서 fun1을 먼저 하면 a = 20이 되고 왼쪽을 먼저 시작하면 8이 된다. 따라서 C언어에서 구현할 때는 피해야한다.  

**Referential Transparency**의 특징이란 Side effect가 없어야한다.  
예를 들어 `result1 = (fun(a) + b) / (fun(a) - c);`  
`temp = fun(a);
result2 = (temp + b) / (temp -c);`  
이때, result1과 result2가 같다면 Referential Transparency를 가지고 있다고 할 수 있다.  
이러한 특징을 보면 Assignment가 없는 pure functional language는 항상 Referential Transparency를 갖는다.  
장점 : 프로그램을 이해하기 쉬워진다.  

## Operator Overloading  
자료형 별로 연산을 다르게 정의해놓았다. 이 부분을 오버로딩했다고 할 수 있다. 프로그래머 입장에서는 익숙한 기호로 사용할 수 있다는 장점이 있다.  
하지만 C와 C++에서 `&, -, *`은 뜻이 애매해서 컴파일러가 오류를 검출하는데 있어서 문제가 생길 수 있다. 추가적으로 가독성에도 문제가 있을 수 있다.  
예를 들어서 x = &y인 경우 프로그래머의 실수로 x = x & y을 잘못 기입한 경우 오류를 탐지하지 못하는 문제가 생길 수 있다는 것이다.  
C++과 C#, F#에서 user-defined overloaded operator을 만들 수 있다.  
예를 들어 A * B + C * D(MatrixAdd(MatrixMult(A, B), MatrixMult(C, D))와 같이 배열 자료형끼리의 연산을 오버로딩하면 이러하게 편하게 코딩이 가능하며, 가독성이 증가한다.  
하지만 잠재적인 문제로 사용자가 센스없이 오버로딩하게 된다면 가독성도 떨어질 수 있다.  

- **Type Conversions**  
만약 컴파일러가 자동으로 해준다면 `Coercion`이라고 한다.  

## Narrowing conversion  
원본의 값을 변환 시 잃어버리는 값이 있으면 Narrowing conversion이라고 한다. ex) 1.2 -> 1 (float -> int)  
Widening conversion  
원본이 값을 변환 시 그대로 다 갖고 더 크게 변환 해주는 것이다.  
따라서 안정적이며, Coercion을 허용한다.  
ex) 1 -> 1.0 (int -> float)  

Mixed Mode operation일 경우 coercion이 묵시적으로 일어나게 된다. coercion이 일어나게 되면 컴파일러가 *타입 오류*를 탐지 못하는 경우가 있을 수 있다.  

```
int a;
float b, c, d;
...
d = b * a; // (c를 써야하나 실수 한 경우)
```  
추가적으로 C언어나 Java에서 integer보다 작은 타입의 경우에는 integer로 coercion하고 연산을 한뒤 다시 값에 coercion해준다.  

C언어에서 프로그래머가 명시적으로 형변환하는 경우에는 변수 앞에 적어준다.  

예외처리가 필요한 표현이 있다.  
divison by zero  
overflow  

관계식  
`< > <= >= == != /= ~=`등 사용된다.  
Javascript와 PHP에서의 `==`와 `===`의 차이를 보자  
`==`은 coerced가 일어난 뒤 비교를 한다. 하지만 `===`은 coerced가 일어나지 않는다.  

Boolean  
C에서는 0이 거짓, 0이 아니면 참이다. 잘못된 표현중 하나는 `if(a<b<c)`이다. `a<b`을 먼저 실행한다음 1 혹은 0이랑 c를 비교한 값을 if 조건문에 넣게 된다.  
고치게되면 `if(a<b && b<c)`로 고쳐야한다.  

**Short Circuit Evaluation**  
전체를 evaluation을 하지 않고도 일부분을 evaluation을 해도 값을 얻을 수 있는 경우를 Short Circuit Evaluation이라고 한다.  
ex) (13 * a) * (b / 13 - 1)  
만약 a가 0이라면 (b / 13 - 1)하면 된다.  
지원하지 않는 경우 일어나는 문제  
```
index = 0;
while (index < length> && (LIST[index] != value))
	index++;
```
만약 길이가 length와 같아진 경우 false가 반환되나, 뒤에도 evaluation을 해야하므로 LIST[length]가 들어가게 되어 세그먼트 폴트가 일어날 수 있다.  
e.g (a > b) || (b++ / 3)  
여기서는 선조건인 (a>b)가 false여야 뒷조건을 실행하므로 b++가 무조건 일어나지는 않는다. 하지만 이렇게 side effect가 있도록 코딩하지 않도록 해야한다.  

## Assignment  
### general syntax  
`<target_var> <assign_operator> <expression>`  
assign_opeartor는 FOTRAN, BASIC, C기반 언어는 `=`을 사용한다. Ada같은 경우에는 `:=`을 사용한다.  

compound assignment operator  
`a = a + b` ==> `a += b`  

Unary assignment operator  
`sum = ++count` // count 연산 먼저  
`sum = count++` // 할당 먼저
`count++`  
`-count++`// count 연산 후 -붙인다.  

Perl의 조건 할당  
`($flag ? $total : $subtotal) = 0`  
이것은 밑에 코드와 같다.
```
if ($flag)
	$total = 0
else
	$subtotal = 0
```

### Assignment as an Expreesion  
`whlie((ch = getchar()) != EOF)`
상수랑 assignment statement와 비교하는 경우이다.  
side effect가 일어날 수 있다. 그로 인해 가독성이 떨어질 수 있다.  
E.g `a = b + (c = d / b) -1`  
변수 c에 d/b 값을 할당 후 b + c - 1을 계산하여 변수 a에 할당한다.  

Multiple Assignments  
Perl, Ruby, Lua에서 Tuple을 사용하면 ($first, $second, $third) = (20, 30, 40);  

### 함수형 언어에서의 할당  
ML에서 `val fruit = apples + oranges;`  
을 사용하게되면 fruit에 apples + oranges의 값이 바인딩되어 수정이 불가능하다. 따라서 변수들의 재사용이 불가능하다. 매번 변수들을 선언해서 사용해야 하므로 Cache을 사용하지 못하게된다. 따라서 속도가 느릴 수 밖에 없다.  