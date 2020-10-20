  
 
  

# SQL 활용

## 조인(Join)
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

## 계층형 조회(CONNECT BY)
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

## 서브쿼리
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

## 그룹 함수
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

## 윈도우 함수
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

## 테이블 파티션
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