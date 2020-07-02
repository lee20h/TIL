# 📙 Today I Learned  
## 규칙  
* 기억에 남는 내용 기록  
* 1일 2개의 알고리즘 문제 해결  
* markdown으로 작성  
  
---  
[5월](./month/MAY)  
[6월](./month/JUNE)  

---  

* 1日  

Database : 정보를 데이터로 저장하고 컴퓨털르 사용해서 효율적으로 접근하도록 가공한 것  
Database Management System(DBMS) : 데이터베이스를 관리하는 시스템  
DBMS의 필요성  
- 다수에게 데이터 공유  
- 대량의 데이터 다루기  
- 읽기/쓰기의 자동화  
- 불의의 사고 대처  

DBMS의 종류  
- 계층형 데이터베이스  
	계층구조(트리구조)  
- 관계형 데이터베이스  
	열과 행으로 이뤄진 2차원 표 형식 데이터 관리  
	SQL(Structured Query Language) 사용하여 데이터 처리  
	대표적인 RDBMS Oracle, SQL Server, DB2, PostgreSQL, MYSQL  
- 객체지향 데이터베이스  
	객체지향 언어와 비슷하게 객체 단위로 데이터 관리  
- XML 데이터베이스  
	XML(eXtensible Markup Language)형식을 사용하여 데이터를 대량으로 빠르게 처리  
- 키-밸류형 데이터스토어  
	해시와 비슷한 구조로, 웹 서비스에서 초고속으로 검색할 때 사용  

RDBMS 시스템 구성은 클라이언트-서버형으로 이루어져있다. 클라이언트에서 SQL문을 작성하여 서버(RDBMS)에 전달하면 데이터베이스에서 꺼내 요구한 데이터를 클라이언트에 넘겨주는 식으로 작동한다. 한 대의 컴퓨터에서 RDBMS와 클라이언트를 동시에 동작시켜도 되고, 서로 다른 컴퓨터에서 동작시켜도 된다. 복수의 클라이언트에서 하나의 RDBMS로 연결하여 데이터를 반환 받을 수 있다.  

테이블 구조는 열과 행으로 이루어진 2차원 표 형식으로 클라이언트가 SQL문을 작성하여 서버에 요청하면 데이터베이스에서 해당 테이블에 있는 데이터를 추출하여 클라이언트에게 보내준다. 이 때 하나의 데이터베이스에 여러 테이블을 둘 수 있다. 그리고 반환된 데이터는 **항상 2차원 표 형태**로 나타나게 된다.  
테이블의 열은 Column으로, 데이터 항목을 나타내고 테이블의 행은 Record로, 데이터 한 건을 뜻한다. RDBMS에서는 **반드시 행 단위로 데이터를 읽고 쓴다.** RDBMS에선 행과 열이 교차하는 칸에 대한 용어가 없어서 공부하는 책에서는 임의로 Cell이라고 명명하고 공부를 할려고 한다. 하나의 Cell에는 무조건 하나의 데이터만 넣을 수 있다.  

Data Definition Language (DDL)  
데이터를 저장하는 데이터베이스 및 테이블을 생성, 삭제를 위한 것으로 각각의 명령어는 CREATE, DROP, ALTER이다.  

Data Manipulation Language (DML)  
테이블의 행을 검색하거나 변경하기 위한 명령어로, SELECT, INSERT, DELETE가 있다.  

Data Cotrol Language (DCL)  
데이터베이스에서 처리한 변경 내용을 확정하거나 취소하기 위한 명령어다. 또 사용자에게 처리 권한을 부여한다.  
- COMMIT : DB 변경 내용을 확정한다.  
- ROLLBACK : DB 변경 내용을 취소한다.  
- GRANT : 사용자에게 처리 권한을 부여한다.  
- REVOKE : 사용자 처리 권한을 제거한다.  

SQL문 마지막에 명시적으로 세미콜론을 붙여야한다. 또한, 대소문자 구별이 없으므로 키워드, 테이블명을 대소문자 구별없이 사용해도 똑같이 인식한다. 단, **테이블에 등록된 데이터에 있어서는 대소문자가 구별이되므로 유의**해야한다. 책에서 임의로 규칙을 정해서 SQL문을 기술하자면 키워드는 대문자, 테이블명은 첫 문자만 대문자, 그 외는 전부 소문자로 약속하고 공부한다.  

