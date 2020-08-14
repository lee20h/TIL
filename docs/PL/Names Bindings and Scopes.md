---
sidebar: auto
---
# Names, Bindings, and Scopes  

명령형언어는 폰노이만 아키텍쳐를 추상한다.  
- 명령과 데이터는 메모리에 저장된다.  
- cpu에 의해서 필요한 연산이 실행된다.  

명령형의 언어 피연산자를 담당하는 memory cell이 variables(변수)다.  

## 변수의 여러 속성
### Name  
변수의 이름, 함수의 이름, 매개변수 이름, 구조체  
Identifier와 상호호환되게 사용  

- Length  
    - 자유도 증가  
    - 컴파일타임 ↓  
    ∵ Symbol table에 넣음
    - 메모리 ↑  
    ∵ 런타임에 기록시 실행시간 ↓와 함께
- Form  
    - underscore (`_`)을 대체해서 Camel notation 사용  
    ScoreValue instead of score_value  
    - PHP  
    `$` 로 변수 선언  
    e.g. $scoreValue  
    - Perl  
    Scalar $  
    Array @  
    Hash %  
    변수 선언 
- Case sensitivity  
    - C기반 언어는 대소문자 구별한다. 이것은 가독성을 떨어트린다고 하는데 사람마다 다르다.  
- Special words  
    - 가독성을 높일 수 있지만 Reserved word(예약어)가 지정되있는 경우 피해야한다.  
    - 예약어가 많으면 유저가 예약어를 피해서 변수를 써야하지만 부족하다면 불편하다.  
	
### Variables  
변수는 memory cell을 매핑한것이다.  
특성 : name, address, value, type, lifetime, scope  

- Name  
    앞에서 정리한 것과 같다.  

- Address  
    - C Pointer와 같이 변수와 연관된 메모리의 주소이다.  
    - 변수가 함수 속에서 다른 주소를 가질 수 있다. (10강에서 계속)
    - L-value(변수의 주소)와 같다.  
    - Alias : 같은 주소에 다른 이름 (C 포인터 C++ 참조자) 가독성 저하  


- Type
    - 변수 값의 범위와 어떤 연산을 쓸지 결정한다.  

- Value
    - *Abstract memory cell* : 물리적 cell 이나 변수와 연관된 cell  
    - l-value : address  
    - r-value : value  
    
- **Binding**  
    권한과 속성 사이의 연관이다.  
    - 변수의 type과 value, operation과 symbol  
    binding time에 따라 static과 dynamic으로 나뉘어진다.  
    Language design time, implementation time, compile time은 static binding time  
    따라서, static binding은 
        1) 런타임 전
        2) 프로그램 실행 중 바뀌지 않으면  
    
    Load time과 Runtime, global은 dynamic binding time 은 dynamic binding time으로,  
    1) 실행중에 처음 발생하거나  
    2) 프로그램 실행 중에 바뀔 수 있으면
    dynamic binding이다.  

    Type Binding은 변수가 프로그램에 참조되기전에 자료형이 바운딩되어야한다. 만약 static binding인 경우 explicit 혹은 implicit 선언이 있어야한다.  

    Static Type Binding  
    - 명시적 선언  
        - 프로그래머가 직접 명시해서 선언하는 경우
    - 묵시적 선언  
        - 컴파일러가 자동으로 타입을 찾아내는 묵시적 선언
        - default convention  
        지정하지 않으면 자동으로 default에 들어감
            1) naming convention  
        Fotran에서 사용, 타이핑시에 잘못 치는 경우 잘못된 자료형이 바인딩되어 에러가 일어날 수 있다.   
            2) Using context  
            타입을 추론하는 방식 ex) var 타입 초기화 값을 보고 추정함 (컴파일 시간에 결정되므로 static)  
    
    Dynamic Type Binding  
    바인딩된 자료형 외의 다른 자료형으로 바뀌는 경우 (주소와 메모리셀이 바뀔 수 있음)

    장점 : 프로그래밍 유연성 ↑  
    type명시로 인한 재사용률 ↑  
    단점 : 신뢰성 ↓  
    변수들이 런타임에 새로운 자료형을 가질 수 있어서 메모리 ↑  
    타입체크를 해야하므로 속도 ↓
### Lifetime  
- 어떤 메모리 셀에 바운딩되냐에 따라 다르다.  
- static (data)  
    - 실행 전 메모리 셀에 바운딩
    - 실행 이후에 값 바뀌지 않음.
    - 재귀x
