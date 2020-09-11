# 📙 Today I Learned  
## 규칙  
* 기억에 남는 내용 기록 후 [정적 웹페이지](https://lee20h.github.io/TIL/)에 정리
* 쓸데없는 Commit 지양
* markdown으로 작성
* 문제 풀고 [Problem Solving](https://github.com/lee20h/TIL/tree/master/Problem%20Solving) 폴더에 모으기

---  

# 2020년

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

- 3日  

KMP 문제 풀이 [Censoring](http::/noj.am/10747)  

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;

int fail[MAX];
int match[MAX];

/*
	match = 문자열 s1의 인덱스일 때 문자열 s2와 일치하는 길 이로, 벡터에 s1 글자에 담은다.
	제거할 문자열 찾은 경우 벡터에서 그 만큼의 길이를 제거 후 제거한 문자열의 첫 문자가 들어오기 전의 상태로 돌아간다.
	따라서 match에 벡터의 사이즈값으로 해당 값을 받아온다. 
*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s1, s2;
	cin >> s1 >> s2;
	
	for (int i=1,j=0; i<s2.length(); i++) {
		while(j>0 && s2[i] != s2[j])
			j = fail[j-1];
		if(s2[i] == s2[j])
			fail[i] = ++j;
	}
	
	vector<char> v;
	
	for (int i=0,j=0; i<s1.length(); i++) {
		v.push_back(s1[i]);
		while(j>0 && s1[i] != s2[j])
			j = fail[j-1];
		if(s1[i] == s2[j]) {
			if(j == s2.length()-1) {
				for(int i=0; i<s2.length(); i++)
					v.pop_back();
				j = match[v.size()];
			}
			else
				j++;
		}
		match[v.size()] = j;
	}
	for (auto ans : v)
		cout << ans;
}
```

위의 주석과 같지만 더 설명을 붙여본다. kmp 실패함수를 통해서 해당 긴 문자열에서 짧은 문자열을 찾기를 반복한다. 이 때 벡터에 계속 해당 값들을 집어 넣으며 찾게 되면 찾은 문자열만큼 빼준다. 이후 인덱스를 다시 잡아주기 위해서 match 배열로 잡아주면 된다.

---

- 5日  

4일은 SQLD 시험 준비로 잠시 쉬어갔다.  

오늘은 시험 이후에 네이버에서 예전에 진행했었던 `D2 대학생 밋업: 백엔드 개발`에 대해 쓴 글에 대해 읽어봤다. 백엔드를 지망하는 학생이지만, 일의 범위나 다양한 시각을 생각하지 못해봤던 나에게 도움이 된 글이였다.  

[네이버 D2](https://d2.naver.com/news/3435170)에서 상세하게 읽어볼 수 있으며, 그 중 궁금했었던 부분이나, 도움이 된 부분을 기록하려고 한다.  

## 일의 범위

웹앱 개발, 데이터 분석 엔지니어링, 분산파일 시스템 혹은 DBMS 개발자들도 백엔드 개발자라고 불린다. 프론트엔드 개발자에 비해 그 영역이 모호하다고 볼 수 있다. 서버, DB, 프론트엔드 까지 풀스택으로 개발하는 백엔드 개발자도 심심치않게 볼 수 있다. 폭 넓은 기술을 접하기 때문에 여러 시스템 엔지니어나, 프론트엔드 개발자들과 소통을 많이하게 된다. 따라서 여러가지 분야에 대해서 공부하기 쉽고 그 중 하나를 전문으로 하는 전문가로 성장할 수 있다.  

## 전망

새로운 도구와 프레임워크의 등장은 개발자의 수요나 가치를 하락시키는 존재이지 않을까라는 염려가 있다. 이러한 염려는 기우에 불과하다. 왜냐하면 새로운 시스템에 대한 수요와 유지 보수할 기존의 시스템도 늘어나기 때문이다. 이러한 시스템들을 관리하기 위해서는 개발자들의 투자와 수요는 줄어들 수 없다. 이러한 이유로 인해 새로운 도구와 프레임워크들의 등장은 새로운 기회가 될 수 있으므로 잘 캐치할 수 있도록 하자.  

하지만 개발 분야만 본다면 분야가 계속 발전하게 되면서 자신이 전문으로 하고자하는 분야를 계속 담당할 수 없게 될 수 있다. 왜냐하면 시대가 변하면서 주로 사용하는 기술들이 변하기 때문이다. 그런 시대 속에서 빠르게 적응하면서 준비를 하기 위해서는 자신이 전문으로 하고자하는 분야 외에도 다른 분야에 대한 역량을 충분히 키워두는 것이 도움이 될 수 있다.  

이러한 흐름에는 백엔드 개발은 무난한 선택이라고 볼 수 있다. 여러가지 분야를 백엔드라고 말할 수 있다는 이전의 말과 같이 여러 분야와 조화되어서 변해가는 시대 흐름에 자신이 선택할 수 있는 폭을 넓힐 수 있기 때문이다.  

## 필요한 지식

- 웹 생태계의 스펙
	- HTML, HTTP(1.1 , HTTP/2)
- 기본 SDK, 라이브러리/프레임워크 이해와 활용
- 클라이언트를 위한 API 설계
- 서버/컴퍼넌트/객체 간의 역할 분담/의존성/통신 방법 설계
- 저장소 활용
	- DBMS 설계
	- Cache 적용
		- Global/Local cache 적용범위, 라이프 싸이클, 솔루션 선택
	- 파일 저장 정책/솔루션 선택 활용
- 검색엔진 연동 방식 결정
- 빌드 도구
	- Maven/Gradle
- 배포 전략
- 성능 테스트/프로파일링/튜닝
	- JVM 레벨의 튜닝 (GC 옵션 등)
		- 웹 서버(Nginx,Tomcat)등의 설정/튜닝
	- OS 설정의 주요 값 확인
- 인접 기술에 대한 이해
	- DBMS, Front End 등
- 서버 개발자에만 해당하지는 않는 항목
	- 테스트 코드 작성/리팩토링 기법
	- 버전 관리 전략
		- branch 정책 등
		
해당 부분은 사이트의 글을 그대로 인용해왔다. 이 부분은 JVM과 Linux를 바탕으로 한 환경에서 필자가 웹 서버 개발에 있어서 필요한 부분이라고 적은 부분이다.  

이러한 지식들을 한 사람이 모두 가지고 있어야하는 게아닌 팀의 개발자들의 지식을 합쳐서 구현 방식과 정책이 결정된다.  

이 때 팀 구성원이 할 수 있는 기술을 선택하되, 내부의 소수만 사용하는 관리 도구는 팀원 모두가 처음 쓰는 기술을 적용할 수 있지만, 큰 서비스에는 작은 서비스에서 먼저 시도 후 적용하는 것이 일반적이다.  

## 데이터베이스

백엔드 개발자에겐 RDB가 여전히 가장 우선시 되어지는 데이터베이스이다. 해당 데이터베이스를 다루는 능력이 핵심 역량으로 꼽힌다. 예시를 통해서 보면 개발하는 도중에도 쿼리의 호출 횟수나 실행 계획이 비효율적이지 않은지 확인하는 습관, 운영 중에도 느린 쿼리를 모니터링하고 DBA와 협업하여 성능 개선하는 습관, ORM같은 추상화된 프레임워크를 써서 SQL을 작성하지 않은 경우에도 이러한 습관은 필요하다.  

대용량 서비스에서의 과거와 현재의 차이를 보면, 과거에는 서버 간의 네트워크 호출 비용을 줄이기 위해 한번에 많은 테이블을 조인하는 긴 SQL을 통해서 DB 쿼리를 짰다. 하지만 요즘은 복잡한 JOIN은 피하고 단순한 SQL을 통해서 DB 쿼리를 짜는 추세이다. 왜냐하면 데이터를 다른 저장소에 캐시하거나 분산해서 저장하기 쉽기 때문이다. 대용량 저장하는 UGC 서비스에서는 RDB 테이블 사이의 JOIN을 최대한 제약하고 어플리케이션 레벨에서 여러 저장소의 연관된 데이터를 조합한다.  

DB안에서 실행되는 Stored prodecure은 급하게 개발된 서비스에서 많이 사용되었다. 네트워크 호출비용이 없고 DB안에 저장되므로 배포 절차가 단순했기 때문이다. 하지만, 길게 작성되게 되면 작성자도 수정하기 힘들어지고, 버전관리가 어려워진다. 추가적으로 데이터의 연산에 DB서버의 CPU 자원을 소모하게 되어 병목이 일어날 수 있어 가급적 사용을 하지 않는다.  

분산 DB를 사용하기도 어렵다. DB 서버 1대는 성능 향상을 위해 Local cache, Gloal cache를 동원하기도 한다. RDB는 사용량이 늘어나면 분산하는 비용도 상당하기 때문에 성장 가능성이 있는 큰 서비스의 경우에는 RDB의 자원을 아끼는 방법도 생각해야한다.  

해당 게시물에는 이 외에도 많은 내용이 있으나 당장 내가 받아들이기가 어려운 내용들도 상당히 많다. 따라서 지금은 이렇게까지 읽어보고 정리했으므로 다음에 조금 더 지식이 쌓인 뒤 읽어보며 회고해보도록 한다.  

마지막으로는 개발자의 수준에 대해 정리한 부분을 강조하고 싶다. 개발도구를 잘 활용하는 능력은 실력이라고도 할 수 있고, 이러한 도구를 토대로 새로운 도구에 적용하여 적응하는 능력도 실력이라고 볼 수 있다. 따라서 필자가 얘기하는 레벨2. 즉, 개발도구의 공식 레퍼런스를 보고 사용법을 스스로 익힐 수 있고 자신이 경험한 사용법을 문서화해서 팀 내에 설명하고 알려 줄 수 있는 수준이 되어야 한다는 것을 느낀다.  

어떤 개발툴이나 언어를 뛰어넘어 서비스에 필요한 부분에 대해 러닝커브를 크게 올릴 수 있는 개발자가 될 필요가 있다는 것을 느낄 수 있는 글이였다. 다음엔 밑의 내용에 대해 이해하는 시간을 가져볼려고 한다.  

---

- 6日  

DP 문제 풀이 [문제](http://noj.am/11052)  

DP 문제를 풀어보고 이해하는 시간을 가졌다.  

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000+1;

int p[MAX];
int dp[MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> p[i];
	}
	
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=i; j++) {
			dp[i] = max(dp[i],dp[i-j]+p[j]);
		}
	}
	cout << dp[n];
}
```

해당 문제에서 요구하는 것은 n개의 카드를 살 때 최대의 값을 찾는 것이다. 이때 n개 만큼 숫자가 주어지게 된다. i번째 숫자는 i개의 카드가 든 카드팩을 의미하므로 마지막 n번째 숫자는 n개의 카드가 든 카드팩을 의미한다. 따라서 각각의 갯수를 생각하면서 코딩을 해야한다.  

문제를 제대로 읽지 않고 풀이를 생각한게 가장 큰 오점이였다. 인덱스만큼의 카드가 들어있는 줄 모르고 각각을 1개라고 생각하면서 풀었다가 다시 문제를 읽게 되었다.  

처음의 포문은 먼저 카드팩의 숫자를 의미한다. 따라서 i개의 카드를 골랐다는 것을 뜻한다. 또한 안쪽 포문은 해당 i개의 숫자만큼 카드를 골랐을 때 최대의 값을 구하기 위한 반복문으로 현재 뽑은 카드의 숫자가 i이므로 i보다 크지 않은 만큼의 반복을 해야한다.  

이러한 로직으로 이루어져있으며, 안쪽 포문에서 최댓값을 구할 때 dp[i-1]이 아닌 dp[i-j]를 해줘야 카드팩에 들어있는 카드 숫자만큼 빼줄 수 있어서 제대로 n개의 카드를 골랐을 때의 최댓값을 구할 수 있다.

---

- 7日  

# 컴퓨터 네트워크 road map

## 인터넷이란 무엇인가?  

Computing devices : hosts, end-system(PC, Workstation, server). 네트워크 앱이 실행된다.  

Communication links
- fiber, copper, radio, satellite
- transmission rate = **bandwidth**

Routers: foward packets(chunks of data)  
	
![What's_The_Internet](./docs/.vuepress/public/images/Network/WTI.jpg)  

구조를 설명하는 그림으로, 라우터들과 서버, 워크스테이션과 모바일로 구성되어있다. 네트워크 시점으론 라우터들과 호스트들로 볼 수 있다. ISP는 KT와 같은 회사를 의미한다.  

IDC(Internet Data Center)는 그림의 regional ISP와 같이 서버를 라우터에 붙여서 설치하기도 하는데 병목현상을 줄이고 데이터들을 전송하기 수월하게 한다. 즉, 대용량 서비스에 유리하다.  

Network protocol : 인터넷의 입장에서 모든 통신활동이 프로토콜에 의해 제어된다.  

protocol이란 패킷의 포맷, 순서가 정의되어 있는 것으로 네트워크에서 레이어마다의 규칙이라고 생각하면 좋다. 사람과의 대화처럼 컴퓨터의 대화에서도 필요한 것이 프로토콜이다.   

## 네트워크 구조

Edge router : end-system에 접속하게 해주는 edge router의 역할은 사용자마다 허용된 트래픽만큼 제한(regulation) 해준다. 그리고 서로 다른 ISP에서 허용 트래픽 이상을 통신할려하면 요금이 더 부과될 수 있으므로 우회하는 방향으로 라우팅을 하기도 한다.  

Core router : Edge router에서 제한을 해줬으므로 Core router의 역할은 전송 속도를 빠르게 해주는 부분이다.  

Access networks : end-system이 Edge router에 접근하기 위해 필요한 망으로, 구리선, 전화선, 무선 등이 있다. 전체 네트워크 사이즈의 80% 이상을 차지한다. 따라서 Backbone은 20% 정도 차지한다고 보면 된다.  

## Network edge

end systems(hosts)
- 웹 이메일와 같이 응용프로그램 구동

client/server model
- 클라이언트가 요청시 서버가 그 요청의 서비스를 제공
- 웹 클라이언트/서버, 이메일 클라이언트/서버
- 비용 생길 수 있음

peer-peer model (p2p)
- 서버없이 단말끼리 통신
- 서버 역할과 클라이언트 역할 동시에 수행
- 비용 절감. 서비스 안정성 문제

## Network Core

신뢰할 수 있는 라우터끼리 연결되어 통신하므로 제한(regulation)문제는 없다. 하지만 라우터들을 거쳐서 통신할 때 문제를 이야기한다.  

**circuit switching**  
- 먼저 연결하고 데이터를 보냄
- 지연이 없고 자원을 예약하여 퀄리티가 좋음
- 음성 전화

**packet-switching**
- 연결없이 패킷단위로 보냄
- 라우터에 버퍼 꽉 찼을시 패킷 버려짐(packet loss)
- out of order 문제
- 인터넷 데이터

virtual circuit switching: 두 가지 방법을 보완한 방법  

## Access network(망)

end-system이 Edge router에 접속하기 위한 망

- ADSL : 전화선을 이용한 방법. 중계기가 300m 미만

- Cable modems : HFC(hybrid fiber coax) 동축 케이블을 사용하되 광 케이블로 끌고가서 연결. 공유하므로 같이 사용하면 속도 저하

![Cable_network](./docs/.vuepress/public/images/Network/Cable_Network.jpg)  

- LAN : local area network로 대부분 ethernet을 사용한다. 

- Wireless LANs

## Physical Media

`TP(Twisted Pair) < Coaxial < Fiber < Radio(terrestrial microwave, LAN, wide-area, satellite)`

## Protocol Layer

네트워크가 복잡하기 때문에 레이어를 이룬다. 각 레이어들은 자기들만 집중하면 되기 때문에 간단해진다.  

복잡한 시스템을 위해서 레퍼런스 모델로 레이어를 나눈다. 이때 인터넷 계층은 5계층으로 나뉜다.  

|인터넷 5계층|
|---|
| application |
|transport|
|network|
|link|
|physical|  

계층별 예시

**application**
- FTP, SMTP, STTP

**transport**
- TCP, UDP

**network**
- IP, routing protocols

link
- ppp, Ethernet

physical
- bit on the wire

![Layering](./docs/.vuepress/public/images/Network/Layering.jpg) 

end-system은 5계층, router는 3계층을 구현한다. end-system에서는 각 프로토콜에 있는 것은 상대방 peer에 대해서 1:1 통신되는 방식으로 디자인 되어있다.  

## history

- 1967 : ARPAnet
- 1972 : ARPAnet 퍼블리싱
- 1973 : Ethernet 제안
- 1979 : ARPAnet 200개의 노드 갖음
- 1983 : TCP/IP, DNS
- Early 1990's : ARPAnet 국방부 -> 민간
- 1994 : www 표준

---

# Network Layer

![network_layer](./docs/.vuepress/public/images/Network/network_layer.jpg)  

# Host-to-Host Delivery : Internetworking, Addressing and Routing

## Internetworks

![internetwork](./docs/.vuepress/public/images/Network/internetwork.jpg)  

네트워크간의 연결을 맡아주는 부분이 internetwork라고 한다.  

![network_layer_at_the_sources](./docs/.vuepress/public/images/Network/network_layer_at_the_sources.jpg)  

위의 그림이 네트워크 레이어에서의 ip 패킷 흐름도라고 볼 수 있다. 라우터 측면에서의 흐름도 비슷하며, 초기엔 유닉스 머신으로, 라우터를 사용했다는 것만 기억해두자.  

목적지 도달시에 헤더를 보고 오류 판단한다. 쪼개진 경우 모으는 Reassemble한 뒤 올려보낸다. 쪼개져 있지 않는다면 바로 올려보내는 모습을 볼 수 있다.  

네트워크 계층에서의 Switching은 Packet switching을 사용하고 있고 Datagram approach를 사용한다.  

![datagram_approach.jpg](./docs/.vuepress/public/images/Network/datagram_approach.jpg.jpg)  

# Addressing

IP주소는 32bit 주소로 전세계에서 공통적으로 사용한다.  
IP주소를 십진수나 이진수 표기법으로 변환하는 것은 많이 해보았으니 넘긴다.  

Classful addressing : A,B,C,D,E 5개의 클래스로 나눈다.  

다음주에 계속

---

# 소프트웨어공학

# 1장 시스템 공학과 소프트웨어 공학

들어가기에 앞서 현재는 변화의 시대에 있어서, 우리에게 많은 변화를 요구한다. 변화를 하지 않는 것은 발전을 포기하는 것과 같다고 볼 수 있다. 따라서 변화 없이 더 좋은 제품을 만들 수 있는 기술과 경쟁력이 향상되지 않는다.  

발전을 위한 변화는 바른 원리에 의한 것이여야한다. 성공적인 소프트웨어 개발을 위한 방법론에 속하는 바른 원리를 알아본다.  

## 과학과 공학

- 자연과학 : 자연의 법칙 탐구
- 공학 : 자연과학이 발견한 자연의 법칙을 응용하여 인류의 편익을 위해 무엇인가를 생산하는 전문분야
- 과학기술 : 공학과 자연과학을 지칭
- 공학과 자연과학은 서로 보완하며, 상호 의존적인 관계로 발전
- 자연과학이 근본적인 지식의 탐구에 관련되어 있다면, 공학은 실제 문제의 해결과 '더 나은 삶의 추구'를 위한 과학지식의 응용과 관련되어 있다.
- 공학은 당면한 문제를 해결하기 위하여 자연과학의 지식을 필요로 하며 이는 다시 자연과학의 분야에 영향을 미쳐 공학과 자연과학은 서로 보완하며 발전해왔다.  

## 시스템 공학

- 시스템은 어떤 목적과 기능을 수행하기 위하여 유기적인 관계를 맺으며 함께 작용하는 요소들의 집합
- 시스템은 여러 요소들로 이루어진 특정한 집합
- 각 요소는 다른 요소들과 관계를 가지고 시스템의 공동목표를 위하여 함께 작용
- 시스템의 예 : 사람, 컴퓨터 시스템, 자동차 운전 시스템
- 시스템 공학은 시스템의 개발과 운용, 유지보수를 합리적으로 행하기 위한 사고방법, 절차, 조직 및 기법 등을 총칭
- 시스템 공학의 기술적 측면과 관리적 측면
	- 기술적 측면 : 시스템을 구성하는 물적 요소의 적합성과 이의 효과적인 조합에 의한 효율의 극대화를 추구
	- 관리적 측면 : 시스템 개발에 관련된 업무가 제대로 이루어지도록 인원, 설비, 자재 등에 대한 계획과 통제를 행하는 관리기술

### 컴퓨터 시스템과 소프트웨어 시스템

- 시스템 개발은 인간의 욕구와 사회적 필요성에 의해 시작
- 평가기준은 시스템의 목적에 따라 다름
- 가치 평가기준 : 성능, 시간, 비용, 신뢰성, 보전성, 안전성 등
- 평가요소들은 시스템의 기술적 측면과 관리적 측면
- 컴퓨터 시스템 공학은 기능을 HW, SW 등의 시스템의 구성요소에 할당
- 시스템 개발 첫 단계는 사용자가 요구하는 목표와 시스템의 제약조건으로부터 시스템을 정의

## 건축공학의 예

- 큰 건물을 지을 때 진행되는 과정과 공법을 통해서 다른 공학들의 적용되는 기본 원리를 발견

1. 설계 회사에서 설계, 도면 완성
2. 시공회사 선정
3. 설계 도면대로 건축
4. 감리회사가 감리
5. 사용자들이 입주 후 사용 및 유지보수

예를 들어 설계사가 큰 병원을 설계할 때 필요한 부분을 봐보자. 건물의 용도에 대한 특성을 파악하고 나타날 문제점을 해결해야한다. 이를 위해 설계팀들이 만들어지고 다양한 사용자들의 니즈를 찾고 규명하는 것을 시스템 공학에서는 **시스템 분석** 또는 **요구사항 분석**이라고 한다.  

### 공정 과정

요구사항 분석 단계
- 설계팀 구성, 사용자 니즈 수집 훟 통합
- 요구사항 분석은 설계 이전에 수행되어야 할 중요한 과정

설계 단계
- 사용자의 니즈를 만족할 수 있도록 건물의 윤곽을 그리는 과정
- 설계사가 요구사항을 통합하여 설계 도면 완성

구현 단계
- 시공회사는 설계 도면을 가지고 건물 건축

감리 단계
- 시공 후 감리회사는 설계 도면대로 건축되었는지 확인
- 체계적이며 분할된 공정과정을 통해 안전과 품질 보증
- 건물에 이상 발견시 책임의 소재 규명, 품질의 관리

운용과 유지보수 단계
- 감리 후 사용자들이 입주

이전 시대에서는 예술적인 면, 형식적인 면을 강조해서 미켈란젤로의 설계와 시공이 가능하였지만, 건물의 기능과 생산성이 강조되면서 설계와 시공이 분리되면서 위와 같은 과정이 굳혀졌다.  

### 건축 공학 생명주기 모델

`건축물 사용자 요구사항 분석 -> 건축물 설계 -> 시공 -> 감리 -> 유지보수`  

생명주기 모델은 간단, 명료하여 프로젝트 진행시 수행되어야할 활동들과 그 활동들의 순서를 정하고 관리, 통제하기 쉽게 한다. 해당 흐름을 프로세스라고 할 수 있다.  

프로세스는 입력물을 받아 임무를 수행하고 결과물을 만들어내는 활동이다. 프로세스는 연결되어있으며 한 프로세스의 결과물은 연결된 다음 프로세스의 입력물이 된다. 프로젝트가 어떤 단계를 거쳐 진행되고 각 단계의 작업, 산출물은 무엇인지 명확히 하는 것 프로젝트에 참여한 여러 사람들이 의사 소통을 원활하게 할 수 있는 기준이 된다. 이러한 기본개념은 다른 공학에도 그대로 적용된다.  


## Everything is created twice

월트 디즈니의 말을 통해서 공학을 보자  

첫번째는 마음속에서 창조하는 것이고, 두번째는 실제적으로 만드는 것이다.  

따라서 첫번째 창조는 *분석*이라고 하며, 두 번째 창조는 *개발*이라 부른다. 이때 분석에는 계획 단계가 포함이 되고 개발에는 설계와 구현, 시험을 포함한다.  

첫번째 창조의 결과는 유저의 관점에서 시스템의 모습을 논리적으로 나타낸 논리적 모델이어야 하며, 응용분야의 용어로 기술되어야 한다.  

두번째 창조는 엔지니어의 관점에서 소프트웨어의 모습을 물리적으로 나타낸 물리적 모델이며, 소프트웨어 용어로 기술될 수 있다.

결론적으로 첫번째 창조는 무엇을 만들 것인가 규명하는 단계이고, 두번재 창조는 해당 목표를 어떻게 이루어 나갈지 찾는 실천 과정이다.  

첫번째 창조를 하는 사람을 시스템 분석가, 두번째 창조를 하는 사람을 개발자라고 부른다. 

## 요약

모든 것은 두번 창조된다는 것을 모르는 경우 많은 부작용이 발생한다. 엔지니어가 사용자의 관점과 엔지니어의 관점을 구별하지 못하는 경우며, 목표와 수단을 구별하지 못하는 경우다.  

따라서 엔지니어의 시작은 사용자의 관점과 엔지니어의 관점을 구별하는 것이다.  

이번 장에서 건축공학을 중심으로 일반적인 공학의 진행과정을 보았는데 이때 공학의 기본 원리가 적용되어 요구사항 분석, 설계, 구현, 시험 및 유지보수 과정을 거쳐야한다. 이것은 소프트웨어 개발에도 적용되므로 이를 통해서 기술의 향상과 높은 품질의 제품을 생산해야한다.

---

# 2장 소프트웨어 개발의 일반적 공정 과정

## 소프트웨어 개발 과정

`계획 -> 요구사항 분석 -> 설계 -> 구현 -> 시험 및 유지 보수` 과정(생명주기)을 거쳐야한다. 이때 각 과정에서는 검증이 이뤄져야하고 전체적인 소프트웨어 위험 분석이 시행되어야한다.

소프트웨어는 여러 구성요소가 유기적으로 상호작용하는 시스템으로, 일반적으로는 HW 및 다른 요소들과 결합한다.  

시스템 전체에 대한 기능과 니즈의 정의가 선결된 후 그 기능의 일부를 소프트웨어 시스템이 담당한다.  

만약 시스템을 구매할 고객이 이미 정해져있는 경우 고객이 비용을 담당하는 주문생산 제품을 개발하게 된다. 이때는 고객과의 계약으로 개발이 시작되고, 유저가 고객으로 한정되어 있다.  

고객이 주문하면 개발하는 것보다 이미 상업화된 제품을 구입하는 경향이 늘고 있다. 해당 제품이 주문생산 제품보다 시간과 비용을 줄일 수 있어서 선호된다. 만약 상업화된 제품이 고객의 니즈를 충족시키지 못한 경우 수정사항을 요구하는 쪽으로 넘어가게 된다.  

소프트웨어 품질을 보증하기위해서는 소프트웨어의 공정 과정을 분석, 설계, 구현할 때 유지보수 과정에 적용될 수 있는 기법과 도구들이 확립되어야한다. 또한 각 공정과정의 임무, 입력물, 산출물, 사용도구가 각각 잘 정리되어야한다.  

## 프로젝트 계획

프로젝트 계획은 소프트웨어 프로젝트의 핵심 활동이며 소프트웨어 프로젝트 관리에서 가장 중요하게 여겨지는 과정이다.  

계획은 본질적으로 미래의 변화를 준비하는 과정으로, 목표를 세우고 이를 달성하기 위해 체계적인 진행 상황 관리를 할 수 있도록 세부 행동 방안을 마련하는 것이며 프로젝트 실행과 통제의 지침이 된다. 이 단계에서 결과물은 계획서 문서들이 될 수 있다.

## 요구사항 분석

소프트웨어 개발 생명주기에서 계획단계 다음으로 이루어지며, 고객의 요구를 만족시키는 소프트웨어를 개발하기 위해 고객의 요구사항을 알아내는 것은 시스템을 개발하는 관리자와 실무자에게 중요한 단계다.  

요구사항 오류를 줄이기 위해서 프로젝트 초기인 요구사항 분석단계에서부터 다양한 이해관계자를 프로그램에 참여시키는 것은 중요하다. 이해관계자의 활발한 참여는 잘못된 요구사항을 찾고 중요 요구사항을 누락시키지 않도록 할때 도움이 된다.  

요구사항은 프로젝트 범위 관리에 기초 자료를 제공한다. 프로젝트가 수행되는 모든 과정에 영향을 미칠 수 있다. 따라서 요구사항을 규명, 명세화, 효율적으로 관리하는 문제는 소프트웨어 개발자에게 중요한 부분이다.    

소프트웨어 프로젝트 실패 원인이 요구사항 분석이 잘못된 경우가 많다. 따라서 여러가지를 자문하여 답을 고려하여 분석해야한다.

### 요구사항의 규명

사용자의 관점에서 시스템의 요구사항을 모으는 것이 요구사항의 규명이라고 할 수 있다. 기능, 성능, 인터페이스에 대한 요구사항들이 있고 이러한 요구사항 분석은 업무 분석으로 불린다.  

요구사항 분석은 고객의 니즈가 나오게 된 원인, 배경, 환경 등에 대한 분석을 포함한다. 또한, 시스템에 대한 필요가 나오게 된 고객의 내부 환경과 외적 요인을 파악해야한다.  

내적 요인 : 인력 규모 축소, 기술력 향상, 생산 증대, 서비스 향상  
외적 요인 : 경쟁, 법규나 제도의 변화, 시장 여건의 변화  

요구사항 분석 단계의 **주요 초점**은 어떻게(how to)가 아니라 무엇
(what)이다.  

### 타당성 조사

주어진 시간과 예산안에서 시스템을 개발 해야하고, 가능한 빠른 시간 내에 타당성을 평가하는 것이 요구된다. 따라서 타당성 조사는 프로젝트 계획 단계에서 이뤄지는 것이 바람직하며 분석단계에서도 이뤄지는 것이 일반적이다. 그리고 타당성 조사는 경제적 타당성, 기술적 타당성, 법적 타당성, 대체 방안 등에 집중되어 이뤄져있다.  

시스템에 개발 요구되는 시간, 비용, 인력 등의 자원은 시스템의 타당성에 직접적인 영향을 미친다. 그러므로 자원의 투자와 그 이익을 조사하고 위험에 대한 분석을 수행해야한다.  

일반적으로 시스템 개발은 비용을 줄이고 생산성과 서비스를 향상 시키기 위해 행해진다.  

### 비용과 일정에 대한 제약 설정

요구사항을 분석하는 분석가는 응용 분야에 대한 해박한 지식이 요구된다. 왜냐하면 개발 비용, 개발 일정, 시스템 성능에 대해 정확한 예측을 해야하기 떄문이다.  

프로젝트 관리가 매우 중요하며 관리활동은 요구되는 자원과 성취해야할 임무, 소요 기간, 추적해야 할 이정표 등을 포함한다. SW 프로젝트 관리는 다른 공학에 비해 취약한 형편이다. 따라서 관리가 효율적으로 이루어질려면 각 기능과 소요 비용과 개발 기간의 예측, 제약 조건 및 위험에 대한 평가 등이 분석 단계나 계획 단계에서 이루어져야 한다.  

### 요구사항 정의 문서화

유저의 요구사항과 시스템의 기능이 문서화되어야 한다. 이때의 산출물이 **요구사항 명세서**가 된다. 기능 명세서, 목표 문서, 기능 요구서라고도 불리는 이 명세서는 분석가가 만드는 경우가 대부분이나, 고객과 함께 만드는 경우도 있다.  

요구사항 명세서는 고객과 개발 회사의 계약서로도 쓰일 수 있고, 명세서를 통해서 추후에 발생하는 문제와 변화에 대한 책임이 명확히 규명될 수 있어야 한다. 이를 위해서 요구사항 명세서에 시스템에 연관된 당사자들이 동의하여 서명하고 그 다음 단계로 넘어가는 것이 바람직하다. 따라서 요구사항 명세서는 프로젝트와 관계된 모든 사람이 읽고 이해하기 쉽도록 쓰여져야 한다.  

### 소프트웨어 개발 실정

제안서에 의해 계약이 이뤄지고 난 후 그대로 개발에 들어가는 경우가 많다. 즉, 구체적인 목표의 확립없이 구현을 시작한다. 설계와 프로그래밍 과정에서 새로운 요구사항이 나타나면 그때서 요구사항의 수정이 이뤄진다.  

이러한 개발 방법으로 제대로 된 좋은 품질의 제품이 생산될 것인가 라는 의문이 생긴다. 이는 나중에 시스템이 완성 된 후 시험할 수 있는 근거를 잃을 수 있다. 왜냐 어떤 부분이 잘못되었는지 가릴 기준이 없기 때문이다.  

**요구사항 명세서**는 품질을 측정하는 기초가 되는 동시에 소프트웨어공학이 추구하는 고품질 소프트웨어를 만든다는 단일 목표에 접근할 수 있게 한다.

소프트웨어 시스템 개발이 실패로 끝나는 경우 실패의 이유를 조사하면 업무 분석이 잘못되었다는 이유이다. 따라서 구체적인 목표의 확립없이 개발에 들어갔다는 것을 의미한다. 목표가 구체적으로 명시되어 있지 않다면 프로젝트를 성공적으로 이끌기 어렵다는 것을 보여준다.  

사용자의 관점과 엔지니어의 관점이 섞여있으면 프로젝트의 관리도 어렵고 좋은 품질의 제품도 만들 수 없다. 그러므로 사용자와 개발자 관점의 분리는 어느 공학에서든 요구되는 원칙이다.  

결론은 분석과 설계에 충분한 노력을 들여야 한다.  

## 설계

설계란 분석과정에서 모아진 요구사항을 설계도면에 옮기는 것이다. 분석과정을 개념적단계라 할때 설계 과정은 물리적 실현의 첫단계이다. 또한, 설계는 품질에 직접적인 영향을 미치며, 설계가 제대로 되지 않으면 안정감이 없는 시스템이 만들어진다. 안정감이 없는 시스템은 유지보수가 어렵고 조금만 변화가 가해진다면 견디지 못한다.

시스템을 만들며 중요하게 구분되어야 하는 것이 무엇(what)과 떻게(how to)이다. 시스템 설계는 서브시스템들로 이뤄진 시스템 구조를 결정하고, 서브시스템들을 HW 및 SW 등의 구성요소들에게 할당한다.

소프트웨어 시스템 설계 단계의 결과물은 설계 문서를 뜻한다.

### 설계 원칙

시스템을 구성요소로 분할한다. 시스템의 구성요소들 사이에 주고 받는 정보의 소통이 최소화되고 각 구성요소의 도긻성이 유지될 수 있도록 시스템을 분할해야한다.  

이후 요구되는 성능과 자원에 대한 예측을 할 수 있어야 한다. 설계에서는 어떻게(how to) 그 문제를 해결할 것인가를 결정한다. 여기서 what과 how to를 나눠 보자.  
무엇(what) : 사용자나 시스템의 기능, 사용자의 관점  
어떻게(how to) : 기능의 수행 방법, 엔지니어의 관점  

비용, 소요 시간, 용량, 그리고 신뢰성 등에 대한 연구를 통해서 현실과 예산에 맞는 최적의 설계 방법을 선택해야한다. 이 방법을 trade-off란 단어로 표현한다.  

소프트웨어 개발도 요구사항 명세서와 설계 문서가 나온 다음 프로그래밍에 들어가는 것이 원칙이다.

## 구현

설계 단계에서 나온 설계 문서를 시스템 설계 모습으로 변환시키는 것이다. 이러한 과정을 통해서 시스템의 기능이 수행 가능한 모습으로 나타난다. 이 과정은 건축의 시공 단계에 해당되며, 설계가 세부적인 방법으로 수행된다. 그 결과물로 소프트웨어 제품이 나올 수 있다. 즉, 구현은 프로그래밍 또는 코딩이라고 부른다.  

구현 과정이 설계 이전 과정보다 비용이 더 많이 든다. 시스템 개발 과정 중 프로그래밍에 드는 비용은 평균 20%, 40~50%의 비용이 요구사항 분석과 설계에 들어간다. 이 비율은 요구사항 분석과 설계가 가지는 중요성을 보여준다.  

소프트웨어 시스템 구현시 부딪히는 어려움은 대부분 분석과 설계의 잘못에 의한 것이다. 설계가 제대로 이뤄지면 시스템 구현은 상대적으로 단순하고 기계적인 과정인 것을 알 수 있다.  

## 시험

어느 제품이든 품질에 대한 중요성은 강조해야한다. 우수한 품질의 제품을 얻기 위해서는 제품이 개발되는 공정 과정마다 품질 보증을 위한 절차를 따라야 한다. 공식적인 검토회 등을 통해 필터링 작업이 필요하다.  

시스템 시험은 품질보증 활동의 중요한 일부분이며 그 임무는 사용자 요구사항, 설계, 구현의 전 과정에 대한 최종 점검을 포함한다. 시험은 제품의 오류를 발견하고 수정하는 과정이며, 시스템 개발 전체 과정에 대하여 체계적으로 점검할 수 있는 일련의 활동들의 집합이다. 시험을 하지 않았을 때 나타나는 문제점과 과다한 비용을 생각하여 보면, 시험 하는 데 드는 비용의 정당성을 찾을 수 있다.  

### 소프트웨어 시스템 시험

사용자 요구사항, 설계, 코딩의 전 과정에 대한 점검이며, 소프트웨어 개발 비용 중 40% 이상을 차지하는 경우가 흔하다. 체계적인 소프트웨어 시스템 테스트를 하기 위해서는 테스트 계획이 만들어져야한다. 이 테스트 계획은 최소한의 시간과 비용을 투자해서 최대한의 확률로 오류를 찾아낼 수 있도록 만들어져야 한다.   

### 소프트웨어 테스트 유형

프로그램의 기본 단위인 모듈에 대한 테스트를 시험하는 **단위 시험(unit test)**가 있으며, 모듈들을 통합하여 프로그램에 대한 **통합 시험(integration test)**을 한다. 그 이후 소프트웨어와 다른 시스템 요소(HW, 다른 SW) 등 모든 요소들이 조화를 이루어 시스템 기능을 만족하는지 확인하는 **시스템 시험(system test)**을 한다. 마지막으로, 고객이 참여하여 요구사항 만족 여부를 검증하는 **인수시험(acceptance test)**이 있다.  

### 소프트웨어 테스트 프로세스

체계적인 소프트웨어 테스트를 하기 위해서는 어떻게 테스트를 수행할지 계획을 세워서 **시험 계획(test plan) 단계**, 시험에 사용되는 데이터를 준비하는 **테스트 설계(test design) 단계**, 소프트웨어 입력하여 결과를 얻어내는 **테스트 실행(test execution) 단계**, 테스트에서 얻어낸 결과를 분석하고 기록하는 **평가(test result analysis and evaluation) 단계**. 총 4개의 프로세스를 거쳐야한다.  

### Yourdon이 주장하는 생존을 위한 6가지 기술

- 객체지향 개발 방법 (Object-Oriented Methods)
- CASE 도구 활용 (CASE Tools)
- 소프트웨어 품질 보증 (Software Quality Assurance)
- 구조적 방법 (Structured Methods)
- 소프트웨어 개발 및 품질의 계량화  (Software Metrics)
- 리엔지니어링 (Re-Engineering)

## 유지보수

제품의 유지보스는 사용 중 발생하는 여러 변경 사항에 대해 적응하는 활동이며 변화에 대비하는 과정이다. 소프트웨 유지보수는 4가지로 그 활동이 요약이 된다.  

- 잘못된 것을 수정하는 유지보수
- 시스템을 새 환경에 적응시키는 유지보수
- 새로운 기능을 추가하는 유지보수
- 미래의 시스템 관리를 위한 유지보수

소프트웨어 시스템의 유지보수를 위해 시스템 변경에 의한 재 요구분석, 재 설계, 재 구현, 재 시험이 필요하게 되고, 관련된 문서의 수정까지도 수반하기 때문에 체계적인 관리 기능이 필요하다.  

### 소프트웨어 유지보수

소프트웨어 시스템은 개발할 때부터 유지보수에 대비하여 만들어져야 한다. 왜냐 잘 설계된 시스템도 유지보수에 드는 비용이 실제 개발 비용보다 많이 드는 경우가 대부분이다.  

유지보수 비용은 개발 당시에는 빙산처럼 노출된 작은 부분만 보인다. 실제 유지보수를 하게 되면 수면 아래의 거대한 부분이 드러난다. 계속 이용하고 발전되어야 하는 소프트웨어 시스템이 빈약하게 설계되고 문서화되어 잇지 않을 대 이를 유지보수해야 하는 엔지니어들과 사용하는 고객들이 겪는 불편함이 크다.  

따라서 탄탄한 계획과 절차에 의한 시스템 제작이 중요하다. 소프트웨어가 건축이나 다른 공학에 비해 유연성을 가지고있지만 그 유연성이 남용된다면 유지보수가 불가능한 상황까지 갈 수 있다.  

### 건축 공학과 소프트웨어 공학 비교

| 건축 공학 | 소프트웨어 공학 |
|---|---|
| 계획 | 계획 |
| 건물 사용자 요구사항 분석 | 소프트웨어 사용자 요구사항 분석 |
| 건물 설계 |  소프트웨어 설계 |
| 시공 | 프로그래밍(코딩) |
| 감리 | 테스팅 |
| 건물 유지보수 | 소프트웨어 유지보수 |

건축 공학과 소프트웨어 공학 공정 과정 비교를 하면 위의 표와 같다. 즉, 위의 표가 소프트웨어의 생애주기(life cycle)이라고 할 수 있다.  

### 소프트웨어 품질과 우리의 미래

소프트웨어 시스템들은 미래의 우리 사회를 지탱하는 중요한 기간 시스템들이 될 것이다. 이러한 기간 소프트웨어 시스템 개발도 탄탄한 계획과 절차에 의하여 구축하여야 한다. 처음부터 올바르게 만들지 않고는 품질 개선 노력과 품질 보증 활동이 성공적으로 이뤄질 수 없고 고품질의 제품과 서비스로 고객의 욕구를 만족시킬 수 없다.  

각 기업에서 소프트웨어 시스템의 품질 보증을 위한 공정 과정과 품질 관리 체계를 확립해야 한다. 품질은 개발팀의 목적과 고객의 기대 및 요구와 직결되어 있다. 모든 엔지니어들과 관리자들이 소프트웨어 개발에 요구되는 체계적인 공정 과정에 대한 중요성을 인식하고, 품질 방침을 이해하여 이를 실천해 나가야 한다. 또한 정부나 기업에서도 제도적으로 그 공정을 과정을 지원해줘야한다.  

## 요약

엔지니어링의 기본 원칙은 개발 과정이 수행되는 임무에 의해 분리되어야 한다.

소프트웨어 개발의 경우 `요구사항 분석 -> 설계 -> 프로그래밍 -> 시험 및 유지보수`로 이어지는 생명주기에 대하여 조사했다.  

요구사항 분석과정에서 사용자에게 제공해야할 기능을 정의했다. 설계 단계부터는 요구사항에서 저으이된 기능을 어떻게 개발할 것인가에 초점을 둔다.  

소프트웨어 시스템 개발도 개발 단계를 분리하여 높은 품질의 소프트웨어 개발을 할 수 있게 된다. 소프트웨어 공학은 개발 계획과 진행에 있어 단계별로 수행되어야 하는 임무를 규정한다.  

시스템 개발은 프로젝트 중간 단계에서 나타나는 산출물을 요구하며, 중간 목표를 설정하고 각 과정을 수행해 나갈 때 최종 목표인 고품질의 소프트웨어가 만들어진다. 각 중간 목표에 대한 철저한 검증을 통해 잘못된 것을 여과하는 작업이 수행되어야 한다.  

---

# 3장 소프트웨어 개발에 대한 오해와 실체

## 소프트웨어 공학 정의

소프트웨어 공학은 실제 효과적으로 작동할 수 있는 우수한 소프트웨어를 최적의 비용으로 얻기 위하여 사용하는 견고한 엔지니어링 원칙이다. 경영학, 경제학, 전산학 및 시스템 공학적인 문제 해결 원리에 기초한다. 허용되는 예산과 시간 범위 안에서 효과적으로 소프트웨어 제품을 개발하고 유지, 보수하는 활동과 관련된 기술적, 관리적 원리를 가지고 있다. 또, 소프트웨어 공학은 소프트웨어 시스템의 개발, 운용, 관리에 적용되는 체계적인 접근 방법이다.  

소프트웨어 공학의 주요 목표는 소프트웨어 제품의 품질을 향상시키고 생산성 및 사용자 만족도를 증진시키는데 있다.  

## 소프트웨어와 관련된 질문들

1. 소프트웨어 시스템을 개발하는데 드는 비용 중 프로그래밍에 드는 비용은 어느 정도인가? ans. 20%  
-> 소프트웨어 시스템은 물리적보다 논리적인 요소들로 구성되어 있어서 건축은 약 80~90% 시공에 소요되지만, 소프트웨어는 20%정도 소요되고, 약 40~50%의 개발 비용이 프로그래밍 이전 단계에 소요된다. 따라서 수치화 하면 테스팅 40%, 프로그래밍 20%, 요구사항 분석과 디자인 40%으로 나뉜다.

2. 중간 사이즈의 소프트웨어 시스템을 개발할 때 한 프로그래머가 일년에 만드는 실행코드는 평균 몇줄이나 될까? ans. 5,000줄 이하  
-> 평균 하루에 10줄 정도 프로그램 작성, 일년으로 계산하면 3,000 ~ 4,000 줄 정도 실행코드를 만든다. 실제로 프로그래머가 짤 수 있는 프로그램의 양은 시스템의 크기, 응용 분야의 난이도에 따라 큰 차이를 보인다.  
통신 시스템의 일부인 교환기 소프트웨어나 운영체제 소프트웨어는 사무 처리용 소프트웨어보다 줄당 4배 이상의 비용이 소요된다. 왜냐하면 품질을 보증하기 위한 노력과 관계가 있다.

3. 사용자에게 배달되는 소프트웨어 시스템의 실행코드 1000줄당 예상되는 오류의 갯수는? ans. 4개 미만  
-> 개발하는 과정에서 발견되는 오류는 1000줄 마다 실행코드에 약 50 ~ 60개 정도 있고, 제품이 완료되어 배달된 후 발견되는 오류는 평균 4개 이하이다. 오류의 종류에 따라 커다란 문제점을 내포할 수 있다.  
소프트웨어의 많은 오류가 출고 이후에 발견되며, 출고 이전에 효과적으로 결함을 찾아내어 여과시키는 것은 소프트웨어의 품질보증을 위하여 필수적이다.  
따라서 소프트웨어의 품질은 생산성보다도 더 핵심적인 현안으로 떠오른다.

4. 사용자가 발견하는 소프트웨어 시스템의 오류는 어떤 것에 기인하는 경우가 많은가? ans. 제안서와 사용자 요구사항에 대한 잘못된 이해  
-> 소프트웨어 시스템 개발에 있어 가장 어려운 문제는 사용자가 무엇을 원하는지 정확히 정의 내리는 일이다. 성공의 열쇠는 무엇을 만들 것이고, 사용자에게 어떤 기능과 편리함을 제공할 수 있는가를 빠르고 효과적으로 파악하는 데 달려있다.  
목표가 정확히 분석되어 있지 않은 상황에서 개발에 들어간다면 시스템이 제대로 만들어 질 확률이 떨어진다. 프로그래밍을 서둘러 시작할수록 더 오랜 시간이 걸려 늦게 끝난다고 볼 수 있다.특히 개발 도중 새로운 요구사항이 계속적으로 추가된다면 체계적인 설계를 하지 못해 품질에 심각한 영향을 미친다. 따라서 개발 이전 목표를 구체적으로 확립하는 것이 성공의 열쇠라고 할 수 있다.

5. 소프트웨어 시스템을 유지, 보수하는데 드는 비용이 개발비용의 몇 배정도 될까? ans. 2배  
-> 소프트웨어 개발 비용보다 유지보수 관리비용이 더 많이 들어가지만, 개발 중에는 유지보수 비용이 과소평가 되기 쉽다. 이 비용은 얼마나 체계적으로 만들어졌느냐에 따라 반비례한다. 개발비용이 총 비용의 약 33%를 차지한다면 유지보수 비용은 약 67%를 차지한다.

### 소프트웨어 현실  

소프트웨어는 눈에 보이지 않는다 해서 하드웨어 또는 시스템의 부속으로 딸려가는 부분으로 인식되어 있는 경우가 많다. 소프트웨어 시스템에 들어가는 비용은 제품의 가격에도 포함되지 않은 경우가 많다. 따라서 높은 품질의 소프트웨어 개발을 지원 제도와 인식의 변화가 필요하다.  

### 품질의 중요성

품질 보증에 대한 계획적이고 체계적인 접근 방법의 적용은 필수적이다. 품질은 시스템을 개발하는 조직의 목적과, 시스템을 사용할 고객의 기대 및 요구와 깊은 관계가 있다.  

조직의 어느 일부에 의해 향상될 수 없으며, 관리자의 품질에 대한 목표와 의지가 있을 때 가능하다. 관리자와 개발자 모두가 품질에 대한 원칙을 이해하고 실행할 때 품질을 향상시켜 나갈 수 있다. 즉, 만드는 사람의 관점만 가지고는 품질이 향상될 수 없고, 사용자의 관점이 제품에 반영될 떄 품질 향상이 가능하다.

## 소프트웨어의 위기

소프트웨어는 결정적인 전환점이나 발전 없이 느리고 점진적인 변화만 있어 왔다. 또한 개발 역사 동안 생산성이나 개발 방법에서 전환점이 없다. 따라서 현재의 엔지니어들이 아직도 30년 전과 비슷한 방법으로 소프트웨어 시스템을 개발하고 있는 경우가 흔하다.  

소프트웨어의 위기는 이러한 30년간 전환전이 없었다는 것에 기인한다. 소프트웨어 개발 기술의 낙후함과 전문 인력 부족현상이 소프트웨어 위기 현상을 야기시켰다.  

### 소프트웨어 위기의 원인

1. 소프트웨어 생산성이 사용자들의 서비스에 대한 요구를 따라가지 못한다.  

	- 고객의 기대치 상승했으나, 생산성 증대하지 못했다.
	- 소프트웨어 프로젝트는 제안서에 의해 시작되었으나, 사용자의 요구사항에 대한 정확한 내용을 파악하기 어려운게 대부분이며, 확실한 요구사항과 목표를 세우기 어렵다.
	- 사용자와 개발자간의 의견교환 미흡하다.

2. 소프트웨어 품질이 향상되지 못하고 유지보수가 힘들다.

	- 사용자가 볼 수 있는 작동하는 시스템은 공정 후반부에 가서야 얻을 수 있다.
	- 주요한 결점들이 후반부에 발견되어 시스템 전체에 큰 문제를 일으키는 경우가 많다.
	- 소프트웨어 프로젝트는 공기 내에 끝내기 어려운 경우가 많다.
	- 유지보수 많은 노력과 비용 소요
	- 새로운 프로젝트 추진 어려움
	- 시스템 개발에 있어 소프트웨어 비용이 하드웨어 비용을 능가한다.
	- 소프트웨어 품질 관리는 하드웨어의 비해 힘들다.

3. 관리자나 엔지니어들이 새로운 기법들에 대하여 잘 모르며 과거의 경험에 의존하여 코딩에 접근한 경우가 많다.  

4. 새로운 기술에 대한 훈련이 없다.  

5. 기업에서 관리자와 개발자들에 대한 교육과 훈련을 지속적 제공해야한다.  

6. 소프트웨어 체계적인 접근 방법이 많지 않아 소프트웨어 품질 향상의 장애 요인이다.  

7. 객체지향 소프트웨어 개발 방법론이 소프트웨어 품질 향상 방법 중 하나이다.  

8. 프로젝트 개발 일정과 소요비용 예측이 매우 부정확하다.  

	- 다른 공학에 비해 과거의 경험과 자료가 적다.
	- 일정과 비용 예측을 하는 중견관리자들의 경험이 부족하다.

## 소프트웨어 위기의 해결책

1. 소프트웨어 시스템 개발은 일반적으로 인식되는 것보다 매우 어려운 일이다. 그 원인과 문제점에 대한 정확한 인식이 필요하다.

2. 체게적인 소프트웨어 개발 방법의 필요성이나 중요성을 인식이 필요하다.

3. 소프트웨어 개발은 기술적인 문제 뿐 아니라 관리적인 측면에서 조직적으로 문제를 극복하려는 노력을 요구한다.

4. 참여한 모든 사람들이 문제점에 대한 정확한 인식과 목표를 가지고 그것을 해결하기 위한 방법과 과정을 공유해야한다.

## 소프트웨어에 대한 오해

소프트웨어와 관계가 있는 관리자, 고객, 엔지니어들이 가지고 있는 오해 분석  

관점을 가볍게 읽어본다.  

관리자의 오해 : 소프트웨어 개발에 관한 좋은 책들이 있고 책안에 개발 표준과 단계가 제시되어 우리에게 필요한 부분을 제공한다. 개발자들에게 필요한 최신 기계나 CASE 도구를 도입하였으니 좋은 제품을 빠른 시일 내에 개발이 가능할 것이다. 엔지니어들이 요구분석을 하고 있으면 생산적이지 못한 일을 하고 있는 줄 안다.  

고객의 오해 : 목표에 대한 개략적인 기술만 하면 충분하며, 세부적인것은 나중에 채워 넣으면 된다. 사용자의 요구사항은 계속 변하며 소프트웨어는 유연하여 쉽게 변경을 수용할 수 있다.  

엔지니어의 오해 : 일단 프로그램이 만들어지고 작동되면 우리의 임무는 끝난다. 시스템을 작동시켜 보기 전까지는 품질을 평가할 방법이 없다. 프로젝트의 결과는 작동하는 프로그램뿐이다.

## 요약

소프트웨어 공학이란 체계적인 공법을 적용하여, 최적의 비용으로 고품질의 소프트웨어 시스템을 개발하는 것이며, 단일 목표는 높은 품질의 제품을 만드는 것이다. 그 목표에 있어 많은 어려움이 있으며, 관리자, 고객 그리고 엔지니어들의 오해가 있다.  

소프트웨어 개발은 기술적인 측면 뿐아니라 관리적인 측면에서 조직적으로 문제 극복 후 품질을 향상시키려는 노력을 요구한다. 따라서 참여한 모든 사람들이 무네점에 대한 정확한 인식과 목표를 가질 때 좋은 품질의 제품이 만들어지고 프로젝트는 성공적으로 완수할 수 있다.  

---

- 8日  

DP와 문자열 문제 해결

[퇴사](http://noj.am/14501)  
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, ans = 0;
	cin >> n;
	vector<pair<int,int>> v(n+1);
	vector<int> dp(n+1);
	for (int i=1; i<=n; i++) {
		cin >> v[i].first >> v[i].second;
		dp[i] = v[i].second;
	}
	
	for (int i=2; i<=n; i++) {
		for (int j=1; j<i; j++) {
			if(i-j >= v[j].first)
				dp[i] = max(v[i].second + dp[j], dp[i]);
		}
	}
	
	for (int i=1; i<=n; i++) {
		if(i + v[i].first > n + 1)
			continue;
		ans = max(ans, dp[i]);
	}
	cout << ans;
}
```
해당 문제는 주어진 날짜만큼 일이 주어지고 일에 해당되는 봉급을 최대한 많이 받을 수 있는 값을 구하는 문제이다. 처음에는 이중 포문을 통해서 브루트포스로 구해볼려고 했지만 마지막 예시에서 오답이 나와 어려움을 겪었다. 다시 생각해보니 dp[i]라는 것을 i번쨰 날짜에 가장 높은 봉급으로 설정한 뒤 각각의 값을 더해 max 값을 구했다.  

[버그잡이 꿍](http://noj.am/6613)  
```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6*2;
int fail[MAX];
int idx[MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string bug;
	while(cin >> n >> bug) {
		memset(fail, 0, sizeof(fail));
		
		for(int i=1,j=0; i<bug.length(); i++) {
			while(j>0 && bug[i] != bug[j])
				j = fail[j-1];
			if(bug[i] == bug[j])
				fail[i] = ++j;
		}
		cin.ignore();
		for (int t=0; t<n; t++) {
			string str;
			getline(cin,str);
			
			char ans[MAX];
			int k = 0;
			
			for(int i=0,j=0; i<str.length(); i++) {
				idx[k] = j;
				ans[k++] = str[i];
				while(j>0 && str[i] != bug[j])
					j = fail[j-1];
				if(str[i] == bug[j]) {
					if(j == bug.length()-1) {
						k -= bug.length();
						j = idx[k];
					}
					else
						j++;
				}
			}
			ans[k] = '\0';
			cout << ans << '\n';
		}
	}
}
```
이 문제는 문장이 n만큼 주어지며, 버그 문장이 주어진다. 해당 버그 문장이 있는 부분을 제거하고 원 문장을 출력하는 문제이다. 처음부터 kmp 실패함수를 버그 문장에 적용하여 실패함수를 구하였다. 이후에 주어진 문장에서 kmp 알고리즘을 이용해서 겹치는 부분을 찾았다. 이때 벡터를 이용해서 해당 인덱스를 구한 뒤 벡터에서 pop_back() 연산을 통해 벡터에 해당 원 문장을 구하도록 하였다. 이러한 방법은 결국 시간초과라는 결과를 냈다.  

이후에 다시 생각해보니 벡터의 pop_back() 연산을 이용하게 되면 거기서 시간이 크게 소요될 것 같아 char형 배열과 인덱스 배열을 하나 선언하여 인덱스를 유지하며, char형 배열에 원 문장을 추가해갔다. 이후 해당 버그 문장을 발견하게 되면 그 만큼의 인덱스를 줄이고 덮어씌어가는 형식으로 진행했다. 마지막으로 끝난 경우 마지막 인덱스에 널문자를 삽입해 뒤에 어떠한 문자가 있든지 무시하도록 설계했다.  

그러자 원하는 만큼 시간을 줄일 수 있었다. 또한 getline 함수를 사용하면서 버퍼가 비워지지않아 fflush() 함수를 사용해보았지만 원하는 기능을 하지 못했다. 따라서 이 부분을 찾아보게 되어 cin.ignore()라는 함수를 통해서 버퍼를 비우고 문제의 필요한 값을 입력 받을 수 있었다.  

---

- 9日  

# OpenSource Software Development 1장 History of Open Source SW  

1970년대 이전, 에덴동산과 같이 SW가 자유로웠다. 이때 하드웨어만을 제작, 판매가 이뤄졌다. 그리고 소프트웨어는 공개되어 있어서 누구나 자유롭게 공유, 수정, 배포가 가능했다. 이때의 유닉스가 등장했다.  

1980년대 상업용 컴퓨터의 시장 확대와 개인용 컴퓨터의 확산이 이뤄졌다. 이 시절에는 과학에서 산업화로 넘어가기 시작했다. 그 화두에는 빌 게이츠의 편지가 있다. 빌 게이츠의 편지로 지적재산권에 대해 언급되기 시작했다.  

이후 이전의 시스템의 이식성이 낮아, 유닉스로 다 넘어가기 시작했다. 이때부터 유닉스의 상용화가 시작되었다. 상용 SW은 소스코드 비공개이며, 동작을 분석하는 리버스 엔지니어링도 금지되었다.  

이러한 흐름에도 여전히 자신을 과학자라고 생각하는 해커들은 상용화에 반대를 하였다. 폐쇄성은 과학의 발전을 막고, 발전 속도를 더디게 할 것이라고 주장했다.  

## GNU

해당 주장을 하는 사람 중 유명한 사람이 바로 Richard Matthew Stallman이다. Stallman은 GNU라는 집단을 만들어 자유롭게 SW를 공유하는 해커 공동체를 복구하자는 선언문을 게시했다. 선언문에서는 프로그래밍을 완전히 과학의 영역으로 본다.  

GNU에서 Free Software의 기반인 새로운 OS Kernel을 만들고자 했으나, 결과는 실패했다. 이외에는 GCC, GDB, Emacs, Sendmail 등 소프트웨어를 새로 제작했다. GNU를 운영할 재단을 설립하기도 했는데 해당 재단을 FSF(Free Software Foundation)라고 명명했다.  

GNU가 정의하는 자유 소프트웨어란  
- 프로그램을 어떠한 목적을 위해서도 실행할 수 있는 자유
- 프로그램의 작동 원리를 연구하고 이를 자신의 필요에 맞게 변경시킬 수 있는 자유
- 이웃을 돕기 위해서 프로그램을 복제하고 배포할 수 있는 자유
- 프로그램을 향상시키고 이를 공동체 전체의 이익을 위해서 다시 환원시킬 수 있는 자유

## 리눅스의 등장

Linus Tovalds가 홀로 개발하던 OS를 GNU 메일링 리스트에 올려서 다른 개발자들과 완성해갔다. 이후 GNU에서 자유 소프트웨어를 위한 OS 커널을 개발에 어려움을 겪어, 리눅스를 GNU 시스템과 결합시켰다. 따라서 리눅스를 Linux Kernel + GNU SWs로 배포하게 되었다.  

지금까지의 흐름을 살펴보면 소프트웨어를 자유롭게 공유하면서 개발하던 초기에서 소프트웨어가 상업화가 되기 시작했다. 이러한 변화때문에 소프트웨어 업계가 자유 소프트웨어와 상업화 소프트웨어로 분열이 일어났다.  

## 오픈소스의 등장

1998년에 여러 자유 소프트웨어 공동체들의 리더들이 모여서 자유 소프트웨어 재단의 anti-business 적인 면을 개선하자는 주제로 의견을 나눴다.  

그 결과로 오픈 소스라는 새로운 용어가 탄생하게 되었다. 오픈 소스는 자유 소프트웨어보다 상업적인 제약을 완화시키며, 개발 과정에 다수의 개발자가 참여하도록 유도한다.  

자유 소프트웨어와의 차이점을 보면 기업이 받아들이기 어려운 Free라는 단어를 제거하고 결과물의 활용에 주목하는 자유 소프트웨어와 다르게 결과물의 용도보다 개발 과정에 많은 사람이 참여하는 것에 주목했다.  

## 오픈소스 소프트웨어 탄생 의미

과학계와 산업계가 자유롭게 교류할 수 있는 가교 역할을 수행하며, 기존 자유 소프트웨어의 정신을 이어받으면서 상용 소프트웨어가 비상용 소프트웨어와 상호작용 할 수 있게 하였다.  

---

# Distributed Computing 1장 Cloud Computing-Intro  

## 컴퓨팅 시스템의 변천

메인프레임 시대 -> 클라이언트/서버 시대 -> 웹 컴퓨팅 시대 -> 클라우드 컴퓨팅 시대  

## 데이터센터의 진화와 중요 이슈

초기에는 Traditional DataCenter는 애플리케이션 마다 각각 서버를 하나씩 두고 그 위에 시스템 관리 소프트웨어를 둬서 구동하였다. 이때는 서버 효율이 비효율적이었다.

이후 Virtualized DataCenter는 고도화 사업을 통해 다수의 서버에 가상화를 통해서 한 서버당 여러 애플리케이션을 두고 그 위에 가상화 시스템 관리 소프트웨어를 둬서 구동한다. 이전보다는 효율을 증대시켜서 TCO(Total Cost of Ownership)를 줄일 수 있었다.  

최근에는 Cloud DataCenter로, 분산된 서버에 가상화를 한 뒤 클라우드 시스템 관리 소프트웨어에서 각각의 애플리케이션을 구동하는 방식으로 이루어져있다.  

## 클라우드 컴퓨팅이란?

여러 곳에서 클라우드 컴퓨팅을 정의한다. 그 중 NIST 기관에서 정의하는 클라우드 컴퓨팅에 대해서 알아보자.  

인터넷이 아니더라도 네트워크를 통해서 원할 때 원하는 만큼네트워크, 서버, 저장공간, 애플리케이션 등 여러 공유된 상태로 제공될 수 있다. 또한, 서비스를 제공을 위한 준비를 빠르게 하며 서비스 반납도 빠르게 한다. 이러한 작업을 높은 레벨의 가용성으로 제공되어야한다.  

클라우드 컴퓨팅의 대한 유저의 관점
- 작업의 과정이 어떻게 되는지 몰라도 된다.
- 제공자가 무엇을 하는지 몰라도 된다.
- 물리적인 인프라를 소유할 필요 없다.

## Utility Computing

쉽게 이해하자면 원할때 원하는 만큼 서비스를 제공받고 반납하는 모델이다. 즉, Demand-on이라는 단어를 통해서 의미를 생각해 볼 수 있다.

## Service Oriented Architecture (SOA)

클라우드 컴퓨팅이 있기 전에 이미 있던 개념으로, OOP. 객체지향 프로그래밍과 같이 객체간의 요청에 맞춰서 제공하듯이, 서비스 제공자와 소비자 사이의 요청에 맞춰서 서비스 형태로 제공하는 것이다. 해당 개념은 웹 서비스의 모델이기도 하다.  

## Quality of Service (QOA)

클라우드 컴퓨팅은 물리 자원이 아닌 가상 자원을 타인들과 공유해서 사용한다. 따라서 다른 사람들이 많이 사용하게 되면 나에게 할당되는 자원은 떨어질 수 밖에 없다. 이때 유저들은 제공자가 어떻게 제공하는지 관심이 없지만, 서비스의 품질에만 관심이 있다.  

인터넷 기반으로 된 서비스의 경우 특정 유저를 위한 높은 품질의 서비스를 제공할 수 없다. Best Effort라는 용어를 통해서 특정 유저들을 위해 높은 품질의 서비스를 제공하지는 못하지만 최선을 다하겠다는 용어이다. 왜냐하면 인터넷은 패킷 전달만 고려하고 만들어졌기 때문이다. 따라서 서비스의 품질에 대한 고려가 제외가 된 채로 설계되었기 때문이다. 이런 분야에서 쓰이는 용어가 QOA이다.

## Service Level Agreement (SLA)

Quality of Service가 구체화된 것이 클라우드 컴퓨팅의 Service Level Agreement라고 생각하면 좋다. 즉, 유저가 원하는 품질의 서비스를 제공자와 계약을 하는 것이다. 클라우드는 SLA를 먼저 동의를 하고 사용하게 된다.  

서비스의 레벨을 정확히 명시하고 계약을 하기 때문에 서비스의 품질이 부족하다면 그만큼의 패널티를 보상 해줘야한다. 그리고 그 서비스를 어떻게 관리할 것인지 명시되어 있는 것이 SLA다.

---

# Docker Compose

Docker Compose란 다중 컨테이너 도커 애플리케이션을 정의하고 실행하기 위한 도구이다.  

간단한 예시 프로그램을 만들어서 이해를 해보자.  

## 예시 프로그램

express를 통해서 간단하게 페이지를 구현해본다. 다음의 소스로 구현하였다.  

`package.json`
```json
{
  "name": "docker-compose-app",
  "version": "1.0.0",
  "description": "",
  "main": "server.js",
  "scripts": {
    "start": "node server.js"
  },
  "dependencies": {
    "express": "4.17.1",
    "redis": "3.0.2"
  },
  "author": "",
  "license": "ISC"
}

```
`server.js`
```js
const express = require("express");
const redis = require("redis");

//레디스 클라이언트 생성

const client = redis.createClient({
    host: "redis-server",
    port: 6379
});

const app = express();

//숫자는 0 부터 시작하여 증가
client.set("number", 0);

app.get('/', (req, res) => {
    client.get("number", (err, number) => {
        // 현재 숫자 증가
        client.set("number", parseInt(number) + 1);
        res.send(`숫자가 1씩 증가합니다. 숫자: ${number}`);
    })
})

app.listen(8080);
console.log('Server is Running');
```

지금까지 만들어온 Dockerfile과 같이 만들면 된다.  
`dockerfile`
```dockerfile
FROM node:10

WORKDIR /usr/src/app

COPY ./ ./

RUN npm install

CMD ["node", "server.js"]
```

여기까지는 이전에 했던 부분과 비슷하다. 해당 소스를 도커를 통해 실행을 하게 되면 다음과 같다.  

두 개의 컨테이너로 나눠져, 레디스가 들어있는 컨테이너와 node 앱과 레디스 클라이언트가 들어있는 컨테이너가 존재하게 된다.  

두 개의 컨테이너를 따로따로 실행하게 되면 컨테이너 사이에 아무런 설정 없이 접근이 불가능하다. 따라서 node.js 앱이 레디스 서버에 접근을 할 수 없게 되어 에러가 일어나게 된다.  

## docker compose 파일 구조와 작성

여기서 컨테이너 사이에 통신을 하게 해주기 위해서 Docker Compose를 이용하게 된다.  

해당 프로젝트에 `docker-compose.yml` 파일이 추가된다.  

먼저 docker-compose 파일 구조를 보게 되면 docker-compose 속에 다중의 컨테이너들을 넣어주게 된다. 여기서는 컨테이너들을 services라고 명한다. 해당 컨테이너에서 해줘야하는 역할들을 적어줘서 묶어서 실행하게 된다.  

- version : docker compose 버전
- services : 이곳에 실행하려는 컨테이너들을 정의
	- redis-server : 컨테이너 이름
		- image : 컨테이너에서 사용하는 이미지
	- node-app : 컨테이너 이름
		- build : 현 디렉토리에 있는 Dockerfile
		- ports : 포트 맵핑 로컬 포트 : 컨테이너 포트

```yml
version: "3"
services: 
    redis-server:
        image: "redis"
    node-app:
        build: .
        ports:
            - "5000:8080"
```

이후에 도커를 실행할 때의 명령어는 `docker-compose up`으로 사용하면 된다. 이때 유의해야할 점은 프로젝트 디렉토리에 위치한 상태에서 명령어를 사용해야한다.  

## docker compose 명령어 옵션

docker compose 명령어에서 --build 옵션을 줄 수 있다. 해당 옵션이 있고 없고의 차이를 보자.  

먼저 docker-compose up의 경우에는 이미지가 없을 때 이미지를 빌드하고 컨테이너를 실행시키는 반면에, docker-compose up --build는 이미지가 있든 없든 이미지를 빌드하고 컨테이너를 실행한다.  

따라서 이미지가 수정이 된 경우에는 --build 옵션을 명시해서 이미지를 새로 빌드해야 해당 수정사항이 반영된다는 것을 알 수 있다.  

추가적으로 여러 개의 터미널로 실행하지 않고 하나의 터미널로 docker compose로 컨테이너를 실행하고자 한다면 다음과 같은 옵션을 사용하면 된다.  

`docker compose -d up` -d 옵션은 detached 모드로써 앱을 백그라운드에 실행한다. 따라서 앱에서 나오는 output을 출력하지 않고 백그라운드에서 계속 실행하게 된다.  

이후에 docker compose를 중지 시키고 싶다면 `docker-compose down` 명령어를 통해서 작동된 앱을 중지 시킬 수 있다.  

---

- 10日  

오늘은 프로그래머스에서 주최하는 코딩 챌린지를 시작하는 첫 달이다. 그래서 시작 전에 조금 문제들을 풀며 보냈다. 대부분 쉬운 문제 위주로 워밍업을 했다. 그에 반해 코딩 챌린지의 문제는 생각보다 쉬운 편에 속하였다.  

하지만 문제를 풀어감에 있어서 집중력도 떨어지고 실수가 잦아서 길어진 탓에 제대로 못 풀었다. 대부분 구현을 하면 되는 문제로, 갈피는 금방 잡혔다. 2번 문제에서 초기화 과정에서 실수가 있어서 체크하지 못하고 1시간정도 허비되었다. 이후 3번 문제에서는 집중력도 떨어진 상태에서 시간 초과를 해결하지 못하였다. dp를 사용하여 시간을 대폭 줄일 수 있다는데 dp로 생각을 이끌어가지 못했다.  

그러므로 자연스레 4번은 제대로 읽지도 못하고 끝나게되었다. 4848명중 477등으로 끝났는데 허수를 포함하면 좋은 성적은 아니란 것을 알 수 있었다. 앞으로 문자열만 공부하는 것이 아닌 dp에 더 중점을 두고 ps를 공부할 것이다.  

1번 기억x, 2번 달팽이 채우기, 3번 dp를 이용한 풍선 터뜨리기, 4번 2차원 배열 두 개 사이의 조건 맞춰서 조합

---

- 11日  

# Travis CI

CI란? 지속적 통합(Continuous Integration, CI)은 지속적으로 퀄리티 컨트롤을 적용하는 프로세스를 실행하는 것이다. - 작은 단위의 작업, 빈번한 적용. 지속적인 통합은 모든 개발을 완료한 뒤에 퀄리티 컨트롤을 적용하는 고전적인 방법을 대체하는 방법으로서 소프트웨어의 질적 향상과 소프트웨어를 배포하는데 걸리는 시간을 줄이는데 초점이 맞추어져 있다. 대표적인 CI 툴에는 젠킨스(Jenkins)가 있다. (출처: 위키백과)  

즉, 팀 내에서 작업한 결과물들을 정기적으로 통합하는 것이라고 볼 수 있다. 개발자들이 각각 작업한 결과물들을 따로 합치게되면 버그가 생길 수 있으므로 주기적으로 통합하면서 컴파일, 테스트, 빌드 등을 하여 검증해준다.

그 중 Travis CI는 Github에서 진행되는 오픈소스 프로젝트를 위한 지속적인 통합 서비스로, Github repository에 있는 프로젝트를 특정 이벤트에 따라 자동으로 테스트, 빌드하거나 배포 할 수 있다.  

## 흐름

로컬 Git -> Github -> Travis CI -> AWS  

1. 로컬 Git에 있는 소스를 Github 저장소에 Push
2. Github master 저장소에 소스가 Push되면 Travis CI에게 소스가 Push가 되었다고 알림
3. Travis CI는 업데이트된 소스를 Github에서 가져옴
4. 가져온 소스 테스트 코드 실행
5. 테스트 코드 실행 후 테스트 성공시 호스팅한다.

## Github과 연결 순서

1. [Travis CI 사이트](http://https://travis-ci.org) 이동
2. github 연결하여 sign up
3. 해당 레포지토리 활성화
4. 이후 push시 자동으로 연동

## 설정

Docker의 경우에는 `docker-compose.yml`에 했던거와 같이 Travis CI는 `.travis.yml`파일에 설정을 할 수 있다.  

1. 도커환경에서 해당 앱을 실행하고 있으니 Travis CI에서도 도커환경 구성한다.

2. 구성된 도커 환경에서 `Dockerfile.dev`를 이용해서 도커 이미지 생성

3. Test 수행할 방법을 설정

4. 호스팅을 어떻게 할 것인지 설정

`.travis.yml`
```yml
sudo: required

language: generic

services:
	- docker

before_install:
	- echo "start Creating an Image with dockerfile"
	- docker build -t lee20h/docker-react-app -f Dockerfile.dev .

script:
	- docker run -e CI=true lee20h/docker-react-app npm run test -- --coverage

after_success:
	- echo "Test Success"
```

- sudo : 관리자 권한 갖기
- language : 언어(플랫폼) 선택
- services : 환경 구성
- before_install : 스크립트 실행 할 수 있는 환경 구성
- script : 실행할 스크립트(테스트 실행)
- after_success : 테스트 성공 후 할일

해당 파일을 작성하면서 문제가 있었다. 그것은 바로 VSCode를 이용하면서 yml파일을 작성하였는데 자동으로 들여쓰기 해주는 부분이였다.  

예를 들어 `services:`를 친뒤 개행하고 `- docker`같은 속성들을 넣어줄 때 자동으로 탭으로 들여쓰기를 해주는데 이 부분이 github에서는 문제로 작용이 되었다. push는 되지만 travis가 감지를 못하는 문제가 있었다.  

따라서 .travis.yml 작성 시에는 꼭 들여쓰기를 유의해야한다.  
 
---