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