상수란 SQL문 안에 직접 기술하는 문자열, 날짜, 숫자 등을 상수라고 한다. 문자열의 경우는 `''` 작은따옴표를 이용한다. 날짜에도 작은따옴표를 이용하지만 기술하는데에 여러 형식이 있으나 `'년-월-일'`을 사용하도록 하자. 숫자에 있어서는 그냥 숫자만 기술하면 된다. 단어를 구별하는 구분자는 공백이나 줄바꿈문자로 구별한다.  

데이터베이스 테이블을 작성해보자.
```
CREATE DATABASE <shop>
CREATE TABLE Goods
(good_id	CHAR(4)			NOT NULL,
goods_name	VARCHAR(100)	NOT NULL,
goods_classify VARCHAR(32)	NOT NULL,
sell_price	INTEGER	,
buy_price	INTEGER ,
register_date	DATE,
PRIMARY KEY (goods_id));
```
테이블을 작성할 때는 한글을 사용하지 못하지만 테이블 안에 들어가는 데이터의 경우에는 한글을 사용할 수 있다. 테이블은 영문자나 숫자, 언더바만 가능하다. 또한 처음 시작은 영문자로 시작해야한다. 마지막으로 테이블의 이름이 중복이 되면 안된다.  

데이터형에 대해 말해보면 오늘 공부한 내용으론 가장 기본적인 형들만 보았다. 먼저, INTEGER형은 말 그대로 정수형이다. CHAR형의 경우 문자열형으로 고정 문자열을 넣으므로 처음에 최대 길이를 괄호로 지정하게 되는데 문자열을 넣을 때 최대 길이보다 작다면 남은 공간을 전부 공백으로 채우게 된다. 이 때 문자열의 경우 대소문자를 구별하여 인식하게 된다. 그 다음 VARCHAR형을 보면 CHAR형과는 다르게 가변 문자열 형식으로 공백으로 채우지 않는다. DATE형은 날짜를 저장하는 데이터형이다. 년월일을 저장하지만 Oracle에서는 시분초까지 포함한다.  

마지막으로 제약 설정이라는 것이 있다. 데이터형을 넣을 때 오른쪽에 있는 것이 제약으로 위에서는 NOT NULL을 사용했다. 이 제약의 경우는 반드시 데이터가 존재해야 한다는 것을 의미한다. 또 **주 키 제약**이라는 것은 주 키를 통해 해당 상품의 데이터를 추출할 수 있다. 만약 주 키에 중복된 값이 있다면 추출할 수 없다.  

테이블 삭제와 변경에 대해 알아보자. 변경의 경우는 DROP을 사용하면 된다.  
```
DROP TABLE Goods;
```
삭제 후 복구는 불가능하므로 유의해서 사용하자.  
테이블에 열이 부족하면 다시 만들지 않고 수정해서 사용하는 방법이 있다. 바로 ALTER TABLE 문으로, 이런 식으로 사용한다.  
```
ALTER TABLE Goods ADD COLUMN goods_name_eng VARCHAR(100);
```
ALTER TABLE 테이블명 ADD COLUMN 열 정의. 오라클이나 SQL서버에서는 COLUMN을 빼고 정의한다. 또한 오라클에서 복수 개의 열을 한번에 추가하는 경우엔 `{}`을 사용하여 묶는다.  
ADD뿐 아니라, DROP의 경우도 ADD을 대체해서 사용하면 똑같이 사용할 수 있다.  
```
ALTER TABLE Goods DROP COLUMN goods_name_eng;
```

테이블에 데이터를 등록하는 방법  
```
BEGIN TRANSACTION - SQL Server와 PostgreSQL  
START TRANSACTION - MySQL  
사용하지 않음 - Oracle, DB2 
// 행추가를 위한 조건
INSERT INTO Goods VALUES ('0001', '티셔츠', '의류', 1000, 500, '2009-09-20');
...
INSERT INTO Goods VALUES ('0008', '볼펜', '사무용품', 100, NULL, '2009-11-11);

COMMIT;
```

