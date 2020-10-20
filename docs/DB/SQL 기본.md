  
 
  


# SQL 기본

DBMS는 오라클 기준으로 정리하였다.

## 관계형 데이터베이스
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

## SQL의 종류
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

## DDL (Data Definition Language)
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

## DML (Date Manipulation Language)
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

## DCL(Data Control Language)
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

## TCL(Transaction Control Language)
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