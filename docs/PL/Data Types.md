---
sidebar: auto
---
# Data Types

1) **표현**
2) **연산**  

자료형은 2가지를 고려해야한다. 이 부분을 생각하면서 공부하자  

Data type : 데이터의 모음과 미리 정의된 연산들의 모음  

descriptor : 변수의 속성들의 모음  
![descriptor](/TIL/images/Program_Language/descriptor.JPG)  
모든 속성들은 정적이라서 컴파일 시간까지만 필요하다.(Symbol table에 유지) 따라서 런타임에는 value만 유지한다.  

object : 상속을 제외한 추상 데이터  

## Primitive data types  
가장 기본적인 data type  
비트마다 하드웨어에 기반해서 data type을 정함  

### Numeric types
- integer  
음의 정수 표현  
	- Sign-magnitude notation (MSB가 부호비트)  
	산술문제가 존재 (0011 (3) + 1011 (-3) ≠ 0)  
	- Two's complement notation  
	보수 취하고 1을 더함  
	대부분 사용함
	- One's complement notation  
	0을 표현하는 방법이 2가지가 있음 (1111, 0000)  

- floating point  
표현방법  
	 - Fixed-point notation  
	 1.3  
	 0001 | 0011  
	 0.03 같은 숫자 표현 불가
	 - Floating-point notation  
	 0.13 x 10¹  
	 0111 | 0001  
	 이러한 원리로 작동한다.  
	 0.03 = 0.3 x 10^(-1)도 같이 표현할 수 있다.  

- complex  
	real + imaginary  

- decimal  
	C언어에서 제공 X  
	은행에서 많이 사용함 (COBOL)  
	BCD : 0,1로 코딩된 십진법을 사용함  
	4bit or 8bit 사용  
	ex) 123  
	4 bit : 0001 0010 0011  
	8 bit : 00000001 00000010 00000011  
	장점 : 정확성  
	단점 : 범위 한계, 메모리 낭비  

- boolean  
	true or false  
	byte 단위로 표현 (bit로 하면 연산시 복잡함)  
	장점 : 가독성  

- character  
	숫자 -> 문자 매핑
	ASCII 이용  
	영어 외의 언어 Unicode  

## Structured data types  
primitive data type들을 구조화 시킨 data type  

### string
- issue  
primitive로 볼지, char형의 배열로 볼지  
string의 길이를 정적으로 할지 동적으로 할지 (hi -> hello, hello -> hi)  

- operation  
assignment and copying: 주소를 공유 or 값만 복사  

    - comparison  
    - catenation  
    - substring  
    - pattern matching(Perl)  

- C, C++ Not primitive  
Library of function  
E.g) char str[] = "apples";  
strcpy(dest, src)  만약 primitive라면 자동으로 사이즈가 늘어나서 복사된다.  

- Java primitive  
Perl, JavaScript, Ruby, and PHP  
pattern matching에 정규표현(regular expressions) 사용한다.  
E.g `/[A-Za-z][A-Za-z\d]+/`  
E.g `/\d+\.?\d*|\.\d+/`  
`+` : 1개 이상 나옴  
`*` : 0개 이상 나옴  
`?` : optional  
`\.` : 숫자 .  
`|` : or  

- Length option  
static or dynamic  
    - static 속도↑ 편의성↑
        COBOL, Java's String class  
        Compile-time descriptor가 필요하다.
    - Limited Dynamic Length  
        C and C-style C++  
        \0을 주는 것보다 길이를 크게 할당  
        run-time descriptor가 필요 할 수 있으나 static과 비슷해서 필요 없을 때가 많다.   
    - Dynamic (no maximum)   속도↓ 공간↓
        SNOBOL4, Perl, JavaScript, standard C++ library  
        run-time descriptor가 필요하다.  
        할당과 해제에 큰 구현문제가 있다.


### Enumeration type  
C#의 enum  

Design issues  
enum 이름이 겹치는 경우 

장점 : 가독성 증가, 신뢰성 증가(컴파일러 체크 가능, 연산 불가)

Reliability vs Writeability  
```cpp
1) Reliability
days nextDay(days d) {
    int i = d;
    i++;
    if(i == 7) i = 0;
    return (days)i;
}

2) Writeability
days nextDay(days d) {
    if (d == mon)
        return tue;
    else if(d == tue)
        return wed;
        ...
}
```
`1)`(정수로 변환이 가능한 경우)과 같이 코딩하면 유저가 실수 할 수 있다. 코드가 쉬워지며 가독성이 떨어진다.  
`2)`(변환 불가)은 코딩이 길어지고 실수가 적어진다.  

