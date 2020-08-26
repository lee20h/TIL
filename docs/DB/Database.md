---
sidebar: auto
---

# Database

## SQLD 데이터 모델링의 이해  

### 데이터 모델링
데이터 모델링의 특징
- 추상화
- 단순화
- 명확성  

데이터 모델링 단계  
- 개념적 모델링 : 추상화 수준이 가장 높으며, 업무 측면에서 모델링
- 논리적 모델링 : 정규화를 통해서 재사용성을 높임
- 물리적 모델링 : 성능, 보안, 가용성 등을 고려하여 데이터베이스 구축

데이터 모델링 관점
- 데이터
- 프로세스
- 데이터와 프로세스  

데이터 모델링을 위한 ERD  
1) 엔터티를 도출하고 그린다.
2) 엔터티를 배치한다.
3) 엔터티 간의 관계를 설정한다.
4) 관계명을 서술한다.
5) 관계 참여도를 표현한다.
6) 관계의 필수 여부를 표현한다.  


데이터 모델링을 위한 ERD  고려사항
- 중요한 엔터티를 왼쪽 상단 배치
- ERD는 이해가 쉬워야하며, 너무 복잡하지 않게 해야함  

데이터 모델링 고려사항
- 데이터 모델의 독립성  
- 고객 요구사항의 표현  
- 데이터 품질 확보  

### **3층 스키마**  
- 외부 스키마 : 응용 프로그램이 접근하는 데이터베이스
- 개념 스키마 : 통합 데이터베이스 구조, 전체 데이터베이스 내의 규칙과 구조 표현
- 내부 스키마 : 개발자 관점으로, 데이터베이스의 물리적 저장 구조

| 독립성 | 설명 |
|:-----:|---|
| 논리적 독립성 | 개념 스키마가 변경되더라도 외부 스키마 영향X |
| 물리적 독립성 | 내부 스키마가 변경되더라도 개념 스키마 영향X |

### **엔터티**
엔터티 : 업무에서 관리해야 하는 데이터 집합, 저장되고 관리되어야 하는 데이터  

엔터티의 특징
- 식별자 : 유일한 식별자
- 인스턴스 집합 : 2개 이상의 인스턴스
- 속성 : 반드시 속성가져야 함
- 관계 : 다른 엔터티와 최소한 한 개 이상 관계
- 업무 : 업무에서 관리되어야 하는 집합  

엔터티의 종류  
- 유형과 무형에 따른 종류
  - 유형 엔터티 : 물리적 형태 O
  - 개념 엔터티 : 물리적 형태 X
  - 사건 엔터티 : 비즈니스 프로세스 실행하면서 생성
- 발생 시점에 따른 종류
  - 기본 엔터티 : 키 엔터티, 독립적 생성
  - 중심 엔터티 : 기본 엔터티와 행위 엔터티 중간
  - 행위 엔터티 : 2개 이상의 엔터티로부터 발생

### 속성
속성의 특징
- 하나의 값만 가짐
- 업무에서 관리되는 정보
- 주식별자에게 함수적으로 종속. 즉, 기본키가 변경되면 속성의 값도 변경

속성의 종류
- 분해 여부에 따른 종류
  - 단일 속성 : 하나의 의미
  - 복합 속성 : 여러 개의 의미
  - 다중값 속성 : 속성에 여러 개의 값 가짐, 엔터티로 분해됨
- 특성에 따른 종류
  - 기본 속성 : 본래의 속성
  - 설계 속성 : 데이터 모델링 과정에서 발생되며 유일한 값 부여
  - 파생 속성 : 다른 속성에 의해서 만들어짐

### 관계
관계의 종류
- 존재 관계 : 엔터티 간의 상태
- 행위 관계 : 엔터티 간의 어떤 행위

관계 차수 : 두 개의 엔터티 간에 관계에 참여하는 수  
관계 차수의 종류
- 1대1 관계 : 완전 1대1(엔터티와의 관계가 하나이며, 반드시 존재), 선택적 1대1(엔터티와의 관계가 하나이거나 존재X)
- 1대N 관계 : 엔터티에 행이 하나 있을 때 다른 엔터티의 값이 여러 개
- M대N 관계 : 두 개의 엔터티가 서로 여러 개의 관계, RDBMS에서는 M대N 관계이 Join은 카테시안 곱이므로 1대N, N대1로 해소  
- 필수적 관계와 선택적 관계

식별 관계와 비식별 관계
- 식별 관계
  - 독립적으로 존재하는 강한 개체
  - 다른 엔터티와 관계에서 기본키 공유
  - 강한 개체는 식별 관계로 표현
  - 기본 키 값이 변경되면 식별관계의 엔터티의 값도 변경
  - 공유 받은 엔터티는 약한 개체(외래키)
  - 식별 관계는 실선
- 비식별 관계
  - 강한 개체의 기본키를 다른 엔터티에서 일반 칼럼으로 관계를 가짐
  - 비식별 관계는 점선

### 엔터티 식별자
- 식별자의 종류
  - 대표성 여부에 따른 종류
    - 주식별자
      - 최소성
      - 대표성
      - 유일성
      - 불변성
    - 보조 식별자 : 대표성 X
      - 유일성
      - 최소성
  - 생성 여부에 따른 종류
    - 내부 식별자 : 엔터티 내부에서 스스로 생성됨
    - 외부 식별자 : 다른 엔터티와의 관계로 인해 만들어짐
  - 속성의 수에 따른 종류
    - 단일 식별자 : 하나의 속성
    - 복합 식별자 : 두 개 이상의 속성
  - 대체 여부에 따른 종류
    - 본질 식별자 : 비즈니스 프로세스에서 만들어짐
    - 인조 식별자 : 인위적으로 만들어짐

- 키의 종류
  - 기본키 : 후보키 중 엔터티 대표
  - 후보키 : 유일성과 최소성 만족
  - 슈퍼키 : 유일성 만족, 최소성 만족 X
  - 대체키 : 여러 개의 후보키 중에서 기본키를 선정하고 남은 키
  - 외래키 : 하나 혹은 다수의 다른 테이블의 기본 키 필드를 가리키는 것으로 **참조 무결성** 확인에 사용됨, 허용된 데이터 값만 DB에 저장을 위해서 사용

## 데이터 모델과 성능
### 정규화
- 데이터의 일관성
- 최소한의 데이터 중복
- 최대한의 데이터 유연성

| 정규화 절차 | 설명 |
|----------|-------|
| 제1정규화 | 속성의 원자성 확보, **기본키 설정** |
| 제2정규화 | 기본키가 2개 이상의 속성이면, **부분 함수 종속성**을 분해 |
| 제3정규화 | 기본키를 제외한 칼럼 간에 종속성 제거, **이행 함수 종속성**을 제거 |
| BCNF | 기본키를 제외하고 후보키가 있는 경우 후보키가 기본키를 종속시키면 분해 |
정규화는 제5정규화까지 있으나 실질적으로는 제3정규화까지만 실행된다.  

