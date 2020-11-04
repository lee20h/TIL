# AWS Database services

## Database란?

- A database is a collection of **structured** data
    - File is a collection of bytes (data)
- Database captures an abstract representation of the domain of an application
    - Typically organized as “records” (traditionally, large numbers, on disk)
    - and relationships between records
- DBMS (DB Management System)
    - is a (usually complex) piece of software that sits
    - in front of a collection of data,
    - and mediates applications accesses to the data,
    - guaranteeing many properties about the data and the accesses

### DB and DBMS

![image](https://user-images.githubusercontent.com/59367782/98074229-4e7e2f00-1ead-11eb-8fd2-91f6b8278e47.png)

### DBMS: Issues

- **Atomicity**
- **Consistency**
- **Isolation**
- **Durability**

### DBMS: Key Concepts

- Representing Data
    - Data model
    - Conceptual/Logical Schema
    - Physical Schema
- Declarative Querying and Query Processing
    - High level language for accessing data
    - `Data Independence` (logical and physical)
    - Optimization Techniques for efficiently accessing data
- **Transaction**
    - a way to group actions that must happen atomically (all or nothing)
    - guarantees to move the DB content from a consistent state to another
    - isolate from parallel execution of other actions/transactions
    - recoverable in case of failure (e.g., power goes out) 

### Storage System vs. DBMS

- 둘 모두 데이터를 저장하는 시스템
    - 일반적으로 DB는 스토리지 시스템 상위에 위치하며, 데이터 저장은 스토리지에서 담당
- 차이점은?
    - Representing Data?
    - Query Processing?
    - **Transaction (For ACID!)**

- 원자성(Atomicity): 트랜잭션과 관련된 작업들이 부분적으로 실행되다가 중단되지 않는 것
- 일관성(Consistency): 트랜잭션이 실행을 성공적으로 완료하면 언제나 일관성 있는 데이터베이스 상태로 유지하는 것
- 독립성(Isolation): 트랜잭션을 수행 시 다른 트랜잭션의 연산 작업이 끼어들지 못하도록 보장하는 것
- 지속성(Durability): 성공적으로 수행된 트랜잭션은 영원히 반영되어야 함

## AWS Database

### 서비스 특징

![image](https://user-images.githubusercontent.com/59367782/98075958-b41fea80-1eb0-11eb-8af2-4eb63fafce2c.png)

- 설치, 패치, 재시작 등 모든 관리 서비스 제공
- 필요한 시점에 쉽게 확장
- 사용한 만큼 비용 청구
- 여러 AWS 서비스와 편리한 연동

### 종류

- **관계형**
- **키-값**
- 문서
- **인 메모리** : 데이터 엑세스해야 할 때 데이터를 메모리에 직접 저장하여 마이크로 지연 시간 제공한다.
- 그래프
- 시계열
- 원장

### AWS DB 특징

- 특별히 구축된 데이터베이스
- 확장성
- 완전관리형 또는 서버리스
- 엔터프라이즈급

### AWS DB

![image](https://user-images.githubusercontent.com/59367782/98076582-d9f9bf00-1eb1-11eb-837c-d1b43d0e6a6b.png)

### 서비스 배치

![image](https://user-images.githubusercontent.com/59367782/98076629-f4cc3380-1eb1-11eb-8ec8-f0aa7e8d9c7b.png)

### 인스턴스 주의점

- 중지 (Stop) 기능
    - DB 인스턴스는 최대 7일간 중지 가능
        - 7일이 지날 때까지 수동으로 시작하지 않으면 자동으로 시작됨
    - 중지된 동안에도 스토리지와 백업 스토리지에 대해 요금 부과됨
- 중지할 수 없는 인스턴스
    - 읽기 전용 복제본을 포함한 또는 읽기 전용 복제본인 DB
    - 다중 AZ 배포인 DB 인스턴스
    - Microsoft SQL 서버 미러링을 사용하는 DB 인스턴스
- 중지된 상태에서의 제한
    - 중지된 DB 인스턴스는 수정할 수 없음
    - 중지된 DB 인스턴스와 연결된 옵션 그룹은 삭제할 수 없음
    - 중지된 DB 인스턴스에 연결된 DB 파라미터 그룹은 삭제할 수 없음

## AWS RDS & Aurora (Relational Database Service)

### RDS

- Relational DB 서비스
    - 클라우드에서 관계형 데이터베이스를 간편하게 설정, 운영 및 확장
        - 프로비저닝, 패치, 백업, 복원, 장애 탐지, 복구
    - DB가 설치, 설정된 인스턴스 형태로 제공
        - 메모리, 성능 또는 I/O 최적화 인스턴스 유형을 선택 가능
    - 6개의 DB 지원
        - Amazon Aurora, Oracle, Microsoft SQL Server, PostgreSQL, MySQL 및 MariaDB
    - 기존 DB의 migration 을 지원

[참고 자료](https://docs.aws.amazon.com/ko_kr/AmazonRDS/latest/UserGuide/Welcome.html)

### 주요 기능

- 확장성 (서비스 중지 최소화)
    - 스토리지 용량 확장 (MySQL, MariaDB, PostgreSQL 및 Oracle DB 가능)
    - 컴퓨팅 인스턴스 변경 (수 분 이내 종료)
- 성능
    - 범용 SSD: 최대 3,000 IOPS
    - Provisioned IOPS SSD: 최대 30,000 IOPS
- 가용성/내구성
    - 자동 백업, DB 스냅샷 관리, 다중 AZ 배포, HW 결함 시 자동 교체
- 관리
    - 편리한 생성/관리, 모니터링, SW 자동 패치, 이벤트 알림
- 참고
    - [AWS RDS 제품 세부 정보](https://aws.amazon.com/ko/rds/features/)
    - [RDS 스토리지](https://docs.aws.amazon.com/ko_kr/AmazonRDS/latest/UserGuide/CHAP_Storage.html)

### 다중 AZ 배포

- 다중 AZ DB 인스턴스
    - Amazon RDS는 기본 DB 인스턴스를 자동 생성하고,
    - 다른 가용 영역(AZ)에 있는 예비 인스턴스에 데이터를 동기적으로 복제
    - 인프라 장애가 발생하면, Amazon RDS가 예비 인스턴스 (또는 Amazon Aurora의 경우 읽기 전용 복제본)로 자동 장애 조치를 수행하여, 장애 조치 완료 후 데이터베이스 작업을 바로 재개
- 설정 방법
    - Console에서 해당 옵션 체크

[AZ 배포 참고](https://aws.amazon.com/ko/rds/features/multi-az/)

### RDS Scale out

- 읽기 트래픽을 자동으로 관리되는 `Read Replica`로 분산
- 복수의 Read Replica를 사용하여 워크로드 분산 처리
- 손쉬운 구성

### 읽기 전용 복제본 (Read Replica)

- 읽기 성능 향상
    - 특정 소스 DB 인스턴스의 복제본을 하나 이상 생성하여, 여러 데이터 사본에서 들어오는 대량의 애플리케이션 읽기 트래픽을 처리
- 가용성 향상
    - 장애 처리 시, 독립 실행형 DB 인스턴스로 승격될 수 있음
- 요금
    - 표준 인스턴스와 동일 요금
- 설정 방법
    - Console에서 해당 옵션 체크

[Read Replica 참고](https://aws.amazon.com/ko/rds/features/read-replicas/)    

### 요금

- CPU 크레딧: Xen과 같은 가상화 시스템에서 CPU를 분배하기 위해 사용하는 파라미터. RDS 인스턴스는 EC2인스턴스보다 높고 일관된 크레딧을 부여받아, 높은 성능을 제공할 수 있음
- 다중 AZ배포와 단일 AZ배포는 2배의 가격 차이

### Aurora

Aurora: Enterprise급 DB 서비스

- 자가 복구 분산 스토리지 기반의 AWS RDS
    - 읽기 전용 복제본 최대 15개, 특정 시점으로 복구, Amazon S3로 지속적 백업, 3개의 가용 영역에 걸친 6개의 데이터 복제
- 30초 이내에 인스턴스 장애 조치 수행
- MySQL, PostgreSQL 호환
- 상용 DB의 성능 및 99.99% 이상의 가용성 제공
    - 최대 MySQL 의 5배, PostgreSQL의 3배 성능

RDS보다 비싸고 좋은 성능을 제공한다.