- dynamic (heap, stack) 
    - stack-dynamic (stack)  
        - 재귀 허용
        - 할당과 해지시의 오버헤드 존재
        - Subprogram이 history senstive하지 않다.
        - 비효율적인 참조(간접 주소)
    - explicit heap-dynamic(heap) 명시적 동적할당
        - 자료형은 컴파일 시간에 바운드 되지만 메모리에 적재는 런타임에 일어난다.  
        - new delete  
        - 동적으로 저장공간관리  
        - 복잡하거나 어렵다.
    - implicit head-dynamic(heap) 컴파일러가 할당 및 해제
        - 선언된 자료형과 다른 자료형으로 할당이 가능하다.
        - 높은 유연성
        - 런타임 오버헤드
        - 컴파일러가 오류 탐색기능 손실
        
### Scope  
scope란 쓰이고 읽히는 범위  
지역변수는 선언된 프로그램 유닛의 한정된다.

- nonlocal 변수  
    - 전역변수
- Scope rules  
    - nonlocal 변수에 대해서만 적용됨

- Static Scope  
사람이나 컴파일러가 실행 전에 소스만 보고 알 수 있으면 Static한 변수

    - **subprogram can be nested**
subprogram 중첩 가능
속도 ↓

    - subprogram cannot be nested  
subprogram 중첩 불가능
속도 ↑ (C기반언어)

```cpp
func big() {
    func sub1() {
        var x = 7;
        sub2();
    }
    func sub2() {
        var y = x; // x nonlocal 변수 (static scope일 때는 big의 x)
    }
    var x = 3;
    sub1();
}
```
big에 의해서 sub1에 `x`가 가려진 걸 `hidden` or `closer`변수라고 한다.

### Block
```cpp
void sub() {
    int count;
    while(...) {
        int count;
        count++;
        ...
    }
}
```
C와 C++에서는 허용하나, JAVA와 C#은 허용하지 않는다. 속도면에서는 좋지 않다. 할당과 해지 반복을 한다.

함수형 언어는 `let`키워드로 블록을 구성한다.  
Scheme
```s
(LET (
    (top (+ a b))
    (bottom (- c d))/ top bottom)
)
```
ML
```m
let
    val top = a + b
    val bottom = c -d
in
    top / bottom
end
```
추가적으로 함수언어는 매번 변수를 만들어서 사용한다.


Blcok의 Scope는 선언부터 Block 끝까지  

### Global Scope
블록 밖에서 전역변수로 정의되면 어디서든 사용할 수 있다.  
C언어에서는 오직 한번만 정의해야한다.
extern으로 다른 파일에서 특정한 변수를 받아와서 사용하는 것도 전역변수로 사용할 수 있다.

PHP의 경우에 전역변수를 사용할 때는 global로 선언하거나 $GLOBALS로 사용해야한다.

Python 또한, 전역변수와 지역변수가 이름이 같은 경우에는 명시적으로 global로 선언해주어야한다.

### Dynamic Scope  
	non-local 변수에 대해서는 실행시간에 콜체인을 따라가서 호출한 caller를 확인해야한다.

## **Scope 정리**  

```cpp
func big() {
	func sub1() {
		var x = 7;
		sub2();
	}
	func sub2() {
		var y = x;
	}
	var x = 3;
	sub1();
}
```
Static Scoping인 경우엔 sub2의 x를 big의 x를 참조한다.  
Dynamic Scoping인 경우엔 sub2의 x를 sub1의 x를 참조한다.  

Dynamic Scoping
- 장점 : 편리함
- 단점 : 구현 힘듬, 정적인 타입체크가 불가능, 가독성 저하

Scope와 Lifetime은 관련이 있지만 다른 개념이다. 

*referencing environment* : statement에서 보이는 모든 이름의 집합체  
- static-scoped : 콜스택 전체
- dynamic-scoped : 콜체인

*active* : subprogram이 콜 후 리턴 전  

- Named Constants  
상수들은 처음에 한번 값을 바운딩해주고 계속 사용된다.  
가독성과 변경하는데 용이하다는 장점이 있다.  
Ada, C++, JAVA는 동적으로 바운딩  
C#은 readonly(동적으로 바운딩), const(컴파일 시간에 바운딩) 두개 사용  
	- 초기화 :  
		static : 제한O  
		dynamic : 제한X