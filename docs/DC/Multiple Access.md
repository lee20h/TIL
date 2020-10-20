  
 
  

# Multiple Access

## Random access  
Node사이의 충돌을 허용하며, 충돌을 해결하기 위한 이슈가 있다.  

## Multiple access (MA)  
### ALOHA Protocol  
충돌이 일어나면 **backoff**한다.

### **Carrier-sense multiple access**(CSMA)  
캐리어를 확인해서 전송 중이라면 기다린다. Packet 전송 전에 확인 후 전송하는 방식으로 충돌이 일어나기도 한다. 그 이유는 동시에 전송하거나 확인 할 때 delay가 존재 할 수 있기 때문이다. Persistence strategy을 사용해서 최대한 충돌을 줄인다.  

- Persistence strategies  
앞의 상태가 뒤에 영향을 받는 것이다. p-persistent하면 p의 확률로 전송한다.  
- Nonpersistent  
앞과 뒤가 독립적이라서 영향을 받지 않는다. Idle인 경우 즉시 보내고 Busy인 경우 랜덤한 시간을 기다린다.

### **CSMA/CD** (collision detection)  
충돌 시에 전송을 취소한다. 충돌이 일어나지 않는다면 성공적인 전달이며, 충돌이 일어난다면 전송을 취소하고 재전송 할 때 **exponential backoff**을 통해서 충돌을 줄인다.(0~2ⁿ-1 중 하나의 시간을 골라서 진행)  
실제로는 프로토콜로 관리하지만 충돌이 일어나지 않는다. (full-duplex스위칭 허브)  

### CSMA/CA (collision avoidance)  
무선환경에서는 충돌을 발견 못하기 때문에 충돌을 회피할 방법을 찾는다. Persistence strategy을 사용한다. Idle line을 많이 넣어서 간격을 줘서 충돌을 피한다.  

Channelization  
공유 가능한 Bandwidth을 시간이나, 공간, 코드로 나누는 것이다.  

FDMA  
유저마다 주파수를 나눠져서 그 채널로 Multiple access 방법이다.  

TDMA  
채널은 한개로, time slot으로 나눈다.  

### **CDMA**  
FDMA + TDMA로 한 채널에 동시에 전송이 가능하다. 주파수를 나누지 않고 대역폭을 자유롭게 사용할 수 있다.  
encoding rule :  
data bit 0 -> -1  
data bit 1 -> +1
silence -> 0  

CDMA Multiplexer  
![CDMA_MUX](/TIL/images/Data_Communication/CDMA_MUX.JPG)  
![CDMA_DEMUX](/TIL/images/Data_Communication/CDMA_DEMUX.JPG)  