테이블을 수정하는 방법  
```
ALTER TABLE Gods RENAME TO Goods; // Oracle, PostgreSQL
RENAME TABLE Gods TO Goods; // DB2
sq_rename 'Gods', 'Goods'; // SQL Server
RENAME TABLE Gods to Goods; // MySQL
```

아주 조금 사용해본 데이터베이스가 MySQL이므로 책으로 공부하지만 MySQL을 기준으로 공부할 것 같다.  

---

- 2日  

데이터베이스 SELECT문  
테이블에서 데이터를 꺼낼 때 SELECT를 사용한다. 테이블 속 데이터 중 원하는 것을 선택한다고 생각하면 된다. 그리고 이것을 쿼리, 질의라고 부른다. 가장 기본적이며 많이 사용되는 구문이다.  

```
SELECT <열명>, ...
	FROM <테이블명>;
```
여기서 SELECT와 FROM을 Clause라고 부른다. 이 Clause는 SQL문을 구성하는 요소로 여러 키워드로 시작하는 문장이다.  

SELECT로 원하는 열의 이름을 지정하고 FROM으로 데이터를 꺼낼 테이블의 이름을 지정한다. 예시로 어제 짠 테이블의 열을 출력해보자.  
```
SELECT goods_id, goods_name, buy_price
	FROM Goods;
```
이렇게 실행하게 되면 goods_id, good_name, bur_price의 데이터들을 보여준다.  
여기서 지정하지 않고 모든 열을 출력하려면,
```
SELECT *
	FROM Goods;
```
같이 사용하면 된다. 이 때 `*`란 모든 열을 의미한다.  

추가적으로 SQL문에서 개행을 어디서나 해도 상관이 없으나, 연속개행으로 인한 빈 줄이 끼게된다면 실행이 안되므로 주의해야한다.  

이어서 `AS`키워드를 이용해서 별명을 지을 수 있다. 바로 이런 방식이다.  
```
SELECT goods_id AS id,
       goods_name AS name,
	   buy_price AS price
	FROM Goods;
```
여기서 영어가 아닌 한글로 대체할 수 있는데 이 때는 `""` 큰 따옴표를 이용해야 한다.  

별명 뿐아니라 상수를 출력하게 SELECT문을 짤 수 있다. 
```
SELECT '상품' AS munja, 38 AS num, '2009-02-24' AS nalja, goods_id, goods_name
	FROM Goods;
```

중복을 제거하는 키워드도 존재한다. 바로 `DISTNCT`라는 키워드다.  
```
SELECT DISTNCT goods_classify
	FROM Goods;
```
이 때 중복을 제거할 때 NULL을 포함한다. 이 키워드는 항상 열 앞에 쓰여야한다. 열이 쓰이다 도중에 포함될 수 없다.  

WHERE문은 조건문이라고 생각하면 된다. SELECT와 FROM으로 어떤 테이블에서 어떤 열을 구할지 정한다는거라면 WHERE은 행을 구할 수 있다.  
```
SELECT goods_name, goods_classify
	FROM Goods
	WHERE goods_classify = '의류';
```
goods_classify라는 열의 값이 의류인지 비교해서 해당하는 행을 선택해준다. 여기서 SELECT와 FROM문으로 열을 먼저 구하는게 아니라 WHERE문으로 행을 선택한 다음 SELECT와 FROM문에서 열을 구한다. 따라서 이러한 Clause들은 순서를 지켜야한다. 순서가 안 지켜진다면 에러가 발생할 수 있다.  

프로그래밍 언어들과 같이 주석처리를 할 수 있다. 주석을 작성하기 위한 방법으로는 `--`로 `//`와 같이 한 줄만 주석처리하는 방법과 복수 행 주석은 여타 다른 프로그래밍 언어와 같이 `/* */`사이에 기술하는 방법이다.  