정규화의 문제점
- 데이터 양이 증가하면 비교 건수 증가
- Join이 부하 유발 -> 성능 저하

### 반정규화
- 데이터베이스의 성능 향상을 위하여, 데이터 중복 허용함 조인 줄이는 성능 향상 방법
- SELECT 속도 향상, 데이터 모델의 유연성 하락(중복 허용)

반정규화 필요한 경우
- 정규화로 인한 수행 속도 느린 경우
- 다량의 범위 자주 처리해야 하는 경우
- 특정 범위의 데이터 자주 처리하는 경우
- 요약/집계 정보가 자주 요구되는 경우

반정규화 절차
- 대상 조사 및 검토 : 데이터 처리 범위, 통계성 등을 확인하여 반정규화 대상 조사
- 다른 방법 검토 : 클러스터링, 뷰, 인덱스 튜닝, 응용 프로그램, 파티션을 검토
- 반정규화 수행 : 테이블, 속성, 관계, 등을 반정규화

반정규화 기법
- 계산된 컬럼 추가 : 값 등을 계산하고 결과를 특정 칼럼에 추가
- 테이블 수직분할 : 하나의 테이블을 두개 이상의 테이블로 분할, 즉 칼럼 분할
- 테이블 수평분할 : 하나의 테이블에 있는 값을 기준으로 테이블 분할
- 테이블 병합 : 1대1의 관계의 테이블을 하나의 테이블로 병합하여 성능 향상, 1대N 관계의 테이블도 마찬가지나, 많은 양의 데이터 중복 발생, 슈퍼 타입과 서브 타입 관계가 발생시 통합하여 성능 향상

슈퍼 타입 및 서브 타입 변환 방법
- OneToOne Type : 슈퍼 타입과 서브 타입을 개별 테이블로 도출
- Plus Type : 슈퍼 타입과 서브 타입 테이블로 도출
- Single Type : 슈퍼 타입과 서브 타입을 하나의 테이블로 도출

### 분산 데이터베이스
중앙 집중형 데이터베이스 : 한 대의 물리적 시스템에 DBMS 설치 후 여러 명이 사용  
분산 데이터베이스 : 물리 적으로 떨어진 데이터베이스에 네트워크로 연결하여 분산된 작업 처리  

분산 데이터베이스의 투명성 종류
- 분할 투명성
- 위치 투명성
- 지역 사상 투명성
- 중복 투명성
- 장애 투명성
- 병행 투명성

분산 데이터베이스 설계 방식
- 상향식 설계 방식 : 지역 스키마 작성 후 전역 스키마 작성
- 하향식 설계 방식 : 전역 스키마 작성 후 지역 스키마 작성

분산 데이터베이스의 장단점  
장점
- 데이터베이스 **신뢰성과 기용성**이 높다
- 분산 데이터베이스가 병렬 처리를 수행하기 때문에 **빠른 응답** 가능
- 분산 데이터베이스를 추가하여 시스템 **용량 확장**이 쉽다

단점  
- 데이터베이스가 여러 네트워크를 통해서 분리되어 있기 때문에 **관리와 통제가 어렵다**
- 보안관리가 어렵다
- 데이터 **무결성 관리가 어렵다**
- 데이터베이스 **설계가 복잡하다**

## SQL 기본
### 관계형 데이터베이스
- 릴레이션에 데이터 저장, 관리
- 릴레이션을 사용해서 집합 연산과 관계 연산 가능

집합 연산
- 합집합(Union)
- 차집합(Difference)
- 교집합(Intersection)
- 곱집합(Cartesian product)

관계 연산
- 선택 연산(Selection)
- 투영 연산(Projection)
- 결합 연산(Join)
- 나누기 연산(Division)

테이블의 구조
- 기본키 : 하나의 테이블에서 유일성, 최소성 Not Null 만족하며 테이블을 대표
- 행 : 하나의 테이블에 저장되는 값, 튜플
- 칼럼 : 어떤 데이터를 저장하기 위한 필드, 속성
- 외래키 : 다른 테이블의 기본키를 참조(조인)하는 칼럼, Join을 하기 위해 사용

### SQL의 종류
- DDL(Data Definition Language) : 관계형 데이터베이스의 구조 정의 언어 (Create, Alter, Drop, Rename)
- DML(Date Manipulation Language) : 테이블에서 데이터를 입력, 수정 조회 (Insert, Update, Delete, Select)
- DCL(Data Control Language) : 데이터베이스 사용자에게 권한을 부여하거나 회수 (Grant, Revoke, Trumcate)
- TCL(Transaction Control Language) : 트랜젝션을 제어하는 명령어 (Commit, Rollback, Savepoint)

트랜잭션의 특성  
- 원자성 : 데이터베이스 연산의 전부가 실행되거나 전혀 실행되지 않아야함 (트랜잭션의 처리가 끝나지 않은 경우 실행되지 않은 상태와 동일해야함)
- 일관성 : 트랜잭션 실행 결과로 데이터베이스의 상태가 모순되지 않아야 함
- 고립성 : 트랜잭션 실행 중 생성하는 연산의 중간결과는 다른 트랜잭션이 접근할 수 없음
- 영속성 : 트랜잭션이 실행을 완료하면 그 결과는 영구적 보장

SQL문의 실행 순서  
1) 파싱 : SQL문의 문법 확인 후 구문 분석
2) 실행 : 옵티마이저가 수립한 실행 계획에 따라 SQL 실행
3) 인출 : 데이터 읽어서 전송

### DDL
- Create Table : 테이블 생성, 기본키, 외래키, 제약사항 등 설정
- Alter Table : 테이블 변경, 칼럼 추가 변경 삭제, 기본키나 외래키 설정
- Drop Table : 해당 테이블 삭제 (구조와 저장된 데이터 삭제)

**테이블 생성**  
```sql
Create Table EMP
(
  empno number(10) primary key,
  ename varchar2(20),
  sal   number(6)
)
```
칼럼 이름과 데이터 타입을 입력한다. 칼럼 이름은 영문, 한글, 숫자 모두 가능하다.  
varchar은 가변 길이 문자열, char은 고정 길이 문자열이다.  

제약조건 사용  
기본키, 외래키, 기본값, not null 등 테이블 생성시에 지정 가능하다.  
`constraint`을 사용하여 기본키와 기본키의 이름을 지정하며, 외래키 지정 가능
```sql
constraint depttk foreign key (deptno)
    references dept(deptno)
```
`default`을 이용하여 기본 값을 지정  
`sysdate`로 오늘 날짜 시분초를 지정  
`CASCADE`옵션을 외래 키 설정 후 지정할 수 있다. 예로 ON DELETE CASCADE를 통해서 기본키가 사라지면 외래키도 사라지게 하여 **참조 무결성**을 지킬 수 있다.  

