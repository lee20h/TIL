  
 
  
# Statement-Level Control Structure

## Control Structure  
if문 else문  
Selection Statements  
2개의 조건 : if-else  
여러개의 조건 : switch  

C와 C++, 파이썬에서는 if 조건절에 boolean이 아닌 숫자도 가능하다.  

## Nesting Selectors  
Java에서 if문 속 if가 존재할 때 else가 있다면 가장 가까운 if와 연결된다. 아니면 괄호로 묶어줘야한다.  

Funtional Language에서는 Selector의 결과가 무조건 값이다.  

**C언어에서는 switch** 조건절에는 무조건 정수가 들어와야한다.  
정수랑 실수를 비교해도 속도차이가 많이 난다.  
break절 전까지 다 실행이 가능하다.  

*C#과 비교*  
C언어에서는 조건절에서는 정수만 가능하지만, C#에서는 정수와 문자열을 허용한다. 그리고 C#에서는 여러 케이스가 계속 실행되는 것을 허용하지 않는다. 따라서 한 케이스마다 goto나 break가 나와야한다.  

Scheme에서의 Multiple Selector  
```s
(COND
	(predicate1 expression)
	...
	(predicaten expression)
	[ (ELSE expression n+1)]
)
```
조건 predicate가 참일 경우 expression 실행  

## 반복문  
Counter-Controlled Loops (for문)  
initial, terminal, stepsize  

C와 C++의 for문의 차이는 조건절에 C에서는 다 정수이지만, C++에서는 bool타입도 들어갈 수 있다는 점과 초기화절에서 변수 정의 유무이다.  
Java와 C#랑 C++의 차이로는 Java와 C#은 무조건 bool타입이여야한다.  

Python의 for문에서는 else가 있을 수 있는데 이때의 else는 for문이 정상적으로 종료되야 실행된다. 또한, 범위를 잡을 수 있는데 전에 공부한 범위를 잡던 것 처럼 범위를 잡으면 된다. ex) range(5) = [0,1,2,3,4]  
range(2, 7) = [2,3,4,5,6] range(0, 8, 2) = [0,2,4,6]  

## Funtional Language에서의 Loop  
명령형 언어에서는 counter 변수를 가지고 loop을 돌지만 함수형 언어에서는 재귀호출을 통해서 반복을 구현한다.  
```cpp
명령형
int sum(int a) {
	int s = 0;
	for (int i=a; i>=1; i--)
		s += i;
	return s;
}
함수형 // 속도가 느림
int sum (int a) {
	if (a == 1) return 1;
	else a + sum(a-1);
}
```  

C와 C++은 while처럼 먼저 조건절을 보고 반복하거나 do_while처럼 실행 후 조건절을 보는 경우 둘 다 가능하다. 그리고 조건절에서는 산술이 가능하다.  
Java에 경우에는 조건절은 boolean형이여야 하며 반복문에서 goto가 불가능하다.  

## 반복자를 통한 반복  
흔히 아는 iterator을 가지고 반복을 하면 된다. C언어에서는 기본적으로 제공하지 않아서 유저가 직접 정의해서 사용해야한다.  
PHP에서는 iterator을 먼저 정의해서 사용하면 된다.  
키워드  
current : 현재 위치의 원소 반환  
next : 현재 위치에서 다음 위치로 이동  
reset : 첫번째 원소로 이동  
ex)  
```php
@list = (1,3,5);  
reset $list;
print ("First number: " + cureent($list));
while ($current_value = next($list))
	print ("Next number: " + $cureent_value + "<br\n>");
```
Java 5.0에서는 for가 foreach와 같다. for (String myElement : myList) { }  
C#과 F#에서도 foreach를 사용하는데 유저가 원하는 `IEnumerator`인터페이스를 가지고 foreach을 원하는대로 사용할 수 있다.  
```java
List<String> names = new list<String>();
names.Add("Bob");
names.Add("Carol");
names.Add("Ted");
foreach (String name in names)
	console.WriteLine ("Name: {0}", name);  
```

## goto  
주요 개념은 가독성의 증가이다. Java에서는 허용하지 않고 C#에서는 가끔 사용된다.  

## Guarded Commands
**Guarded Commands** (개념을 이해)  
Dijkstra가 디자인한 검증을 목적으로 한 프로그래밍이다. 일반적으로는 쓰이지 않는 개념이다.  
Guarded Commands로 쓰여진 코드들은 병렬적으로 실행이 가능하며, 순서가 중요하지 않다.  

Selection Guarded Command  
```r
if <Boolean expr> -> <statement>
[] <Boolean expr> -> <statement>
...
[] <Boolean expr> -> <statement>
fi
```
모든 조건절을 동시에 확인해서 참인 것들 중에서 랜덤으로 실행이 된다. 하나 이상 참이 있어야한다. 다 거짓이라면 런타임 에러가 일어난다.  

Loop Guarded Command  
```r
do <Boolean> -> <statement>
[] <Boolean> -> <statement>
...
[] <Boolean> -> <statement>
od
```
모든 조건절을 동시에 확인해서 참인 것들 중에서 랜덤으로 반복이 된다. 다 거짓이라면 loop에서 빠져나가게 된다.  