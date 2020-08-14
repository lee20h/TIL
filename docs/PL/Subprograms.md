---
sidebar: auto
---
# Subprograms

1) **Procedure** (리턴 X)  
2) **Function** (리턴 O)  

두개를 합쳐 Subprogram이라고 한다. 정의와 호출은 C언어와 같이 생각하면 된다.  
active란 호출이 되었으나 아직 끝까지 가지 않은 상태이다.  
header란 이름이라고 생각하면 된다. body는 실행할 형태를 정의한 것이다.  

## Parameter  

1) Formal 정의시 적는 매개변수  
2) Actual 호출시 넘어가는 매개변수  

Python에서는 같은 이름의 서로 다른 버전의 함수를 정의할 수 있다. def 함수가 실행전까지는 호출이 될 수 없어서 조건절로 나눠서 정의 후 다른 버젼의 함수를 호출 할 수 있다.  

### **Actual / Formal Parameter 매핑방법**  
Positional (C언어)  
매개변수의 순서에 맞춰서 매핑을 하는 방법으로 안전하고 효과적이다고 볼 수 있다.  

Keyword  
`f(a=1, b=2);`  
이런식으로 사용하는 방법이다. 프로그래머가 함수가 정의된 부분을 다 알고 있어야한다. 순서가 바뀌어도 가능하다.  

Default Value  
C++ Python Ruby Ada PHP에서 Formal Parameter에 기본 값을 지정해줄 수 있다. 호출 시에 비어있으면 정의 해놓은 기본 값이 들어가고 매개변수를 넘긴다면 해당 값을 넣는다. C++에서는 Positional하게 매개변수를 매핑하기 때문에 매개변수에서 맨 오른쪽부터 기본 값을 줘야한다.  

### **Variable numbers of parameters**  
인자의 갯수가 바뀔 수 있는 것을 가변인자라고 한다.  
예를들어 C언어에서의 printf을 살펴보면  
`int printf(const char *fmt, ...); printf("%d",2); printf("%d%d",5,7);`  
이 가변인자를 사용하려면 무조건 **Positional한 언어**여야만 가능하다. 위치를 사용해서 가변인자를 구현하기 때문이다.  
C#에서도 사용할 수 있다.  
```cs
public void DisplayList(params int[] list) {
	foreach (int next in list) {
		Console.WriteLine("Next value {0}", next);
	}
}
MyClass myObject = new MyClass;
int[] myList = new int[6] {2,4,6,8,10,12};
myObject.DisplayList(myList);
myObject.DisplayList(2, 4, 3 * x - 1, 17);
```
원래는 첫번째와 같이 actual parameter에는 int의 배열만 받을 수 있으나 params로 받게 되면 인자를 가변으로 다 받을 수 있다. 하지만 받는 인자들의 자료형은 꼭 동일해야한다. 이러한 함수 정의 방법으로 자유도가 증가한다.  

| Memory |
|:--------|  
| Code |
| Data |
| Heap |
| Stack |

위와 같이 메모리 구조를 가진다. 지역 변수는 stack-dynamic에 저장이 된다. 이러한 구조 때문에 재귀가 가능해진다. 그리고 밑에 쌓인 subprogram들의 공간을 공유해서 사용할 수 있다. 단점으로는 할당과 해지, 초기화 시간이 걸린다. 또한 스텍에서 해당 subprogram을 찾고 거기서 상대주소를 찾기 때문에 Indirect addressing라고 보면 된다. 그리고 이전에 있었던 일들을 기억하지 않는다. (history insensitive)  

## **Parameter Passing**  
Semantics Model
1) In mode
2) Out mode
3) Inout mode  

![Parameter-Passing](/TIL/images/Program_Language/Parameter-Passing.JPG) 
대부분은 명시해서 사용한다. int x out y inout z와 같이 명시한다. C언어에서는 In mode만 지원한다. 하지만 Pointer을 이용해서 극복한다.  