**테이블 변경**
- 테이블명 변경  
`ALTER TABLE ~ RENAME TO`문 사용  
- 칼럼 추가  
`ALTER TABLE ~ ADD`문 사용
- 칼럼 변경  
`ALTER TABLE ~ MODIFY`문 사용  
- 칼럼 삭제  
`ALTER TABLE ~ DROP COLUMN`문 사용
- 칼럼명 변경  
`ALTER TABLE ~ RENAME COLUMN ~ TO`문 사용

**테이블 삭제**  
`DROP TABLE`을 통해서 다 삭제 할 수 있으며, `CASCADE CONSTRAINT`옵션을 사용할 수 있다. 해당 참조된 제약사항까지 모두 삭제하는 옵션이다.  

**뷰(VIEW) 생성과 삭제**  
뷰란 테이블로부터 유도된 가상의 테이블로 실제 데이터는 가지고 있지 않지만 테이블을 참조해서 원하는 칼럼만을 조회할 수 있게한다. 따라서 SQL문 형태로 저장되어 실행 시에 참조 된다.  

뷰의 특징
- 참조한 테이블 변경 시 뷰도 변경
- 뷰에 대한 입력, 수정, 삭제에 제약
- 특정 칼럼만 조회시켜 보안성 향상
- 뷰 변경이 불가하여 재생성 해야함
- ALTER문 사용 불가

뷰의 장점
- 보안 기능
- 데이터 관리 간단
- SELECT문 간단
- 한 테이블에 여러 뷰 가능

뷰의 단점
- 독자적인 인덱스 불가
- 삽입, 수정, 삭제 연산 제약
- 데이터 구조 변경 불가

### DML
**INSERT**
1) INSERT문 사용
```sql
INSERT INTO table (column1, column2, ...) VALUES (expression1, expression2, ...);
```
테이블명, 칼럼명, 데이터 순으로 입력  

2) SELECT문 사용

```sql
INSERT INTO DEPT_TEST
  SELECT * FROM DEPT;
```

3) Nologging 사용

데이터베이스에 데이터 입력받을 때 check point 이벤트가 발생하면 로그파일의 데이터를 데이터 파일에 저장한다. 이 때 기록을 최소화 시켜서 입력 시 성능을 향상하는 방법이 Nologging옵션이다. 이 옵션은 Buffer Cache 메모리 영역을 생략하고 기록한다.  

**UPDATE**  
값을 수정하기 위해서 사용
```sql
UPDATE EMP
  SET ENAME = '조조'
WHERE EMPNO = 100;
```
조건문을 입력하지 않으면 모든 데이터가 수정되므로 유의!  

**DELETE**  
값을 삭제하기 위해서 사용
```sql
DELETE FROM EMP
WHERE EMPNO = 100;
```
조건문을 입력하지 않으면 모든 데이터가 삭제되며, 데이터가 삭제되어도 테이블의 용량이 초기화되지 않는다.  

TRUNCATE  
`DELETE`와 다르게 삭제시에 테이블의 용량이 초기화된다.
```sql
TRUNCATE TABLE 테이블명;
```

**SELECT**  
특정 칼럼을 조회한다.
```sql
SELECT *
FROM EMP
WHERE 사원번호 = 1000;
```

문법
- SELECT * : 모든 칼럼 출력
- FROM EMP : FROM절에서 테이블 명 기입
- WHERE 사원번호 = 1000 : 조건문 지정

**ORDER BY**
- SELECT 문에서 정렬 가능
- 오름차순 내림차순 가능 ASC, DESC
- 정렬시점은 모든 실행이 끝난 뒤 데이터 출력 바로 직전
- 데이터베이스 메모리 사용. 따라서 정렬로 인한 성능 저하 발생가능  

**INDEX를 사용한 정렬 회피**
정렬은 데이터베이스에 부하를 주므로 인덱스를 사용하여 `ORDER BY`를 피할 수 있다.  
기본 키를 기준으로 오름차순으로 정렬된다.  
또한 INDEX 힌트를 줄 수 있다.
```sql
SELECT /*+ INDEX_DESC(A) */
FROM EMP A;
```
기본 키를 기준으로 먼저 인덱스가 생성이 되고 그 인덱스에서 테이블로 매핑되는 방식인데 이때, 인덱스를 오름차순이나 내림차순으로 정렬할 수 있다.  

**DISTINCT와 ALIAS**  
1) DISTINCT  
중복데이터 제거
2) ALIAS  
`AS`키워드를 통해서 별칭을 지정해줄 수 있다.  

**WHERE**  
비교 연산자
- `=`
- `<`
- `<=`
- `>`
- `>=`

부정 연산자
- `!=`
- `^=`
- `<>`
- `NOT 칼럼 =`
- `NOT 칼럼 >`

논리 연산자
- `AND`
- `OR`
- `NOT`

SQL 연산자
- `LIKE '%비교 문자열%'` (%, _)
- `BETWEEN A AND B`
- `IN (list)`
- `IS NULL`
- `NOT BETWEEN A AND B`
- `NOT IN 'list;`
- `IS NOT NULL`

**NULL의 특징**
- 모르는 값
- 값의 부재
- NULL과 숫자, 날짜 연산 = NULL
- NULL과 값 비교 = 알 수 없음

NULL 값 조회  
IS NULL, IS NOT NULL 사용  

NULL 관련 함수
- NVL 함수 : NULL이면 다른 값으로 바꾼다. `NVL(MGR,0)`
- NVL2 함수 : NVL 함수와 DECODE 함수를 하나로 만듬. `NVL2(MGR,1,0)`
- NULLIF 함수 : 두 개의 값이 같으면 NULL, 아니면 첫 번째 값 반환. `NULLIF(EXP1, EXP2)`
- COALESCE : NULL이 아닌 최초의 값 반환. `COALESCE(EXP1, EXP2, EXP3, ...)`  

**GROUP BY**  
테이블에서 소규모 행을 그룹화하여 합계, 평균, 최댓값, 최솟값 등 계산하는 집계함수 사용 가능하다.  

**HAVING문**  
WHERE절과 비슷하나, HAVING문은 GROUP BY의 조건절이다. WHERE절을 사용하게 되면 GROUP BY대상에서 제외되는 데이터가 생길 수 있다.  

**집계 함수**  
- COUNT()
- SUM()
- AVG()
- MAX(), MIN()
- STDEEV()
- VARIAN()

