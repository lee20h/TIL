
# Implementing Subprograms

Call을 하게 되면 context switch에서 PCB에 저장해서 다시 복원하듯이 런타임 스택에 저장(push) 후 끝나면 다음 주소값으로 return(pop)하게 된다.  

## Simple Subprogram
Local 변수가 없고, nested가 없는 Subprogram이다.  
### Call Sematics  
1) 현재 실행상태를 스택에 저장
2) 매개변수 전달
3) 리턴값을 전달
4) 이동

### Return Sematics
1) Out mode라면 현재의 값을 actual parameter로 복사
2) 리턴이 함수라면 함수값이 리턴
3) 스택에 저장된 실행상태 복원  
4) 이동

필요한 저장소  
상태 정보, 매개변수, 리턴주소, 리턴 값이나 함수, 임시변수 - Stack에 저장. 따라서 재귀 가능  

Actual code와 non-code(data) 두 파트로 나눠져있다. 여기서는 **activation record**(non-code)에 대해서만 주로 다룬다.  
Activation record instance call할때마다 stack에 쌓이게 된다.
| Simple subprogram |
|:--------|  
| Local variables |
| Parameters |
| Return address |
이런 식으로 stack이 쌓인다.  

| Memory | Simple subprogram |
|:--------:|:--------:|  
| Code | Code |
| Data | Data |
| Heap | Data |
| Stack | Data |

### Typical Activation Record
| Typical Activation Record |
|:--------|  
| Local variables |
| Parameters |
| **Dynamic link** |
| Return address |
Stack을 사용하는데에 있어 이전의 Stack의 Top의 위치를 저장할 필요가 있어서 Dynamic link에 저장한다.  

Activation record 사이즈가 dynamic하다. 
Stack Pointer를 Environment Pointer라고도 한다.  
C의 예제
![Activation_record_c](/TIL/images/Program_Language/Activation_record_c.JPG)  

재귀 없이 ARI 그림(Activaiton record instance)  
지역변수 괄호로 표시  
main(p) calls fun1  
fun1(s,t) calls fun2  
fun2(y) calls fun3  
![ARI](/TIL/images/Program_Language/ARI.JPG)  
그림에서 Dynamic Link가 아닌 파란색 선으로 다시 표시했다.  

Dynamic Chain == Call Chain  
top을 기준으로 상대주소로 찾아 지역변수에 접근 할 수 있다. 지역변수의 상대위치는 컴파일 타임에 컴파일러에 의해 정해진다.  

### 재귀가 있을 때의 Activation record  
| Activation Record for factorial|
|:--------|
| Functional value |
| Parameters |
| **Dynamic link** |
| Return address |

재귀가 있을 때의 ARI 그림  
Call  
![ARI-Fact](/TIL/images/Program_Language/ARI-Fact.JPG)  

Return
![ARI-Fact-ret](/TIL/images/Program_Language/ARI-Fact-ret.JPG)  

그림으로 보고 이해 해야한다. 그림에서 또한 Dynamic Link가 호출자의 Top을 가르키도록 해야한다.  

C언어는 Nested subprogram이 지원하지 않아서 이전까지의 설명으로 충분하지만 다른 언어(FORTAN 95+, Ada, Python, JavaScript, Ruby, Lua)에서는 허용되므로 봐보자.  
변수의 이름이 같은 경우 먼저 맞는 ARI를 찾고 ARI에서의 Offset을 찾아야한다.  
Static-scope일 때는 이미 정해져있기 때문에 offset을 찾기 쉽다. 맞는 ARI를 찾기 위해서 Static-Scope에서 정한 방법은 Static link를 ARI에 가지고 부모 함수의 Top에 연결해준다. Static_depth가 the depth of nesting이다.  
Chain_offset or nesting_depth란 static_link을 몇번 따라갔는가이다. pair로 정의하면 (chain_offset, local_offset)으로 정의하면 된다.  

Ada의 예시
```r
procedure Main_2 is
  X : Integer;
  procedure Bigsub is
    A, B, C : Integer;
    procedure Sub1 is
      A, D : Integer;
      begin -- of Sub1
      A := B + C;  <-----------------------1
    end;  -- of Sub1
    procedure Sub2(X : Integer) is
      B, E : Integer;
      procedure Sub3 is
        C, E : Integer;
        begin -- of Sub3
        Sub1;
        E := B + A:   <--------------------2
        end; -- of Sub3
      begin -- of Sub2
      Sub3;
      A := D + E;  <-----------------------3
      end; -- of Sub2 }
    begin -- of Bigsub
    Sub2(7);
    end; -- of Bigsub
  begin
  Bigsub;
end; of Main_2 }
```
Call sequence for Main_2  
Main_2 calls Bigsub  
Bigsub calls Sub2  
Sub2 calls Sub3  
Sub3 calls Sub1  
이러한 순서로 이뤄져 있다.  

지금까지 했던 내용에서 추가해야할 내용은 **Static Link**의 경우 자기를 감싸는 함수(ancestor)의 ARI의 시작부분을 가르켜야한다.  

## Static Scoping

dynamic link는 전에 스택의 top pointer  
static link는 가장 가까운 static parent의 ARI의 시작부분이다.  

static parent을 찾는 두가지의 방법  
1) dynamic chain으로 전부 찾아보기
2) static depth을 이미 컴파일 타임에 알기 때문에 그 차이를 가지고 구한다.  

Static chain의 문제점  
non-local 변수에 대해 접근할려고 할 때 속도가 느려질 수 있다. 따라서 C언어에서는 non-local 변수는 글로벌 변수만 허용하며, nesting을 허용하지 않아서 속도를 저하시킬 요인을 없앴다.  

Block  
example C
```c
void f() {
	{int temp;
	temp = list[upper];
	list[upper]
 = list[lower];
	list[lower] = temp;
	}	
}

```
stack에 block을 더 쌓게 된다. 가독성은 증가할 수 있으나 실행속도에서는 저하한다. (컴파일러가 똑똑하면 가려줘서 해결이 되기도 함)  

## Dynamic Scoping
Dynamic Scoping을 지원하는 프로그래밍 언어일 때 static link는 필요없다.  
이 때 구현 방법 2가지
1) Deep Access : dynamic chain을 통해서 직접 검색함. 따라서 모든 ARI에 변수 이름을 저장할 공간을 가지고 있어야한다. 검색 시간도 오래걸린다 (worst : 전부 다 찾음)
2) Shallow Access : 변수 마다 스택을 만들어서 쓰이는 함수들을 하나씩 쌓아놓는다. 스택의 탑에 위치한 함수가 현재 쓰이는 위치이다.  
![Central-Table](/TIL/images/Program_Language/Central-Table.JPG)  
Central Table이 이렇게 구현이된다.  