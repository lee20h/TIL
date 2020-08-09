---
sidebar: auto
---

# Circuit Switching and Telephone Network

## Circuit Switching  
![Circuit-Switching](/TIL/images/Data_Communication/Circuit-Switching.JPG)  
서킷 생성 후 통신하는 방식으로 
N-by-M Switch(input N, output M)와 N-by-n folded Switch(input, output N) 입력과 출력의 차이를 두고 나뉘어진다. 이 때 두가지 기술이 있다. Space-division switch와 Time-division swtich가 있다.  

## Space-division switch  
공간적으로 분리된 경로를 제공하는 방법이다. 아날로그와 디지털 네트워크에서 설계될 수 있다.  
Crossbar Switch  
Grid형식으로 만들어서 스위치 방식으로 원하는 목적지로 가게한다. 연결성은 가장 좋으나 효율이 떨어진다. 
Blocking이 제일 좋다.  
Multistage switch  
예제를 통해서 모양과 작동만 이해하자  
![Multistage_switch](/TIL/images/Data_Communication/Multistage_switch.JPG)  
single stage라면 15x15개가 필요하나, 위의 그림처럼 만들게 된다면 줄일 수 있다. 그리고 잘 구성한다면 Crossbar Switch만큼의 Blocking에 근사할 수 있다.  

## Time-division Switch  
Time-divsiion multiplexing(TDM)  
![TDM](/TIL/images/Data_Communication/TDM.JPG)  
TSI에서 1<->3, 2<->4으로 매칭해주며, RAM에서 저장 후 매칭하기 때문에 delay가 존재한다.  
TDM bus  
TDM과 TDM bus와는 구조차이만 있을 뿐 기능 차이는 별로 없다. 가운데 버스를 둬서 스위칭 개념으로 매칭한다.  

## Space and time-divsion switch 조합  
Stage을 나눠서 조합할 수 있다. 두 개의 특징을 정리하면 Space-division은 지연이 없으며 비용이 많이 든다. Time-division은 지연이 있으나 비용이 덜 든다. 따라서 두 타입을 잘 조합하면 지연과 가격을 최소로 할 수 있다.  