**SELECT문 실행 순서**
1) FROM
2) WHERE
3) GROUP BY
4) HAVING
5) SELECT
6) ORDER BY

**형변환**
명시적 형변환 함수
- TO_NUMBER(문자열) : 문자열 -> 숫자
- TO_CHAR(숫자 혹은 날짜, [FORMAT]) : 숫자 혹은 날짜 -> FORMAT 문자
- TO_DATE(문자열, FORMAT) : 문자열 -> FORMAT의 날짜형  

**내장형 함수(BUILT-IN FUNCTION)**
DUAL TABLE : Oracle 데이터베이스에 의해서 자동으로 생성되는 임시 테이블로, 내장형 함수를 실행할 때 사용 가능하다.  

내장 함수 종류
- ASCII
- CHAR
- SUBSTR
- CONCAT
- LOWER
- UPPER
- LENGTH OR LEN
- LTRIM
- RTRIM
- TRIM
- SYSDATE
- EXTRACT('YEAR'|'MONTH'|'DAT' FROM DUAL)
- ABS
- SIGN
- MOD
- CEIL/CEILING
- FLOOR
- ROUND
- TRUNC

**DECODE, CASE**
DECODE  
IF문과 같이 조건이 참이면 A, 거짓이면 B  
```sql
DECODE (EMPNO, 1000, 'TRUE', 'FALSE')
```

CASE  
IFELSE문과 같이 조건을 나열하여 해당하면 실행하며, 다 거짓인 경우 ELSE문 실행  
```sql
CASE [EXPRESSION]
  WHEN CONDITION_1 THEN RESULT_1
  WHEN CONDITION_2 THEN RESULT_2
   ...
  WHEN CONDITHION_N THEN RESULT_N
  ELSE RESULT
END
```

**ROWNUM, ROWID**
ROWNUM  
Oracle 데이터베이스의 SELECT문 결과에 논리적 일련번호 부여한다. 따라서 조회되는 행 수를 제한할 때 많이 사용된다. 페이지 단위 출력을 하기 위해선 인라인 뷰(FROM절 서브쿼리)를 사용한다.  

LIMIT과 같이 사용할 수 있다.
```sql
SELECT *
FROM ( SELECT ROWNUM list, ENAME
    FROM EMP)
WHERE list <= 5;
```

페이지 단위 출력의 인라인 뷰는 아래와 같다.
```sql
SELECT *
FROM (SELECT ROWNUM list, ENAME
    FROM EMP)
WHERE list BETWEEN 5 AND 10;
```

ROWID  
Oracle 데이터베이스 내에서 데이터를 구분할 수 있는 유일한 값이다. ROWID를 통해서 데이터가 어떤 데이터 파일, 어느 블록에 저장되어 있는지 알 수 있다.  
```sql
SELECT ROWID, EMPNO
FROM EMP
```

ROWID 구조
- 오브젝트 번호 : 1~6, 오브젝트 별로 유일한 값으로 속한 오브젝트 값
- 상대 파일 번호 : 7~9, 데이블스페이스에 속한 데이터 파일에 대한 상대 파일번호
- 블록 번호 : 10~15, 데이터 파일 내부에 블록 데이터 위치번호
- 데이터 번호 : 16~18, 데이터 블록에 데이터가 저장된 순서

**WITH**
서브쿼리를 사용해서 임시 테이블이나 뷰처럼 사용할 수 있는 구문으로, 서브쿼리 블록에 별칭을 지정한다. 옵티마이저는 SQL을 인라인 뷰나 임시 테이블로 판단한다.  
```sql
WITH viewData AS
  (SELECT * FROM EMP
    UNION ALL
  SELECT * FROM EMP)
SELECT * FROM viewData WHERE EMPNO=1000;
```

### DCL(Data Control Language)
GRANT  
데이터베이스 사용자에게 권한(연결, 입력, 수정, 삭제, 조회)을 부여
```sql
GRANT privileges ON object TO user;
// privileges 권한 대입, object 테이블명, user DB사용자 지정
```
Privileges(권한)
- SELECT : 조회
- INSERT : 삽입
- UPDATE : 수정
- DELETE : 삭제
- REFERENCES : 참조하는 제약조건
- ALTER : 수정
- INDEX : 인덱스 생성
- ALL : 모든 권한

```sql
GRANT SELECT, INSERT, UPDATE, DELETE
  ON EMP
  TO LIMBEST;
```

WITH GRANT OPTION
- 특정 사용자에게 권한을 부여할 수 있는 권한 부여
- 권한 A -> B, B -> C 부여한 후 권한 취소하면 모든 권한이 회수

WITH ADMIN OPTION
- 테이블에 대한 모든 권한 부여
- 권한 A -> B, B -> C 부여한 후 권한 취소하면 B 사용자 권한만 취소

```sql
GRANT SELECT, INSERT, UPDATE, DELETE
  ON EMP
  TO LIMBEST WITH GRANT OPTION;
```

REVOKE
권한 회수
```sql
REVOKE privileges ON object FROM user;
```

### TCL(Transaction Control Language)
COMMIT
- INSERT, UPDATE, DELETE문으로 변경된 데이터를 데이터베이스에 반영
- COMMIT하면 덮어씌워 이전 데이터 소실
- 다른 모든 데이터베이스 사용자는 변경된 데이터 볼 수 있다.
- COMMIT 완료되면 데이터베이스 변경으로 인한 LOCK 해제
- COMMIT이 완료되면 다른 모든 데이터베이스 사용자는 변경된 데이터 조작 가능
- COMMIT을 실행하면 하나의 트랜잭션 과정 종료

AUTO COMMIT  
SQL *PLUS 정상 종료시 AUTO COMMIT  
DDL 및 DCL 사용시 AUTO COMMIT  
SQL *PLUS에서 `set autocommit on;` 실행시 AUTO COMMIT  

ROLLBACK  
- 실행시 변경 사항 모두 취소 후 트랜잭션 종료
- INSERT, UPDATE, DELETE문 작업 취소. 단, 이전 COMMIT한 곳까지 복구
- ROLLBACK 실행시 LCOK 해제되어 다른 사용자 데이터베이스 조작 가능

SAVEPOINT
- 트랜잭션을 작게 분할하여 관리. 지정된 위치 이후의 트랜잭션만 ROLLBACK 가능
- `SAVEPOINT <SAVEPOINT명>`
- 데이터 변경 취소 `ROLLBACK TO <SAVEPOINT명>`
- ROLLBACK 실행시 SAVEPOINT와 관계없이 데이터의 모든 변경사항을 저장하지 않는다.

## SQL 활용
### 조인(Join)
EQUI(등가) 조인(교집합)  
- 조인은 여러 개의 릴레이션을 사용해서 새로운 릴레이션을 만드는 과정
- 가장 기본은 교집합
- 두 개의 테이블 간에 일치하는 것을 조인

