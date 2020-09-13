---
sidebar: auto
---

# SQL 최적화의 원리
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

## 옵티마이저 종류
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

## 인덱스
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

## 실행 계획
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

## 옵티마이저 조인(Optimizer Join)
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