### Array Types  
**homogeneous aggregate(같은 종류의 집합체)** of data elements  

C 계열, Java에서는 배열과 원소의 자료형은 같아야한다.  
하지만, Javascript, Python, Ruby에서는 typeless reference라는 자료형을 넣게되면 다른 자료형의 포인터를 가질 수 있다.

- indexing (subscripting)  
인덱스를 넣으면 해당 원소를 매핑해준다.  
Fortran과 Ada는 () 사용 (함수 사용과 혼동 가능)  
나머지는 [] 사용  
index와 element 자료형이 다를 수 있다.  
do not specify range checking :  
C, C++ Perl, and Fortan 속도↑  
Perl은 array는 `@`을 붙여서 선언, `$`을 붙이고 인덱싱하여 접근  
인덱싱값이 음수인 경우에는 오른쪽 끝에서 절댓값만큼 인덱싱하면 된다. 그리고 배열에 값이 없을 때 `undef`을 참조시키며 오류를 보고하지 않는다.  

- Static array  
장점 : 효율성  
단점 : 메모리  
- Fixed stack-dynamic array  
단점 : 속도(할당 & 해지)
- Fixed heap-dynamic array  
장점 : 유연성  
- Heap-dynamic array (subscript range가 dynamic하다)  
장점 : 유연성  
단점 : 속도(할당 & 해지)  
![data](/TIL/images/Program_Language/data.JPG)  
Fixed는 생성시에 사이즈가 고정된다. Heap-dynamic을 제외하고 나머지 3가지는 subscript range가 스토리지에 할당 이후 lifetime 내내 바운딩 되어있다.  

- Array categories  
JavaScript 배열은 연속적이지 않아도 된다. C언어를 예를 들면 배열이 연속적이여야 하나, JavaScript같은 경우에는 0~9, 50 총 배열의 길이는 11이나, 인덱싱이 자유롭다. 인덱스가 없는 곳을 참조할 경우 `undefined`가 반환된다.  
Python, Ruby, Lua는 배열끼리 붙이거나 원소를 집어 넣을 때만 배열 크기가 증가한다.  

- Array Initialization  
C, C++, C#, Java는  
```cs
int list [] = {4, 5, 7, 83};
```  
배열의 길이를 컴파일러가 계산해준다.  
C와 C++은 
문자형 배열 즉 문자열도  
```c
char name [] = "freddie";
```  
자동으로 크기를 8을 할당해준다. (null-character)  
```c
char *name [] = {"Bob", "Jake", "Joe"};
```  
Java는 String을 기본 타입으로 인정하기 때문에
```java
String* [] names = {"Bob", "Jake", "Joe"};
```  
로 해야한다.  

- Operations  
대부분 할당, 비교, 배열끼리 붙이기, slice을 제공하지만 C언어는 아무것도 제공하지 않는다.  

- 다차원 배열의 모양  
    - Rectangular : row와 column의 수가 같다.(C#)  
    E.g `myArray[3,7]`  
    - Jagged : row와 column의 수가 다르다. (C, C++, C#, JAVA)  
    E.g `myArray[3][4]`  배열의 배열로 정의

- Slice  
    새로운 자료형이 아닌 정의된 배열의 부분배열이다.  
    ex) Python  
    ```py
    vector = [2, 4, 6, 8, 10, 12, 14, 16]
    mat = [ [1,2,3], [4,5,6], [7,8,9] ]
    ```
    vector[3:6]이라고 작성 인덱스 3부터 6번 이전까지 즉, [3,6)과 같은 개념이다. C++ string 라이브러리의 substr와 비슷하다.  
    mat[1] => [4,5,6]  
    mat[0][0:2] => [1,2]  
    vector[0:7:2] => [2,6,10,14]  
    이차원 배열인 경우는 해당 row을 반환하거나 row가 지정된 경우엔 column을 반환하면 된다.  
    마지막 slice는 인덱스 0부터 시작해서 인덱스 7까지 idx+=2 해서 반환한다.  

- 배열들의 주소 찾기  
1차원 배열인 경우  
address(list[k]) = address (list[lower_bound]) + ((k-lower_bound) * element_size)  
2차원 배열인 경우  
Location (a[i,j]) = address of a [row_lb,col_lb] + (((i - row_lb) * n) + (j -col_lb)) * element_size  
    - Row major  
    Row 부터 채워감 (대부분의 언어)
    - Column major  
    Column부터 채워감 (FORTRAN)  

- Associative Arrays (Dictional)  
순서가 없는 집합, 인덱싱을 key-value로 되는 배열  

ex) Perl  
array `@`로 선언 `$`로 접근  
Associative Array `%`로 선언 `$`로 접근  
e.g) %hi_temps = ("Mon" => 77, "Tue" => 79, "Wed" => 65, ...);
$hi_temps{"Wed"} = 83;
delete $hi_temps{"Tue"};  