INNER JOIN  
- EQUI조인과 같으며, 표준SQL이다.
- ON문을 이용해서 조인 조건을 서술한다.  

HASH JOIN  
- 선행 테이블을 결정 후 선행 테이블에서 주어진 조건(WHERE구)에 해당하는 행 선택
- 행 선택 후 조인 키를 기준으로 해시 함수를 사용해서 해시 테이블을 메인 메모리에 생성하고 후행 테이블에서 주어진 조건에 만족하는 행 찾기
- 후행 테이블의 조인 키를 사용해서 해시 함수를 적용하여 해당 버킷 검색

INTERSECT 연산
- 두 개의 테이블에서 교집합 조회

NON-EQUI(비등가) 조인  
정확하게 일치하지 않는 것을 조인 (`=`을 제외한 `>` `<` `<=` `>=`)  

OUTER JOIN  
- 두 개의 테이블 간에 교집합을 조회하고 한쪽 테이블에만 있는 데이터도 포함시켜서 조회
- 왼쪽 테이블에만 있는 행 포함시 `LEFT OUTER JOIN`
- 오른쪽 테이블에만 있는 행 포함시 `RIGHT OUTER JOIN`
- 두 테이블 전부 포함시 `FULL OUTER JOIN`
- ORACLE 데이터베이스에서는 `(+)` 기호 사용

CROSS JOIN  
- 조인 조건구 없이 2개의 테이블을 하나로 조인
- 조인구가 없기 때문에 카테시안 곱 발생(A x B)  

UNION을 사용한 합집합 구현  
UNION
- 두 개의 테이블을 하나로 만드는 연산
- 두 개의 테이블의 칼럼 수, 칼럼의 데이터 형식 모두가 일치 해야한다.  
- 중복 데이터 제거하며, 정렬과정 발생

UNION ALL  
- 두 개의 테이블을 하나로 합치되, 중복과 정렬 유발X

차집합을 만드는 MINUS  
- MINUS 연산은 두 개의 테이블에서 차집합 조회  
- MS-SQL에서는 EXCEPT

### 계층형 조회(CONNECT BY)
ORACLE 데이터베이스에서 지원하며, 계층형으로 데이터 조회  
```sql
CREATE TABLE EMP(
  EMPNO NUMBER(10) PRIMARY KEY,
  ENAME VARCHAR2(20),
  DEPTNO NUMBER(10),
  MGR NUMBER(10),
  JOB VARCHAR2(20),
  SAL NUMBER(10)
)

INSERT INTO EMP VALUES(1000, 'TEST1', 20, NULL, 'CLERK', 800);
INSERT INTO EMP VALUES(1001, 'TEST2', 30, 1000, 'SALESMAN', 1600);
INSERT INTO EMP VALUES(1002, 'TEST3', 30, 1000, 'SALESMAN', 1250);
INSERT INTO EMP VALUES(1003, 'TEST4', 20, 1000, 'MANAGER', 2975);
INSERT INTO EMP VALUES(1004, 'TEST5', 30, 1000, 'SALESMAN', 1250);
INSERT INTO EMP VALUES(1005, 'TEST6', 30, 1001, 'MANAGER', 2850);
INSERT INTO EMP VALUES(1006, 'TEST7', 10, 1001, 'MANAGER', 2450);
INSERT INTO EMP VALUES(1007, 'TEST8', 20, 1006, 'ANALYST', 3000)
INSERT INTO EMP VALUES(1008, 'TEST9', 30, 1006, 'PRESIDENT', 5000);
INSERT INTO EMP VALUES(1009, 'TEST10', 30, 1002, 'SALESMAN', 1500);
INSERT INTO EMP VALUES(1010, 'TEST11', 20, 1002, 'CLERK', 1100);
INSERT INTO EMP VALUES(1011, 'TEST12', 30, 1001, 'CLERK', 950);
INSERT INTO EMP VALUES(1012, 'TEST13', 20, 1000, 'ANALYST', 3000);
INSERT INTO EMP VALUES(1013, 'TEST14', 10, 1000, 'CLERK', 1300);

COMMIT
```
- CONNECT BY는 트리 형태의 구조로 질의 수행
- START WITH구는 시작 조건을 의미, CONNECT BY PRIOR는 조인 조건
- ROOT로부터 하위 노드의 질의 실행
- 계층형 조회에서 MAX(LEVEL)사용시 최대 계층 수
```sql
SELECT MAX(LEVEL)
FROM LIMBEST.EMP
START WITH MGR IS NULL
CONNECT BY PRIOR EMPNO = MGR;
```

LPAD 함수를 이용해 계층형 조회 결과를 명확히 볼 수 있다.
```sql
SELECT LEVEL, LPAD(' ', 4 * (LEVEL -1) ) || EMPNO, MGR, CONNECT_BY_ISLEAF
FROM EMP
START WITH MGR IS NULL
CONNECT BY PRIOR EMPNO = MGR;
```

CONNECT BY 키워드
- LEVEL : 검색 항목의 깊이
- CONNECT_BY_ROOT : 계층구조에서 가장 최상위 값
- CONNECT_BY_ISLEAF : 계층구조에서 가장 최하위 값
- SYS_CONNECT_BY_PATH : 계층구조의 전체 전개 경로
- NOCYCLE : 순환구조가 발생지점까지만 전개
- CONNECT_BY_ISCYCLE : 순환구조 발생 지점 표시

### 서브쿼리
- SELECT문에 SELECT문 사용시 스칼라 서브쿼리
- FROM문에 SELECT문 사용시 인라인 뷰
- WHERE구에 SELECT문 사용시 서브쿼리

서브쿼리 종류
- 단일 행 서브쿼리 : 반환하는 행 수 하나 (`=` `<` `<=` `>` `>=` `<>` 사용)
- 다중행 서브쿼리 : 반환하는 행 수 여러 개 (`IN` `ANY` `ALL` `EXIST` 사용)

다중 행 서브쿼리
- IN : MAIN QUERY의 비교조건이 SUBQUERY의 결과 중 하나만 동일하면 된다.(OR조건)
- ALL : MAIN QUERY와 SUB QUERY의 결과가 모두 동일하면 참, `< ALL` : 최솟값 반환, `> ALL` : 최댓값 반환
- ANY : MAIN QUERY의 비교조건이 SUB QUERY의 결과 중 하나 이상 동일하면 참, `< ANY` : 하나라도 크게 되면 참, `> ANY` : 하나라도 작게 되면 참
- EXIST : MAIN QUERY와 SUB QUERY의 결과가 하나라도 존재하면 참

