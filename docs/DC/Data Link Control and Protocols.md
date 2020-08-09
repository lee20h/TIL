---
sidebar: auto
---

# Data Link Control and Protocols

- Flow Control  
받는 사람의 buffer가 안 넘치게 함

- Error Contorl  
오류시에 계속 재전송  

## Stop-and-Wait ARQ  
Sender에서 Frame을 전송하고 Receiver는 받은 다음 ACK로 원하는 Frame을 요청하게 된다.Time-out을 둬서 답장이 안 오게 되면 재전송을 하며, 중복으로 받게되면 버리고 다시 ACK으로 요청하게 된다.  
Piggybacking  
Frame에 ACK bit을 둬서 overhead을 최소화 하는 방법이다. 

## Go-Back-N ARQ  
n bit을 할당한 경우 Frame의 갯수는 0~2ⁿ-1  
sender **window size < 2ⁿ** 여야 성립된다. receiver window size는 1이여야 한다.  

## Selective-Repeat ARQ  
ACK와 NAK을 둘 다 사용하며 Receiver의 Window size가 달라진다. 두 Window Size가 2ⁿ/2가 된다.  