### Record Types  
**heterogeneous aggregate(다른 종류의 집합체)**  
C언어에서 Struct  
배열에서는 인덱스를 숫자로했지만 레코드에서는 이름으로 접근한다.  

레코드에서 dot(.)을 이용해서 접근한다.  

### Tuple Types  
레코드와 비슷하나, 이름을 사용하지 않고 배열과 같이 순서대로 인덱싱한다.  

함수가 여러 값을 반환할 때 사용하기 좋다.  

ex) Python  
myTuple = (3, 5.8, 'apple')  
string과 같이 +으로 다른 튜플끼리 붙일 수 있다.  

ML  
var myTuple = (3, 5.8, 'apple');  

#1(myTuple)로 첫번째 원소에 접근 할 수 있다. 그리고 새로운 튜플타입을 선언할 수 있다.  
type intReal = int * real;

F#  
let tup = (3, 5, 7)  
let a, b, c = tup  

Tuple이 없는 C언어  
```c
1)
typedef struct _TwoValue {
    int intVal;
    float floatVal;
} TWO_VALUE;

TWO_VALUE f() {
    TWO_VALUE v;
    
    return v;
}
int main() {
    TWO_VALUE t;
    ...
    t = f();
}

2)
void f(int *ip, float *fp) {
    ...

    *ip = 3;
    *fp = 1.2f;
}
int main() {
    int i;
    float f;

    f(&i,&f);
}

// Tuple을 지원하는 C언어

tuple f() {
    ...
    return (3, 1.2f);
}
int main() {
    tuple t;
    ...
    t=f();
}
```
Tuple을 지원하지 않는다면 상당히 번거로워지고 C언어에서는 여러 반환값을 포인터를 이용해서 처리하고 있다. 하지만 가독성이 안 좋아서 Tuple을 사용할 수 있다면 좋다.  


### List Types
LISP와 Scheme  
`,`가 없이 사용한다.  
(A B C D) (A (B C) D)  
함수를 호출하는 경우와 똑같기 때문에 	`(A B C D) 구분한다.  

Operation
Car List 첫번째 원소  
Cdr List 첫번째 원소 제외한 원소들  
Cons List끼리 통합한다.  

ML  
Cons을 `::`로 대체해서 사용한다.  
3 :: [5, 7, 9] == Cons `3, (5, 7, 9)  
CAR과 CDR이 hd와 tl로 대체  

F# ≒ ML  

Python  
원소들의 타입이 달라도 된다.  
myList = [3, 5.8, "grape"]  
`x = myList[1]` x = 5.8  
`del myList[1]` 가능하며 이후에는 인덱스가 하나씩 땅겨짐  

**Comprehensions**  
[x * x for x in range(6) if x % 3 == 0]  
range(6) creates [0, 1, 2, 3, 4, 5, 6]  
∴ 나오는 리스트는 [0, 9, 36] x = 0 3 6  

### Unions Types  
여러개의 타입이 하나의 공간을 공유하는 형태  
공간은 개체중에서 가장 큰 사이즈가 해당 Union의 공간이다.  
메모리가 부족할 때는 많이 사용했으나, 지금은 많이 사용하지 않는다.  

Discriminated  
Type을 명시해서 사용하는 Union (Ada)  
Free Union  
Type checking을 하지않는 Union (C, C++, FORTRAN)  

```r
Ada Union
type Shape (Circle, Triangle, Rectangle);
type Colors is (Red, Green, Blue);
type Figure (Form: Shape) is record
    Filed: Boolean;
    Color: Colors;
    case Form is
        when Circle => Diameter: Float;
        when Triangle => Leftsid, Rightside: Integer;
        Angle: Float;
        when Rectangle => Side1, Side2: Integer;
    end case;
end record;
```
![Ada_union](/TIL/images/Program_Language/Ada_union.JPG)  
각각의 상황에 따라 메모리가 할당되는게 다르다.  

Java나 C#에서는 union을 지원하지 않는다.  
Free union은 안전하지 않지만 빠르다. (자료형검사 X)
Ada의 Descriminated union은 안전하지만 속도가 느리다.  