스칼라 서브쿼리  
반드시 한 행과 한 컬럼만 반환하는 서브쿼리로, 여러 행 반환 시 오류가 발생한다.  

연관 SUBQUERY  
연관 서브쿼리는 서브쿼리 내에서 메인 쿼리 내의 칼럼을 사용하는 것을 의미

### 그룹 함수
**ROLLUP**
- GROUP BY의 컬럼에 대해 **SUBTOTAL**을 만듬
- GROUP BY구에 칼럼이 두 개 이상 오면 **순서에 따라 결과가 달라짐**
```sql
SELECT DECODE(DEPTNO, NULL, '전체합계', DEPTNO), SUM(SAL)
FROM EMP
GROUP BY ROLLUP(DEPTNO);
```
DEPTNO에 대해서 GROUP BY로 급여 합계를 계산하고 부서별 전체합계를 추가해서 계산한다.  
ROLLUP은 DEPTNO에 대해서 기존 GROUP BY와는 다르게 부서별 전체합계를 계산한다.  

**GROUPING 함수**  
- ROLLUP, CUBE, GROUPING SETS에 생성되는 **합계값을 구분**하기 위해 만들어짐
- 예로 소계, 합계 등이 계산되면 GROUPING 함수는 1을 반환하고 아니면 0을 반환해서 합계값 식별
```sql
SELECT DEPTNO, GROUPING(DEPTNO), JOB, GROUPING(JOB), SUM(SAL)
FROM EMP
GROUP BY ROLLUP(DEPTNO)
```

**GROUPING SETS 함수**
- GROUP BY에 나오는 칼럼의 순서와 관계없이 **다양한 소계** 만듬
- GROUP BY에 나오는 칼럼의 순서와 관계없이 **개별적**으로 모두 처리
```sql
SELECT DEPTNO, JOB, SUM(SAL)
FROM EMP
GROUP BY GROUPING SETS(DEPTNO, JOB);
```
GROUPING SETS함수로 DEPTNO와 JOB을 실행한 결과 DEPTNO 합계와 JOB 합계가 개별적으로 조회되었다. 즉, 서로 관계가 없다.  

**CUBE 함수**  
- CUBE 함수에 제시한 칼럼 가능한 모든 집계 계산
- 다차원 집계를 제공하여 다양하게 데이터 분석
- **조합할 수 있는 경우의 수 모두 조합** (부서와 직업을 CUBE로 사용하면 부서별 합계, 직업별 합계, 부서별 직업별 합계, 전체합계 조회)

```sql
SELECT DEPTNO, JOB, SUM(SAL)
FROM EMP
GROUP BY CUBE(DEPTNO, JOB);
```

### 윈도우 함수
윈도우 함수는 행과 행 간의 관계를 정의하기 위해서 제공되는 함수로, 순위, 합계, 평균, 행 위치 등을 조작할 수 있다.  
```sql
SELECT WINDOW_FUNCTION(ARGUMENTS)
        OVER (PARTITION BY 칼럼
                ORDER BY WINDOWING절)
FROM 테이블명;
```

**윈도우 함수 구조**  
- ARGUMENTS(인수) : 윈도우 함수에 따라서 0~N개 설정
- PARTITION BY : 전체 집합을 기준에 의해 소그룹으로 나눔
- ORDER BY : 어떤 항목에 대해서 정렬
- WINDOWING : 행 기준의 범위, ROWS는 물리적 결과의 행 수, RANGE는 논리적인 값에 의한 범위

**WINDOWING**
- ROWS : 부분집합인 윈도우 크기를 물리적 단위로 행의 집합을 지정
- RANGE : 논리적인 주소에 의해 행 집합을 지정
- BETWEEN~AND : 윈도우의 시작과 끝의 위치 지정
- UNBOUNDED PRECEDING : 윈도우의 시작 위치가 첫 번째 행
- UNBOUNDED FOLLOWING : 윈도우 마지막 위치가 마지막 행 
- CURRENT ROW : 윈도우 시작 위치가 현재 행

```sql
SELECT EMPNO, ENAME, SAL,
        SUM(SAL) OVER(ORDER BY SAL,
                  ROWS BETWEEN UNBOUNDED PRECEDING
                  AND UNBOUNDED FOLLOWING) TOTSAL
FROM EMP;
```
SAL의 전체합계를 조회하는 쿼리문  
BETWEEN 사이의 값으로 현재행, 처음, 마지막 행을 조건을 줄 수 있다.  

**순위 함수(RANK Function)**  
- 윈도우 함수는 특정 항목과 파티션에 대해서 순위를 계산하는 함수를 제공하나, 순위 함수는 RANK, DENSE_RANK, ROW_NUMBER 함수를 가지고 있다.

순위 관련 윈도우 함수  
- RANK : 특정항목 및 파티션에 대해서 순위 계산, 동일한 순위는 동일한 값 부여
- DENSE_RANK : 동일한 순위를 하나의 건수로 계산
- ROW_NUMBER : 동일한 순위에 대해서 고유의 순위를 부여
```sql
SELECT ENAME, SAL,
      RANK() OVER (ORDER BY SAL DESC) ALL RANK,
      RANK() OVER (PARTITION BY JOB ORDER BY SAL DESC) JOB RANK
FROM EMP;
```
급여 순위를 계산하되, 동일한 순위는 동일하게 조회한다. 직업별로 파티션을 만들고 JOB별 순위를 조회한다.  

**집계 함수(RANK Function)**
- SUM : 파티션별 합계
- AVG : 파티션별 평균
- COUNT : 파티션별 행 수
- MAX, MIN : 파티션 별 최댓값, 최솟값  

**행 순서 관련 함수**
- FIRST_VALUE : 파티션에 가장 처음에 나오는 값, MIN함수와 같은 결과
- LAST_VALUE : 파티션에 가장 나중에 나오는 값, MAX함수와 같은 결과
- LAG : 이전 행을 가져옴
- LEAD : 윈도우의 특정 위치의 행 가져옴. 기본값은 1  
```sql
SELECT DEPTNO, ENAME, SAL, 
  FIRST_VALUE(ENAME) OVER (PARTITION BY DEPTNO
    ORDER BY SAL DESC ROWS UNBOUNDED PRECEDING) AS DEPT_A FROM EMP;
```

**비율 관련 함수**  
- CUME_DIST : 파티션 전체 건수에서 현재 행보다 작거나 같은 건수에 대한 누적 백분율 조회, 누적 분포상에 위치를 0~1 사이의 값을 가진다.
- PERCENT_RANK : 파티션에서 제일 먼저 나온 것을 0으로 제일 늦게 나온 것을 1로 하여 값이 아닌 행의 순서별 백분율 조회
- NTILE : 파티션별로 전체 건수를 ARGUMENT 값으로 N등분한 결과 조회
- RATIO_TO_REPORT : 파티션 내에 전체 SUM(칼럼)에 대한 행 별 칼럼값의 백분율을 소수점까지 조회

