  
 
  
# Overview of Data Communications and Networking

전북대학교 편기현 교수님의 데이터통신 수업 정리입니다. McGraw-Hill 출판사 책을 이용해 공부했습니다.

Data_Communications의 이미지 출처 : McGraw-Hill

## 데이터의 방향과 흐름
- Simplex : 단방향  
- Half-duplex : 반이중 통신  
- Full-duplex : 전이중 통신  

네트워크 물리적구조  
연결 타입  
- Point-to-point  
![point-to-point](/TIL/images/Data_Communication/point-to-point.JPG)  
- Multipoint  
![multi-pointer](/TIL/images/Data_Communication/multi-pointer.JPG)  

## 토폴리지 종류
### Mesh  
![Mesh](/TIL/images/Data_Communication/Mesh.JPG)  
n(n-1)/2개의 물리적 채널을 갖는다.  
장점 : Traffic 문제가 없으며 한 링크가 망가져도 통신 가능  
단점 : Cost높음
### Star  
![Star](/TIL/images/Data_Communication/Star.JPG)  
HUB에 연결되서 사용됨  
장점 : mesh에 비해 적은 비용, 상대적으로 안정적
### Bus  
![Bus](/TIL/images/Data_Communication/Bus.JPG)  
메인 케이블(Backbone)에 연결하는 MultiPoint 연결방식  
장점 : 쉬운 설치  
단점 : 문제 발생 시 수정 어려움  
### Ring  
![Ring](/TIL/images/Data_Communication/Ring.JPG)  
Point-to-Point방식 연결  

토폴리지 방식들의 특징, 주요한 점만 파악하자  

## 네트워크 카테고리  
개념 이해 필요
- LAN  캠퍼스, 사무실, 빌딩    
이더넷으로 대체함  
![Multiple-building-LAN](/TIL/images/Data_Communication/Multiple-building-LAN.JPG)  
multiple-building-LAN의 추상화  
- MAN  도시  
- WAN  지역  

Protocol : 규칙의 집합  

De jure standards : 기관에서 정함  
De facto standards : 비중을 통해서 정함