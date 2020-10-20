
# Network Models  

각각의 Layer에서는 Low Layer에서 일어나는 일들에 관심이 없다.  

## 5-Layer Internet model  

|          |
|-----------|
| Application |
| Transport |
| Network |
| Data link |
| Physical |  
![5-layer](/TIL/images/Data_Communication/5-layer.JPG)  

Peer-to-peer  
![p2p](/TIL/images/Data_Communication/p2p.JPG)  
Physical Layer는 직접적으로 연결하며 데이터를 변환해서 사용한다.  

![internet_model](/TIL/images/Data_Communication/internet_model.JPG)  
구체적인 통신의 표현  

## Layer 기능  

Physical Layer : 이웃  node에게 Signal 전달  
(**bit을 signal로 변환**해서 전달)  
Bit-to-signal transformation  
Bit-rate control  
Bit-synchronization  
Multiplexing  
Switching  

### Data link Layer : **Next-hop delivery** - **한 노드에서 다음 노드로 Frame을 전달**  
Ethernet기반으로 흐름제어, 오류제어, 접근제어 존재  
![Data-link](/TIL/images/Data_Communication/Data-link.JPG)  
![note-to-node](/TIL/images/Data_Communication/note-to-node.JPG)  
Packetizing  
Media access control  
Addressing  
Flow control  
Error control  


### Network Layer : **end-to-end**(종단간 전송 Source to Destination) Ip -> Ip까지 전송함 따라서 global address 필요  
![end-to-end](/TIL/images/Data_Communication/end-to-end.JPG)  

### Transport Layer : **Process-to-process**이며, Port Addressing을 한다.  end-to-end에 있어서의 흐름제어와 오류제어를 한다.  
![Reliable_process-to-process](/TIL/images/Data_Communication/Reliable_process-to-process.JPG)  

### Application Layer : 전자우편, 파일 전송, 원격, WWW같은 유저에게 서비스를 제공하기위한 Layer  

## 요약 :  
![summary_5Layer](/TIL/images/Data_Communication/summary_5Layer.JPG)  