### Pointer and Reference Types  
Pointer랑 달리 Reference는 초기화가 필요하다.  

- Pointer Operation  
1) assignment(할당)
2) dereference(역참조 : 값 읽어오기)  

dereference는 implicit(묵시적), explicit(명시적) 가능함  

```c
int a = 10;
int *p;
int &b = a;

p = &a;
a = 20;
printf("%d",b); // 묵시적
printf("%d",*p); // 명시적
```

- Problems  
**Dangling pointers** (dangerous)  
```c
char *p;
p = (char *)malloc(100);
...
free(p);
...
*p = 'a'; // p is a dangling pointer
```
Lost heap-dynamic variable (memory leakage problem, dangling object, garbage)  
```c
void f() {
    char *p =(char *)malloc(100)  
    ...
    /p's content is lost!
}
```

Ada  
dangling pointer을 없애기 위해서 scope에 끝에서 자동으로 메모리를 해지한다. 하지만 메모리 누수는 일어날 수 있다.  

C, C++  
포인터 연산이 가능하다. *(p+i) == p[i]  
void * 포인터는 다른 타입의 포인터도 받을 수 있다.  
```c
int a = 10;
void *p = &a;
*p; // error;
* (int*)p; // ok;
```

Reference Types  
C++ Reference는 수정이 불가능하다.  
Java의 Reference는 수정이 가능하다.  
C#은 C++와 Java 두개 다 제공.  

**Dangling Pointer Problem Solution**  
1) Tombstone  
![Tombstone](/TIL/images/Program_Language/Tombstone.JPG)  
Tombstone : heap-dynamic variable  
묘비 메모리 해지시 nil값으로 유지
메모리↑ 시간↑
2) Lock-and-keys  	
![Lock-and-keys](/TIL/images/Program_Language/Lock-and-keys.JPG)  
Head-dynamic variable으로, Lock과 key가 같아야 접근이 가능하다.  
메모리↑ 시간↑

## Heap Management  
매우 복잡한 런타임 프로세스이다.  
Single-size cells vs variable-size cells (고정 vs 가변)  
single-size cell은 간단하지만 variable-size cell은 복잡해진다.

garbage 정리 방법  
1) **Reference counters** (eager approach)  
counter을 garbage들을 갯수만큼 유지한다. 꾸준히 정리한다.    
장점 : 지연이 없어 다른 방법들 보다 속도가 좋다.
단점 : 공간 낭비, counter 늘리고 줄이는 시간 필요  
2) Mark-sweep (lazy approach)  
마킹이 안된 것들을 한번에 정리  
![Mark-sweep](/TIL/images/Program_Language/Mark-sweep.JPG)  
메모리가 부족할 시에 Garbage Collection이 일어나고 root로 부터 dfs로 marking을 한다. Mark Phase가 끝나면 marking이 안된 것들을 해지하는 Sweep Phase가 일어난다.  
이 때, 프로그램 작동이 멈춘 다음 끝나고 작동이 재개한다.  
단점 : 지연 존재  

## Type Checking  

Compatible Type  
`void f(float b) {}`  
`f(3);`  
`3 + 1.2`  
컴파일러에서 자동으로 변환 시켜주는 것을 `coercion`이라고 한다. 안되면 프로그래머가 직접 형변환을 해줘야한다.  
Type Checking이 강하면 type error가 없지만 프로그래머의 부담이 늘어난다.  
이 전부 static하다면 type checking도 static하다.  
같은 말로 피연산자들이 전부 dynamic하다면 type checking도 dynamic하다.  
**strongly typed**  
프로그래밍언어가 strongly typed하면 컴파일 이후엔 type error가 없다. 예로는 ML과 Ada이다.  
다른 언어를 살펴보면 C와 C++은 Strong Type이 아니다. 매개변수 type check도 안하거나 union은 type check을 안한다.  
Coercion이 강해질수록 strong typing이 약화되므로 서로 상충관계로 있다.  
Name Type Equivalence : 구조가 같아도 이름이 다르다면 할당이 안된다. 이름이 같아야지 할당이 가능하다.  
구현은 쉬우나, 제약이 많다.  
Structure Type Equivalence : 이름이 다르더라도 구조가 같으면 할당이 가능하다.  
유연하게 프로그래밍이 가능하나 구현이 어렵다. 

### 요약
이름이 같으나 필드가 다를 때 같은 구조인가?  
인덱스가 다르나 길이가 같은 배열이 같은 배열인가?  
같은 구조와 같은 이름이지만 단위가 다른 경우 같은 구조인가?  
구현이 애매하다는 이유다.