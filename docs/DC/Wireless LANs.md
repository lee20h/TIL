  
 
  

# Wireless LANs

IEEE 802.11  
2가지 mode  
- ad hoc : 단말기 끼리 통신  
- AP : Access Pointer을 통해서 통신  
    - ESS : AP와 AP두개이상  
    - BSS : AP한개  

## CSMA/CA를 사용한다.  
### CSMA/CD을 사용하지 않는 이유  
1) 데이터를 받고 보내고 동시에 일어날려면 cost가 더 든다.  
2) hidden terminal의 존재로 항상 충돌을 찾지 못한다.  
3) signal이 멀리 있으면 신호가 약해져서 끝이 충돌하는 것을 찾기 어려워진다.  

Hidden terminal problem  
장애물이 존재하는 경우 다른 signal을 찾지 못해서 충돌이 일어나는지 모르는 상황이 Hidden terminal이라고 한다.  

### CSMA/CA의 핵심  
RTS CTS 컨트롤 패킷을 만들어서 RTS에 시간 정보를 담아서 보낸다. 받은 다른 노드들이 그 시간 동안 데이터를 보내지 않는다.(Network Allocation Vector) 따라서 충돌이 회피된다.  
![CSMA/CA](/TIL/images/Data_Communication/CSMACA.JPG)  


## 외의 연결 방법들
Bluetooth  
무선 LAN으로 고안되었으며, ad hoc network으로 구성되어있다. 2가지 타입으로 나눠진다.  
Piconets  
Master와 Slave관계로 사용된다. 최대 8개 ex) Pc와 주변기기들  
Scatternet  
Piconets을 연결한 방법. 연결된 한가지가 gateway 역할로 master이자 다른 Piconet의 Slave 역할을 할 수 있다.  