### **구현**  
물리적으로 값을 옮기는 방법  
실질적 메모리에 적재된 값을 변경하는 방법  

1) Pass-by-Value (In mode)  
2) Pass-by-Result (Out mode)  
3) Pass-by-Value-Result (Inout mode)  
4) Pass-by-Reference (Inout mode)  
5) Pass-by-Name (Inout mode)  

### Pass-by-Value  
actual parameter의 값을 formal parameter에 초기화시켜준다.  
단점으로는 Formal Parameter 공간이 추가적으로 필요하다. 또한, 값만 복사해오기 때문에 Indirect addressing으로 두번 접근해서 속도가 떨어진다.  

### Pass-by-Result  
Formal Parameter가 지역변수처럼 사용된 다음 반환 될 때 Actual Parameter에 값이 반환된다. 이 방법 또한 추가적인 공간이 필요하다.  
잠재적 문제  
C#에서의 예  
```cs
void Fixer(out int x, out int y) {
	x = 17;
	y = 35;
}
...
f.Fixer(out a, out a);
```  
이 때 변수 a의 값은 무엇일까?  
컴파일러마다 어떤 값을 넣는지는 다르다.  
다른 예시도 보자.  
```cs
void Doit(out int x, int idx) {
	x = 17;
	idx = 42;
}
...
sub = 21;
f.Doit(out list[sub], sub);
```
list[sub]에 참조할때 sub값이 어떻게 될까?  
함수를 호출하고 처음에는 sub이 21이였으나 끝날 때는 42로 바뀌게 된다.  

### Pass-by-Value-Result  
위의 두 방식을 합쳤다.  

### Pass-by-Reference  
Call-by-Reference와 같은 말로, 주소값을 전달하는 방식이다. 장점으로는 전달하는 과정이 효율적이다. 왜냐 값의 입장에서 보면 정수가 아닌 구조체인 경우 구조체를 그대로 복사할 때 크기가 크지만, 주소값을 전달하기 때문에 메모리를 아낄 수 있다. 단점으로는 Formal parameter에 접근하는 속도가 느리며 원치않은 Side effect와 aliase가 일어날 수 있다.  
원치않은 Aliase가 일어나면 가독성과 신뢰성에 큰 영향을 준다.  

### Pass-by-Name  
C의 MACRO정의 (#define)과 똑같다고 보면 된다.  
```c
#define swap(t,a,b) {t = a; a = b; b = t;}
int temp = 0, value7 = 10, value9 = 20;
swap(temp,value7,value9);
```  
자유도가 증가하며 **Textual substitution**가 일어난다.  

![Parameter-Passing-Methods](/TIL/images/Program_Language/Parameter-Passing-Methods.JPG)  
C와 C++에서 다차원 배열을 Formal Parameter로 받아야하는 경우 `void f(int v[][10])`이런 식으로 뒤에 사이즈를 명시해야 stack에서 배열 크기만큼 할당할 수 있다.  
해결법으로 배열의 주소값과 차원별로 사이즈를 보내주는 방식으로 할 수 있다.  
```c
void f(int **v, int xsize, int ysize) { }
```

Java와 C#인 경우에는 배열자체가 객체로 보기 때문에 객체를 그냥 적어주기만 하면 call-by-reference로 넘어가게 된다. length을 가지고 사이즈를 해결할 수 있다. 속도는 느리지만 프로그래머가 유연하게 코딩이 가능하다.  

## 매개변수 전달할 때 고려해야하는 점  
1) Efficiency
2) One-way or two-way data transfer  

One-way란 in 혹은 out mode만 가능하며 Two-way는 inout mode을 뜻한다. 1과 2는 서로 반비례하므로 잘 선택해야한다.  

매개변수로 함수의 이름을 넣는 함수 (high-order-function)  
ex) `void g(); int k(); f(g()); f(k())`  

