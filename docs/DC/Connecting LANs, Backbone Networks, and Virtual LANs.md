  
 
  

# Connecting LANs, Backbone Networks, and Virtual LANs

## 장비와 장비를 연결할 때 사용하는 장비
- Physical : Repeater or hub  
- Data link : Bridge or two-layer switch  
- Network : Router or three-layer switch  

### Physical
Repeater : 물리계층에서 신호 연장, 복원 역할하는 장비  

Hub : dummy hub, switching hub  
dummy hub : multi-port repeater 물리계층에서 사용됨  
switching hub : 모양은 같으나, 내부구조가 완전 다름. Data link계층 장비이다.(Bridge)  

### Data Link
bridge : Data link 계층 장비로, repeater와는 달리 패킷을 읽어보고 정함  
Transparent bridges  
각 station이 bridge가 있는지 몰라도 됨  
3가지 조건  
1. 다른 station으로 forward됨  
2. 자동으로 forwarding table이 만들어져야한다.  
3. Loop가 형성되면 안된다.  

Spanning tree를 만든다. 이것은 물리적으로 존재하는 loop를 없앨 수 있다.

## Virtual LANs  
다른 LAN에 존재해도 가상 LAN을 구성하여 Broadcast시에 해당 V-LAN에만 보낼 수 있다.  