연산자에 대해 알아보자.  
먼저 산술 연산자는 사칙연산 모두 사용할 수 있다.  예시로,  
```
SELECT goods_name, sell_price, sell_price * 2 AS "sell_price_x2"
	FROM Goods;
```
이런 경우 goods_name sell_price sell_price_x2 순서대로 출력하게 되는데, 이 때 sell_price_x2의 경우 데이터가 같은 행 sell_price의 2배가 출력되게 된다. 추가적으로 NULL이 들어간 사칙연산의 경우 모두 NULL이 된다.  

비교 연산자의 경우 `=` `<>`을 사용해서 만든다. 대소관계와 같은 경우, 그리고 같지않다를 만든다.  
```
SELECT goods_name, goods_classify
	FROM Goods
	WHERE sell_price = 500;
```
Goods 테이블에서 goods_name, goods_classify 열 중 sell_price가 500인 행을 선택하는 구문이다. 프로그래밍 언어와 다른 점은 `<>`이 같지 않다라는 것이다. 대부분 `!=`을 사용하는데 이것은 표준SQL에서 인정하지 않기 때문에 안정성을 위해서 `<>`을 사용한다.  
날짜형에서도 또한 사용할 수 있는데, 크다 작다 개념이 이전 이후로 생각하면 된다. 그리고 `<=`와 `>=`은 꼭 부등호 다음 등호가 나오는 순서대로 기술해야한다. 그리고 산술연산자와 비교연산자를 같이 사용하여 WHERE문을 기술할 수 있다.  
문자열의 대소관계는 항상 사전식으로 비교한다. 따라서 첫 문자의 사전식 대소관계 같은 경우에는 그 다음 문자를 비교하면서 정렬하게 된다. 그리고 비교연산자에 NULL은 사용될 수 없다. NULL을 뽑기위해 `<>`을 사용하거나 `= NULL`을 사용하면 NULL인 행을 구할 수 없다. 따로 키워드를 사용해하는데 그것은 `IS NULL`과 `IS NOT NULL`이다. WHERE문에 연산자 사용하듯이 사용하면 NULL이나 NOT NULL을 구할 수 있다.  

논리 연산자에 대해 알아보자. 앞서서 사용했던 `<>`도 부정의 의미를 가지고 있지만 더 넓은 범위로 생각할 수 있는 연산자가 있다. 바로 `NOT`이다. 또 `AND`와 `OR`을 사용해서 WHERE 조건을 원하는 조건으로 매칭할 수 있다. 여기서 `OR`연산자 보다 `AND`연산자가 우선순위가 높으므로 괄호를 이용해서 명확히 표시해야 원하는 조건을 제대로 제시할 수 있게 된다.  
```
SELECT goods_name, goods_classify, register_date
	FROM Goods
	WHERE goods_classify = '사무용품'
	AND ( register_date = '2009-09-11'
			OR register_date = '2009-09-20');
```
논리 연산자에서 진릿값을 생각하면 진리표를 그리고 참과 거짓을 가려내 명확하게 나오는 값일 것이다. 하지만 SQL에서는 불명(UNKNOWN)이라는 값이 존재한다. 이렇게 3가지 논리 연산을 3치 논리라고하며, 흔히 아는 프로그래밍 언어에서 사용하는 것을 2치 논리라고 한다. 3치 논리를 표로 정리해보면  

| P | Q | P AND Q | 
|---|---|---------|
| 참 | 참 | 참 |
| 참 | 거짓 | 거짓 |
| 참 | 불명 | 불명 |
| 거짓 | 참 | 참 |
| 거짓 | 거짓 | 거짓 |
| 거짓 | 불명 | 거짓 |
| 불명 | 참 | 불명 |
| 불명 | 거짓 | 거짓 |
| 불명 | 불명 | 불명 |  

| P | Q | P OR Q |
|---|---|---------|
| 참 | 참 | 참 |
| 참 | 거짓 | 참 |
| 참 | 불명 | 참 |
| 거짓 | 참 | 참 |
| 거짓 | 거짓 | 거짓 |
| 거짓 | 불명 | 불명 |
| 불명 | 참 | 참 |
| 불명 | 거짓 | 불명 |
| 불명 | 불명 | 불명 |  

이렇게 정리해볼 수 있다.  

--- 
