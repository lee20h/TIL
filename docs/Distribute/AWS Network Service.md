# AWS Network Service

## 네트워크 사전 지식

- IP
- Inbound/Outbound traffic (ingress/egress)
- Subnet
- CIDR (Classless Inter-Domain Routing)
- Routing
- DNS
- VPN, NAT

### Addressing: MAC

네트워크 세그먼트의 데이터 링크 계층에서 통신을 위한 네트워크 인터페이스에 할당된 고유 식별자로 주로 네트워크 주소로 사용됨

![image](https://user-images.githubusercontent.com/59367782/98638656-0065a180-236d-11eb-80f8-d1bcd5895d3e.png)


### Addressing: IP

네트워크와 노드의 주소를 표현한 방법 중 하나로, 전 세계를 연결해준 인터넷의 프로토콜이다.

![image](https://user-images.githubusercontent.com/59367782/98639301-2a1ec880-236d-11eb-915f-181eeb689e81.png)


### Routing

라우팅 알고리즘의 목적은 패킷을 어디로 보낼지 결정하는 것이다. 각자가 분산된 독립적인 형태로 이루어져있다. 

hop을 계산하여 보낼 수 있는 네트워크를 테이블화하여 라우팅 테이블을 작성한다. 라우팅 테이블은 네트워크의 주소와 hop을 매핑하여 작성된다. 이러한 테이블을 일정한 주기로 알려줘서 자신들이 패킷을 어디로 보낼 수 있는지 알 수 있다.

- Routed Protocol: IP, IPX, Apple Talk
- Routing Protocol: RIP, IGRP, EIGRP, OSPF, IS-IS, BGP, DBMPR, MOSPF, PIM Desne & Sparse

### OSI 7 Layers

![image](https://user-images.githubusercontent.com/59367782/98644376-b9c77580-2373-11eb-98e4-190faabba88f.png)

레이어에 따라서 패킷에 헤더를 추가하거나 줄이는 식으로 패킷을 전송한다.

![image](https://user-images.githubusercontent.com/59367782/98646491-cef1d380-2376-11eb-9191-d85260e8b9fc.png)

### Network Class

![image](https://user-images.githubusercontent.com/59367782/98646582-eb8e0b80-2376-11eb-85db-7fd840ea3a19.png)

- 필요성: IP를 분할하여 각 기관 별로 배분하기 위함.
- 단점
    - C클래스는 너무 작고, B클래스는 너무 크다 -> IP 주소의 낭비
    - 예) 전북대 직원은 2000명 내외. B클래스를 할당하면? 6만개 이상 IP는 낭비됨

### Subnet

![image](https://user-images.githubusercontent.com/59367782/98646714-1a0be680-2377-11eb-9167-f6ad46979a98.png)

- 서브넷: 각 클래스 내에서 다시 네트워크를 분할하는 단위
- 필요성: IP 할당의 낭비를 막고, 네트워크를 서로 구분해주기 위함
- 장점: 주소 절약, 라우팅 테이블 크기 감소
- 단점: 복잡하다.

### CIDR: Classless Inter-Domain Routing

- 비트 단위의 IP 주소 표준 분할 방식
    - “Class 로 나눈 것 부터가 잘못!”
    - 클래스 없이, IP 주소를 원하는 대로 분할할 수 있게 하자.

![image](https://user-images.githubusercontent.com/59367782/98646881-622b0900-2377-11eb-98df-7f4f0969cc07.png)

## AWS Network Servcies

- Amazon VPC : Virtual Private Cloud로 자체 프라이빗 가상 네트워크를 통해 클라우드 리소스를 격리

- Elastic Load Balancing : Load Balancing을 클라우드에서 여러 Amazon EC2 인스턴스 전체에 애플리케이션 트래픽을 자동으로 분산

- Amazon Route 53 : Domain Name Service(DNS) 서비스로, 사용자 요청을 AWS 리소스로 연결할 수 있는 가용성과 확장성이 뛰어난 클라우드 DNS

- AWS Direct Connect : AWS로의 전용 네트워크 연결한다. 사용자 네트워크와 Amazon VPC 간의 전용 네트워크 연결

### AWS Direct Connect 

- 사용자 서버에서 AWS로 전용 네트워크 연결을 설정
    - AWS와 사용자의 데이터 센터, 사무실, 또는 코로케이션 환경 사이에 프라이빗 연결을 설정
        - 인터넷 연결이 아님
    - 네트워크 비용을 줄이고, 대역폭 처리량을 향상하며, 인터넷 기반 연결보다 일관된 네트워크 경험을 제공
    - 사용자 서버에서 AWS 프라이빗 리소스에 액세스 가능
        - 예: 프라이빗 IP 공간을 사용하는 Amazon Virtual Private Cloud(VPC)에서 실행되고 있는 Amazon EC2 인스턴스


### AWS Direct Connect Pricing

- 포트 요금 + 데이터 송신 요금

![image](https://user-images.githubusercontent.com/59367782/98939980-9ea06580-252d-11eb-8216-7605b05ab505.png)

- 참고자료
    - [AWS VPC 소개](https://aws.amazon.com/ko/vpc/?hp=tile&so-exp=below)
    - [AWS VPC 시작하기](https://aws.amazon.com/ko/vpc/?hp=tile&so-exp=below)
    - [VPC Deep Dive (김상필 AWS solutions architect)](https://www.slideshare.net/awskorea/vpc-deep-dive?from_action=save)

## AWS VPC (Virtual Private Cloud)

### Network

- Cloud network service
    - 사용자의 가상 컴퓨팅 자원 간의 가상 네트워크를 구성하는 서비스
    - 기본: IP 주소 범위, 서브넷, 라우팅, 게이트웨이 구성 등
    - 확장: VPN, NAT 등
- AWS Network
    - Private: AWS 내부에서만 사용 가능한 주소
        - 집 공유기에 연결된 내 노트북 IP (192.168.0.22)
- Public: AWS 외부에서 연결 가능한 주소
    - 내 노트북으로 port forwarding 을 설정해 외부에서 접속하도록 한 경우
    - 외부 -> 공유기 (114.72.x.x / 192.168.0.1) -> 노트북 (114.72.x.x / 192.168.0.22)

### VPC

- VPC 서비스
    - Amazon Web Services(AWS) 클라우드에 논리적으로 격리된 **가상 네트워크를 정의**하고, 그 내부에 AWS 리소스를 배치, 사용할 수 있음
    - (Virtual IDC: __Internet Data Center__ 라고 생각할 수 있음)
- 기능
    - IP 주소 범위 선택, 서브넷 생성, 라우팅 테이블 및 네트워크 게이트웨이 구성 등 가상 네트워킹 환경을 제어
    - IPv4, v6 지원
    - 보안 기능 제공 (filtering, access control, h/w isolation)
- 비용: 무료
    - VPN, NAT 서비스 유료
    - [AWS 비용 참고](https://aws.amazon.com/ko/vpc/pricing)

### VPC를 이용한 네트워크 구성 예

![image](https://user-images.githubusercontent.com/59367782/98940812-e5db2600-252e-11eb-8415-b57dfdd87eee.png)

- 간단한 공용 웹 사이트 호스팅
    - 블로그 또는 간단한 웹 사이트와 같은 기본 웹 애플리케이션을 VPC에 호스팅
    - 웹 서버가 인터넷의 인바운드 HTTP 및 SSL 요청에 응답하도록 허용
    - 동시에 웹 서버가 인터넷에 대한 아웃바운드 연결을 시작하지 못하도록 하는 보안 그룹 규칙을 만들어 웹 사이트를 보호
        - 타 서버로 능동적으로 접근하지 못하게 하여 DDoS 등에 좀비 PC로 이용되는 것을 방지함

- 다중 계층 웹 애플리케이션 호스팅
    - 웹 서버, 애플리케이션 서버 및 데이터베이스 간에 액세스 및 보안 제한을 엄격하게 적용
    - 2개의 서브넷: 공개적으로 액세스할 수 있는 서브넷과 비공개로 액세스할 수 있는 서브넷
        - Public subnet: 웹 서버
        - Private subnet: 어플리케이션 서버, DB
            - Outbound access: NAT 게이트웨이 사용 (management console, update 등)
- 서버와 서브넷 사이의 액세스를 제어
    - 웹 서버가 (혹은 웹 서버만) App 서버 및 DB를 정상적으로 사용하도록,
    - 네트워크 액세스 제어 목록과 보안 그룹에서 제공하는 인바운드 및 아웃바운드 패킷 필터링을 사용

## ELB (Elastic Load Balancing)

### ELB

- 들어오는 애플리케이션 트래픽을 자동으로 분산
    - 대상: Amazon EC2 인스턴스, 컨테이너, IP 주소 등
        - 단일 가용 영역 또는 여러 가용 영역에 분산 가능
    - 애플리케이션의 내결함성 보장
        - 고가용성, 자동 확장/축소, 보안
    - 세 가지 로드 밸런서 제공

### Application and Network Load Balancer

- 차이점: 각각 L7 과 L4 계층에서 동작
    - 프로토콜
        - ALB: HTTP, HTTPS
        - NLB: TCP
    - 성능
        - 더 낮은 계층에서 동작하므로 **ALB에 비해 NLB의 처리 성능이 높음**
- Classic LB
    - L4, L7 으로 명확히 구분하기 전, 통합된 형태로 서비스하였음
    - VPC 이전에 EC2-classic 이라 불리던 네트워크 서비스에서 사용됨
    - VPC 사용 시에는 더 이상 사용을 권장하지 않음

### ELB 특징

- 고가용성
    - 인스턴스의 상태를 주기적으로 점검하여, 정상 상태의 인스턴스에만 트래픽을 전달함

- 탄력성
    - Auto-scaling 과 통합 가능
    - ELB 자체도 scale out 을 수행하여, 부하에 탄력적으로 대응함

- 기타
    - 보안: 보안 그룹으로 제어 가능
    - 모니터링: CloudWatch 와 통합
    - Hybrid load balancing: 사용자의 로컬 on premise 리소스와 통합 가능

- ELB Scale-out
    - ELB는 인스턴스를 기반으로 제공되는 서비스
    - 인스턴스가 감당하지 못하는 수준의 트래픽이 몰리면, scale out 수행
        - 추가 인스턴스를 생성해 처리함
        - 생성까지 시간이 걸리므로 요청이 단기간에 급증하는 경우, 서비스 딜레이가 생길 수 있음

- MultiAZ 로 로드 밸런싱을 하는 경우
    - 각 AZ 별로 ELB 인스턴스가 생성됨
    - AZ별로 같은 비율로 트래픽이 분배됨
        - 따라서 각 AZ의 서비스 처리 성능은 유사하게 유지되어야 함

### ELB 요금

- Application Load Balancer
    - 실행된 시간 또는 부분 시간 그리고 시간당 사용된 로드 밸랜서 용량 단위(LCU)에 대해 요금이 부과된다.

- Network Load Balancer
    - 실행된 시간 또는 부분 시간 그리고 시간당 Network Load Balancer에서 사용된 로드 밸랜서 용량 단위(LCU)에 대해 요금이 부과된다.

- [AWS ELB 요금](https://aws.amazon.com/ko/elasticloadbalancing/pricing/)


## AWS Route 53 (DNS Service)

- 참고 자료
    - [Route 53 설명서](https://docs.aws.amazon.com/route53/index.html)
    - [Route 53 개발자 메뉴얼](http://docs.aws.amazon.com/ko_kr/Route53/latest/DeveloperGuide/route53-dg-ko_kr.pdf)

### DNS

- 도메인 이름과 IP 간의 연결을 담당하는 서비스
- [AWS DNS 설명](https://aws.amazon.com/ko/route53/what-is-dns/)


### DNS related concepts

- 최상위 도메인(Top-Level Domain)
    - .com, .org 등 도메인 이름의 마지막 부분. 두 가지 유형의 TLD 존재
    1. 일반적인 최상위 도메인: 웹사이트의 내용과 연관되어 명명된 도메인
        - 예) .edu
    2. 지리적 최상위 도메인: 웹사이트의 지리적 영역과 연관되어 명명된 도메인
        - 예) .kr
- 도메인 등록 기관
    - 특정 최상위 도메인을 가진 도메인을 판매할 권리를 소유한 기관
- 도메인 등록 대행자
    - 국제인터넷주소관리기구(ICANN)가 인증한, 특정 최상위 도메인(TLD) 등록을 처리하는 회사.
    - 예) Amazon Registrar, Inc.는 .com, .net, .org 도메인의 등록 대행자

### AWS Route 53

- 클라우드 DNS 서비스
    - 최종 사용자와 웹서비스와의 연결을 담당
        - 53은 DNS service port
- 기능
    - 기본 DNS 기능, 트래픽 관리, 도메인 이름 등록, 상태 확인
        - 공개 DNS 레코드를 생성하고 관리함으로써 서비스 상태에 따라 동적으로 도메인 이름과 IP의 연결을 변경 가능
- 비용: 종량 과금제 (pay-per-use)
    - 호스팅 영역, 트래픽 흐름, 쿼리 당 요금제 적용
    - [AWS 요금 정책](https://aws.amazon.com/ko/route53/pricing/)

![image](https://user-images.githubusercontent.com/59367782/99928163-42d6a780-2d8b-11eb-8e46-87cf8b4e2b37.png)


### Rotue 53의 특징

- 가중치 기반 규칙 (1:1, 1:10)
- 장애 조치 규칙 (Primary, Slave)
- 지리 위치 규칙 (USA, Asia)
- 지연시간 규칙 (Region-based)
- 다중 응답 규칙 (Random)
- 엔드포인트
    - 최종 도달점 (S3, EC2 등) 설정

### DNS 서비스

- 단순히 도메인 이름과 IP 주소 간의 변환 기능만 제공하는 것이 아니라, DNS를 활용한 서비스 전달 경로의 설정이 가능함
    - 사용자는 동일한 Domain name으로 접근하고,
    - 지역에 따라, 혹은 가용 상태에 따라 서로 다른 Region, AZ에서 실제 서비스를 제공함
- 최상위 레벨의 Load balancing, traffic management 역할을 수행할 수 있음