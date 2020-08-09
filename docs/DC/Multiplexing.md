---
sidebar: auto
---

# Multiplexing

- Multiplexer(MUX) : 여러개의 선을 한 선으로 모아주는 것  
- Demultiplexer(DEMUX) : 한 선을 여러 개로 나눠주는 것  
- FDM(analog)  
Carrier frequency을 기준으로 Analog multiplexing으로 signals을 compine한다.  
Guard band : 사이사이 띄어놓기  

- WDM
FDM과 동일하되 빛의 파장을 이용해서 장비가 다르다.  

- TDM(Time Division multiplex, digital)  
전체 대역폭을 각각에게 할당을 해주나, 시간마다 할당되는 선이 다르다. Wide band을 한 커넥션에 연결한다. FDM과 비교하면 FDM은 주파수를 쪼개서 사용하므로 작은 주파수 대역으로 전송한다.  
Frame들의 크기는 다 동일하며, 전송 프레임들을 모은 것을 time slot(base time)이라 하며, 하나당 T sec가 필요하다고 한다.  
link의 data rate는 시간 n만큼 빨라지며, unit의 duration은 시간 n만큼 짧아진다.  
Interleaving은 개념적인 부분으로, 그림으로 이해를 한다. frame 간격을 벌려서 Sender와 Receiver가 동기화하여 돌아간다.  
![Interleaving](/TIL/images/Data_Communication/Interleaving.JPG)  

동기화  
동기 : clock 사용  
비동기 : signal 사용  
MUX와 DEMUX사이의 동기화는 비동기 방식으로 한다. 1-bit framing bit을 1과 0을 계속 바꿔가며 한다. 그러므로 frame 사이즈가 1늘어나야한다.  

- Inverse TDM  
TDM을 반대로 여러 개의 라인을 하나의 빠른 속도의 라인으로 모아주는 것이다.