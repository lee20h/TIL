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