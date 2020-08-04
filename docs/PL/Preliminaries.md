---
sidebar: auto
---
# Preliminaries

## 언어를 평가하는 요소
1) Readability (주관적일 수 있다)  
	- simplicity
	- orthogonality
	- data type
2) Writability (주관적일 수 있다)
	- simplicity
	- orthogonality
	- support for abstraction
3) Reliability (ex. type error) Writability와 반비례
	- type checking (C언어는 type unsafety)
	- exception handling (C언어 제공x, c++ java 제공)
	- aliasing ( ex) 포인터)
4) Cost  
	- 교육비용
	- 작성비용
	- 컴파일비용
	- 실행비용
	- 유지보수비용 등
5) Others
	- Portability
	- Generality

## 언어 설계에 영향을 주는 2가지 정리
- 하드웨어
- 당시대 사람들의 Needs  
	- 50-60년대 간단한 프로그램
	- 60년대 fortran
	- 70년대 프로세스지향, 데이터지향적 프로그래밍 (자료 추상화)
	- 80년대 중반 객체지향 프로그래밍 (자료 추상화 + 상속 + 다형성)  

## 구현 방법
- 컴파일
	- 프로그램을 기계어로 번역한다. 속도↑ 개발↓
- 인터프리터 방식
	- 인터프리터를 통해 번역한다. 속도↓ 개발↑
- 하이브리드 방식
	- 컴파일러와 인터프리터 타협 ex) Java  

### 컴파일
고급언어 -> 저급언어  
속도↑ 개발↓ (Slow Translation, Fast execution)  
어휘분석은 토큰으로 나눠서 분석
구문분석은 토큰들을 파스트리로 변환해서 분석  

![Compilation](/images/Program_Langauge/Compilation.JPG)

컴파일 순서  
컴파일-링킹-로딩-실행  
c - obj - exe - procese 등록  

메모리 영역  
- code
- data
- heap
- stack  

폰 노이만의 병목현상(bottleneck)  
연결 속도보다 instruction이 빠르게 되면 일어난다. 컴퓨터의 속도 한계 주요원인이다.  
cpu와 메모리 사이에는 cache가 존재해서 극복한다.  

### 인터프리터
기계어 번역x  
실행속도 느림 (컴파일보다 10~100배 느림)  
가끔 더 많은 공간 요구  
지금까지 고급언어로는 적게 사용됨  

과정
소스 + 입력 데이터 -> 인터프리터 -> 결과  
- 메모리多 속도↓  

### 하이브리드  
컴파일러와 인터프리터 사이  
고급언어 -> 중간언어 (해석이 쉬움)  
인터프리터보단 빠름  
초기 JAVA가 하이브리드  

추가적으로, Just-in-Time Implementation Sysmtems  
하이브리드와 같이 중간언어 사용  
처음 호출에는 하이브리드 중간언어 사용  
두번째 이후 호출에서는 컴파일 기계언어 사용  

## 요약
- 프로그래밍 언어 평가요소 4가지
	- 가독성
	- 쓰기가능성
	- 신뢰성
	- 비용  
- 언어 설계 영향 요인
	- 하드웨어
	- 사람들의 니즈
- 프로그래밍 언어 해석 방법 3가지
	- 컴파일
	- 인터프리팅
	- 하이브리드  