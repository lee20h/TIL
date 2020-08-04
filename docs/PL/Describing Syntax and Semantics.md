---
sidebar: auto
---
# Describing Syntax and Semantics 

## 구문과 의미
- 구문 (syntax) : form 모양
- 의미 (Semantics) : 표현의 의미  

**Syntax**
lexeme : 가장 하위의 구문 단위, 최소단위  
token : lexeme의 범주, 종류  


## BNF && CFG
CFG (Context - Free - Grammar)  
- 문맥자유언어 클래스 정의
- 자연어 문법 기술함  

BNF (Backus - Naur Form)  
- 문맥 자유 문법에 속함
- 구문 변수 = 논터미널
- lexeme or token = 터미널

left hand side, right hand side  
-> 기준으로 왼쪽, 오른쪽

시작 심볼은 문법의 논터미널  

**Rules**(->)  
RHS 한개 이상  
재귀적으로 기술 가능  
시작 심볼에서 시작 후 끝은 무조건 **터미널 심볼**로 끝나도록 **유도**(=>)되어야한다.  

문장은 Sentential form  
터미널심볼은 Sentence  

Leftmost derivation  
맨 왼쪽 논터미널심볼 가장먼저 유도(확장)

파스트리 : 계층적으로 유도를 표현함  

## Ambiguous
하나의 문장에서 두개 이상의 파스트리 생성  


Unambiguous   expression grammar  
파스트리에 연산자의 **우선순위**를 주어줌  

연산자의 Associativity  
연산자가 동일한 우선순위을 가져 Ambiguous가 생기는 경우 left associativity, right associativity로 나눠서 왼쪽부터 or 오른족부터  

**ambiguous 해결**
1) 우선순위 부여  
2) 우선순위 같은 경우 associativity 부여  

`<expr> -> <expr> + <expr> | const` (ambiguous) 
`<expr> -> <expr> + const | const` (unambiguous)  

*Extended BNF*  
BNF ≒ Extended BNF  
**표현력은 같음**  
Optional []  
Alternative ()  
Repetitions {}  

## 요약
BNF와 CFG는 표현이 같다.