### 테이블 파티션
**Partition 기능**  
- 파티션은 대용량의 테이블을 여러 개의 데이터 파일에 분리해서 저장
- 테이블의 데이터가 물리적으로 분리된 데이터 파일에 저장되면 입력, 수정, 삭제, 조회 성능이 향상
- 파티션은 각각 파티션 별로 독립적 관리, 파티션 별로 백업하고 복구가 가능하면 파티션 전용 인덱스 생성도 가능
- 파티션은 Oracle 데이터베이스의 논리적 관리 단위인 테이블 스페이스 간에 이동이 가능
- 데이터 조회시 데이터의 범위를 줄여서 성능 향상

Range Partition  
- 테이블의 칼럼 중에서 값의 범위를 기준으로 여러 개의 파티션으로 데이터를 나누어 저장
- 행을 분리 시 범위를 지정해서 파티션을 나눌 수 있다.

**List Partition**
- 특정 값을 기준으로 분할하는 방법

**Hash Partition**
- 데이터베이스 관리 시스템이 내부적으로 해시 함수를 사용해서 데이터 분할
- 결과적으로 데이터베이스 관리 시스템이 알아서 분할하고 관리

이외에도 Composite Partition이 있는데 이것은, 여러 개의 파티션 기법을 조합해서 사용하는 것이다.  

**파티션 인덱스**
- Global Index : 여러 개의 파티션에서 하나의 인덱스 사용
- Local Index : 해당 파티션 별로 각자의 인덱스 사용
- Prefixed Index : 파티션 키와 인덱스 키가 동일
- Non Prefixed Index : 파티션 키와 인덱스 키가 다르다.

Oracle 데이터베이스는 Global Non-Prefixed 지원하지 않는다.  

## SQL 최적화의 원리
**옵티마이저(Optimizer)**
- SQL 개발자가 SQL을 작성하여 실행할 때, 옵티마이저는 SQL을 어떻게 실행할 것인지 계획함. 즉, SQL 실행 계획을 수립하고 SQL을 실행한다.
- 옵티마이저는 SQL의 실행 계획을 수립하고 SQL을 실행하는 데이터베이스 관리 시스템의 소프트웨어이다.
- 동일한 결과가 나오는 SQL도 어떻게 실행하느냐에 따라 성능이 달라지므로, 옵티마이저의 실행 계획은 SQL의 성능에 아주 중요한 역할을 한다.

**옵티마이저 특징**
- 데이터 딕셔너리(Data Dictionary)에 있는 오브젝트 통계, 시스템 통계 등의 정보를 사용해서 예상되는 비용 산정
- 여러 개의 실행 계획 중에서 최저비용을 가지고 있는 계획을 선택해서 SQL을 실행한다.

**옵티마이저의 필요성**
- SQL개발자가 작성한 SQL문이 어떻게 실행되냐에 따라 성능이 달라지므로, 실행 계획을 잘 수립해야 한다. 실행 계획을 비효율적 수립하게 되면 SQL 개발자는 SQL을 개선해야 한다. 이때 옵티마이저에게 실행 계획을 변경하도록 요청할 수 있는데 HINT를 사용한다. (HINT : /*+ RULE */과 같은 형태로 옵티마이저에서 실행방법을 알려주는 것)

**옵티마이저 실행 계획 확인**
- 옵티마이저는 SQL 실행 계획을 PLAN_TABLE에 저장한다.
- SQL 개발자는 PLAN_TABLE을 조회해서 실행 계획을 확인할 수 있다.

### 옵티마이저 종류
**옵티마이저의 실행 방법**  
- SQL 실행시 파싱을 실행해서 SQL의 문법 검사 및 구문분석을 수행한다.
- 구문분석이 완료되면 옵티마이저가 규칙 기반 혹은 비용 기반으로 실행 계획을 수립한다.
- 옵티마이저는 기본적으로 비용 기반 옵티마이저를 사용해서 실행 계획을 수립한다. 비용 기반 옵티마이저는 통계정보를 활용해서 최적의 실행 계획을 수립하는 것이다.
- 실행 계획 수립이 완료되면 최종적으로 SQL을 실행하고 실행이 완료되면 데이터를 인출(Fetch)한다.

**옵티마이저 엔진**
- Query Transformer : SQL문이 효율적으로 실행하기 위해서 옵티마이저가 변환하며, 변환되어도 결과는 동일하다.
- Estimator : 통계정보를 사용해서 SQL 실행비용을 계산한다. 총 비용은 최적의 실행 계획을 수립하기 위해서이다.
- Plan Generator : SQL을 실행할 실행 계획을 수립한다.

규칙 기반 옵티마이저는 실행 계획을 수립할 때 15개의 우선순위를 기준으로 실행 계획을 수립한다. 최신 Oracle 버전은 규칙 기반 옵티마이저보다 비용 기반 옵티마이저를 기본적으로 사용한다.
| 우선순위 | 설명 |
|:------:|-------|
| 1 | ROWID를 사용한 단일 행인 경우 |
| 2 | 클러스터 조인에 의한 단일 행인 경우 |
| 3 | 유일하거나 기본키를 가진 해시 클러스터 키에 의한 단일 행인 경우 |
| 4 | 유일하거나 기본키에 의한 단일 행인 경우 |
| 5 | 클러스터 조인인 경우 |
| 6 | 해시 클러스터 조인인 경우 |
| 7 | 인덱스 클러스터 키인 경우 |
| 8 | 복합 칼럼 인덱스인 경우 |
| 9 | 단일 칼럼 인덱스인 경우 |
| 10 | 인덱스가 구성된 칼럼에서 제한된 범위를 검색하는 경우 |
| 11 | 인덱스가 구성된 칼럼에서 무제한 범위를 검색하는 경우 |
| 12 | 정렬-병합 조인인 경우 |
| 13 | 인덱스가 구성된 칼럼에서 MAX 혹은 MIN을 구하는 경우 |
| 14 | 인덱스가 구성된 칼럼에서 ORDER BY를 실행하는 경우 |
| 15 | 전체 테이블을 스캔(FULL TABLE SCAN)하는 경우 |

ROWID를 사용한 조회
```sql
SELECT /*+ RULE */ * -- 규칙 기반 옵티마이저로 실행하라는 HINT
FROM EMP
WHERE ROWID='AAAHYhAABAAALNJAAN';
```

