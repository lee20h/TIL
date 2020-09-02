# 📙 Today I Learned  
## 규칙  
* 기억에 남는 내용 기록 후 웹에 정리
* 쓸데없는 Commit 지양
* markdown으로 작성
* 1일 1문제(PS, SQL)이상 해결
* 문제 풀고 Problem Solving 폴더에 모으기

---  

| [5월](./month/5월) | [6월](./month/6월) | [7월](./month/7월) | [8월](./month/8월) |
|----|-----|-----|---|

---  

- 1日  

# SQLD 문제 풀이

- 데이터베이스 모델링

| 절차 | 설명 |
|---|---|
| 절차 | 설명 |
| 개념적 데이터 모델링 | 전사적인 데이터 모델로 기업 전체 데이터베이스 구조를 모델링한다. 높은 추상화 제공 |
| 논리적 데이터 모델링 | 재사용성이 높은 데이터 모델로 시스템을 구축하기 위한 데이터베이스 모델이다. 키, 속성, 관계 등을 표현 |
| 물리적 데이터 모델링 | 물리적 저장장치를 고려하여 저장장치에 맞게 데이터베이스를 구축한다. 데이터베이스 성능, 가용성, 보안 등을 고려 |  

- 반정규화

데이터베이스 성능을 향상시키기 위해서 데이터 중복, 통합, 분리, 집계 등을 수행하는 모델링 기법이다. 반정규화 기법은 테이블 병합, 분할, 추가 기법이다. 업무처리를 위한 기능칼럼 추가는 반정규화가 아니다. 

- 상호연관 서브쿼리

메인쿼리 값을 서브쿼리가 사용하고 서브쿼리의 값을 받아서 메인쿼리의 값을 받아서 메인쿼리가 계산되는 쿼리이다.  

- 정규형

1차 정규형 : 모든 속성은 반드시 하나의 값, 속성 값의 중복 제거  
2차 정규형 : 식별자에 종속되지 않는 속성의 중복 제거  
3차 정규형 : 2차 정규형을 만족하며, 식별자 외 일반 칼럼간의 종속 존재 제거  

- 유일 인덱스 스캔 (Unique Index Scan)

기본키 또는 유니크 인덱스로 엑세스 가능  

인덱스 : 원하는 데이터를 빠르게 찾기 위해 탐색키를 갖는 테이블로, 원하는 데이터를 쉽게 찾을 수 있게 돕는 책의 색인과 비슷한 개념  

인덱스 특징 : 테이블 기반으로 선택적으로 생성할 수 있는 구조.  
테이블에 인덱스를 생성하지 않아도 되고 여러 개 생성 가능.  
Insert, Update, Delete 등 DML 작업은 테이블과 인덱스를 함께 변경하므로 느려 질 수 있음  

- 속성

엔터티는 2개 이상의 속성으로 구성.  
속성은 엔터티를 설명하고 인스턴스의 구성요소.  
하나의 속성은 하나의 값을 갖음.  
속성의 특성 : 기본 속성, 설계 속성, 파생 속성  

- 순번을 구하는 그룹함수

RANK 함수 : ORDER BY를 포함한 쿼리문에서 특정 항목에 대한 순위를 구하는 함수이다. 이 때 특정범위 (PARTITION BY) 내에서 순위를 구할수도 있고 전체 데이터에 대한 순위를 구할 수도 있다.  
동일한 값에 대해서는 동일한 순서를 부여하게 된다.  

DENSE_RANK 함수 : 동일한 순위를 하나의 건수로 취급한다.  

ROW_NUMBER 함수 : ROW_NUMBER 함수는 동일한 값이라도 고유한 순위를 부여한다.  

동일한 값의 순위를 정해야 할 때 오라클의 경우 ROWID가 적은 행이 먼저 나온다.  

만약 동일 값에 대한 순서까지 관리하고 싶으면 ROW_NUMBER() OVER (ORDER BY SAL DESC, ENAME)을 같이 ORDER BY 절을 이용해 추가적인 정렬기준은 정의해야한다.

---

- 2日  

# SQLD 정리

## SQL 기본

- DDL : Table － Partition : range, List, Hash Partition

- DML : insert, update, delete, select

- DCL : grant, revoke

- TCL : commit, rollback

## Join

- 순수관계

	1. SELECT
	2. PROJECT
	3. (Natural) JOIN
	4. Divide