### 참조 환경
참조 환경에 따라서 함수에서 어떤 변수를 참조하는게 달라진다. 그 방법에 대해 설명해보자.  
1) **Shallow binding** (dynamic-scoped languages)
2) **Deep binding**(static-scoped languages)
3) **Ad hoc binding** (그때 마다 다르며 자신을 call한 환경의 변수를 참조)  

ex)
```cpp
function sub1() {
	var x;
	function sub2() {
		alert(x);
	};
	function sub3() {
		var x;
		x = 3;
		sub4(sub2);
	};
	function sub4(subx) {
		var x;
		x = 4;
		subx();
	};	
	x = 1;
	sub3();
}
``` 
Shallow binding : sub4'x  
Deep binding : sub1'x  
Ad hoc binding : sub3'x  

Indirect call  
C와 C++에서는 함수 포인터를 이용해서 구현한다.  
C#에서는 delegate을 사용한다.  
```cs
public delegate int Change(int x);
static int fun1 (int x) {}
Change chgfun1 = new Change(fun1);
chgfun1 += fun2;
chgfun1(12);
```
delegate에 동일한 타입의 함수포인터 여러 개를 담은 뒤 한번에 실행할 수 있다.  

### overloaded subprogram  
이름이 같고 다른 subprogram이다. ad hoc polymorphism이라고도 한다.   
e.g `void f(); void f(int a); void (int a, int b)`  

Generic Subprogram  
Generic 혹은 Polymorphic subprogram 이라고 한다.  
C++에서는 template을 가지고 구현한다.  
```cpp
template <class Type> Type max(Type first, Type second) {
	return first > second ? first : second;
}
```
Subprogram이 모든 타입을 받아서 사용되는게 아니라 자료형 별로 여러가지 버젼의 subprogram이 생성이 된다.  

User-defined overloaded Operator  
Python example  
```py
def __add__ (self, second) :
	return Complex(self.real + second.real, self.imag + second.imag)
```
이렇게 정의해서 사용해도 좋지만 `x + y`로 표현한다면 가독성이 좋아진다.  

## **Closure**  
subprogram과 referencing environment를 합친 것을 Closure이라고 한다.  
Closure을 데이터처럼 사용할려면 함수에서 Closure을 반환하면 사용할 수 있다.  
JavaScript에서의 Closure는  
```js
function makeAdder(x) {
	return funtion(y) {return x + y;}
}
...
var add10 = makeAdder(10); // 함수
var add5 = makeAdder(5); // 함수
document.write("add 10 to 20: " + add10(20) + "<br />");
document.write("add 5 to 20: " + add5(20) + "<br />");
```
Closure는 anonymous function이라고 할 수 있는데 이게 곧 referencing environment이다.  
C#에서는 delegate을 이용해서 closure을 만든다.  
`Func<int, int> // <input, output>`
```cs
static Func<int, int> makeAdder(int x) {
	return delegate (int y) {return x + y;};
}
```
Func문법 빼고는 JavaScript와 같다고 보면 된다.  

## **Coroutine**  
Caller와 Callee가 있을 때 subprogram은 호출 후 Callee가 끝나야 반환이 된다. 하지만 Coroutine에서는 Caller와 Callee가 서로 같은 프로그램을 완성한다. Coroutine Call 대신에 `resume`이라는 이름을 쓴다. 이러한 이름이 붙여진 이유가 재호출 시에 이전 호출에서 멈춘 시점부터 다시 시작하기 때문이다.  
Quasi-concurrent execution이라며 동시실행한다고 보기도 한다. 

Coroutine을 이용해서 가능한 실행 흐름
![Coroutine](/TIL/images/Program_Language/Coroutine.JPG)  
이런 식으로 A -> B -> A 이런식으로 흘러갈 수 있다.  

![Coroutine-Loop](/TIL/images/Program_Language/Coroutine-Loop.JPG)
Loop가 있어도 똑같이 진행된다고 생각하면 된다.  