**비용 기반 옵티마이저**
- 오브젝트 통계 및 시스템 통계를 사용해서 총 비용을 계산
- 총 비용은 SQL문을 실행하기 위해서 예상되는 소요시간 혹은 자원의 사용량을 의미
- 총 비용이 적은 쪽으로 실행 계획을 수립. 단, 비용 기반 옵티마이저에서 통계정보가 부적절한 경우 성능 저하가 발생

### 인덱스
- 인덱스는 데이터를 빠르게 검색하는 방법
- 인덱스는 인덱스 키로 정렬되어 있기 때문에 원하는 데이터 빠르게 조회
- 오름차순, 내림차순 조회 가능
- 하나의 테이블에 여러 개의 인덱스 생성, 하나의 인덱스는 여러 개의 칼럼으로 구성
- 테이블을 생성할 때 기본키는 자동으로 인덱스가 만들어지고 인덱스의 이름은 `SYSXXX`이다.

인덱스의 구조
- Root Block, Branch Block, Leaf Block으로 구성되고 Root Block은 인덱스 트리에서 가장 상위에 있는 노드, Branch Block은 다음 단계의 주소를 가지고 있는 포인터로 되어 있다.
- Leaf Block은 인덱스 키와 ROWID로 구성되고 인덱스 키는 정렬되어서 저장하며, Double Linked List 형태로 되어있어 양방향 탐색이 가능하다.

**인덱스 생성**
- `CREATE INDEX`문을 사용해서 생성
- 인덱스를 생성할 때 한 개 이상의 칼럼을 사용해서 생성
- 인덱스 키는 기본적으로 오름차순 정렬, `DESC`구 포함시 내림차순 정렬

**인덱스 스캔**  
인덱스 유일 스캔
- 인덱스의 키 값이 중복되지 않은 경우, 해당 인덱스를 사용할 때 발생

인덱스 범위 스캔
- SELECT문에서 특정 범위를 조회하는 WHERE문을 사용시 발생
- `Like`, `Between`이 대표적인 예로서, 데이터의 양이 적으면 인덱스 자체를 실행하지 않고 TABLE FULL SCAN이 될 수 있다.
- 인덱스의 Leaf Blcok의 특정 범위를 스캔한 것이다.

인덱스 전체 스캔
- 인덱스에서 검색되는 인덱스 키가 많은 경우에 Leaf Block의 처음부터 끝까지 전체를 읽어 들인다.

추가적으로 Table Full Scan시에 High Watermark의 의미
- 테이블의 데이터를 모두 읽은 것을 의미
- 테이블을 읽을 때 High Watermark 이하까지만 Table Full Scan을 한다.
- High Watermark는 테이블에 데이터가 저장된 블록에서 최상위 위치를 의미하고 데이터가 삭제되면 High Watermark가 변경

### 실행 계획
```sql
SELECT * FROM EMP, DEPT;
WHERE EMP.DEPTNO = DEPT.DEPTNO AND
      EMP.DEPTNO = 10;
```
쿼리가 있을 때에 실행 계획을 읽는 방법
1) DEPT 테이블의 SYS_C007959 인덱스를 유일하게 조회(INDEX UNIQUE SCAN)
2) INDEX에서 DEPT 테이블 ROWID을 사용해서 조회
3) EMP 테이블을 전체 스캔(FULL SCAN)
4) DEPT 테이블과 EMP 테이블을 Nested Loop 방식의 조인을 해서 최종 결과를 만듬 (Nested Loop : DEPT 테이블에서 먼저 데이터를 찾고 EMP 테이블을 찾는 것을 의미 := Random ACcess)

INDEX SCAN(SYS_C007959) -> INDEX SCAN(DEPT TABLE : Outer Table) -> TABSLE ACCESS FULL(Inner Table)  
먼저 조회되는 테이블이 Outer Table, 그 다음 조회되는 테이블이 Inner Table이다.

### 옵티마이저 조인(Optimizer Join)
**Nested Loop 조인**  
- 하나의 테이블에서 데이터를 먼저 찾고 그 다음 테이블을 조인하는 방식으로 실행
- 먼저 조회되는 테이블이 외부 테이블(Outer Table), 그 다음 조회되는 테이블이 내부 테이블(Inner Table)
- 외부 테이블(선행 테이블)의 크기가 작은 것을 먼저 찾는 것이 중요하다. 왜냐 데이터가 스캔되는 범위를 줄이기 위해서이다.
- Random Access가 발생하는데 이것은 성능 지연을 발생시킨다. 따라서 Nested Loop 조인은 Random Access의 양을 줄여야 성능이 향상

```sql
SELECT /*+ ordered use_nl (b) */ * -- use_nl힌트는 Nested Loop 조인을 실행하게 함.
FROM EMP a, DEPT b
WHERE a.DEPTNO = b.DEPTNO
  AND a.DEPTNO = 10;
```
- `use_nl` 힌트는 의도적 Nested Loop 조인 실행
- EMP 테이블 FULL SCAN 후 DEPT 테이블 FULL SCAN하여 Nested Loop 조인
- `ordered` 힌트는 FROM절에 나오는 테이블 순서대로 조인. ordered 힌트는 혼자 사용하지 않고, `use_nl`, `use_merge`, `use_hash` 힌트와 같이 사용

**Sort Merge** 조인  
- 두 개의 테이블을 SORT_AREA라는 메모리 공간에 모두 로딩하고 SORT를 수행
- 두 개의 테이블에 대해서 SORT가 완료되면 MERGE함
- 정렬이 발생하기 때문에 데이터양이 많아지면 성능이 떨어짐
- 정렬 데이터양이 너무 많으면 정렬은 임시 영역에서 수행되는데 이때, 임시 영역은 디스크에 있어서 성능이 떨어진다.

```sql
SELECT /*+ ordered use merge(b) */ *
FROM EMP a, DEPT b
WHERE a.DEPTNO = b.DEPTNO
  AND a.DEPTNO = 10;
```
- use_merge 힌트를 사용해서 의도적으로 SORT MERGE을 하였으며, Ordered은 앞서 말한 것과 같이 FROM절 뒤에 나오는 테이블을 순서대로 조인하게한다.
- use_merge 힌트는 항상 ordered 힌트와 같이 사용되어야 한다.

**Hash 조인**
- 두 개의 테이블 중에서 작은 테이블을 HASH 메모리에 로딩하고 두 개의 테이블의 조인 키를 사용해서 해시 테이블을 생성한다.
- 해시 함수를 사용해서 주소를 계산하고 해당 주소를 사용해서 테이블을 조인하기 떄문에 CPU 연산을 많이 한다.
- 선행 테이블이 충분히 메모리에 로딩되는 크기여야 한다.

```sql
SELECT /*+ ordered use_hash(b) */ *
FROM EMP a, DEPT b
WHERE a.DEPTNO = b.DEPTNO
  AND a.DEPTNO = 10;
```