- 일반 집합연산

	1. union
	2. intersect
	3. minus, except
	4. product

- FROM절 Join

	1. Inner Joint Select
	2. Natural Join
	3. Outer Join
	4. Cross Join
	5. USING
	6. ON 조건절

## 데이터 모델링

- 3층 스키마 

	1. 외부 스키마 : 사용자 관점, View 단계
	2. 개념 스키마 : 데이터 통합 및 조직 전체의 DB 구조
	3. 내부 스키마 : 물리적 저장

- 데이터 모델링

	- 3가지 요소 : Thing, Attribute, Relationship

	- 절차 
		1. 개념적 : 높은 추상화, 포괄적, EA 수립
		2. 논리적 : 재사용성, 정규화
		3. 물리적 : 성능, 저장 등 물리적 특성

- 관계형 DB

	- Entity
		- 조건 : 업무에서 관리
		- 종류 : 유무(유형, 개념, 사건) , 발생 시점  (기본, 중심, 행위)

	- 정규화 : 완전 함수 종속성, 부분 함수, 이행 함수, 후보키가 기본키에 종속

	- Attribute : 하나의 속성 = 하나의 값, 기본-설계-파생 속성, 종류(단일 값, 복합, 다중 속성)

	- 관계 : 종류(존재관계, 행위관계), 관계 차수, Check, 식별과 비식별 관계

	- 반정규화 : 대상(범위, 용량, 통계, 조인 수), 다른 방법 유도(클러스터링, 뷰, 인덱스 조정), 반정규화 적용(테이블, 속성, 관계 반정규화)

	- 식별자 : 대표성(주, 보조), 생성여부(내부, 보조), 속성 수(단일, 복합), 대체여부(본질, 인조)

## Optimizer

- SQL Operation

	1. AND-EQUAL : INDEX에 의해서 반환된 ROWID를 병합해서 공통값으로 변환
	2. CONCATNATION : 반환되는 ROW를 합산(UNION, UNION ALL)
	3. Connect by : 계층형 Query
	4. Count : Count(*) 집계 함수 사용
	5. Filter : Where절의 조건절을 사용하지 못함
	6. For update : Row Level Lock이 발생하는 연산
	7. Hash Join : 해시 조인
	8. Hash anti Join : 한쪽 Row를 추출할 때 다른 쪽 Row와 매칭되지 않은 것을 추출 (Not in, Not Exist, minus)
	9. Hash Semi Join : Exists절을 사용하느 세미 조인(hash_sj or merge_sj 힌트 사용)
	10. Index Range Scan : `<`, `>` between, like 사용
	11. Index unique Scan
	12. Inlist iterator : inlist에 있는 인수만큼을 반복
	13. itersection : 여러 쿼리의 반환 결과값을 병합해서 공통 부분만 추출
	14. Nested Loop : 중첩 루프를 사용해서 조인
	15. Merge Join : Sort와 Merge 단계로 조인
	16. Merge Semi Join
	17. minus : 차집합

- Sub Query

	- Scalar : 한 행을 리턴하는 서브쿼리로 Select 절에 존재
	- Inline View : FROM절에 서브 쿼리 사용
	- 연관 Subquery : 메인쿼리 조건절이 서브쿼리에 사용, 메인쿼리의 칼럼이 서브쿼리에서 사용
	- Filter형 Subquery : 확인자, 메인쿼리에 주입을 받아 확인자, 조인으로 풀리지 않음
	- Early Filter형 Subquery : 서브쿼리가 메인쿼리로 푸쉬되면서 먼저 실행 (push_subq 힌트)
	- Access형 Subquery : 메인쿼리에 값을 제공하는 제공자( 단일 값 서브쿼리), 서브쿼리가 먼저 실행됨, join으로 풀림
	- 멀티값 서브쿼리 : 여러 개의 행을 되돌림(IN, ANY, ALL EXISTS 사용)


- Optimizer Join

	- Nested Loop : 중첩 for문, 소량의데이터. Random Access가 최소화. 힌트 ordered use_nl

	- Sort Merge : Sort 단계와 병합 단계, 병렬로 실행. 힌트 use_merge

	- Hash Join : 등가조인에 사용, 작은 테이블이 드라이빙 테이블이 되어야함. CPU 과다사용, Random Access 최소화. 힌트 use_hash

---

